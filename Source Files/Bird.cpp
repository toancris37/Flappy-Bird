#include "Bird.h"

int Bird::time;
int Bird::timeline[12];

Bird::Bird()
{
	time = 0;

	for (int i = 0; i < 12; i++)
	{
		timeline[i] = 36 + i;
	}

	bird_fly[0] = new GameObject("Flappy Bird/Bird/down_fly.png");
	bird_mid[0] = new GameObject("Flappy Bird/Bird/mid_fly.png");
	bird_down[0] = new GameObject("Flappy Bird/Bird/up_fly.png");

	bird_fly[1] = new GameObject("Flappy Bird/Bird/down_-20.png");
	bird_mid[1] = new GameObject("Flappy Bird/Bird/mid_-20.png");
	bird_down[1] = new GameObject("Flappy Bird/Bird/up_-20.png");

	bird_fly[2] = new GameObject("Flappy Bird/Bird/down_-10.png");
	bird_mid[2] = new GameObject("Flappy Bird/Bird/mid_-10.png");
	bird_down[2] = new GameObject("Flappy Bird/Bird/up_-10.png");

	bird_fly[3] = new GameObject("Flappy Bird/Bird/down.png");
	bird_mid[3] = new GameObject("Flappy Bird/Bird/mid.png");
	bird_down[3] = new GameObject("Flappy Bird/Bird/up.png");

	bird_fly[4] = new GameObject("Flappy Bird/Bird/down_10.png");
	bird_mid[4] = new GameObject("Flappy Bird/Bird/mid_10.png");
	bird_down[4] = new GameObject("Flappy Bird/Bird/up_10.png");

	bird_fly[5] = new GameObject("Flappy Bird/Bird/down_20.png");
	bird_mid[5] = new GameObject("Flappy Bird/Bird/mid_20.png");
	bird_down[5] = new GameObject("Flappy Bird/Bird/up_20.png");

	bird_fly[6] = new GameObject("Flappy Bird/Bird/down_30.png");
	bird_mid[6] = new GameObject("Flappy Bird/Bird/mid_30.png");
	bird_down[6] = new GameObject("Flappy Bird/Bird/up_30.png");

	bird_fly[7] = new GameObject("Flappy Bird/Bird/down_40.png");
	bird_mid[7] = new GameObject("Flappy Bird/Bird/mid_40.png");
	bird_down[7] = new GameObject("Flappy Bird/Bird/up_40.png");

	bird_fly[8] = new GameObject("Flappy Bird/Bird/down_50.png");
	bird_mid[8] = new GameObject("Flappy Bird/Bird/mid_50.png");
	bird_down[8] = new GameObject("Flappy Bird/Bird/up_50.png");

	bird_fly[9] = new GameObject("Flappy Bird/Bird/down_60.png");
	bird_mid[9] = new GameObject("Flappy Bird/Bird/mid_60.png");
	bird_down[9] = new GameObject("Flappy Bird/Bird/up_60.png");

	bird_fly[10] = new GameObject("Flappy Bird/Bird/down_70.png");
	bird_mid[10] = new GameObject("Flappy Bird/Bird/mid_70.png");
	bird_down[10] = new GameObject("Flappy Bird/Bird/up_70.png");

	bird_fly[11] = new GameObject("Flappy Bird/Bird/down_80.png");
	bird_mid[11] = new GameObject("Flappy Bird/Bird/mid_80.png");
	bird_down[11] = new GameObject("Flappy Bird/Bird/up_80.png");

	bird_fly[12] = new GameObject("Flappy Bird/Bird/down_90.png");
	bird_mid[12] = new GameObject("Flappy Bird/Bird/mid_90.png");
	bird_down[12] = new GameObject("Flappy Bird/Bird/up_90.png");
}

void Bird::updateBird()
{
	for (int i = 0; i < 13; i++)
	{
		bird_fly[i]->GameObject::updateBird();
		bird_mid[i]->GameObject::updateBird();
		bird_down[i]->GameObject::updateBird();
	}
}


void Bird::flyBird(int n)
{
	if (0 <= cnt && cnt < 8)
	{
		bird_fly[n]->RenderObj();
	}
	if (8 <= cnt && cnt < 16)
	{
		bird_mid[n]->RenderObj();
	}
	if (16 <= cnt && cnt < 24)
	{
		bird_down[n]->RenderObj();
	}
	cnt++;
	if (cnt == 24)
	{
		cnt = 0;
	}
	
}

void Bird::loadBird()
{
	if (Function::mouse_event[START_BUTTON] == 0
		||
		(Function::mouse_event[START_BUTTON] == 1 && Function::number_click == 0)
		)
	{
		flyBird(3);
	}

	if (Function::number_click > 0 && Function::collision_ground == false && Function::mouse_event[START_BUTTON] == 1)
	{
		if (0 <= time && time < timeline[0])
		{
			flyBird(0);
		}
		if (timeline[0] <= time && time <=timeline[1])
		{
			flyBird(1);
		}
		if (timeline[1] <= time && time < timeline[2])
		{
			flyBird(2);
		}
		if (timeline[2] <= time && time < timeline[3])
		{
			flyBird(3);

		}
		if (timeline[3] <= time && time < timeline[4])
		{
			flyBird(4);

		}
		if (timeline[4] <= time && time < timeline[5])
		{
			flyBird(5);

		}
		if (timeline[5] <= time && time < timeline[6])
		{
			flyBird(6);

		}
		if (timeline[6] <= time && time < timeline[7])
		{
			flyBird(7);

		}
		if (timeline[7] <= time && time < timeline[8])
		{
			flyBird(8);

		}
		if (timeline[8] <= time && time < timeline[9])
		{
			flyBird(9);
		}
		if (timeline[9] <= time && time < timeline[10])
		{
			flyBird(10);

		}
		if (timeline[10] <= time && time < timeline[11])
		{
			flyBird(11);
		}
		if (timeline[11] <= time)
		{
			flyBird(12);
		}
		
		time++;
		if (Function::click == true)
		{
			time = 0;
			Map::sound_bird->loadSound();
		}
	}
	if (Function::number_click > 0 && Function::collision_ground == true && Function::mouse_event[START_BUTTON] == 1)
	{
		bird_mid[12]->RenderObj();
	}
}

SDL_Rect Bird::getBirdRect()
{
	return bird_mid[3]->getRect();
}

