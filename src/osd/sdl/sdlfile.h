//============================================================
//
//  sdlfile.h - SDL file access functions
//
//  Copyright (c) 1996-2010, Nicola Salmoria and the MAME Team.
//  Visit http://mamedev.org for licensing and usage restrictions.
//
//  SDLMAME by Olivier Galibert and R. Belmont
//
//============================================================

#include "osdcore.h"

//============================================================
//  ENUM DEFINITIONS
//============================================================
enum
{
	SDLFILE_FILE = 0,
};

//============================================================
//  TYPE DEFINITIONS
//============================================================

struct _osd_file
{
	int	handle;
	int	type;
	char	filename[1];
};

//============================================================
//  PROTOTYPES
//============================================================

file_error error_to_file_error(UINT32 error);
