#pragma once

#include "Engine.h"

class TextureManager {

public:
	static SDL_Texture* LoadTexture(const char* fileName);
};