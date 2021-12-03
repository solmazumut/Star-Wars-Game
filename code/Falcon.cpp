#include "Falcon.h"
#include "Bullet.h"

Falcon::Falcon(GameManager* gameIn) : Object(120, 120, 100, 100, gameIn)
{
	scene = 0;
	count = 3;
	for (int i = 0; i < 26; i++)
	{
		images.push_back(make_shared<olc::Sprite>("Assets/"+ to_string(i+1) + ".png"));
	}
}

void Falcon::move(float time)
{
	if (game->GetKey(olc::A).bHeld)
	{
		coordinateX -= speed * time;
	}

	if (game->GetKey(olc::D).bHeld)
	{
		coordinateX += speed * time;
	}

	if (coordinateX <= 0)
	{
		coordinateX = 0;
	}
	if (coordinateX+80 >= game->ScreenWidth())
	{
		coordinateX = game->ScreenWidth() -80;
	}
}

void Falcon::drawHPbar()
{
	double ratio = (double)(armor) / (double)100;
	for (int i = coordinateX; i < coordinateX+10; i++)
	{
		if (i < coordinateX + ratio * 10)
		{
			game->DrawRect(i, coordinateY + 30, 1, 1, olc::GREEN);
		}
		else {
			game->DrawRect(i, coordinateY + 30, 1, 1, olc::RED);
		}
	}
}

void Falcon::draw(float time)
{
	if (scene == 26)
	{
		scene = 0;
	}

	game->DrawSprite(coordinateX, coordinateY, images[scene]);

	count -= time;
	if (count <= 0)
	{
		scene++;
		count = 3;
	}

	drawHPbar();
	
}
shared_ptr<Object> Falcon::fire()
{
	return make_shared<Bullet>(coordinateX + 40, coordinateY - 1, game, -1);
}

bool Falcon::isFire()
{
	if (game->GetKey(olc::SPACE).bPressed)
	{
		return true;
	}
	return false;
}

void Falcon::collision(shared_ptr<Object> O)
{
	if (O->collisionForBullet(coordinateX, coordinateX + 80, coordinateY, coordinateY +100, "Falcon"))
	{
		armor -= 10;
	}
}