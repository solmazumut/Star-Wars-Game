#pragma once
#include "olcSimpleEngine.h"

class Object;

using namespace std;

class GameManager :public olc::PixelGameEngine
{
	int score;
	bool isGameStart;
	bool gameOver;
	shared_ptr<olc::Sprite> background;
	vector<shared_ptr<Object>> objects;

	shared_ptr<olc::Sprite> menu1;
	shared_ptr<olc::Sprite> menu2;

	shared_ptr<olc::Sprite> gameover;

public:
	bool OnUserCreate();
	bool OnUserUpdate(float);
};