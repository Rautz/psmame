//============================================================
//
//  video.c - SDL video handling
//
//  Copyright (c) 1996-2010, Nicola Salmoria and the MAME Team.
//  Visit http://mamedev.org for licensing and usage restrictions.
//
//  SDLMAME by Olivier Galibert and R. Belmont
//
//============================================================

#include <SDL/SDL.h>
#include <SDL/SDL_syswm.h>

// MAME headers
#include "emu.h"
#include "rendutil.h"
#include "ui.h"
#include "emuopts.h"
#include "uiinput.h"

// MAMEOS headers
#include "video.h"
#include "window.h"
#include "input.h"

#include "osdsdl.h"

//============================================================
//  CONSTANTS
//============================================================


//============================================================
//  GLOBAL VARIABLES
//============================================================

sdl_video_config video_config;

//============================================================
//  LOCAL VARIABLES
//============================================================

static sdl_monitor_info *primary_monitor;
static sdl_monitor_info *sdl_monitor_list;

//============================================================
//  PROTOTYPES
//============================================================

static void video_exit(running_machine &machine);
static void init_monitors(void);
static sdl_monitor_info *pick_monitor(sdl_options &options, int index);

static void check_osd_inputs(running_machine &machine);

static void extract_video_config(running_machine &machine);
static void extract_window_config(running_machine &machine, int index, sdl_window_config *conf);
static float get_aspect(const char *defdata, const char *data, int report_error);
static void get_resolution(const char *defdata, const char *data, sdl_window_config *config, int report_error);


//============================================================
//  sdlvideo_init
//============================================================

int sdlvideo_init(running_machine &machine)
{
	int index, tc;

	// extract data from the options
	extract_video_config(machine);

	// ensure we get called on the way out
	machine.add_notifier(MACHINE_NOTIFY_EXIT, video_exit);

	// set up monitors first
	init_monitors();

	// we need the beam width in a float, contrary to what the core does.
	video_config.beamwidth = machine.options().beam();

	// initialize the window system so we can make windows
	if (sdlwindow_init(machine))
		return 1;

	tc = machine.total_colors();

	// create the windows
	sdl_options &options = downcast<sdl_options &>(machine.options());
	for (index = 0; index < video_config.numscreens; index++)
	{
		sdl_window_config conf;
		memset(&conf, 0, sizeof(conf));
		extract_window_config(machine, index, &conf);
		conf.totalColors = tc;
		if (sdlwindow_video_window_create(machine, index, pick_monitor(options, index), &conf))
			return 1;
	}

	return 0;
}


//============================================================
//  video_exit
//============================================================

static void video_exit(running_machine &machine)
{
	// free all of our monitor information
	while (sdl_monitor_list != NULL)
	{
		sdl_monitor_info *temp = sdl_monitor_list;
		sdl_monitor_list = temp->next;
		global_free(temp);
	}

}


//============================================================
//  sdlvideo_monitor_refresh
//============================================================

void sdlvideo_monitor_refresh(sdl_monitor_info *monitor)
{
	{
		{
			static int first_call=0;
			static int cw, ch;

			SDL_VideoDriverName(monitor->monitor_device, sizeof(monitor->monitor_device)-1);
			if (first_call==0)
			{
				const SDL_VideoInfo *sdl_vi;

				sdl_vi = SDL_GetVideoInfo();
				#if (SDL_VERSION_ATLEAST(1,2,10))
				cw = sdl_vi->current_w;
				ch = sdl_vi->current_h;
				#endif
				first_call=1;
				if ((cw==0) || (ch==0))
				{
					if ((cw==0) || (ch==0))
					{
						mame_printf_warning("WARNING: SDL_GetVideoInfo() for driver <%s> is broken.\n", monitor->monitor_device);
						mame_printf_warning("         You should set SDLMAME_DESKTOPDIM to your desktop size.\n");
						mame_printf_warning("            e.g. export SDLMAME_DESKTOPDIM=800x600\n");
						mame_printf_warning("         Assuming 1024x768 now!\n");
						cw=1024;
						ch=768;
					}
				}
			}
			monitor->monitor_width = cw;
			monitor->monitor_height = ch;
			monitor->center_width = cw;
			monitor->center_height = ch;
		}
	}

	{
		static int info_shown=0;
		if (!info_shown)
		{
			mame_printf_verbose("SDL Device Driver     : %s\n", monitor->monitor_device);
			mame_printf_verbose("SDL Monitor Dimensions: %d x %d\n", monitor->monitor_width, monitor->monitor_height);
			info_shown = 1;
		}
	}
}



