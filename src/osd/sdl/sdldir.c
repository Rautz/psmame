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

#ifndef _LARGEFILE64_SOURCE
#define _LARGEFILE64_SOURCE
#endif

#ifdef SDLMAME_LINUX
#define __USE_LARGEFILE64
#endif
#ifndef SDLMAME_BSD
#ifdef _XOPEN_SOURCE
#undef _XOPEN_SOURCE
#endif
#define _XOPEN_SOURCE 500
#endif

//#include <sys/types.h>
#ifndef __CELLOS_LV2__
#include <sys/stat.h>
#else
extern "C"{
#include <time.h>
#include <types.h>
#include <sys/fs.h>

struct statst {
        /*
         * POSIX defines that at least the following members should be
         * in stat structure
         */
        dev_t st_dev;                           /* ID of the device */
        ino_t st_ino;                           /* File serial number */
        mode_t st_mode;                         /* Mode of file */
        nlink_t st_nlink;                       /* Number of links */
#if 0
        uid_t st_uid;                           /* User ID */
        gid_t st_gid;                           /* Group ID */
#else
        int32_t st_uid;                         /* User ID */
        int32_t st_gid;                         /* Group ID */
#endif
        dev_t st_rdev;                          /* Device ID */
        off64_t st_size;                        /* File size in bytes */
        time_t st_atime;                        /* Last access time */
        time_t st_mtime;                        /* Last data modiflcation time */
        time_t st_ctime;                        /* Last status chage time */
        blksize_t st_blksize;           /* I/O block size */
        blkcnt_t st_blocks;                     /* Number of blocks */
        /*
         * User defined members
         */
};
int stat(const char *path, struct statst *buf);
#define        S_IFDIR 0040000

}
#endif
#include <fcntl.h>
#ifndef __USE_BSD
#define __USE_BSD	// to get DT_xxx on Linux
#endif
#undef _POSIX_C_SOURCE  // to get DT_xxx on OS X
#include <dirent.h>

#include "osdcore.h"
#include "sdlos.h"

#if defined(SDLMAME_WIN32) || defined(SDLMAME_OS2)
#define PATHSEPCH '\\'
#define INVPATHSEPCH '/'
#else
#define PATHSEPCH '/'
#define INVPATHSEPCH '\\'
#endif

#if defined(SDLMAME_DARWIN) || defined(SDLMAME_WIN32) || defined(SDLMAME_NO64BITIO) || defined(SDLMAME_BSD) || defined(SDLMAME_OS2) || defined(__CELLOS_LV2__)
typedef struct dirent sdl_dirent;
typedef struct statst sdl_stat;
#define sdl_readdir readdir
#define sdl_stat_fn stat
#else
typedef struct dirent64 sdl_dirent;
typedef struct stat64 sdl_stat;
#define sdl_readdir readdir64
#define sdl_stat_fn stat64
#endif

#define HAS_DT_XXX defined(SDLMAME_LINUX) || defined(SDLMAME_BSD) || defined(SDLMAME_DARWIN)

struct _osd_directory
{
	osd_directory_entry ent;
	sdl_dirent *data;
	DIR *fd;
	char *path;
};

static char *build_full_path(const char *path, const char *file)
{
	char *ret = (char *) osd_malloc(strlen(path)+strlen(file)+2);
	char *p = ret;

	strcpy(p, path);
	p += strlen(path);
	*p++ = PATHSEPCH;
	strcpy(p, file);
	return ret;
}


#if HAS_DT_XXX
static osd_dir_entry_type get_attributes_enttype(int attributes)
{
	if (attributes == DT_DIR)
		return ENTTYPE_DIR;
	else
		return ENTTYPE_FILE;
}
#else

static osd_dir_entry_type get_attributes_stat(const char *file)
{
	sdl_stat st;
	if(sdl_stat_fn(file, &st))
		return (osd_dir_entry_type) 0;

#ifdef __CELLOS_LV2__
	if (st.st_mode & S_IFDIR)
#else
	if (S_ISDIR(st.st_mode))
#endif
		return ENTTYPE_DIR;
	else
		return ENTTYPE_FILE;
}
#endif

static UINT64 osd_get_file_size(const char *file)
{
	sdl_stat st;
	if(sdl_stat_fn(file, &st))
		return 0;
	return st.st_size;
}

//============================================================
//  osd_opendir
//============================================================

osd_directory *osd_opendir(const char *dirname)
{
	osd_directory *dir = NULL;
	char *tmpstr, *envstr;
	int i, j;

	dir = (osd_directory *) osd_malloc(sizeof(osd_directory));
	if (dir)
	{
		memset(dir, 0, sizeof(osd_directory));
		dir->fd = NULL;
	}

	tmpstr = (char *) osd_malloc(strlen(dirname)+1);
	strcpy(tmpstr, dirname);

	if (tmpstr[0] == '$')
	{
		char *envval;
		envstr = (char *) osd_malloc(strlen(tmpstr)+1);

		strcpy(envstr, tmpstr);

		i = 0;
		while (envstr[i] != PATHSEPCH && envstr[i] != INVPATHSEPCH && envstr[i] != 0 && envstr[i] != '.')
		{
			i++;
		}

		envstr[i] = '\0';

		envval = osd_getenv(&envstr[1]);
		if (envval != NULL)
		{
			j = strlen(envval) + strlen(tmpstr) + 1;
			osd_free(tmpstr);
			tmpstr = (char *) osd_malloc(j);

			// start with the value of $HOME
			strcpy(tmpstr, envval);
			// replace the null with a path separator again
			envstr[i] = PATHSEPCH;
			// append it
			strcat(tmpstr, &envstr[i]);
		}
		else
			fprintf(stderr, "Warning: osd_opendir environment variable %s not found.\n", envstr);
		osd_free(envstr);
	}

	dir->fd = opendir(tmpstr);
	dir->path = tmpstr;

	if (dir && (dir->fd == NULL))
	{
		osd_free(dir->path);
		osd_free(dir);
		dir = NULL;
	}

	return dir;
}


//============================================================
//  osd_readdir
//============================================================

const osd_directory_entry *osd_readdir(osd_directory *dir)
{
	char *temp;
	dir->data = sdl_readdir(dir->fd);

	if (dir->data == NULL)
		return NULL;

	dir->ent.name = dir->data->d_name;
	temp = build_full_path(dir->path, dir->data->d_name);
	#if HAS_DT_XXX
	dir->ent.type = get_attributes_enttype(dir->data->d_type);
	#else
	dir->ent.type = get_attributes_stat(temp);
	#endif
	dir->ent.size = osd_get_file_size(temp);
	osd_free(temp);
	return &dir->ent;
}


//============================================================
//  osd_closedir
//============================================================

void osd_closedir(osd_directory *dir)
{
	if (dir->fd != NULL)
		closedir(dir->fd);
	osd_free(dir->path);
	osd_free(dir);
}

