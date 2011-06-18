#include <es_system.h>

ESThreads*			es_threads = 0;

namespace
{
	volatile bool	want_to_die = false;
	void			(*ExitFunction)() = 0;
};

void				ESSUB_Init				();
void				ESSUB_Quit				();
ESThreads*			ESSUB_MakeThreads		();
bool				ESSUB_WantToDie			();
bool				ESSUB_WantToSleep		();
std::string			ESSUB_GetBaseDirectory	();

void				InitES					(void (*aExitFunction)())
{
	ExitFunction = aExitFunction;

	ESSUB_Init();

	es_threads = ESSUB_MakeThreads();
	ESNetwork::Initialize();
	ESVideo::Initialize();
	ESAudio::Initialize();
	ESInput::Initialize();
}

void				QuitES					()
{
	ESInput::Shutdown();
	ESAudio::Shutdown();
	ESVideo::Shutdown();
	ESNetwork::Shutdown();
	delete es_threads;

	ESSUB_Quit();
}

volatile bool		WantToDie				()
{
	want_to_die = ESSUB_WantToDie();

	if(want_to_die && ExitFunction)
	{
		ExitFunction();
		exit(1);
	}
	
	return want_to_die;
}

volatile bool		WantToSleep				()
{
	return ESSUB_WantToSleep();
}

