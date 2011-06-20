#include <es_system.h>

void					ESAudio::Initialize				()
{
	cellAudioInit();

	CellAudioPortParam portparam = {2, BlockCount, CELL_AUDIO_PORTATTR_BGM, 1};
	cellAudioPortOpen(&portparam, &Port);

	cellAudioGetPortConfig(Port, &Config);

	cellAudioCreateNotifyEventQueue(&QueueID, &QueueKey);
	cellAudioSetNotifyEventQueue(QueueKey);
	sys_event_queue_drain(QueueID);

	cellAudioPortStart(Port);
	
	Thread = es_threads->MakeThread(ProcessAudioThread, 0);
	Semaphore = es_threads->MakeSemaphore(1);
}


void					ESAudio::Shutdown				()
{
	cellAudioPortStop(Port);

	ThreadDie = true;
	delete Thread;
	delete Semaphore;

	cellAudioPortClose(Port);
	cellAudioRemoveNotifyEventQueue(QueueKey);
	sys_event_queue_destroy(QueueID, SYS_EVENT_QUEUE_DESTROY_FORCE);
	cellAudioQuit();
}

int						ESAudio::ProcessAudioThread		(void* aBcD)
{
	int16_t samples[1024];
	float outbuffer[512];

	sys_event_t event;

	while(!ThreadDie)
	{
		if(0 != sys_event_queue_receive(QueueID, &event, 100 * 1000))
		{
			break;
		}

		RingBuffer.ReadDataSilentUnderrun((uint32_t*)samples, 256);

		if(!Semaphore->GetValue())
		{
			Semaphore->Post();
		}

		for(uint32_t i = 0; i != 256 * 2; i ++)
		{
			outbuffer[i] = ((float)samples[i]) / 32768.0f;
		}

		cellAudioAddData(Port, outbuffer, 256, 1);
	}
	
	ThreadDie = false;
	return 0;
}

ESThread*				ESAudio::Thread;
ESSemaphore*			ESAudio::Semaphore;
volatile bool			ESAudio::ThreadDie;

sys_event_queue_t		ESAudio::QueueID;
sys_ipc_key_t			ESAudio::QueueKey;

uint32_t				ESAudio::Port;
CellAudioPortConfig		ESAudio::Config;

AudioBuffer<>			ESAudio::RingBuffer;

