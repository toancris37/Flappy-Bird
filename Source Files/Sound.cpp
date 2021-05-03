#include "Sound.h"

Sound::Sound(const char* name)
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		Mix_GetError();
	}
	sound = Mix_LoadWAV(name);
}
void Sound::loadSound()
{
	Mix_PlayChannel(-1, sound, 0);
}
