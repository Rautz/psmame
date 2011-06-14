#pragma once

typedef int (*ThreadFunction) (void*);

class								ESThread
{
	public:
		virtual						~ESThread			() {};

		virtual int32_t				Wait				() = 0;
};

class								ESMutex
{
	public:
		virtual						~ESMutex			() {};

		virtual void				Lock				() = 0;
		virtual void				Unlock				() = 0;
};

class								ESSemaphore
{
	public:
		virtual						~ESSemaphore		() {};

		virtual uint32_t			GetValue			() = 0;
		virtual void				Post				() = 0;
		virtual void				Wait				() = 0;
};

class								ESThreads
{
	public:
		virtual ESThread*			MakeThread			(ThreadFunction aFunction, void* aUserData) = 0;
		virtual	ESMutex*			MakeMutex			() = 0;
		virtual ESSemaphore*		MakeSemaphore		(uint32_t aValue) = 0;
};

