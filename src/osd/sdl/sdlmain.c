//============================================================
//
//  sdlmain.c - main file for SDLMAME.
//
//  Copyright (c) 1996-2011, Nicola Salmoria and the MAME Team.
//  Visit http://mamedev.org for licensing and usage restrictions.
//
//  SDLMAME by Olivier Galibert and R. Belmont
//
//============================================================

// standard sdl header
#include <SDL/SDL.h>
#include <SDL/SDL_version.h>

#ifdef __CELLOS_LV2__
#include <sys/process.h>
extern bool QuitThruSDL;
SYS_PROCESS_PARAM(1001, 1024 * 1024);
#endif

#include <SDL/SDL_ttf.h>

// standard includes
#ifdef MESS
#include <unistd.h>
#endif

// MAME headers
#include "osdepend.h"
#include "emu.h"
#include "clifront.h"
#include "emuopts.h"

// OSD headers
#include "video.h"
#include "input.h"
#include "output.h"
#include "osdsdl.h"
#include "sdlos.h"

#include "watchdog.h"

//============================================================
//  OPTIONS
//============================================================
#ifdef MESS
	#define INI_PATH "/dev_hdd0/game/MAME90000/USRDIR/;.;ini"
#else
	#define INI_PATH "/dev_hdd0/game/MAME90000/USRDIR/;.;ini"
#endif


//============================================================
//  Global variables
//============================================================

//============================================================
//  Local variables
//============================================================

