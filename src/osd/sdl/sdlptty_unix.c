//============================================================
//
//  sdlptty_unix.c - SDL psuedo tty access functions
//
//  Copyright (c) 1996-2010, Nicola Salmoria and the MAME Team.
//  Visit http://mamedev.org for licensing and usage restrictions.
//
//  SDLMAME by Olivier Galibert and R. Belmont
//
//============================================================

#include <sys/types.h>
#ifndef __CELLOS_LV2__
#include <sys/uio.h>
#endif
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#if defined(SDLMAME_FREEBSD) || defined(SDLMAME_DRAGONFLY)
# include <termios.h>
# include <libutil.h>
#elif defined(SDLMAME_NETBSD)
# include <util.h>
#elif defined(SDLMAME_OPENBSD)
# include <termios.h>
# include <util.h>
#elif defined(SDLMAME_LINUX) && !defined(__CELLOS_LV2__)
# include <pty.h>
#endif

#include "sdlfile.h"

const char *sdlfile_ptty_identifier  = "/dev/pts";

file_error sdl_open_ptty(const char *path, UINT32 openflags, osd_file **file, UINT64 *filesize)
{
#ifndef __CELLOS_LV2__
	int master;
	int aslave;
	char name[100];

	if (openpty(&master, &aslave, name, NULL, NULL) >= 0)
	{
		printf("Slave of device %s is %s\n", path, name );
		fcntl(master, F_SETFL, O_NONBLOCK);
		(*file)->handle = master;
		*filesize = 0;
	}
	else
	{
		return FILERR_ACCESS_DENIED;
	}
#endif
	return FILERR_NONE;
}

file_error sdl_read_ptty(osd_file *file, void *buffer, UINT64 offset, UINT32 count, UINT32 *actual)
{
#ifndef __CELLOS_LV2__
	ssize_t result;

	result = read(file->handle, buffer, count);

	if (result < 0)
	{
		return error_to_file_error(errno);
	}

	if (actual != NULL )
	{
		*actual = result;
	}
#endif
	return FILERR_NONE;
}

file_error sdl_write_ptty(osd_file *file, const void *buffer, UINT64 offset, UINT32 count, UINT32 *actual)
{
#ifndef __CELLOS_LV2__
	ssize_t result;
	result = write(file->handle, buffer, count);

	if (result < 0)
	{
		return error_to_file_error(errno);
	}

	if (actual != NULL )
	{
		*actual = result;
	}
#endif
	return FILERR_NONE;
}

file_error sdl_close_ptty(osd_file *file)
{
#ifndef __CELLOS_LV2__
	close(file->handle);
	osd_free(file);
#endif
	return FILERR_NONE;
}
