#pragma once
#include "Object.h"
using namespace std;

class Bullet :public Object
{
	int direction;
public:
	Bullet(double, double, GameManager*,int);
	void move(float);
	void draw(float);
	bool collisionForBullet(double, double, double, double, string);
};