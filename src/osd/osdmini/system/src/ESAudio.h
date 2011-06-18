#if 0
class								ESAudio
{
	public:	
		virtual						~ESAudio				(){};
	
		virtual void				AddSamples				(const uint32_t* aSamples, uint32_t aCount) = 0;
		virtual volatile int32_t	GetBufferAmount			() const  = 0;
		virtual volatile int32_t	GetBufferFree			() const  = 0;
};
#endif
