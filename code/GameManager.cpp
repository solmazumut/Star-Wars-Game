#include "GameManager.h"
#include "Falcon.h"
#include "Fighter.h"

bool GameManager::OnUserCreate()
{
	background = make_shared<olc::Sprite>("Assets/gameBackground.png");
	objects.push_back(make_shared<Falcon>(this));
	objects.push_back(make_shared<Fighter>(this));
	score = 0;
	isGameStart = false;

	menu1 = make_shared<olc::Sprite>("Assets/menuBackground1.png");
	menu2 = make_shared<olc::Sprite>("Assets/menuBackground2.png");

	gameover = make_shared<olc::Sprite>("Assets/gameoverBackground.png");

	gameOver = false;

	return true;
}

bool GameManager::OnUserUpdate(float fElapsedTime)
{
	Clear(olc::BLACK);
	SetPixelMode(olc::Pixel::ALPHA);

	if (isGameStart == false)
	{
		DrawSprite(0, 0, menu1);

		if (GetMouseX() >= 90 && GetMouseX() <= 152 && GetMouseY() >= 200 && GetMouseY() <= 220)
		{
			DrawSprite(0, 0, menu2);

			if (GetMouse(0).bReleased)
			{
				isGameStart = true;
			}			
		}
	}
	else
	{

		if (gameOver == true)
		{
			DrawSprite(0, 0, gameover);

			for (int i = 0; i < objects.size(); i++)
			{
				objects.erase(objects.begin() + i);
				i--;
			}

			if (GetKey(olc::Key::R).bPressed)
			{
				OnUserCreate();
			}
			if (GetKey(olc::Key::E).bPressed)
			{
				return false;
			}
			return true;

		}
		else {
			DrawSprite(0, 0, background);

			for (int i = 0; i < objects.size(); i++)
			{
				objects[i]->move(fElapsedTime);

				if (objects[i]->isFire())
				{
					objects.push_back(objects[i]->fire());
				}

				objects[i]->draw(fElapsedTime);
				objects[i]->timeUpdate(fElapsedTime);



				for (int j = 0; j < objects.size(); j++)
				{
					if (i != j)
					{
						objects[i]->collision(objects[j]);
					}
				}

				if (objects[i]->isCreate())
				{
					objects.push_back(make_shared<Fighter>(this));
					score++;
				}

				if (objects[0]->isDead())
				{
					gameOver = true;
					break;
				}

				if (objects[i]->isDead())
				{
					objects.erase(objects.begin() + i);
					i--;
				}
				
			}
			DrawString(200, 15, to_string((int)score), olc::RED);

			
		}
	}

	return true;
}
