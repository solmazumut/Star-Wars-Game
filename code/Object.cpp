#include "Object.h"

Object::Object(double xIn, double yIn, double speedIn, double armorIn, GameManager* gameIn)
{
	coordinateX = xIn;
	coordinateY = yIn;
	speed = speedIn;
	armor = armorIn;
	game = gameIn;
}

void Object::move(float a) {}

void Object::draw(float a) {}

shared_ptr<Object> Object::fire()
{
	return nullptr;
}

bool Object::isFire()
{
	return false;
}

bool Object::isDead()
{
	if (armor <= 0)
	{
		return true;
	}
	return false;
}

void Object::timeUpdate(float time)
{

}

void Object::collision(shared_ptr<Object> a)
{

}

bool Object::collisionForBullet(double xIn, double xEnd, double yIn, double yEnd, string type)
{
	return false;
}

bool Object::isCreate()
{
	return false;
}