//============================================================
//  sdlvideo_monitor_get_aspect
//============================================================

float sdlvideo_monitor_get_aspect(sdl_monitor_info *monitor)
{
	// refresh the monitor information and compute the aspect
	if (video_config.keepaspect)
	{
		sdlvideo_monitor_refresh(monitor);
		return monitor->aspect / ((float)monitor->monitor_width / (float)monitor->monitor_height);
	}
	return 0.0f;
}



//============================================================
//  sdlvideo_monitor_from_handle
//============================================================

sdl_monitor_info *sdlvideo_monitor_from_handle(UINT32 hmonitor)
{
	sdl_monitor_info *monitor;

	// find the matching monitor
	for (monitor = sdl_monitor_list; monitor != NULL; monitor = monitor->next)
		if (monitor->handle == hmonitor)
			return monitor;
	return NULL;
}


//============================================================
//  update
//============================================================

void sdl_osd_interface::update(bool skip_redraw)
{
	sdl_window_info *window;

	if (m_watchdog != NULL)
		m_watchdog->reset();

	// if we're not skipping this redraw, update all windows
	if (!skip_redraw)
	{
//      profiler_mark(PROFILER_BLIT);
		for (window = sdl_window_list; window != NULL; window = window->next)
			sdlwindow_video_window_update(machine(), window);
//      profiler_mark(PROFILER_END);
	}

	// poll the joystick values here
	sdlinput_poll(machine());
	check_osd_inputs(machine());
}


//============================================================
//  add_primary_monitor
//============================================================

#if !defined(SDLMAME_WIN32) && !(SDL_VERSION_ATLEAST(1,3,0))
static void add_primary_monitor(void *data)
{
	sdl_monitor_info ***tailptr = (sdl_monitor_info ***)data;
	sdl_monitor_info *monitor;

	// allocate a new monitor info
	monitor = global_alloc_clear(sdl_monitor_info);

	// copy in the data
	monitor->handle = 1;

	sdlvideo_monitor_refresh(monitor);

	// guess the aspect ratio assuming square pixels
	monitor->aspect = (float)(monitor->monitor_width) / (float)(monitor->monitor_height);

	// save the primary monitor handle
	primary_monitor = monitor;

	// hook us into the list
	**tailptr = monitor;
	*tailptr = &monitor->next;
}
#endif


//============================================================
//  monitor_enum_callback
//============================================================



//============================================================
//  init_monitors
//============================================================

static void init_monitors(void)
{
	sdl_monitor_info **tailptr;

	// make a list of monitors
	sdl_monitor_list = NULL;
	tailptr = &sdl_monitor_list;
	add_primary_monitor((void *)&tailptr);
}


//============================================================
//  pick_monitor
//============================================================
static sdl_monitor_info *pick_monitor(sdl_options &options, int index)
{
	sdl_monitor_info *monitor;
	float aspect;

	// get the aspect ratio
	aspect = get_aspect(options.aspect(), options.aspect(index), TRUE);

	// return the primary just in case all else fails
	monitor = primary_monitor;

	if (aspect != 0)
	{
		monitor->aspect = aspect;
	}
	return monitor;
}

//============================================================
//  check_osd_inputs
//============================================================

static void check_osd_inputs(running_machine &machine)
{
	sdl_window_info *window = sdlinput_get_focus_window(machine);

	// check for toggling fullscreen mode
	if (ui_input_pressed(machine, IPT_OSD_1))
		sdlwindow_toggle_full_screen(machine, window);

	if (ui_input_pressed(machine, IPT_OSD_2))
	{
		//FIXME: on a per window basis
		video_config.fullstretch = !video_config.fullstretch;
		ui_popup_time(1, "Uneven stretch %s", video_config.fullstretch? "enabled":"disabled");
	}

	if (ui_input_pressed(machine, IPT_OSD_4))
	{
		//FIXME: on a per window basis
		video_config.keepaspect = !video_config.keepaspect;
		ui_popup_time(1, "Keepaspect %s", video_config.keepaspect? "enabled":"disabled");
	}

	if (ui_input_pressed(machine, IPT_OSD_6))
		sdlwindow_modify_prescale(machine, window, -1);

	if (ui_input_pressed(machine, IPT_OSD_7))
		sdlwindow_modify_prescale(machine, window, 1);
}

