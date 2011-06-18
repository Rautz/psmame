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
		static void					MultiStreamCallback		(int streamNumber, void* userData, int cType, void * pWriteBuffer, int nBufferSize);
	
		static const int			BlockCount = 16;

		static ESThread*			Thread;
		static ESSemaphore*			Semaphore;
		static volatile bool		ThreadDie;

		static int32_t				MSChannel;
		static void*				MSMemory;
		static void*				MSBuffers[2];
		static volatile bool		StreamDead;

		static uint32_t				Port;
		static CellAudioPortConfig	Config;

		static AudioBuffer<>		RingBuffer;
};

