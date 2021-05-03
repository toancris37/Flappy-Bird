#pragma once

#ifndef Engine_h
#define Engine_h

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <cstdlib>
#include <ctime>

const int WINDOW_HEIGHT = 800;
const int WINDOW_WIDTH = 600;
class Engine {
public:
	Engine();
	~Engine();

	void init(const char* title, int xpos, int ypos, int width, int height);
	void handleEvents();
	void update();
	void render();
	void clean();
	bool running() 
	{
		return isRunning;
	}
	static SDL_Event event;
	static SDL_Renderer* renderer;
private:
	bool isRunning = false;
	SDL_Window* window;
};


#endif 
