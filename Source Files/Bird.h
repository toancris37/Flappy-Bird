#pragma once

#include "Engine.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Sound.h"
#include "Function.h"

class Bird
{
public:
	Bird();
	~Bird();
	void updateBird();
	void loadBird();
	void flyBird(int n);
	SDL_Rect getBirdRect(); 
	static int time;
	static int timeline[12];

private:
	int cnt = 0;
	GameObject* bird_mid[13];
	GameObject* bird_fly[13];
	GameObject* bird_down[13];
	
	int first = 0;
};