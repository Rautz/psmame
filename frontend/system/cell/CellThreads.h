#pragma once

class								CellThread : public ESThread
{
	public:
									CellThread			(ThreadFunction aThreadFunction, void* aUserData); //External

		virtual						~CellThread			(); //External
		virtual int32_t				Wait				(); //External

		static void					ThreadWrapper		(uint64_t aUser);

	private:
		ThreadFunction				Function;
		void*						UserData;

		sys_ppu_thread_t			Thread;
		int32_t						Result;
		bool						Dead;
};

class								CellMutex : public ESMutex
{
	public:
									CellMutex			(); //External
		virtual						~CellMutex			(); //External

		void						Lock				(); //External
		void						Unlock				(); //External

	private:
		sys_mutex_t					Mutex;
};

class								CellSemaphore : public ESSemaphore
{
	public:
									CellSemaphore		(uint32_t aValue); //External
		virtual						~CellSemaphore		(); //External

		virtual uint32_t			GetValue			(); //External
		virtual void				Post				(); //External
		virtual void				Wait				(); //External

	private:
		sys_semaphore_t				Semaphore;
};


class								CellThreads : public ESThreads
{
	public:
		virtual ESThread*			MakeThread			(ThreadFunction aThreadFunction, void* aUserData) {return new CellThread(aThreadFunction, aUserData);};
		virtual ESMutex*			MakeMutex			() {return new CellMutex();};
		virtual ESSemaphore*		MakeSemaphore		(uint32_t aValue) {return new CellSemaphore(aValue);};
};

