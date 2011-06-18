#pragma once

class								SDLThread : public ESThread
{
	public:
									SDLThread			(ThreadFunction aThreadFunction, void* aUserData); //External

		virtual						~SDLThread			(); //External
		virtual int32_t				Wait				(); //External

	private:
		SDL_Thread*					Thread;
		int32_t						Result;
		bool						Dead;
};

class								SDLMutex : public ESMutex
{
	public:
									SDLMutex			(); //External
		virtual						~SDLMutex			(); //External

		void						Lock				(); //External
		void						Unlock				(); //External

	private:
		SDL_mutex*					Mutex;
};

class								SDLThreads : public ESThreads
{
	public:
		virtual ESThread*			MakeThread			(ThreadFunction aThreadFunction, void* aUserData) {return new SDLThread(aThreadFunction, aUserData);};
		virtual ESMutex*			MakeMutex			() {return new SDLMutex();};
		virtual ESSemaphore*			MakeSemaphore			(uint32_t aValue) {return 0;};
};

