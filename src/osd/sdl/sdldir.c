//============================================================
//
//  sdldir.c - SDL core directory access functions
//
//  Copyright (c) 1996-2010, Nicola Salmoria and the MAME Team.
//  Visit http://mamedev.org for licensing and usage restrictions.
//
//  SDLMAME by Olivier Galibert and R. Belmont
//
//============================================================
#include <cell/cell_fs.h>
#include <string.h>
#include <stdlib.h>

#include "osdcore.h"
#include "sdlos.h"


struct _osd_directory
{
	osd_directory_entry ent;
	int fd;
	char *path;
};

static char *build_full_path(const char *path, const char *file)
{
	char *ret = (char *) osd_malloc(strlen(path)+strlen(file)+2);
	char *p = ret;

	strcpy(p, path);
	p += strlen(path);
	*p++ = '/';
	strcpy(p, file);
	return ret;
}


//============================================================
//  osd_opendir
//============================================================
osd_directory *osd_opendir(const char *dirname)
{
	osd_directory *dir = (osd_directory *)osd_malloc(sizeof(osd_directory));;
	if(dir)
	{
		memset(dir, 0, sizeof(osd_directory));
		dir->fd = NULL;
	}

	if(CELL_OK != cellFsOpendir(dirname, &dir->fd))
	{
		osd_free(dir);
		dir = NULL;
	}

	dir->path = strdup(dirname);
	return dir;
}


//============================================================
//  osd_readdir
//============================================================
const osd_directory_entry *osd_readdir(osd_directory *dir)
{
	char *temp;

	CellFsDirent data;
	uint64_t wasRead;
	if(CELL_OK != cellFsReaddir(dir->fd, &data, &wasRead) || wasRead == 0)
	{
		return 0;
	}

	dir->ent.name = data.d_name;
	dir->ent.type = (data.d_type == CELL_FS_TYPE_DIRECTORY) ? ENTTYPE_DIR : ENTTYPE_FILE;

	//Get file size
	temp = build_full_path(dir->path, data.d_name);
	CellFsStat st;
	dir->ent.size = cellFsStat(temp, &st) ? 0 : st.st_size;
	osd_free(temp);

	//Done
	return &dir->ent;
}


//============================================================
//  osd_closedir
//============================================================
void osd_closedir(osd_directory *dir)
{
	if(dir->fd)
	{
		cellFsClosedir(dir->fd);
	}

	osd_free(dir->path);
	osd_free(dir);
}


