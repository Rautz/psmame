#pragma once

#include <cell/cell_fs.h>
#include <PSGL/psgl.h>
#include <PSGL/psglu.h>
#include <cell/pad.h>
#include <cell/audio.h>
#include <cell/sysmodule.h>
#include <sys/spu_initialize.h>
#include <sysutil/sysutil_sysparam.h>
#include <sysutil/sysutil_bgmplayback.h>
#include <sys/process.h>
#include <sys/event.h>
#include <sys/ppu_thread.h>
#include <sys/sys_time.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <cell/mstream.h>

#include <unistd.h>
#include <assert.h>
#include <dirent.h>
#include <sys/stat.h>

class				PlatformHelpers
{
	public:
		static uint32_t					GetTicks					()
		{
			return sys_time_get_system_time() / 1000;
		}

		static void						Sleep						(uint32_t aMilliseconds)
		{
			sys_timer_usleep(aMilliseconds * 1000);
		}
};

