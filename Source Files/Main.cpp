#include "Engine.h"


Engine* engine = nullptr;

int main(int argc, char* argv[])
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS; 

	Uint32 frameStart;
	int frameTime;

	engine = new Engine();
	engine->init("Flappy Bird", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT);
	
	while (engine->running())
	{
		frameStart = SDL_GetTicks();

		engine->handleEvents();
		engine->update();
		engine->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}
	
	engine->clean();

	return 0;
}