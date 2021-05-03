#pragma once

#include "Engine.h"
#include "GameObject.h"
#include "Map.h"

const int START_BUTTON = 0;
const int SCORE_BUTTON = 1;
const int RESTART_BUTTON = 2;
const int SHARE_BUTTON = 3;

class Function
{
public:
	Function();
	void updatePoint();
	void updateClick();
	void updateMousePosition();
	void resetClick(int n);
	static bool checkCollision(SDL_Rect a, SDL_Rect b);
	static bool mouseEvent(int n);
	static int number_click;
	static bool click;
	static bool mouse_event[4];
	static int point;
	static bool game_over;
	static bool collision_pipe;
	static bool collision_ground;
	static int first_point;
	static int second_point;
	static SDL_Point mPos;
	static bool restart;
private:

	int start = 0;
	int up_pipe = 500;
	int down_pipe = 500;
	int blank = 200;
	int deviation = 5;
};