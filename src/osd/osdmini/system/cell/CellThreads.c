#include <es_system.h>

						CellThread::CellThread			(ThreadFunction aThreadFunction, void* aUserData) : 
	Function(aThreadFunction),
	UserData(aUserData),
	Thread(0),
	Result(0),
	Dead(false)
{
	sys_ppu_thread_create(&Thread, ThreadWrapper, (uint64_t)this, 500, 65536, SYS_PPU_THREAD_CREATE_JOINABLE, "\0");
}

						CellThread::~CellThread			()
{
	Wait();
}

int32_t					CellThread::Wait				()
{
	if(!Dead)
	{
		Dead = true;

		uint64_t result64;
		sys_ppu_thread_join(Thread, &result64);
		Result = (int32_t)result64;
	}

	return Result;
}

void					CellThread::ThreadWrapper		(uint64_t aUserData)
{
	CellThread* thread = (CellThread*)aUserData;
	int32_t result = thread->Function(thread->UserData);
	sys_ppu_thread_exit(result);
}

						CellMutex::CellMutex			() :
	Mutex(0)
{
	sys_mutex_attribute_t attr;
	sys_mutex_attribute_initialize(attr);
	sys_mutex_create(&Mutex, &attr);
}

						CellMutex::~CellMutex			()
{
	sys_mutex_destroy(Mutex);
}

void					CellMutex::Lock					()
{
	sys_mutex_lock(Mutex, 0);
}

void					CellMutex::Unlock				()
{
	sys_mutex_unlock(Mutex);
}

						CellSemaphore::CellSemaphore	(uint32_t aValue)
{
	sys_semaphore_attribute_t attr;
	sys_semaphore_attribute_initialize(attr);
	sys_semaphore_create(&Semaphore, &attr, aValue, aValue);
}

						CellSemaphore::~CellSemaphore	()
{
	sys_semaphore_destroy(Semaphore);
}

uint32_t				CellSemaphore::GetValue			()
{
	sys_semaphore_value_t val;
	sys_semaphore_get_value(Semaphore, &val);
	return val;
}

void					CellSemaphore::Post				()
{
	sys_semaphore_post(Semaphore, 1);
}

void					CellSemaphore::Wait				()
{
	sys_semaphore_wait(Semaphore, 0);
}