//============================================================
//  extract_window_config
//============================================================

static void extract_window_config(running_machine &machine, int index, sdl_window_config *conf)
{
	sdl_options &options = downcast<sdl_options &>(machine.options());
	// per-window options: extract the data
	get_resolution(options.resolution(), options.resolution(index), conf, TRUE);
}

//============================================================
//  extract_video_config
//============================================================

static void extract_video_config(running_machine &machine)
{
	const char *stemp;
	sdl_options &options = downcast<sdl_options &>(machine.options());

	video_config.perftest    = options.video_fps();

	// global options: extract the data
	video_config.windowed      = options.window();
	video_config.keepaspect    = options.keep_aspect();
	video_config.numscreens    = options.numscreens();
	video_config.fullstretch   = options.uneven_stretch();

	// default to working video please
	video_config.novideo = 0;

	// d3d options: extract the data
	stemp = options.video();
	if (strcmp(stemp, SDLOPTVAL_SOFT) == 0)
		video_config.mode = VIDEO_MODE_SOFT;
	else if (strcmp(stemp, SDLOPTVAL_NONE) == 0)
	{
		video_config.mode = VIDEO_MODE_SOFT;
		video_config.novideo = 1;

		if (options.seconds_to_run() == 0)
			mame_printf_warning("Warning: -video none doesn't make much sense without -seconds_to_run\n");
	}
	else
	{
		mame_printf_warning("Invalid video value %s; reverting to software\n", stemp);
		video_config.mode = VIDEO_MODE_SOFT;
	}

	video_config.switchres     = options.switch_res();
	video_config.centerh       = options.centerh();
	video_config.centerv       = options.centerv();
	video_config.waitvsync     = options.wait_vsync();
	video_config.syncrefresh   = options.sync_refresh();
	if (!video_config.waitvsync && video_config.syncrefresh)
	{
		mame_printf_warning("-syncrefresh specified without -waitsync. Reverting to -nosyncrefresh\n");
		video_config.syncrefresh = 0;
	}

	// global options: sanity check values
	if (video_config.numscreens < 1 || video_config.numscreens > MAX_VIDEO_WINDOWS)
	{
		mame_printf_warning("Invalid numscreens value %d; reverting to 1\n", video_config.numscreens);
		video_config.numscreens = 1;
	}

	// yuv settings ...
	stemp = options.scale_mode();
	video_config.scale_mode = drawsdl_scale_mode(stemp);
	if (video_config.scale_mode < 0)
	{
		mame_printf_warning("Invalid yuvmode value %s; reverting to none\n", stemp);
		video_config.scale_mode = VIDEO_SCALE_MODE_NONE;
	}
	if ( (video_config.mode != VIDEO_MODE_SOFT) && (video_config.scale_mode != VIDEO_SCALE_MODE_NONE) )
	{
		mame_printf_warning("scalemode is only for -video soft, overriding\n");
		video_config.scale_mode = VIDEO_SCALE_MODE_NONE;
	}
}


//============================================================
//  get_aspect
//============================================================

static float get_aspect(const char *defdata, const char *data, int report_error)
{
	int num = 0, den = 1;

	if (strcmp(data, SDLOPTVAL_AUTO) == 0)
	{
		if (strcmp(defdata,SDLOPTVAL_AUTO) == 0)
			return 0;
		data = defdata;
	}
	if (sscanf(data, "%d:%d", &num, &den) != 2 && report_error)
		mame_printf_error("Illegal aspect ratio value = %s\n", data);
	return (float)num / (float)den;
}


//============================================================
//  get_resolution
//============================================================

static void get_resolution(const char *defdata, const char *data, sdl_window_config *config, int report_error)
{
	config->width = config->height = config->depth = config->refresh = 0;
	if (strcmp(data, SDLOPTVAL_AUTO) == 0)
	{
		if (strcmp(defdata, SDLOPTVAL_AUTO) == 0)
		{
			return;
		}

		data = defdata;
	}

	if (sscanf(data, "%dx%dx%d@%d", &config->width, &config->height, &config->depth, &config->refresh) < 2 && report_error)
		mame_printf_error("Illegal resolution value = %s\n", data);
}

