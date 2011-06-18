#include <es_system.h>

void					ESAudio::Initialize				()
{
	SDL_AudioSpec spec;
	spec.freq = 48000;
	spec.format = AUDIO_S16;
	spec.channels = 2;
	spec.samples = 2048;
	spec.callback = ProcessAudioCallback;

	SDL_OpenAudio(&spec, &Format);
	SDL_PauseAudio(0);
}


void					ESAudio::Shutdown				()
{
	SDL_CloseAudio();
}

void					ESAudio::ProcessAudioCallback	(void *userdata, Uint8 *stream, int len)
{
	Buffer.ReadDataSilentUnderrun((uint32_t*)stream, len / 4);
}

SDL_AudioSpec			ESAudio::Format;
AudioBuffer<>			ESAudio::Buffer;

