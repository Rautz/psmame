#ifndef _osdsdl_h_
#define _osdsdl_h_

#include <SDL/SDL.h>

#include "watchdog.h"
#include "clifront.h"

//============================================================
//  System dependent defines
//============================================================
// Process events in worker thread
#define SDLMAME_EVENTS_IN_WORKER_THREAD	(0)
#define SDLMAME_INIT_IN_WORKER_THREAD	(0)
#define SDLMAME_HAS_DEBUGGER			(0)

//============================================================
//  Defines
//============================================================
#define SDLOPTION_INIPATH				"inipath"
#define SDLOPTION_AUDIO_LATENCY			"audio_latency"
#define SDLOPTION_SCREEN				"screen"
#define SDLOPTION_ASPECT				"aspect"
#define SDLOPTION_RESOLUTION			"resolution"
#define SDLOPTION_VIEW					"view"
#define SDLOPTION_SDLVIDEOFPS			"sdlvideofps"
#define SDLOPTION_KEEPASPECT			"keepaspect"
#define SDLOPTION_WINDOW				"window"
#define SDLOPTION_NUMSCREENS			"numscreens"
#define SDLOPTION_USEALLHEADS			"useallheads"
#define SDLOPTION_MAXIMIZE				"maximize"
#define SDLOPTION_VIDEO					"video"
#define SDLOPTION_SWITCHRES				"switchres"
#define SDLOPTION_FILTER				"filter"
#define SDLOPTION_CENTERH				"centerh"
#define SDLOPTION_CENTERV				"centerv"

#define SDLOPTION_MULTITHREADING		"multithreading"
#define SDLOPTION_BENCH					"bench"

#define SDLOPTION_WAITVSYNC				"waitvsync"
#define SDLOPTION_SYNCREFRESH			"syncrefresh"
#define SDLOPTION_KEYMAP				"keymap"
#define SDLOPTION_KEYMAP_FILE			"keymap_file"
#define SDLOPTION_UIMODEKEY				"uimodekey"
#define SDLOPTION_OSLOG					"oslog"
#define SDLOPTION_WATCHDOG				"watchdog"

#define SDLOPTION_SIXAXIS				"sixaxis"
#define SDLOPTION_JOYINDEX				"joy_idx"
#define SDLOPTION_KEYBINDEX				"keyb_idx"
#define SDLOPTION_MOUSEINDEX			"mouse_index"

#define SDLOPTVAL_NONE					"none"
#define SDLOPTVAL_AUTO					"auto"

#define SDLOPTVAL_SOFT					"soft"

// read by sdlmame

#define SDLENV_DESKTOPDIM				"SDLMAME_DESKTOPDIM"

#define SDLMAME_SOUND_LOG				"sound.log"
#define SDLOPTVAL_GLLIB					SDLOPTVAL_AUTO


//============================================================
//  TYPE DEFINITIONS
//============================================================

typedef void *osd_font;

//============================================================
//  TYPE DEFINITIONS
//============================================================

class sdl_options : public cli_options
{
public:
	// construction/destruction
	sdl_options();

	// debugging options
	bool oslog() const { return bool_value(SDLOPTION_OSLOG); }
	int watchdog() const { return int_value(SDLOPTION_WATCHDOG); }

	// performance options
	bool multithreading() const { return bool_value(SDLOPTION_MULTITHREADING); }
	bool video_fps() const { return bool_value(SDLOPTION_SDLVIDEOFPS); }
	int bench() const { return int_value(SDLOPTION_BENCH); }

	// video options
	const char *video() const { return value(SDLOPTION_VIDEO); }
	int numscreens() const { return int_value(SDLOPTION_NUMSCREENS); }
	bool window() const { return bool_value(SDLOPTION_WINDOW); }
	bool maximize() const { return bool_value(SDLOPTION_MAXIMIZE); }
	bool keep_aspect() const { return bool_value(SDLOPTION_KEEPASPECT); }
	bool centerh() const { return bool_value(SDLOPTION_CENTERH); }
	bool centerv() const { return bool_value(SDLOPTION_CENTERV); }
	bool wait_vsync() const { return bool_value(SDLOPTION_WAITVSYNC); }
	bool sync_refresh() const { return bool_value(SDLOPTION_SYNCREFRESH); }

	// per-window options
	const char *screen() const { return value(SDLOPTION_SCREEN); }
	const char *aspect() const { return value(SDLOPTION_ASPECT); }
	const char *resolution() const { return value(SDLOPTION_RESOLUTION); }
	const char *view() const { return value(SDLOPTION_VIEW); }
	const char *screen(int index) const { astring temp; return value(temp.format("%s%d", SDLOPTION_SCREEN, index)); }
	const char *aspect(int index) const { astring temp; return value(temp.format("%s%d", SDLOPTION_ASPECT, index)); }
	const char *resolution(int index) const { astring temp; return value(temp.format("%s%d", SDLOPTION_RESOLUTION, index)); }
	const char *view(int index) const { astring temp; return value(temp.format("%s%d", SDLOPTION_VIEW, index)); }

	// full screen options
	bool switch_res() const { return bool_value(SDLOPTION_SWITCHRES); }

	// sound options
	int audio_latency() const { return int_value(SDLOPTION_AUDIO_LATENCY); }

	// keyboard mapping
	bool keymap() const { return bool_value(SDLOPTION_KEYMAP); }
	const char *keymap_file() const { return value(SDLOPTION_KEYMAP_FILE); }
	const char *ui_mode_key() const { return value(SDLOPTION_UIMODEKEY); }

	// joystick mapping
	const char *joy_index(int index) const { astring temp; return value(temp.format("%s%d", SDLOPTION_JOYINDEX, index)); }
	bool sixaxis() const { return bool_value(SDLOPTION_SIXAXIS); }

private:
	static const options_entry s_option_entries[];
};


class sdl_osd_interface : public osd_interface
{
public:
	// construction/destruction
	sdl_osd_interface();
	virtual ~sdl_osd_interface();

	// general overridables
	virtual void init(running_machine &machine);
	virtual void update(bool skip_redraw);

	// debugger overridables
	virtual void init_debugger();
	virtual void wait_for_debugger(device_t &device, bool firststop);

	// audio overridables
	virtual void update_audio_stream(const INT16 *buffer, int samples_this_frame);
	virtual void set_mastervolume(int attenuation);

	// input overridables
	virtual void customize_input_type_list(input_type_desc *typelist);

	// font overridables
	virtual osd_font font_open(const char *name, int &height);
	virtual void font_close(osd_font font);
	virtual bitmap_t *font_get_bitmap(osd_font font, unicode_char chnum, INT32 &width, INT32 &xoffs, INT32 &yoffs);

private:
	static void osd_exit(running_machine &machine);

	watchdog *m_watchdog;

};



//============================================================
//  sound.c
//============================================================

void sdlaudio_init(running_machine &machine);

//============================================================
//  sdlwork.c
//============================================================

extern int sdl_num_processors;

#endif

