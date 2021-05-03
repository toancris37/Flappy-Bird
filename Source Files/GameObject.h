#pragma once

#include "Engine.h"
#include "TextureManager.h"

#include <cmath>

class GameObject {
public:
	GameObject(const char* text);
	~GameObject();

	void updateBird();
	void updatePipe1();
	void updatePipe2();
	void updatePipe3();
	void updateBG();
	void updateGround();

	void RenderObj();

	void updateClick_to_play();
	void updateScoreBoard();
	void updateGameOver();
	void updateFlappyBird();
	void updateGameMenu();

	void updateLeft_button();
	void updateRight_button();

	void firstPoint();
	void secondPoint();
	
	SDL_Rect getRect();
	SDL_Rect up_pipeRect();
	SDL_Rect down_pipeRect();

private:
	double velocity = 0;
	int width;
	int height;
	int cnt = 0;
	double t = 0;
	int numberClick = 0;
	double velocity_fly = - 10;
	double gravity = 0.5;
	int tmp = -1;
	int random1, random2, random3;
	int start = 0;
	int skip = 3.5;
	int h_pipe = 500;
	int blank = 200;


	SDL_Rect desObj;
	SDL_Rect pipe;
	SDL_Texture* objTexture;
	
};