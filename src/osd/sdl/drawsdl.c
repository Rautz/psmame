//============================================================
//
//  drawsdl.c - SDL software and OpenGL implementation
//
//  Copyright (c) 1996-2011, Nicola Salmoria and the MAME Team.
//  Visit http://mamedev.org for licensing and usage restrictions.
//
//  SDLMAME by Olivier Galibert and R. Belmont
//
//============================================================

// standard C headers
#include <math.h>
#include <stdio.h>

//ROBO: Inluce SDL first to fix compile errors

// standard SDL headers
#include <SDL/SDL.h>

// MAME headers
#include "emu.h"
#include "ui.h"

// OSD headers
#include "osdsdl.h"
#include "window.h"

//============================================================
//  DEBUGGING
//============================================================

//============================================================
//  CONSTANTS
//============================================================

//============================================================
//  TYPES
//============================================================

/* sdl_info is the information about SDL for the current screen */
typedef struct _sdl_info sdl_info;
struct _sdl_info
{
	INT32				blittimer;
	UINT32				extra_flags;

	SDL_Surface 		*sdlsurf;

	int					last_hofs;
	int					last_vofs;
	int					old_blitwidth;
	int					old_blitheight;
};

//============================================================
//  INLINES
//============================================================

//============================================================
//  PROTOTYPES
//============================================================

// core functions
static void drawsdl_exit(void);
static void drawsdl_attach(sdl_draw_info *info, sdl_window_info *window);
static int drawsdl_window_create(sdl_window_info *window, int width, int height);
static void drawsdl_window_resize(sdl_window_info *window, int width, int height);
static void drawsdl_window_destroy(sdl_window_info *window);
static render_primitive_list &drawsdl_window_get_primitives(sdl_window_info *window);
static int drawsdl_window_draw(sdl_window_info *window, UINT32 dc, int update);
static void drawsdl_destroy_all_textures(sdl_window_info *window);
static void drawsdl_window_clear(sdl_window_info *window);
static int drawsdl_xy_to_render_target(sdl_window_info *window, int x, int y, int *xt, int *yt);

// soft rendering
static void drawsdl_rgb888_draw_primitives(const render_primitive_list &primlist, void *dstdata, UINT32 width, UINT32 height, UINT32 pitch);
static void drawsdl_bgr888_draw_primitives(const render_primitive_list &primlist, void *dstdata, UINT32 width, UINT32 height, UINT32 pitch);
static void drawsdl_bgra888_draw_primitives(const render_primitive_list &primlist, void *dstdata, UINT32 width, UINT32 height, UINT32 pitch);
static void drawsdl_rgb565_draw_primitives(const render_primitive_list &primlist, void *dstdata, UINT32 width, UINT32 height, UINT32 pitch);
static void drawsdl_rgb555_draw_primitives(const render_primitive_list &primlist, void *dstdata, UINT32 width, UINT32 height, UINT32 pitch);

// Static declarations

static int shown_video_info = 0;

//============================================================
//  drawsdl_init
//============================================================
int drawsdl_init(sdl_draw_info *callbacks)
{
	// fill in the callbacks
	callbacks->exit = drawsdl_exit;
	callbacks->attach = drawsdl_attach;

	mame_printf_verbose("Using SDL single-window soft driver (SDL 1.2)\n");

	return 0;
}

//============================================================
//  drawsdl_exit
//============================================================

static void drawsdl_exit(void)
{
}

//============================================================
//  drawsdl_attach
//============================================================

static void drawsdl_attach(sdl_draw_info *info, sdl_window_info *window)
{
	// fill in the callbacks
	window->create = drawsdl_window_create;
	window->resize = drawsdl_window_resize;
	window->get_primitives = drawsdl_window_get_primitives;
	window->draw = drawsdl_window_draw;
	window->destroy = drawsdl_window_destroy;
	window->destroy_all_textures = drawsdl_destroy_all_textures;
	window->clear = drawsdl_window_clear;
	window->xy_to_render_target = drawsdl_xy_to_render_target;
}

//============================================================
//  drawsdl_destroy_all_textures
//============================================================

static void drawsdl_destroy_all_textures(sdl_window_info *window)
{
	/* nothing to be done in soft mode */
}

