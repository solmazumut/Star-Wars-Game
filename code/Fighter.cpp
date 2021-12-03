#include "Fighter.h"
#include "Bullet.h"

Fighter::Fighter(GameManager* gameIn) : Object(100, -30, 100, 100, gameIn )
{
	image = make_shared<olc::Sprite>("Assets/fighter.png");
	burn = make_shared<olc::Sprite>("Assets/fire.png");
	clockStart = 1;
	clock = clockStart;
}

void Fighter::move(float time)
{
	coordinateX += time * speed;

	if (coordinateX <= -40 || coordinateX >= game->ScreenWidth() - 50)
	{
		speed *= -1;
	}
}

void Fighter::drawHPbar()
{
	double ratio = (double)(armor) / (double)100;
	for (int i = coordinateX + 16; i < coordinateX + 26; i++)
	{
		if (i < coordinateX + 16 + ratio * 10)
		{
			game->DrawRect(i, coordinateY + 60, 1, 1, olc::GREEN);
		}
		else {
			game->DrawRect(i, coordinateY + 60, 1, 1, olc::RED);
		}
	}
}

void Fighter::draw(float time)
{
	if (armor <= 0)
	{
		game->DrawSprite(coordinateX, coordinateY, burn);
	}
	else
	{
		game->DrawSprite(coordinateX, coordinateY, image);
	}

	drawHPbar();
}

shared_ptr<Object> Fighter::fire()
{
	return make_shared<Bullet>(coordinateX + 40, coordinateY + 75, game, 1);
}

bool Fighter::isFire()
{
	if (clock <= 0)
	{
		clock = clockStart;
		return true;
	}

	return false;
}

void Fighter::timeUpdate(float time)
{
	clock -= time;
}

void Fighter::collision(shared_ptr<Object> O)
{
	if (O->collisionForBullet(coordinateX + 20, coordinateX + 70, coordinateY +20, coordinateY+70, "Fighter"))
	{
		armor -= 10;
	}
}

bool Fighter::isCreate()
{
	if (armor <= 0)
	{
		return true;
	}
	return false;
}