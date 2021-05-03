#include "GameObject.h"
#include "Function.h"

GameObject::GameObject(const char* text)
{
	objTexture = TextureManager::LoadTexture(text);
	SDL_QueryTexture(objTexture, NULL, NULL, &width, &height);
	srand(time(0));
	random1 = rand() % 7 * 50;
	random2 = rand() % 7 * 50;
	random3 = rand() % 7 * 50;
}

GameObject::~GameObject()
{}

void GameObject::updateFlappyBird()
{
	desObj.x = 70;
	desObj.y = 200 + 20 * cos(t / 10);
	t++;
	desObj.w = width;
	desObj.h = height;
}

void GameObject::updateGameMenu()
{
	desObj.x = 0;
	desObj.y = 0;
	desObj.w = width;
	desObj.h = height;
}

void GameObject::updateLeft_button()
{
	desObj.x = (WINDOW_WIDTH / 2 - width) / 2 + 15;
		desObj.y = 600;
		desObj.h = height;
		desObj.w = width;
}

void GameObject::updateRight_button()
{
	desObj.x = (3 * WINDOW_WIDTH / 2 - width) / 2 - 15;
	desObj.y = 600;
	desObj.h = height;
	desObj.w = width;
}

void GameObject::updateClick_to_play()
{
	desObj.x = 0;
	desObj.y = 0;
	desObj.h = height;
	desObj.w = width;
	if (Function::number_click == 1 && Function::mouse_event[START_BUTTON] == 1)
	{
		SDL_DestroyTexture(objTexture);
	}
}

void GameObject::firstPoint()
{
	if (Function::collision_ground == false)
	{
		if (0 <= Function::point && Function::point < 10)
		{
			desObj.x = WINDOW_WIDTH / 2 - width / 2;
			desObj.y = 50;
			desObj.w = width;
			desObj.h = height;
		}
		if (10 <= Function::point)
		{
			desObj.x = WINDOW_WIDTH / 2 - width;
			desObj.y = 50;
			desObj.w = width;
			desObj.h = height;
		}
	}
	else
	{
		if (0 <= Function::point && Function::point < 10)
		{
			desObj.x = 460;
			desObj.y = 305;
			desObj.w = width/2;
			desObj.h = height/2;
		}
		if (10 <= Function::point)
		{
			desObj.x = 435;
			desObj.y = 305;
			desObj.w = width / 2;
			desObj.h = height / 2;
		}
	}
}

void GameObject::secondPoint()
{
	if (Function::collision_ground == false)
	{
		desObj.x = WINDOW_WIDTH / 2 + 5;
		desObj.y = 50;
		desObj.w = width;
		desObj.h = height;
	}
	else
	{
		desObj.x = 460;
		desObj.y = 305;
		desObj.w = width/2;
		desObj.h = height/2;
	}
}

void GameObject::updateBird()
{
	if (Function::mouse_event[START_BUTTON] == 0)
	{
		desObj.x = 470;
		desObj.y = 200 + 20 * cos(t / 10);
		t++;
		desObj.w = width;
		desObj.h = height;
	}
	else if (Function::game_over == false)
	{
		if (tmp == -1)
		{
			desObj.h = height;
			desObj.w = width;
			desObj.x = 200;
			desObj.y = 300;
			tmp = 0;
		}
		if (Function::click == true && tmp == 0)
		{
			velocity = velocity_fly;
			tmp++;
		}
		if (Engine::event.type == SDL_MOUSEBUTTONUP && tmp > 0)
		{
			tmp = 0;
		}
	}
	if (tmp >= 0 && Function::number_click > 0 && desObj.y + desObj.h < 700)
	{
		desObj.y += velocity + gravity * 0.5;
		velocity += gravity;
	}
}

void GameObject::updatePipe1()
{	
	if (tmp == -1)
	{
		desObj.x = 800 + cnt * skip;
		desObj.y = -400 + random1;
		desObj.h = height;
		desObj.w = width;
	}
	if (tmp == 0)
	{
		desObj.x = 800 + cnt * skip;
	}

	
	if (desObj.x <= -width)
	{
		tmp = 0;
		cnt = 0;
		random1= rand() % 7 * 50;
	}

	cnt--;

}

void GameObject::updatePipe2()
{
	if (tmp == -1)
	{
		desObj.x = 1100 + cnt * skip;
		desObj.y = -400 + random2;
		desObj.h = height;
		desObj.w = width;
	}
	if (tmp == 0)
	{
		desObj.x = 800 + cnt * skip;
	}
	
	if (desObj.x <= -width)
	{
		tmp = 0;
		cnt = 0;
		random2 = rand() % 7 * 50;
	}
	cnt--;
}

void GameObject::updatePipe3()
{
	if (tmp == -1)
	{
		desObj.x = 1400 + cnt * skip;
	}
	if (tmp == 0)
	{
		desObj.x = 800 + cnt * skip;
	}

	desObj.y = -400 + random3;
	desObj.h = height;
	desObj.w = width;
	cnt--;
	if (desObj.x <= -width)
	{
		tmp = 0;
		cnt = 0;
		random3 = rand() % 7 * 50;
	}
	
}

void GameObject::updateBG()
{
		desObj.y = 0;
		desObj.h = height;
		desObj.w = width;
		desObj.x = cnt * skip;
		
		if (desObj.x == -600)
		{
			cnt = 0;
		}
		cnt--;
}

void GameObject::updateGround()
{
	desObj.y = 700;
	desObj.h = height;
	desObj.w = width;
	desObj.x = cnt * skip;
	
	if (desObj.x == -600)
	{
		cnt = 0;
	}
	cnt--;
}

void GameObject::updateScoreBoard()
{
	desObj.x = WINDOW_WIDTH / 2 - width / 2;
	desObj.y = WINDOW_HEIGHT / 2 - height / 2 - 50;
	desObj.h = height;
	desObj.w = width;
}

void GameObject::updateGameOver()
{
	desObj.x = WINDOW_WIDTH / 2 - width / 2;
	desObj.y = WINDOW_HEIGHT / 2 - height / 2 - 250;
	desObj.h = height;
	desObj.w = width;
}


SDL_Rect GameObject::up_pipeRect()
{
	pipe.x = desObj.x;
	pipe.y = desObj.y;
	pipe.w = desObj.w;
	pipe.h = h_pipe;
	return pipe;
}
SDL_Rect GameObject::down_pipeRect()
{
	pipe.x = desObj.x;
	pipe.y = desObj.y + h_pipe + blank;
	pipe.w = desObj.w;
	pipe.h = h_pipe;
	return pipe;
}

SDL_Rect GameObject::getRect()
{
	return desObj;
}

void GameObject::RenderObj()
{
	SDL_RenderCopy(Engine::renderer, objTexture, NULL, &desObj);
}

