#pragma once

#include "Engine.h"

class Sound
{
public:
	Sound(const char* name);
	void loadSound();
private:
	Mix_Chunk* sound;
};