const options_entry sdl_options::s_option_entries[] =
{
	{ SDLOPTION_INIPATH,                     INI_PATH,    OPTION_STRING,     "path to ini files" },

	// debugging options
	{ NULL,                                   NULL,       OPTION_HEADER,     "DEBUGGING OPTIONS" },
	{ SDLOPTION_OSLOG,                        "0",        OPTION_BOOLEAN,    "output error.log data to the system debugger" },
	{ SDLOPTION_WATCHDOG ";wdog",             "0",        OPTION_INTEGER,    "force the program to terminate if no updates within specified number of seconds" },

	// performance options
	{ NULL,                                   NULL,       OPTION_HEADER,     "PERFORMANCE OPTIONS" },
	{ SDLOPTION_MULTITHREADING ";mt",         "0",        OPTION_BOOLEAN,    "enable multithreading; this enables rendering and blitting on a separate thread" },
	{ SDLOPTION_NUMPROCESSORS ";np",         "auto",      OPTION_INTEGER,	 "number of processors; this overrides the number the system reports" },
	{ SDLOPTION_SDLVIDEOFPS,                  "0",        OPTION_BOOLEAN,    "show sdl video performance" },
	{ SDLOPTION_BENCH,                        "0",        OPTION_INTEGER,    "benchmark for the given number of emulated seconds; implies -video none -nosound -nothrottle" },
	// video options
	{ NULL,                                   NULL,       OPTION_HEADER,     "VIDEO OPTIONS" },
// OS X can be trusted to have working hardware OpenGL, so default to it on for the best user experience
	{ SDLOPTION_VIDEO,                   SDLOPTVAL_SOFT,  OPTION_STRING,     "video output method: soft or opengl" },
	{ SDLOPTION_NUMSCREENS,                   "1",        OPTION_INTEGER,    "number of screens to create; SDLMAME only supports 1 at this time" },
//ROBO
	{ SDLOPTION_WINDOW ";w",                  "1",        OPTION_BOOLEAN,    "enable window mode; otherwise, full screen mode is assumed" },
//ROBO
	{ SDLOPTION_MAXIMIZE ";max",              "0",        OPTION_BOOLEAN,    "default to maximized windows; otherwise, windows will be minimized" },
//ROBO
	{ SDLOPTION_KEEPASPECT ";ka",             "0",        OPTION_BOOLEAN,    "constrain to the proper aspect ratio" },
//ROBO
	{ SDLOPTION_UNEVENSTRETCH ";ues",         "0",        OPTION_BOOLEAN,    "allow non-integer stretch factors" },
	{ SDLOPTION_CENTERH,                      "1",        OPTION_BOOLEAN,    "center horizontally within the view area" },
	{ SDLOPTION_CENTERV,                      "1",        OPTION_BOOLEAN,    "center vertically within the view area" },
	#if (SDL_VERSION_ATLEAST(1,2,10))
	{ SDLOPTION_WAITVSYNC,                    "0",        OPTION_BOOLEAN,    "enable waiting for the start of VBLANK before flipping screens; reduces tearing effects" },
	{ SDLOPTION_SYNCREFRESH,                  "0",        OPTION_BOOLEAN,    "enable using the start of VBLANK for throttling instead of the game time" },
	#endif
	{ SDLOPTION_SCALEMODE ";sm",         SDLOPTVAL_NONE,  OPTION_STRING,     "Scale mode: none, async, yv12, yuy2, yv12x2, yuy2x2 (-video soft only)" },

	// per-window options
	{ NULL,                                   NULL,             OPTION_HEADER,    "PER-WINDOW VIDEO OPTIONS" },
	{ SDLOPTION_SCREEN,                   SDLOPTVAL_AUTO,   OPTION_STRING,    "explicit name of the first screen; 'auto' here will try to make a best guess" },
	{ SDLOPTION_ASPECT ";screen_aspect",  SDLOPTVAL_AUTO,   OPTION_STRING,    "aspect ratio for all screens; 'auto' here will try to make a best guess" },
	{ SDLOPTION_RESOLUTION ";r",          SDLOPTVAL_AUTO,   OPTION_STRING,    "preferred resolution for all screens; format is <width>x<height>[@<refreshrate>] or 'auto'" },
	{ SDLOPTION_VIEW,                     SDLOPTVAL_AUTO,   OPTION_STRING,    "preferred view for all screens" },

	{ SDLOPTION_SCREEN "0",                  SDLOPTVAL_AUTO,   OPTION_STRING,    "explicit name of the first screen; 'auto' here will try to make a best guess" },
	{ SDLOPTION_ASPECT "0",                  SDLOPTVAL_AUTO,   OPTION_STRING,    "aspect ratio of the first screen; 'auto' here will try to make a best guess" },
	{ SDLOPTION_RESOLUTION "0;r0",        SDLOPTVAL_AUTO,   OPTION_STRING,    "preferred resolution of the first screen; format is <width>x<height>[@<refreshrate>] or 'auto'" },
	{ SDLOPTION_VIEW "0",                    SDLOPTVAL_AUTO,   OPTION_STRING,    "preferred view for the first screen" },

	{ SDLOPTION_SCREEN "1",                  SDLOPTVAL_AUTO,   OPTION_STRING,    "explicit name of the second screen; 'auto' here will try to make a best guess" },
	{ SDLOPTION_ASPECT "1",                  SDLOPTVAL_AUTO,   OPTION_STRING,    "aspect ratio of the second screen; 'auto' here will try to make a best guess" },
	{ SDLOPTION_RESOLUTION "1;r1",        SDLOPTVAL_AUTO,   OPTION_STRING,    "preferred resolution of the second screen; format is <width>x<height>[@<refreshrate>] or 'auto'" },
	{ SDLOPTION_VIEW "1",                    SDLOPTVAL_AUTO,   OPTION_STRING,    "preferred view for the second screen" },

	{ SDLOPTION_SCREEN "2",                  SDLOPTVAL_AUTO,   OPTION_STRING,    "explicit name of the third screen; 'auto' here will try to make a best guess" },
	{ SDLOPTION_ASPECT "2",                  SDLOPTVAL_AUTO,   OPTION_STRING,    "aspect ratio of the third screen; 'auto' here will try to make a best guess" },
	{ SDLOPTION_RESOLUTION "2;r2",        SDLOPTVAL_AUTO,   OPTION_STRING,    "preferred resolution of the third screen; format is <width>x<height>[@<refreshrate>] or 'auto'" },
	{ SDLOPTION_VIEW "2",                    SDLOPTVAL_AUTO,   OPTION_STRING,    "preferred view for the third screen" },

	{ SDLOPTION_SCREEN "3",                  SDLOPTVAL_AUTO,   OPTION_STRING,    "explicit name of the fourth screen; 'auto' here will try to make a best guess" },
	{ SDLOPTION_ASPECT "3",                  SDLOPTVAL_AUTO,   OPTION_STRING,    "aspect ratio of the fourth screen; 'auto' here will try to make a best guess" },
	{ SDLOPTION_RESOLUTION "3;r3",        SDLOPTVAL_AUTO,   OPTION_STRING,    "preferred resolution of the fourth screen; format is <width>x<height>[@<refreshrate>] or 'auto'" },
	{ SDLOPTION_VIEW "3",                    SDLOPTVAL_AUTO,   OPTION_STRING,    "preferred view for the fourth screen" },

	// full screen options
	{ NULL,                                   NULL,  OPTION_HEADER,     "FULL SCREEN OPTIONS" },
//ROBO
	{ SDLOPTION_SWITCHRES,                    "1",   OPTION_BOOLEAN,    "enable resolution switching" },

	// sound options
	{ NULL,                                   NULL,  OPTION_HEADER,     "SOUND OPTIONS" },
	{ SDLOPTION_AUDIO_LATENCY,                "3",   OPTION_INTEGER,    "set audio latency (increase to reduce glitches, decrease for responsiveness)" },

	// keyboard mapping
	{ NULL, 		                          NULL,  OPTION_HEADER,     "SDL KEYBOARD MAPPING" },
	{ SDLOPTION_KEYMAP,                      "0",    OPTION_BOOLEAN,    "enable keymap" },
	{ SDLOPTION_KEYMAP_FILE,                 "keymap.dat", OPTION_STRING, "keymap filename" },
#ifdef MESS
	{ SDLOPTION_UIMODEKEY,			         "SCRLOCK", OPTION_STRING,  "Key to toggle MESS keyboard mode" },
#endif	// MESS

	// joystick mapping
	{ NULL, 		                         NULL,   OPTION_HEADER,     "SDL JOYSTICK MAPPING" },
	{ SDLOPTION_JOYINDEX "1",                SDLOPTVAL_AUTO, OPTION_STRING,         "name of joystick mapped to joystick #1" },
	{ SDLOPTION_JOYINDEX "2",                SDLOPTVAL_AUTO, OPTION_STRING,         "name of joystick mapped to joystick #2" },
	{ SDLOPTION_JOYINDEX "3",                SDLOPTVAL_AUTO, OPTION_STRING,         "name of joystick mapped to joystick #3" },
	{ SDLOPTION_JOYINDEX "4",                SDLOPTVAL_AUTO, OPTION_STRING,         "name of joystick mapped to joystick #4" },
	{ SDLOPTION_JOYINDEX "5",                SDLOPTVAL_AUTO, OPTION_STRING,         "name of joystick mapped to joystick #5" },
	{ SDLOPTION_JOYINDEX "6",                SDLOPTVAL_AUTO, OPTION_STRING,         "name of joystick mapped to joystick #6" },
	{ SDLOPTION_JOYINDEX "7",                SDLOPTVAL_AUTO, OPTION_STRING,         "name of joystick mapped to joystick #7" },
	{ SDLOPTION_JOYINDEX "8",                SDLOPTVAL_AUTO, OPTION_STRING,         "name of joystick mapped to joystick #8" },
	{ SDLOPTION_SIXAXIS,			         "0",	 OPTION_BOOLEAN,    "Use special handling for PS3 Sixaxis controllers" },

	// End of list
	{ NULL }
};

