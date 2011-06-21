//============================================================
//
//  minimain.c - Main function for mini OSD
//
//============================================================
//
//  Copyright Aaron Giles
//  All rights reserved.
//
//  Redistribution and use in source and binary forms, with or
//  without modification, are permitted provided that the
//  following conditions are met:
//
//    * Redistributions of source code must retain the above
//      copyright notice, this list of conditions and the
//      following disclaimer.
//    * Redistributions in binary form must reproduce the
//      above copyright notice, this list of conditions and
//      the following disclaimer in the documentation and/or
//      other materials provided with the distribution.
//    * Neither the name 'MAME' nor the names of its
//      contributors may be used to endorse or promote
//      products derived from this software without specific
//      prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY AARON GILES ''AS IS'' AND
//  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
//  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
//  FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
//  EVENT SHALL AARON GILES BE LIABLE FOR ANY DIRECT,
//  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
//  DAMAGE (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
//  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
//  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
//  ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
//  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
//  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
//  IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//============================================================

#include <es_system.h>

#include "emu.h"
#include "osdepend.h"
#include "render.h"
#include "clifront.h"
#include "osdmini.h"

#undef delete

// OPTIONS
class sdl_options : public cli_options
{
public:
	// construction/destruction
	sdl_options(){};
};


//
//  SOFTWARE RENDER
//
#define FUNC_PREFIX(x)		draw32_##x
#define PIXEL_TYPE			UINT32
#define SRCSHIFT_R			0
#define SRCSHIFT_G			0
#define SRCSHIFT_B			0
#define DSTSHIFT_R			16
#define DSTSHIFT_G			8
#define DSTSHIFT_B			0

#include "rendersw.c"

//============================================================
//  FUNCTION PROTOTYPES
//============================================================
static INT32 joypad_get_state(void *device_internal, void *item_internal);
void CELL_Log(const char* aFormat, va_list aArgs);
void CELL_Log(const char* aMessage);
void return_to_loader(bool aError);

//============================================================
//  GLOBALS
//============================================================

// a single rendering target
static render_target *our_target;

// joystick data
static INT32 joypad_button_map[16] = {11, 8, 9, 10, 12, 13, 14, 15, 4, 5, 6, 7, 3, 2, 0, 1};
static INT32 joypad_state[4][16];
static INT32 joypad_axis_state[4][4];

// render data
static UINT32* render_surf, render_width, render_height;
static PSGLdevice* Device;
static PSGLcontext* Context;
static UINT32 screen_width, screen_height;
static INT32 out_width, out_height;
static Texture* esTex;
static GLuint vertex_buffer;
static bool QuitThruXMB;

// Watch dog
#include "watchdog.h"
sys_event_queue_t watchdog::m_queue;
sys_event_port_t watchdog::m_port;
bool watchdog::m_done;
ESThread* watchdog::m_thread;

//============================================================
// MESS or MAME?
//============================================================
#ifdef MESS
# define LOG_FILE "/dev_hdd0/game/MESS90000/USRDIR/mess.log"
# define LOADER_BIN "/dev_hdd0/game/MESS90000/USRDIR/frontend.self"
#else
# define LOG_FILE "/dev_hdd0/game/MAME90000/USRDIR/mame.log"
# define LOADER_BIN "/dev_hdd0/game/MAME90000/USRDIR/frontend.self"
#endif

//============================================================
// return_to_loader
//============================================================
void return_to_loader(bool aError)
{
	static const char* args[2] = {"-showlog", 0};
	sys_game_process_exitspawn2(LOADER_BIN, aError ? args : 0, 0, 0, 0, 64, SYS_PROCESS_PRIMARY_STACK_SIZE_512K);
}

//============================================================
//  logging
//============================================================
static FILE* CELL_LogFile;
void	CELL_Log(const char* aFormat, va_list aArgs)
{
	if(!CELL_LogFile)
	{
		CELL_LogFile = fopen(LOG_FILE, "w");
	}

	vfprintf(CELL_LogFile, aFormat, aArgs);
}

void	CELL_Log(const char* aMessage)
{
	if(!CELL_LogFile)
	{
		CELL_LogFile = fopen(LOG_FILE, "w");
	}

	fprintf(CELL_LogFile, "%s\n", aMessage);
}


