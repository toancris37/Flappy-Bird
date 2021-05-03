#include "Function.h"

SDL_Point Function::mPos;
bool Function::click;
int Function::number_click;
bool Function::mouse_event[4];
int Function::point;
bool Function::game_over;
bool Function::collision_pipe;
bool Function::collision_ground;
int Function::first_point;
int Function::second_point;
bool Function::restart;
Function::Function()
{ 
	
	first_point = 0;
	second_point = 0;
	number_click = 0;
	click = 0;
	for (int i = 0; i < 4; i++)
	{
		mouse_event[i] = false;
	}
	point = 0;
	game_over = false;
	mPos.x = 0;
	mPos.y = 0;
}

void Function::resetClick(int n)
{
	if (Function::mouseEvent(n) == true)
	{
		number_click = 0;
	}
}
void Function::updateMousePosition()
{
	if (Function::click == true)
	{
		SDL_GetMouseState(&Function::mPos.x, &Function::mPos.y);
	}
}

void Function::updateClick()
{

	if (Engine::event.type == SDL_MOUSEBUTTONDOWN && start > 0)
	{
		click = false;
	}
	if (Engine::event.type == SDL_MOUSEBUTTONDOWN && start == 0)
	{
		start++;
		number_click++;
		click = true;
	}
	if (Engine::event.type == SDL_MOUSEBUTTONUP && start > 0)
	{
		click = false;
		start = 0;
	}
}


bool Function::checkCollision(SDL_Rect a, SDL_Rect b)
{
	if (0 <= Bird::time && Bird::time < Bird::timeline[0])
	{
		a.x += 13;
		a.y += 13;
		a.w -= 25;
		a.h -= 13;
	}
	if (Bird::timeline[0] <= Bird::time && Bird::time <= Bird::timeline[1])
	{
		a.x += 10;
		a.y += 14;
		a.w -= 20;
		a.h -= 14;
	}
	if (Bird::timeline[1] <= Bird::time && Bird::time < Bird::timeline[2])
	{
		a.x += 10;
		a.y += 14;
		a.w -= 20;
		a.h -= 14;
	}
	if (Bird::timeline[2] <= Bird::time && Bird::time < Bird::timeline[3])
	{
		a.x += 5;
		a.y += 10;
		a.w -= 10;
		a.h -= 25;
	}
	if (Bird::timeline[3] <= Bird::time && Bird::time < Bird::timeline[5])
	{
		a.x += 10;
		a.y += 15;
		a.w -= 17;
		a.h -= 30;
	}
	if (Bird::timeline[5] <= Bird::time && Bird::time < Bird::timeline[7])
	{
		a.x += 12;
		a.y += 20;
		a.w -= 25;
		a.h -= 40;
	}
	if (Bird::timeline[7] <= Bird::time && Bird::time < Bird::timeline[9])
	{
		a.x += 13;
		a.y += 10;
		a.w -= 26;
		a.h -= 15;
	}
	if (Bird::timeline[9] <= Bird::time && Bird::time < Bird::timeline[11])
	{
		a.x += 15;
		a.y += 10;
		a.w -= 30;
		a.h -= 12;
	}
	
	//The sides of the rectangles
	
	
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	//Calculate the sides of rect B
	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;
	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}

	//If none of the sides from A are outside B
	return true;
}

void Function::updatePoint()
{
	first_point = point / 10;
	second_point = point % 10;
	for (int i = 0; i < 3; i++)
	{
		if (Map::pipe[i]->getRect().x < 242
			&&
			Map::pipe[i]->getRect().x >= 239
			&&
			number_click > 0
			)
		{
			point++;
			Map::sound_point->loadSound();
		}
	}
}

bool Function::mouseEvent(int n)
{
	if (mouse_event[n] == true)
	{
		return false;
	}
	GameObject* button = nullptr;
	switch (n)
	{
	case 0:
		button = Map::start_button;
		break;
	case 1:
		button = Map::score_button;
		break;
	case 2:
		button = Map::restart_button;
		break;
	case 3:
		
		break;
	default:
		break;
	}

	//Mouse is left of the button
	if (Function::mPos.x < button->getRect().x)
	{
		return false;
	}
	//Mouse is right of the button
	else if (Function::mPos.x > button->getRect().x + button->getRect().w)
	{
		return false;
	}
	//Mouse above the button
	else if (Function::mPos.y < button->getRect().y)
	{
		return false;
	}
	//Mouse below the button
	else if (Function::mPos.y > button->getRect().y + button->getRect().h)
	{
		return false;
	}
		
	if (Function::click == true)
	{
		mouse_event[n] = true;
		return true;
	}
	
	else
		return false;

}
