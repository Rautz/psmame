//============================================================
//
//  minidir.c - Minimal core directory access functions
//
//============================================================
//
//  Copyright Aaron Giles
//  All rights reserved.
//
//  Redistribution and use in source and binary forms, with or
//  without modification, are permitted provided that the
//  following conditions are met:
//
//    * Redistributions of source code must retain the above
//      copyright notice, this list of conditions and the
//      following disclaimer.
//    * Redistributions in binary form must reproduce the
//      above copyright notice, this list of conditions and
//      the following disclaimer in the documentation and/or
//      other materials provided with the distribution.
//    * Neither the name 'MAME' nor the names of its
//      contributors may be used to endorse or promote
//      products derived from this software without specific
//      prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY AARON GILES ''AS IS'' AND
//  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
//  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
//  FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
//  EVENT SHALL AARON GILES BE LIABLE FOR ANY DIRECT,
//  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
//  DAMAGE (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
//  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
//  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
//  ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
//  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
//  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
//  IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//============================================================


#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#ifndef __CELLOS_LV2__
#include <sys/stat.h>
#else
#include <cell/cell_fs.h>
#endif

#include "osdcore.h"


struct _osd_directory
{
	osd_directory_entry ent;
	DIR* fd;
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
	}

	dir->fd = opendir(dirname);
	if(!dir->fd)
	{
		osd_free(dir);
		return 0;
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

	struct dirent* data = readdir(dir->fd);

	if(!data)
	{
		return 0;
	}

	dir->ent.name = data->d_name;
	dir->ent.type = (data->d_type == DT_DIR) ? ENTTYPE_DIR : ENTTYPE_FILE;

	//Get file size
	temp = build_full_path(dir->path, data->d_name);
#ifndef __CELLOS_LV2__
	struct stat st;
	dir->ent.size = stat(temp, &st) ? 0 : st.st_size;
#else
	CellFsStat st;
	dir->ent.size = cellFsStat(temp, &st) ? 0 : st.st_size;
#endif

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
		closedir(dir->fd);
	}

	osd_free(dir->path);
	osd_free(dir);
}


//============================================================
//  osd_is_absolute_path
//============================================================
int osd_is_absolute_path(const char *path)
{
	return (path && path[0] == '/');
}