//============================================================
//  main
//============================================================
int main(int argc, char *argv[])
{
	InitES();
	watchdog::init();

	// cli_execute does the heavy lifting; if we have osd-specific options, we
	// would pass them as the third parameter here
	mini_osd_interface osd;
	sdl_options options;
	int res = cli_execute(options, osd, argc, argv);

	watchdog::quit();

	QuitES();

	if(!QuitThruXMB)
	{
		return_to_loader(res != MAMERR_NONE);
	}
	else
	{
		exit(res);
		return res;
	}
}

//
//  init video
//
static inline void init_video()
{
	//Init PSGL
	PSGLinitOptions initOpts = {PSGL_INIT_MAX_SPUS, 1, false, 0, 0, 0, 0, 0};
	psglInit(&initOpts);
	
	Device = psglCreateDeviceAuto(GL_ARGB_SCE, GL_NONE, GL_MULTISAMPLING_NONE_SCE);
	Context = psglCreateContext();
	psglMakeCurrent(Context, Device);
	psglResetCurrentContext();

	//Get Screen Info
	psglGetRenderBufferDimensions(Device, &screen_width, &screen_height);
	glViewport(0, 0, screen_width, screen_height);

	//Some settings
	glClearColor(0, 0, 0, 0);
	glEnable(GL_VSYNC_SCE);

	//Setup Projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrthof(0, screen_width, screen_height, 0, -1, 1);

	// Setup vertex buffer
	glGenBuffers(1, &vertex_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
	glBufferData(GL_ARRAY_BUFFER, 20 * sizeof(GLfloat), 0, GL_STATIC_DRAW);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glVertexPointer(3, GL_FLOAT, 5 * sizeof(GLfloat), 0);
	glTexCoordPointer(2, GL_FLOAT, 5 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
}

static inline void SetVertex(GLfloat* aBase, float aX, float aY, float aU, float aV)
{
	*aBase++ = aX; *aBase++ = aY; *aBase++ = 0.0f;
	*aBase++ = aU; *aBase++ = aV;
}

//TODO: Exit video
//	psglDestroyContext(Context);
//	psglDestroyDevice(Device);
//	psglExit();						
//	free(vertex_buffer);

//============================================================
//  update input
//============================================================
static inline void update_input()
{
	CellPadInfo2 PadInfo;
	CellPadData State;

	//Get pad info
	cellPadGetInfo2(&PadInfo);

	//Scan all pads
	for(int i = 0; i != PadInfo.now_connect && i != 4; i ++)
	{
		//Get data
		cellPadGetData(i, &State);

		//If its a valid list
		if(State.len != 0)
		{
			//Grab all buttons
			uint32_t buttons = State.button[2] | (State.button[3] << 8);

			for(int j = 0; j != 16; j ++, buttons >>= 1)
			{
				joypad_state[i][j] = buttons & 1;
			}

			//Grab all axes
			joypad_axis_state[i][2] = (State.button[5] - 0x80) * 512;
			joypad_axis_state[i][3] = (State.button[4] - 0x80) * 512;
			joypad_axis_state[i][0] = (State.button[7] - 0x80) * 512;
			joypad_axis_state[i][1] = (State.button[6] - 0x80) * 512;
		}
	}
}

//============================================================
//  update render
//============================================================
static inline void update_render(UINT32 width, UINT32 height)
{
	//Check game screen size
	if(render_width != width || render_height != height)
	{
		osd_free(render_surf);	//Freeing and delete zero is a-ok
		delete esTex;

		render_width = width;
		render_height = height;
		render_surf = (UINT32*)osd_malloc(width * height * 4);
		esTex = new Texture(width, height);
	}

	//Check game output region
	INT32 newwidth, newheight;
	our_target->compute_visible_area(screen_width, screen_height, 1.0f, our_target->orientation(), newwidth, newheight);

	if(newwidth != out_width || newheight != out_height)
	{
		out_width = newwidth;
		out_height = newheight;

		float verts[20];
		float out_x = (screen_width - out_width) / 2;
		float out_y = (screen_height - out_height) / 2;
		float out_x2 = out_x + out_width;
		float out_y2 = out_y + out_height;		

		SetVertex(&verts[ 0], out_x, out_y, 0.0f, 0.0f);
		SetVertex(&verts[ 5], out_x2, out_y, 1.0f, 0.0f);
		SetVertex(&verts[10], out_x2, out_y2, 1.0f, 1.0f);
		SetVertex(&verts[15], out_x, out_y2, 0.0f, 1.0f);

		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(verts), verts);
	}
}


//============================================================
//  init
//============================================================
void mini_osd_interface::init(running_machine &machine)
{
	// call our parent
	osd_interface::init(machine);

	// initialize psgl
	init_video();

	// initialize the video system by allocating a rendering target
	our_target = machine.render().target_alloc();

	// initialize input
	cellPadInit(4);	//TODO: Where to quit? The destructor?

	// add game pads
	for(int i = 0; i != 4; i ++)
	{
		char buffer[512];
		snprintf(buffer, 512, "PAD %d", i + 1);
		input_device *devinfo = input_device_add(machine, DEVICE_CLASS_JOYSTICK, buffer, NULL);

		static const char* const ButtonNames[16] = {"Select", "L3", "R3", "Start", "Up", "Right", "Down", "Left", "L2", "R2", "L1", "R1", "Triangle", "Circle", "Cross", "Square"};	

		for(int j = 0; j != 16; j ++)
		{
			input_device_item_add(devinfo, ButtonNames[j], &joypad_state[i][j], (input_item_id)(ITEM_ID_BUTTON1 + joypad_button_map[j]), joypad_get_state);
		}

		for(int j = 0; j != 4; j ++)
		{
			input_device_item_add(devinfo, "Left X Axis", &joypad_axis_state[i][1], (input_item_id)(ITEM_ID_XAXIS + 0), joypad_get_state);
			input_device_item_add(devinfo, "Left Y Axis", &joypad_axis_state[i][0], (input_item_id)(ITEM_ID_XAXIS + 1), joypad_get_state);
			input_device_item_add(devinfo, "Right X Axis", &joypad_axis_state[i][3], (input_item_id)(ITEM_ID_XAXIS + 2), joypad_get_state);
			input_device_item_add(devinfo, "Right Y Axis", &joypad_axis_state[i][2], (input_item_id)(ITEM_ID_XAXIS + 3), joypad_get_state);
		}
	}
}


//============================================================
//  osd_update
//============================================================

void mini_osd_interface::update(bool skip_redraw)
{
	if(!skip_redraw)
	{
		// get the minimum width/height for the current layout
		int minwidth, minheight;
		our_target->compute_minimum_size(minwidth, minheight);
		our_target->set_bounds(minwidth, minheight);

		// update the render state
		update_render(minwidth, minheight);

		// get the list of primitives for the target at the current size and draw them
		render_primitive_list &primlist = our_target->get_primitives();
		primlist.acquire_lock();
		draw32_draw_primitives(primlist, render_surf, minwidth, minheight, minwidth);

		// upload to gpu texture
		uint32_t* pix = esTex->Map();
		memcpy(pix, render_surf, minwidth * minheight * 4);
		esTex->Unmap();

		// unlock the primitives
		primlist.release_lock();

		// present
		esTex->Apply();
		glDrawArrays(GL_QUADS, 0, 4);

		psglSwap();
		glClear(GL_COLOR_BUFFER_BIT); //Better to clear now or at front of function?
	}

	// tick the watchdog
	watchdog::tick();

	// update input
	update_input();

	// check exit state
	if(WantToDie())
	{
		QuitThruXMB = true;
		machine().schedule_exit();
	}
}


//============================================================
//  update_audio_stream
//============================================================

void mini_osd_interface::update_audio_stream(const INT16 *buffer, int samples_this_frame)
{
	ESAudio::AddSamples((uint32_t*)buffer, samples_this_frame);
}


//============================================================
//  set_mastervolume
//============================================================

void mini_osd_interface::set_mastervolume(int attenuation)
{
	//TODO:
}


//============================================================
//  keyboard_get_state
//============================================================

static INT32 joypad_get_state(void *device_internal, void *item_internal)
{
	return *(INT32*)item_internal;
}