//============================================================
//  sdl_options
//============================================================

sdl_options::sdl_options()
{
	add_entries(s_option_entries);
}


//============================================================
//  main
//============================================================
#ifdef __CELLOS_LV2__
#include <SDL_cellhacks.h>
static FILE* CELL_LogFile;
void	CELL_Log(const char* aFormat, va_list aArgs)
{
	if(!CELL_LogFile)
	{
		CELL_LogFile = fopen("/dev_hdd0/game/MAME90000/USRDIR/mame.log", "w");
	}

	vfprintf(CELL_LogFile, aFormat, aArgs);
}
#endif

int main(int argc, char **argv)
{
	int res = 0;

#ifdef __CELLOS_LV2__
	CELL_RC_SetFile("/dev_hdd0/game/MAME90000/USRDIR/sdcellrc");
#endif

	// disable I/O buffering
	setvbuf(stdout, (char *) NULL, _IONBF, 0);
	setvbuf(stderr, (char *) NULL, _IONBF, 0);

	if (TTF_Init() == -1)
	{
		printf("SDL_ttf failed: %s\n", TTF_GetError());
	}

	{
		sdl_osd_interface osd;
		sdl_options options;
		res = cli_execute(options, osd, argc, argv);
	}

#ifdef MALLOC_DEBUG
	{
		void check_unfreed_mem(void);
		check_unfreed_mem();
	}
#endif

	// already called...
	//SDL_Quit();

	TTF_Quit();

	if(CELL_LogFile)
	{
		fclose(CELL_LogFile);
	}

	if(!QuitThruSDL)
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
//  output_oslog
//============================================================
static void output_oslog(running_machine &machine, const char *buffer)
{
	fputs(buffer, stderr);
}

//============================================================
//  constructor
//============================================================
sdl_osd_interface::sdl_osd_interface()
{
	m_watchdog = NULL;
}

//============================================================
//  destructor
//============================================================
sdl_osd_interface::~sdl_osd_interface()
{
}

//============================================================
//  osd_exit
//============================================================
void sdl_osd_interface::osd_exit(running_machine &machine)
{

	if (!SDLMAME_INIT_IN_WORKER_THREAD)
		SDL_Quit();
}

//============================================================
//  init
//============================================================
void sdl_osd_interface::init(running_machine &machine)
{
	// call our parent
	osd_interface::init(machine);

	sdl_options &options = downcast<sdl_options &>(machine.options());
	const char *stemp;

	// determine if we are benchmarking, and adjust options appropriately
	int bench = options.bench();
	astring error_string;
	if (bench > 0)
	{
		options.set_value(OPTION_THROTTLE, false, OPTION_PRIORITY_MAXIMUM, error_string);
		options.set_value(OPTION_SOUND, false, OPTION_PRIORITY_MAXIMUM, error_string);
		options.set_value(SDLOPTION_VIDEO, "none", OPTION_PRIORITY_MAXIMUM, error_string);
		options.set_value(OPTION_SECONDS_TO_RUN, bench, OPTION_PRIORITY_MAXIMUM, error_string);
		assert(!error_string);
	}

	/* get number of processors */
	stemp = options.numprocessors();

	sdl_num_processors = 0;

	if (strcmp(stemp, "auto") != 0)
	{
		sdl_num_processors = atoi(stemp);
		if (sdl_num_processors < 1)
		{
			mame_printf_warning("Warning: numprocessors < 1 doesn't make much sense. Assuming auto ...\n");
			sdl_num_processors = 0;
		}
	}

	/* Initialize SDL */
	if (!SDLMAME_INIT_IN_WORKER_THREAD)
	{
		if (SDL_Init(SDL_INIT_TIMER|SDL_INIT_AUDIO| SDL_INIT_VIDEO| SDL_INIT_JOYSTICK|SDL_INIT_NOPARACHUTE)) {
			mame_printf_error("Could not initialize SDL %s\n", SDL_GetError());
			exit(-1);
		}
	}
	// must be before sdlvideo_init!
	machine.add_notifier(MACHINE_NOTIFY_EXIT, osd_exit);

	if (sdlvideo_init(machine))
	{
		osd_exit(machine);
		mame_printf_error("sdlvideo_init: Initialization failed!\n\n\n");
		fflush(stderr);
		fflush(stdout);
		exit(-1);
	}

	sdlinput_init(machine);

	sdlaudio_init(machine);

	sdloutput_init(machine);

	if (options.oslog())
		machine.add_logerror_callback(output_oslog);

	/* now setup watchdog */

	int watchdog_timeout = options.watchdog();
	int str = options.seconds_to_run();

	/* only enable watchdog if seconds_to_run is enabled *and* relatively short (time taken from ui.c) */
	if ((watchdog_timeout != 0) && (str > 0) && (str < 60*5 ))
	{
		m_watchdog = auto_alloc(machine, watchdog);
		m_watchdog->setTimeout(watchdog_timeout);
	}

	SDL_EnableUNICODE(SDL_TRUE);
}

#define POINT_SIZE 144.0

static TTF_Font * TTF_OpenFont_Magic(astring name, int fsize)
{
	emu_file file(OPEN_FLAG_READ);
	if (file.open(name) == FILERR_NONE)
	{
		unsigned char buffer[5] = { 0xff, 0xff, 0xff, 0xff, 0xff };
		unsigned char magic[5] = { 0x00, 0x01, 0x00, 0x00, 0x00 };
		file.read(buffer,5);
		if (memcmp(buffer, magic, 5))
			return NULL;
	}
	return TTF_OpenFont(name.cstr(), POINT_SIZE);
}

static TTF_Font *search_font_config(astring name, bool bold, bool italic, bool underline, bool &bakedstyles)
{
	return 0;
}

//-------------------------------------------------
//  font_open - attempt to "open" a handle to the
//  font with the given name
//-------------------------------------------------
osd_font sdl_osd_interface::font_open(const char *_name, int &height)
{
	TTF_Font *font = (TTF_Font *)NULL;
	bool bakedstyles = false;
	int style = 0;

	// accept qualifiers from the name
	astring name(_name);

	if (name == "default")
	{
		name = "Liberation Sans";
	}

	bool bold = (name.replace(0, "[B]", "") + name.replace(0, "[b]", "") > 0);
	bool italic = (name.replace(0, "[I]", "") + name.replace(0, "[i]", "") > 0);
	bool underline = (name.replace(0, "[U]", "") + name.replace(0, "[u]", "") > 0);
	bool strike = (name.replace(0, "[S]", "") + name.replace(0, "[s]", "") > 0);

	// first up, try it as a filename
	font = TTF_OpenFont_Magic(name, POINT_SIZE);

	// if no success, try the font path

	if (!font)
	{
		mame_printf_verbose("Searching font %s in -%s\n", name.cstr(), OPTION_FONTPATH);
		emu_file file(machine().options().font_path(), OPEN_FLAG_READ);
		if (file.open(name) == FILERR_NONE)
		{
			astring full_name = file.fullpath();
			font = TTF_OpenFont_Magic(full_name, POINT_SIZE);
			if (font)
				mame_printf_verbose("Found font %s\n", full_name.cstr());
		}
	}

	// if that didn't work, crank up the FontConfig database
	if (!font)
	{
		font = search_font_config(name, bold, italic, underline, bakedstyles);
	}

	if (!font)
	{
		printf("WARNING: Couldn't find/open TrueType font %s, using MAME default\n", name.cstr());
		return NULL;
	}

	// apply styles
	if (!bakedstyles)
	{
		style |= bold ? TTF_STYLE_BOLD : 0;
		style |= italic ? TTF_STYLE_ITALIC : 0;
	}
	style |= underline ? TTF_STYLE_UNDERLINE : 0;
	// SDL_ttf 2.0.9 and earlier does not define TTF_STYLE_STRIKETHROUGH
#if SDL_VERSIONNUM(TTF_MAJOR_VERSION, TTF_MINOR_VERSION, TTF_PATCHLEVEL) > SDL_VERSIONNUM(2,0,9)
	style |= strike ? TTF_STYLE_STRIKETHROUGH : 0;
#else
	if (strike)
		mame_printf_warning("Ignoring strikethrough for SDL_TTF with version less 2.0.10\n");
#endif // PATCHLEVEL
	TTF_SetFontStyle(font, style);

	height = TTF_FontLineSkip(font);

	return (osd_font)font;
}

//-------------------------------------------------
//  font_close - release resources associated with
//  a given OSD font
//-------------------------------------------------

void sdl_osd_interface::font_close(osd_font font)
{
	TTF_Font *ttffont;

	ttffont = (TTF_Font *)font;

	TTF_CloseFont(ttffont);
}

//-------------------------------------------------
//  font_get_bitmap - allocate and populate a
//  BITMAP_FORMAT_ARGB32 bitmap containing the
//  pixel values MAKE_ARGB(0xff,0xff,0xff,0xff)
//  or MAKE_ARGB(0x00,0xff,0xff,0xff) for each
//  pixel of a black & white font
//-------------------------------------------------

bitmap_t *sdl_osd_interface::font_get_bitmap(osd_font font, unicode_char chnum, INT32 &width, INT32 &xoffs, INT32 &yoffs)
{
	TTF_Font *ttffont;
	bitmap_t *bitmap = (bitmap_t *)NULL;
	SDL_Surface *drawsurf;
	SDL_Color fcol = { 0xff, 0xff, 0xff };
	UINT16 ustr[16];

	ttffont = (TTF_Font *)font;

	memset(ustr,0,sizeof(ustr));
	ustr[0] = (UINT16)chnum;
	drawsurf = TTF_RenderUNICODE_Solid(ttffont, ustr, fcol);

	// was nothing returned?
	if (drawsurf)
	{
		// allocate a MAME destination bitmap
		bitmap = auto_alloc(machine(), bitmap_t(drawsurf->w, drawsurf->h, BITMAP_FORMAT_ARGB32));

		// copy the rendered character image into it
		for (int y = 0; y < bitmap->height; y++)
		{
			UINT32 *dstrow = BITMAP_ADDR32(bitmap, y, 0);
			UINT8 *srcrow = (UINT8 *)drawsurf->pixels;

			srcrow += (y * drawsurf->pitch);

			for (int x = 0; x < drawsurf->w; x++)
			{
				dstrow[x] = srcrow[x] ? MAKE_ARGB(0xff,0xff,0xff,0xff) : MAKE_ARGB(0x00,0xff,0xff,0xff);
			}
		}

		// what are these?
		xoffs = yoffs = 0;
		width = drawsurf->w;

		SDL_FreeSurface(drawsurf);
	}

	return bitmap;
}

//DEBUGGER STUBS
void sdl_osd_interface::init_debugger()
{
}

void sdl_osd_interface::wait_for_debugger(device_t &device, bool firststop)
{
}

// win32 stubs for linking
void debugwin_update_during_game(running_machine &machine)
{
}