//============================================================
//  drawsdl_window_create
//============================================================
static int drawsdl_window_create(sdl_window_info *window, int width, int height)
{
	sdl_info *sdl;

	// allocate memory for our structures
	sdl = (sdl_info *) osd_malloc(sizeof(sdl_info));
	memset(sdl, 0, sizeof(sdl_info));

	window->dxdata = sdl;

	sdl->extra_flags = (window->fullscreen ?  SDL_FULLSCREEN : 0);
	sdl->sdlsurf = SDL_SetVideoMode(width, height, 0, sdl->extra_flags);

	if (!sdl->sdlsurf)
		return 1;

	window->width = sdl->sdlsurf->w;
	window->height = sdl->sdlsurf->h;

	// set the window title
	SDL_WM_SetCaption(window->title, "SDLMAME");

	sdl->blittimer = 0;

	return 0;
}

//============================================================
//  drawsdl_window_resize
//============================================================
static void drawsdl_window_resize(sdl_window_info *window, int width, int height)
{
	sdl_info *sdl = (sdl_info *) window->dxdata;

	SDL_FreeSurface(sdl->sdlsurf);
	//printf("SetVideoMode %d %d\n", wp->resize_new_width, wp->resize_new_height);

	sdl->sdlsurf = SDL_SetVideoMode(width, height, 0,
			SDL_SWSURFACE | SDL_ANYFORMAT | sdl->extra_flags);
	window->width = sdl->sdlsurf->w;
	window->height = sdl->sdlsurf->h;
}


//============================================================
//  drawsdl_window_destroy
//============================================================

static void drawsdl_window_destroy(sdl_window_info *window)
{
	sdl_info *sdl = (sdl_info *) window->dxdata;

	// skip if nothing
	if (sdl == NULL)
		return;

	if (sdl->sdlsurf)
	{
		SDL_FreeSurface(sdl->sdlsurf);
		sdl->sdlsurf = NULL;
	}

	// free the memory in the window
	osd_free(sdl);
	window->dxdata = NULL;
}

//============================================================
//  drawsdl_window_clear
//============================================================

static void drawsdl_window_clear(sdl_window_info *window)
{
	sdl_info *sdl = (sdl_info *) window->dxdata;

	sdl->blittimer = 3;
}

//============================================================
//  drawsdl_xy_to_render_target
//============================================================
static int drawsdl_xy_to_render_target(sdl_window_info *window, int x, int y, int *xt, int *yt)
{
	sdl_info *sdl = (sdl_info *) window->dxdata;

	*xt = x - sdl->last_hofs;
	*yt = y - sdl->last_vofs;
	if (*xt<0 || *xt >= window->blitwidth)
		return 0;
	if (*yt<0 || *xt >= window->blitheight)
		return 0;
	return 1;
}

//============================================================
//  drawsdl_window_get_primitives
//============================================================

static render_primitive_list &drawsdl_window_get_primitives(sdl_window_info *window)
{
	sdl_info *sdl = (sdl_info *) window->dxdata;

	if ((!window->fullscreen) || (video_config.switchres))
	{
		sdlwindow_blit_surface_size(window, window->width, window->height);
	}
	else
	{
		sdlwindow_blit_surface_size(window, window->monitor->center_width, window->monitor->center_height);
	}

	window->target->set_bounds(window->blitwidth, window->blitheight, sdlvideo_monitor_get_aspect(window->monitor));
	return window->target->get_primitives();
}

//============================================================
//  drawsdl_window_draw
//============================================================

