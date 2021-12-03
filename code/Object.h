#pragma once
#include "GameManager.h"
using namespace std;

class Object
{
protected:
	double coordinateX;
	double coordinateY;
	double speed;
	double armor;
	GameManager* game;
public:
	Object(double, double, double, double, GameManager*);
	virtual void move(float) = 0;
	virtual void draw(float) = 0;
	virtual shared_ptr<Object> fire();
	virtual bool isFire();
	bool isDead();
	virtual void timeUpdate(float);
	virtual void collision(shared_ptr<Object>);
	virtual bool collisionForBullet(double, double, double, double, string);
	virtual bool isCreate();
};
