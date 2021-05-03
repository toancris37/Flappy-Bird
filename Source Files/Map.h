#pragma once

#include "Engine.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Sound.h"
#include "Bird.h"
#include "Function.h"

class Map {
public:

	Map();

	void updateMap();
	void loadMap();
	void updateSoundMap();
	
	static GameObject* background;
	static GameObject* pipe[3];
	static GameObject* click_to_play;
	static GameObject* ground;
	static GameObject* FlappyBird;
	static GameObject* start_button;
	static GameObject* score_button;
	static GameObject* share_button;
	static GameObject* restart_button;
	static GameObject* gameMenu;
	static GameObject* scoreBoard;
	static GameObject* gameOver;

	static Sound* soundClick_to_play;
	static Sound* sound_bird;
	static Sound* sound_point;
	static Sound* sound_hit;
	static Sound* sound_die;


private:
	GameObject* first_pointImage[10];
	GameObject* second_pointImage[10];
	int tmp = 0;
	bool  die = 0;
};
	
