#pragma once
#include "Object.h"
using namespace std;

class Fighter :public Object
{
	double clockStart;
	double clock;
	shared_ptr<olc::Sprite> image;
	shared_ptr<olc::Sprite> burn;
	void drawHPbar();
public:
	Fighter(GameManager*);
	void move(float);
	void draw(float);
	shared_ptr<Object> fire();
	bool isFire();
	void timeUpdate(float);
	void collision(shared_ptr<Object>);
	bool isCreate();
};