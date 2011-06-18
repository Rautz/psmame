#pragma once

#include <stdlib.h>

template<int Length=8192>
class						AudioBuffer
{
	public:
							AudioBuffer						() : RingBuffer(0), ReadCount(0), WriteCount(0)
		{
			RingBuffer = (uint32_t*)malloc(Length * 4);
		}

							~AudioBuffer					()
		{
			free(RingBuffer);
		}

		uint32_t			WriteData						(const uint32_t* aData, uint32_t aLength)
		{
			int i;

			uint32_t free = GetBufferFree();
			aLength = (aLength > free) ? free : aLength;

			for(i = 0; i != aLength; i ++, WriteCount ++)
			{
				RingBuffer[WriteCount % Length] = aData[i];
			}

			return i;
		}

		uint32_t			ReadData						(uint32_t* aData, uint32_t aLength)
		{
			int i;

			uint32_t available = GetBufferAmount();
			aLength = (aLength > available) ? available : aLength;

			for(i = 0; i != aLength; i ++, ReadCount ++)
			{
				aData[i] = RingBuffer[ReadCount % Length];
			}

			return i;
		}

		uint32_t			ReadDataSilentUnderrun			(uint32_t* aData, uint32_t aLength)
		{
			int i;

			for(i = 0; i != aLength && GetBufferAmount() != 0; i ++, ReadCount ++)
			{
				aData[i] = RingBuffer[ReadCount % Length];
			}

			if(i != aLength)
			{
				memset(&aData[i], 0, (aLength - i) * 4);
			}

			return i;
		}

		volatile int32_t 	GetBufferAmount					() const {return (WriteCount - ReadCount);}
		volatile int32_t 	GetBufferFree					() const {return Length - (WriteCount - ReadCount);}

	private:
		uint32_t*			RingBuffer;

		uint32_t			ReadCount;
		uint32_t			WriteCount;
};

