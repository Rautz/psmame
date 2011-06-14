#include <es_system.h>

						SDLThread::SDLThread			(ThreadFunction aThreadFunction, void* aUserData) : 
	Thread(0),
	Result(0),
	Dead(false)
{
	Thread = SDL_CreateThread(aThreadFunction, aUserData);
}

						SDLThread::~SDLThread			()
{
	Wait();
}

int32_t					SDLThread::Wait					()
{
	if(!Dead)
	{
		SDL_WaitThread(Thread, &Result);
	}

	Dead = true;
	return Result;
}

						SDLMutex::SDLMutex				()
{
	Mutex = SDL_CreateMutex();
}

						SDLMutex::~SDLMutex				()
{
	SDL_DestroyMutex(Mutex);
}

void					SDLMutex::Lock					()
{
	SDL_mutexP(Mutex);
}

void					SDLMutex::Unlock				()
{
	SDL_mutexV(Mutex);
}
