#pragma once

#include "src/utility/AudioBuffer.h"

class								ESAudio
{
	public:	
		static void					Initialize				();
		static void					Shutdown				();

		static void					AddSamples				(const uint32_t* aSamples, uint32_t aCount) {while(RingBuffer.GetBufferFree() < aCount) Semaphore->Wait(); RingBuffer.WriteData(aSamples, aCount);};

		static volatile int32_t		GetBufferFree			() {return RingBuffer.GetBufferFree();};
		static volatile int32_t		GetBufferAmount			() {return RingBuffer.GetBufferAmount();};

	protected:
		static int					ProcessAudioThread		(void* aAudio);
	
		static const int			BlockCount = 16;

		static ESThread*			Thread;
		static ESSemaphore*			Semaphore;
		static volatile bool		ThreadDie;

		static sys_event_queue_t	QueueID;
		static sys_ipc_key_t		QueueKey;

		static uint32_t				Port;
		static CellAudioPortConfig	Config;

		static AudioBuffer<>		RingBuffer;
};

