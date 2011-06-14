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

#include <stdlib.h>
#include <string.h>
#include <cell/cell_fs.h>
#include <sys/sys_time.h>
#include <sys/timer.h>

// MAME headers
#include "osdcore.h"

//============================================================
//   osd_cycles
//============================================================
osd_ticks_t osd_ticks(void)
{
	static osd_ticks_t timenow;
	if(!timenow)
	{
		timenow = sys_time_get_system_time();
	}

	return sys_time_get_system_time() - timenow;
}

osd_ticks_t osd_ticks_per_second(void)
{
	return (osd_ticks_t) 1000000;
}

void osd_sleep(osd_ticks_t duration)
{
	if (duration >= 2000)
	{
		duration -= 2000;
		sys_timer_usleep(duration);
	}
}

//============================================================
//  osd_malloc
//============================================================

void *osd_malloc(size_t size)
{
	return malloc(size);
}


//============================================================
//  osd_free
//============================================================
void osd_free(void *ptr)
{
	free(ptr);
}

//============================================================
//  osd_get_clipboard_text
//============================================================
char *osd_get_clipboard_text(void)
{
	return 0;
}

//============================================================
//  osd_stat
//============================================================
osd_directory_entry *osd_stat(const char *path)
{
	CellFsStat st;
	if(cellFsStat(path, &st) != CELL_OK)
	{
		return 0;
	}

	// create an osd_directory_entry; be sure to make sure that the caller can
	// free all resources by just freeing the resulting osd_directory_entry
	osd_directory_entry *result = (osd_directory_entry*)osd_malloc(sizeof(*result) + strlen(path) + 1);
	strcpy(((char*)result) + sizeof(*result), path);
	result->name = ((char *)result) + sizeof(*result);

	result->type = (st.st_mode & CELL_FS_S_IFDIR) ? ENTTYPE_DIR : ENTTYPE_FILE;
	result->size = st.st_size;

	return result;
}

//============================================================
//  osd_get_volume_name
//============================================================
const char *osd_get_volume_name(int idx)
{
	return (idx == 0) ? "/" : 0;
}

//============================================================
//  osd_get_full_path
//============================================================
file_error osd_get_full_path(char **dst, const char *path)
{
	static const char* path_buffer = "/dev_hdd0/game/MAME90000/USRDIR";
	*dst = (char*)osd_malloc(strlen(path_buffer)+strlen(path)+3);

	if(path[0] == '/')
	{
		strcpy(*dst, path);
	}
	else
	{
		sprintf(*dst, "%s%s%s", path_buffer, PATH_SEPARATOR, path);
	}

	return FILERR_NONE;
}

