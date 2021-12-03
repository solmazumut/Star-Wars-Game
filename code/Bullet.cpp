#include "Bullet.h"

Bullet::Bullet(double xIn, double yIn, GameManager* gameIn, int directionIn) : Object(xIn, yIn, 200, 10, gameIn) {
	direction = directionIn;
}

void Bullet::move(float time)
{
	coordinateY += time * speed * direction;

	if (coordinateY <= 0 || coordinateY >= game->ScreenHeight())
	{
		armor = 0;
	}
}

void Bullet::draw(float)
{
	if (direction == -1)
	{
		game->DrawCircle(coordinateX, coordinateY, 1, olc::BLUE);
	}
	else {
		game->DrawCircle(coordinateX, coordinateY, 1, olc::RED);
	}
}

bool Bullet::collisionForBullet(double xIn, double xEnd, double yIn, double yEnd, string type)
{
	if (coordinateX >= xIn && coordinateX <= xEnd && coordinateY >= yIn && coordinateY <= yEnd && (type == "Falcon" || type == "Fighter"))
	{
		armor = 0;
		return true;
	}
	return false;
}