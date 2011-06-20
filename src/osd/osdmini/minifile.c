//============================================================
//
//  minifile.c - Minimal core file access functions
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

#include "osdcore.h"
#include <stdlib.h>
#include <alloca.h>
#include <unistd.h>
#include <sys/stat.h>
#include <cell/cell_fs.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

struct _osd_file
{
	int	handle;
	char filename[1];
};


//============================================================
//  Prototypes
//============================================================

static UINT32 create_path_recursive(char *path);

//============================================================
//  error_to_file_error
//  (does filling this out on non-Windows make any sense?)
//============================================================

file_error error_to_file_error(UINT32 error)
{
	switch (error)
	{
	case ENOENT:
	case ENOTDIR:
		return FILERR_NOT_FOUND;

	case EACCES:
	case EROFS:
	case EEXIST:
	case EPERM:
	case EISDIR:
	case EINVAL:
		return FILERR_ACCESS_DENIED;

	case ENFILE:
	case EMFILE:
		return FILERR_TOO_MANY_FILES;

	default:
		return FILERR_FAILURE;
	}
}


//============================================================
//  osd_open
//============================================================

file_error osd_open(const char *path, UINT32 openflags, osd_file **file, UINT64 *filesize)
{
	UINT32 access;
	const char *src;
	char *dst;
	struct stat st;
	char *tmpstr;
	int i, j;
	file_error filerr = FILERR_NONE;

	// allocate a file object, plus space for the converted filename
	*file = (osd_file *) osd_malloc(sizeof(**file) + sizeof(char) * strlen(path));
	if(*file == NULL)
	{
		filerr = FILERR_OUT_OF_MEMORY;
		goto error;
	}

	// convert the path into something compatible
	dst = (*file)->filename;
	for(src = path; *src != 0; src++)
	{
		*dst++ = (*src == '\\') ? '/' : *src;
	}
	*dst++ = 0;

	// select the file open modes
	if (openflags & OPEN_FLAG_WRITE)
	{
		access = (openflags & OPEN_FLAG_READ) ? O_RDWR : O_WRONLY;
		access |= (openflags & OPEN_FLAG_CREATE) ? (O_CREAT | O_TRUNC) : 0;
	}
	else if (openflags & OPEN_FLAG_READ)
	{
		access = O_RDONLY;
	}
	else
	{
		filerr = FILERR_INVALID_ACCESS;
		goto error;
	}

	tmpstr = (char*)alloca(strlen((*file)->filename)+1);
	strcpy(tmpstr, (*file)->filename);

	// attempt to open the file
	(*file)->handle = open(tmpstr, access, 0666);
	if ((*file)->handle == -1)
	{
		// create the path if necessary
		if ((openflags & OPEN_FLAG_CREATE) && (openflags & OPEN_FLAG_CREATE_PATHS))
		{
			char *pathsep = strrchr(tmpstr, '/');
			if (pathsep != NULL)
			{
				int error;

				// create the path up to the file
				*pathsep = 0;
				error = create_path_recursive(tmpstr);
				*pathsep = '/';

				// attempt to reopen the file
				if(!error)
				{
					(*file)->handle = open(tmpstr, access, 0666);
				}
			}
		}

		// if we still failed, clean up and osd_free
		if ((*file)->handle == -1)
		{
			osd_free(*file);
			*file = NULL;
			return error_to_file_error(errno);
		}
	}

	// get the file size
	fstat((*file)->handle, &st);
	*filesize = (UINT64)st.st_size;

error:
	// cleanup
	if (filerr != FILERR_NONE && *file != NULL)
	{
		osd_free(*file);
		*file = NULL;
	}

	return filerr;
}


//============================================================
//  osd_read
//============================================================

file_error osd_read(osd_file *file, void *buffer, UINT64 offset, UINT32 count, UINT32 *actual)
{
	ssize_t result;

	lseek(file->handle, (UINT32)offset&0xFFFFFFFF, SEEK_SET);
	result = read(file->handle, buffer, count);
	
	if(result < 0)
	{
		return error_to_file_error(errno);
	}

	if(actual)
	{
		*actual = result;
	}

	return FILERR_NONE;
}


//============================================================
//  osd_write
//============================================================

file_error osd_write(osd_file *file, const void *buffer, UINT64 offset, UINT32 count, UINT32 *actual)
{
	UINT32 result;

	lseek(file->handle, (UINT32)offset&0xFFFFFFFF, SEEK_SET);
	result = write(file->handle, buffer, count);

	if(!result)
	{
		return error_to_file_error(errno);
	}

	if(actual)
	{
		*actual = result;
	}

	return FILERR_NONE;
}


//============================================================
//  osd_close
//============================================================

file_error osd_close(osd_file *file)
{
	close(file->handle);
	osd_free(file);
	return FILERR_NONE;
}


//============================================================
//  osd_rmfile
//============================================================

file_error osd_rmfile(const char *filename)
{
	return remove(filename) ? FILERR_FAILURE : FILERR_NONE;
}


//============================================================
//  osd_get_physical_drive_geometry
//============================================================

int osd_get_physical_drive_geometry(const char *filename, UINT32 *cylinders, UINT32 *heads, UINT32 *sectors, UINT32 *bps)
{
	return FALSE;
}


//============================================================
//  osd_uchar_from_osdchar
//============================================================

int osd_uchar_from_osdchar(UINT32 /* unicode_char */ *uchar, const char *osdchar, size_t count)
{
	wchar_t wch;
	count = mbstowcs(&wch, (char *)osdchar, 1);

	*uchar = (count != -1) ? wch : 0;
	return count;
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
//  osd_get_full_path
//============================================================

file_error osd_get_full_path(char **dst, const char *path)
{
	// derive the full path of the file in an allocated string
	// for now just fake it since we don't presume any underlying file system
	*dst = strdup(path);
	return FILERR_NONE;
}


//============================================================
//  osd_get_volume_name
//============================================================

const char *osd_get_volume_name(int idx)
{
	return (idx == 0) ? "/" : 0;
}

//============================================================
//  create_path_recursive
//============================================================

static UINT32 create_path_recursive(char *path)
{
	char *sep = strrchr(path, '/');
	UINT32 filerr;
	struct stat st;

	// if there's still a separator, and it's not the root, nuke it and recurse
	if (sep != NULL && sep > path && sep[0] != ':' && sep[-1] != '/')
	{
		*sep = 0;
		filerr = create_path_recursive(path);
		*sep = '/';
		if (filerr != 0)
			return filerr;
	}

	// if the path already exists, we're done
	if (!stat(path, &st))
		return 0;

	// create the path
	if (mkdir(path, 0777) != 0)
		return error_to_file_error(errno);
	return 0;
}

