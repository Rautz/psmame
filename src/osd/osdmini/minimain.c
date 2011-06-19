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
//  GLOBALS
//============================================================

// a single rendering target
static render_target *our_target;

// joystick data
static INT32 joypad_button_map[16] = {11, 8, 9, 10, 12, 13, 14, 15, 4, 5, 6, 7, 3, 2, 0, 1};
static INT32 joypad_state[4][16];
static INT32 joypad_axis_state[4][4];

// render data
static UINT32* render_surf;
static UINT32 render_width;
static UINT32 render_height;
static Texture* esTex;

static bool QuitThruXMB;

//============================================================
//  FUNCTION PROTOTYPES
//============================================================

static INT32 joypad_get_state(void *device_internal, void *item_internal);

//============================================================
//  logging
//============================================================
static FILE* CELL_LogFile;
void	CELL_Log(const char* aFormat, va_list aArgs)
{
	if(!CELL_LogFile)
	{
		CELL_LogFile = fopen("/dev_hdd0/game/MAME90000/USRDIR/mame.log", "w");
	}

	vfprintf(CELL_LogFile, aFormat, aArgs);
}

//============================================================
//  main
//============================================================
int main(int argc, char *argv[])
{
	InitES();

	// cli_execute does the heavy lifting; if we have osd-specific options, we
	// would pass them as the third parameter here
	mini_osd_interface osd;
	sdl_options options;
	int res = cli_execute(options, osd, argc, argv);

	QuitES();

	if(!QuitThruXMB)
	{
		const char* args[2] = {"-showlog", 0};
		sys_game_process_exitspawn2("/dev_hdd0/game/MAME90000/USRDIR/frontend.self", (res == MAMERR_NONE) ? NULL : args, NULL, NULL, 0, 64, SYS_PROCESS_PRIMARY_STACK_SIZE_512K);
	}
	else
	{
		exit(res);
		return res;
	}
}

//============================================================
//  update input
//============================================================
static inline void update_input()
{
	ESInput::Refresh();

	for(int i = 0; i != ESInput::PadCount() && i != 4; i ++)
	{
		for(int j = 0; j != 16; j ++)
		{
			joypad_state[i][j] = ESInput::ButtonPressed(i, j);
		}

		for(int j = 0; j != 4; j ++)
		{
			joypad_axis_state[i][j] = ESInput::GetAxis(i, j) * 512; //?
		}
	}
}

//============================================================
//  update render
//============================================================
static inline void update_render(UINT32 width, UINT32 height)
{
	if(render_width != width || render_height != height)
	{
		if(render_surf)
		{
			osd_free(render_surf);
		}

		if(esTex)
		{
			delete esTex;
		}

		render_width = width;
		render_height = height;
		render_surf = (UINT32*)osd_malloc(width * height * 4);
		esTex = ESVideo::CreateTexture(width, height);
	}
}


//============================================================
//  init
//============================================================
void mini_osd_interface::init(running_machine &machine)
{
	// call our parent
	osd_interface::init(machine);

	// initialize the video system by allocating a rendering target
	our_target = machine.render().target_alloc();

	// add game pads
	for(int i = 0; i != 4; i ++)
	{
		char buffer[512];

		snprintf(buffer, 512, "PAD %d", i + 1);
		input_device *devinfo = input_device_add(machine, DEVICE_CLASS_JOYSTICK, buffer, NULL);

		for(int j = 0; j != 16; j ++)
		{
			snprintf(buffer, 512, "%s", ESInput::GetButtonName(j).c_str());
			input_device_item_add(devinfo, buffer, &joypad_state[i][j], (input_item_id)(ITEM_ID_BUTTON1 + joypad_button_map[j]), joypad_get_state);
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
	// get the minimum width/height for the current layout
	int minwidth, minheight;
	our_target->compute_minimum_size(minwidth, minheight);

	// make that the size of our target
	our_target->set_bounds(minwidth, minheight);

	// update the render state
	update_render(minwidth, minheight);

	// get the list of primitives for the target at the current size
	render_primitive_list &primlist = our_target->get_primitives();

	// lock them
	primlist.acquire_lock();

	// draw them
	draw32_draw_primitives(primlist, render_surf, minwidth, minheight, minwidth);

	// upload to gpu texture
	uint32_t* pix = esTex->Map();
	memcpy(pix, render_surf, minwidth * minheight * 4);
	esTex->Unmap();

	// unlock the primitives
	primlist.release_lock();

	// present
	ESVideo::PresentFrame(esTex, Area(0, 0, minwidth, minheight), 0, 10);
	ESVideo::Flip();

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

