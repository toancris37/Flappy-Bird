#include "Map.h"'

GameObject* Map::click_to_play;
GameObject* Map::background;
GameObject* Map::pipe[3];
GameObject* Map::ground;
GameObject* Map::gameMenu;
GameObject* Map::FlappyBird;
GameObject* Map::start_button;
GameObject* Map::score_button;
GameObject* Map::share_button;
GameObject* Map::restart_button;
GameObject* Map::scoreBoard;
GameObject* Map::gameOver;


Sound* Map::soundClick_to_play;
Sound* Map::sound_bird;
Sound* Map::sound_point;
Sound* Map::sound_hit;
Sound* Map::sound_die;


Map::Map()
{
	soundClick_to_play = new Sound("Flappy Bird/Sound/swoosh.wav");
	sound_bird = new Sound("Flappy Bird/Sound/wing.wav");
	sound_point = new Sound("Flappy Bird/Sound/point.wav");
	sound_hit = new Sound("Flappy Bird/Sound/hit.wav");
	sound_die = new Sound("Flappy Bird/Sound/die.wav");

	gameMenu = new GameObject("Flappy Bird/Game_Object_Others/gameMenu.png");
	click_to_play = new GameObject("Flappy Bird/Game_Object_Others/click_to_play.png");
	background = new GameObject("Flappy Bird/Game_Object_Others/background.png");
	pipe[0] = new GameObject("Flappy Bird/Game_Object_Others/pipe.png");
	pipe[1] = new GameObject("Flappy Bird/Game_Object_Others/pipe.png");
	pipe[2] = new GameObject("Flappy Bird/Game_Object_Others/pipe.png");
	ground = new GameObject("Flappy Bird/Game_Object_Others/ground.png");
	FlappyBird= new GameObject("Flappy Bird/Game_Object_Others/Flappy Bird.png");
	start_button = new GameObject("Flappy Bird/Game_Object_Others/start_button.png");
	score_button = new GameObject("Flappy Bird/Game_Object_Others/score_button.png");
	restart_button = new GameObject("Flappy Bird/Game_Object_Others/restart_button.png");
	share_button = new GameObject("Flappy Bird/Game_Object_Others/share_button.png");
	scoreBoard = new GameObject("Flappy Bird/Game_Object_Others/scoreBoard.png");
	gameOver = new GameObject("Flappy Bird/Game_Object_Others/gameover.png");

	first_pointImage[0] = new GameObject("Flappy Bird/Point/0.png");
	first_pointImage[1] = new GameObject("Flappy Bird/Point/1.png");
	first_pointImage[2] = new GameObject("Flappy Bird/Point/2.png");
	first_pointImage[3] = new GameObject("Flappy Bird/Point/3.png");
	first_pointImage[4] = new GameObject("Flappy Bird/Point/4.png");
	first_pointImage[5] = new GameObject("Flappy Bird/Point/5.png");
	first_pointImage[6] = new GameObject("Flappy Bird/Point/6.png");
	first_pointImage[7] = new GameObject("Flappy Bird/Point/7.png");
	first_pointImage[8] = new GameObject("Flappy Bird/Point/8.png");
	first_pointImage[9] = new GameObject("Flappy Bird/Point/9.png");

	second_pointImage[0] = new GameObject("Flappy Bird/Point/0.png");
	second_pointImage[1] = new GameObject("Flappy Bird/Point/1.png");
	second_pointImage[2] = new GameObject("Flappy Bird/Point/2.png");
	second_pointImage[3] = new GameObject("Flappy Bird/Point/3.png");
	second_pointImage[4] = new GameObject("Flappy Bird/Point/4.png");
	second_pointImage[5] = new GameObject("Flappy Bird/Point/5.png");
	second_pointImage[6] = new GameObject("Flappy Bird/Point/6.png");
	second_pointImage[7] = new GameObject("Flappy Bird/Point/7.png");
	second_pointImage[8] = new GameObject("Flappy Bird/Point/8.png");
	second_pointImage[9] = new GameObject("Flappy Bird/Point/9.png");

}
 
void Map::updateSoundMap()
{

	if (Function::number_click == 0 && tmp == 0)
	{
		Map::soundClick_to_play->loadSound();
		tmp = 1;
	}
	if (Function::collision_pipe == true && die == 0)
	{
		sound_hit->loadSound();
		sound_die->loadSound();
		die = 1;
	}
	if (Function::collision_ground == true && die == 0)
	{
		sound_hit->loadSound();
		die = 1;
	}
}

void Map::updateMap()
{
	//bird->updateBird();
	click_to_play->updateClick_to_play();
	start_button->updateLeft_button();
	score_button->updateRight_button();
	FlappyBird->updateFlappyBird();
	gameMenu->updateGameMenu();
	if (Function::mouse_event[START_BUTTON] == 1)
	{
		if (Function::game_over == false)
		{
			background->updateBG();
			if (Function::number_click >= 1)
			{
				pipe[0]->updatePipe1();
				pipe[1]->updatePipe2();
				pipe[2]->updatePipe3();
			}
			ground->updateGround();
		}
		for (int i = 0; i < 10; i++)
		{
			first_pointImage[i]->firstPoint();
			second_pointImage[i]->secondPoint();
		}
	}
	if (Function::collision_ground == true)
	{
		scoreBoard->updateScoreBoard();
		gameOver->updateGameOver(); 
		share_button->updateRight_button();
		restart_button->updateLeft_button();
	}
}



void Map::loadMap()
{
	background->RenderObj();
	pipe[0]->RenderObj();
	pipe[1]->RenderObj();
	pipe[2]->RenderObj();
	ground->RenderObj();
	click_to_play->RenderObj();
	//bird->loadBird();
	share_button->RenderObj();
	restart_button->RenderObj();
	scoreBoard->RenderObj();
	gameOver->RenderObj();
		
	if (Function::number_click >= 1 && Function::mouse_event[START_BUTTON] == true)
	{
		if (Function::point < 10)
		{
			first_pointImage[Function::point]->RenderObj();
		}

		if (Function::point >= 10)
		{
			first_pointImage[Function::first_point]->RenderObj();
			second_pointImage[Function::second_point]->RenderObj();
		}
	}
	
	if (Function::mouse_event[START_BUTTON] == 0)
	{
		gameMenu->RenderObj();
		start_button->RenderObj();
		score_button->RenderObj();
		FlappyBird->RenderObj();
	}
	
}