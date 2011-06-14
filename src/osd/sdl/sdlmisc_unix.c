//============================================================
//
//  sdlos_*.c - OS specific low level code
//
//  Copyright (c) 1996-2010, Nicola Salmoria and the MAME Team.
//  Visit http://mamedev.org for licensing and usage restrictions.
//
//  SDLMAME by Olivier Galibert and R. Belmont
//
//============================================================

// MAME headers
#include "osdcore.h"

//============================================================
//  osd_alloc_executable
//
//  allocates "size" bytes of executable memory.  this must take
//  things like NX support into account.
//============================================================
void *osd_alloc_executable(size_t size)
{
	//TODO: How can this be done on PS3?
	return 0;
}

//============================================================
//  osd_free_executable
//
//  frees memory allocated with osd_alloc_executable
//============================================================
void osd_free_executable(void *ptr, size_t size)
{
}

//============================================================
//  osd_break_into_debugger
//============================================================
void osd_break_into_debugger(const char *message)
{
}
