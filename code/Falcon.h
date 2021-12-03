#pragma once
#include "Object.h"
using namespace std;

class Falcon :public Object
{
	int scene;
	int count;
	vector<shared_ptr<olc::Sprite>> images;
	void drawHPbar();
public:
	Falcon(GameManager*);
	void move(float);
	void draw(float);
	shared_ptr<Object> fire();
	bool isFire();
	void collision(shared_ptr<Object>);
};
