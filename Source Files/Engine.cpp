#include "Engine.h"
#include "TextureManager.h"
#include "Map.h"
#include "GameObject.h"
#include "Bird.h"
#include "Function.h"

SDL_Renderer* Engine::renderer = nullptr;
Map* map;
Bird* bird;
SDL_Event Engine::event;
Function* function;

Engine::Engine()
{}
Engine::~Engine()
{}

void Engine::init(const char* title, int xpos, int ypos, int width, int height)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, xpos, ypos, width, height, 0);

		renderer = SDL_CreateRenderer(window, -1, 0);
	
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			
		isRunning = true; 
		//khoi tao cua so console
	}
	function = new Function();
	map = new Map();
	bird = new Bird();
}


void Engine::handleEvents()
{
	
	SDL_PollEvent(&event);
	switch (event.type) 
	{
		case SDL_QUIT:
			isRunning = false;
			break;
		
		default:
			break;
	}
}

void Engine::update()
{
	
		function->updateClick();
		map->updateMap();
		if (Function::mouse_event[START_BUTTON] == 1)
		{
			function->updatePoint();
			map->updateSoundMap();
		}
		Function::mouseEvent(START_BUTTON);
		bird->updateBird();
		function->updateMousePosition();
		function->resetClick(START_BUTTON);
		for (int i = 0; i < 3; i++)
		{
			if (
				Function::checkCollision(bird->getBirdRect(), Map::pipe[i]->up_pipeRect()) == true
				||
				Function::checkCollision(bird->getBirdRect(), Map::pipe[i]->down_pipeRect()) == true
				)
			{
				Function::collision_pipe = true;
			}
		}
		if (
			Function::checkCollision(bird->getBirdRect(), Map::ground->getRect()) == true
			)
		{
			Function::collision_ground = true;
		}
		if (Function::collision_ground == true || Function::collision_pipe == true)
		{
			Function::game_over = true;
		}
		std::cout << Function::mouseEvent(START_BUTTON) <<" ";
		/*if (Function::mouseEvent(RESTART_BUTTON) == true)
		{
			function = nullptr;
			bird = nullptr;
			map = nullptr;
			map = new Map();
			function = new Function();
			bird = new Bird();
		}*/
}
void Engine::render()
{
	SDL_RenderClear(renderer);
	map->loadMap();
	bird->loadBird();
	SDL_RenderPresent(renderer);
}

void Engine::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	//exit game
}
