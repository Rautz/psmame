#include <es_system.h>

SYS_PROCESS_PARAM(1001, 1024 * 1024);

namespace
{
	volatile bool	want_to_die = false;
	volatile bool	want_to_sleep = false;

	void			sysutil_callback		(uint64_t status, uint64_t param, void *userdata)
	{
		switch (status)
		{
			case CELL_SYSUTIL_REQUEST_EXITGAME:	want_to_die = true; break;
			case CELL_SYSUTIL_SYSTEM_MENU_OPEN:	want_to_sleep = true; break; 
			case CELL_SYSUTIL_SYSTEM_MENU_CLOSE:want_to_sleep = false; break;
		}

		return;
	}
};

void				ESSUB_Init				()
{
	sys_spu_initialize(6, 1);
	cellSysutilRegisterCallback(0, (CellSysutilCallback)sysutil_callback, NULL);

	while(true)
	{
		CellVideoOutState videoState;
		cellVideoOutGetState(CELL_VIDEO_OUT_PRIMARY, 0, &videoState);

		if(videoState.state == CELL_VIDEO_OUT_OUTPUT_STATE_ENABLED)
		{
			break;
		}
	}

	cellSysmoduleLoadModule(CELL_SYSMODULE_FS);
}

void				ESSUB_Quit				()
{
	cellSysmoduleUnloadModule(CELL_SYSMODULE_FS);
	cellSysutilUnregisterCallback(0);
}

ESThreads*			ESSUB_MakeThreads		()
{
	return new CellThreads();
}


bool				ESSUB_WantToDie			()
{
	cellSysutilCheckCallback();
	return want_to_die;
}

bool				ESSUB_WantToSleep		()
{
	cellSysutilCheckCallback();
	return want_to_sleep;
}

std::string			ESSUB_GetBaseDirectory	()
{
#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#ifndef ES_HOME_PATH
#define ES_HOME_PATH /dev_hdd0/game/MDFN90002/USRDIR/
#endif
#define ES_DIR TOSTRING(ES_HOME_PATH)

	return ES_DIR;
}


