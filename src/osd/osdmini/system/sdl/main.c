#include <es_system.h>

namespace
{
	bool			want_to_die = false;
};

void				SetExit					()
{
	want_to_die = true;
}

void				ESSUB_Init				()
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_JOYSTICK | SDL_INIT_TIMER);
}

void				ESSUB_Quit				()
{
	SDL_Quit();
}

ESThreads*			ESSUB_MakeThreads		()
{
	return new SDLThreads();
}

bool				ESSUB_WantToDie			()
{
	return want_to_die;
}

volatile bool		ESSUB_WantToSleep		()
{
	return false;
}

std::string			ESSUB_GetBaseDirectory	()
{
#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#ifndef ES_HOME_PATH
#define ES_HOME_PATH mednafen
#endif
#define ES_DIR TOSTRING(ES_HOME_PATH)

#ifndef __WIN32__
	printf("%s\n", (std::string(getenv("HOME")) + "/." ES_DIR "/").c_str());
	return std::string(getenv("HOME")) + "/." ES_DIR "/";
#else
	char path[MAX_PATH];
	SHGetFolderPathA(0, CSIDL_APPDATA, 0, 0, path);
	return std::string(path) + "/" ES_DIR "/";
#endif
}

