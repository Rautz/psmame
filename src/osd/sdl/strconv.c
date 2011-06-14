//============================================================
//
//  strconv.c - SDL (POSIX) string conversion
//
//  Copyright (c) 1996-2010, Nicola Salmoria and the MAME Team.
//  Visit http://mamedev.org for licensing and usage restrictions.
//
//  SDLMAME by Olivier Galibert and R. Belmont
//
//============================================================

#include <stdlib.h>

// MAMEOS headers
#include "strconv.h"
#include "unicode.h"

//============================================================
//  osd_uchar_from_osdchar
//============================================================
int osd_uchar_from_osdchar(unicode_char *uchar, const char *osdchar, size_t count)
{
	wchar_t wch;
	count = mbstowcs(&wch, (char *)osdchar, 1);

	*uchar = (count != -1) ? wch : 0;
	return count;
}