static int drawsdl_window_draw(sdl_window_info *window, UINT32 dc, int update)
{
	sdl_info *sdl = (sdl_info *) window->dxdata;
	UINT8 *surfptr;
	INT32 pitch;
	int bpp;
	Uint32 rmask, gmask, bmask, amask;
	INT32 vofs, hofs, blitwidth, blitheight, ch, cw;

	if (video_config.novideo)
	{
		return 0;
	}

	// if we haven't been created, just punt
	if (sdl == NULL)
		return 1;

	// lock it if we need it
	pitch = sdl->sdlsurf->pitch;
	bpp = sdl->sdlsurf->format->BytesPerPixel;
	rmask = sdl->sdlsurf->format->Rmask;
	gmask = sdl->sdlsurf->format->Gmask;
	bmask = sdl->sdlsurf->format->Bmask;
	amask = sdl->sdlsurf->format->Amask;

	if (window->blitwidth != sdl->old_blitwidth || window->blitheight != sdl->old_blitheight)
	{
		sdl->old_blitwidth = window->blitwidth;
		sdl->old_blitheight = window->blitheight;
		sdl->blittimer = 3;
	}

	if (SDL_MUSTLOCK(sdl->sdlsurf)) SDL_LockSurface(sdl->sdlsurf);
	// Clear if necessary

	if (sdl->blittimer > 0)
	{
		memset(sdl->sdlsurf->pixels, 0, window->height * sdl->sdlsurf->pitch);
		sdl->blittimer--;
	}


	surfptr = (UINT8 *)sdl->sdlsurf->pixels;

	// get ready to center the image
	vofs = hofs = 0;
	blitwidth = window->blitwidth;
	blitheight = window->blitheight;

	// figure out what coordinate system to use for centering - in window mode it's always the
	// SDL surface size.  in fullscreen the surface covers all monitors, so center according to
	// the first one only
	if ((window->fullscreen) && (!video_config.switchres))
	{
		ch = window->monitor->center_height;
		cw = window->monitor->center_width;
	}
	else
	{
		ch = window->height;
		cw = window->width;
	}

	// do not crash if the window's smaller than the blit area
	if (blitheight > ch)
	{
			blitheight = ch;
	}
	else if (video_config.centerv)
	{
		vofs = (ch - window->blitheight) / 2;
	}

	if (blitwidth > cw)
	{
			blitwidth = cw;
	}
	else if (video_config.centerh)
	{
		hofs = (cw - window->blitwidth) / 2;
	}

	sdl->last_hofs = hofs;
	sdl->last_vofs = vofs;

	window->primlist->acquire_lock();

	// render to it
	{
		int mamewidth, mameheight;

		mamewidth = blitwidth;
		mameheight = blitheight;
		switch (rmask)
		{
			case 0x0000ff00:
				drawsdl_bgra888_draw_primitives(*window->primlist, surfptr, mamewidth, mameheight, pitch / 4);
				break;

			case 0x00ff0000:
				drawsdl_rgb888_draw_primitives(*window->primlist, surfptr, mamewidth, mameheight, pitch / 4);
				break;

			case 0x000000ff:
				drawsdl_bgr888_draw_primitives(*window->primlist, surfptr, mamewidth, mameheight, pitch / 4);
				break;

			case 0xf800:
				drawsdl_rgb565_draw_primitives(*window->primlist, surfptr, mamewidth, mameheight, pitch / 2);
				break;

			case 0x7c00:
				drawsdl_rgb555_draw_primitives(*window->primlist, surfptr, mamewidth, mameheight, pitch / 2);
				break;

			default:
				mame_printf_error("SDL: ERROR! Unknown video mode: R=%08X G=%08X B=%08X\n", rmask, gmask, bmask);
				break;
		}
	}

	window->primlist->release_lock();

	// unlock and flip
	if (SDL_MUSTLOCK(sdl->sdlsurf)) SDL_UnlockSurface(sdl->sdlsurf);
	SDL_Flip(sdl->sdlsurf);

	return 0;
}

//============================================================
//  SOFTWARE RENDERING
//============================================================

#define FUNC_PREFIX(x)		drawsdl_rgb888_##x
#define PIXEL_TYPE			UINT32
#define SRCSHIFT_R			0
#define SRCSHIFT_G			0
#define SRCSHIFT_B			0
#define DSTSHIFT_R			16
#define DSTSHIFT_G			8
#define DSTSHIFT_B			0

#include "rendersw.c"

#define FUNC_PREFIX(x)		drawsdl_bgr888_##x
#define PIXEL_TYPE			UINT32
#define SRCSHIFT_R			0
#define SRCSHIFT_G			0
#define SRCSHIFT_B			0
#define DSTSHIFT_R			0
#define DSTSHIFT_G			8
#define DSTSHIFT_B			16

#include "rendersw.c"

#define FUNC_PREFIX(x)		drawsdl_bgra888_##x
#define PIXEL_TYPE			UINT32
#define SRCSHIFT_R			0
#define SRCSHIFT_G			0
#define SRCSHIFT_B			0
#define DSTSHIFT_R			8
#define DSTSHIFT_G			16
#define DSTSHIFT_B			24

#include "rendersw.c"

#define FUNC_PREFIX(x)		drawsdl_rgb565_##x
#define PIXEL_TYPE			UINT16
#define SRCSHIFT_R			3
#define SRCSHIFT_G			2
#define SRCSHIFT_B			3
#define DSTSHIFT_R			11
#define DSTSHIFT_G			5
#define DSTSHIFT_B			0

#include "rendersw.c"

#define FUNC_PREFIX(x)		drawsdl_rgb555_##x
#define PIXEL_TYPE			UINT16
#define SRCSHIFT_R			3
#define SRCSHIFT_G			3
#define SRCSHIFT_B			3
#define DSTSHIFT_R			10
#define DSTSHIFT_G			5
#define DSTSHIFT_B			0

#include "rendersw.c"


