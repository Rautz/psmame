//============================================================
//
//  sdlprefix.h - prefix file, included by ALL files
//
//  Copyright (c) 1996-2006, Nicola Salmoria and the MAME Team.
//  Visit http://mamedev.org for licensing and usage restrictions.
//
//  SDLMAME by Olivier Galibert and R. Belmont
//
//============================================================

//============================================================
// System specific defines
//============================================================
#define SDLMAME_LINUX 1

#ifdef __GNUC__
#define alloca	__builtin_alloca
#endif

//============================================================
// misc.
//============================================================
#define PATH_SEPARATOR		"/"

