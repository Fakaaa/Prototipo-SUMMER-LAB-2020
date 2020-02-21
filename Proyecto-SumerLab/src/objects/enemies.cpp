#include "enemies.h"

#include "arrows.h"
#include "player.h"

namespace Enemies
{
	const int HEIGHT = 100;
	const int WIDTH = 100;

	const float SPEED = 400.0f;

	int rememberPos;

	ENEMIES enemies[3];

	static void CollisionWithPlayer();

	void Initialize()
	{
		rememberPos = 0;

		for (int i = 0; i < MAX_ENEMIES; i++)
		{
			enemies[i].body.height = HEIGHT;
			enemies[i].body.width = WIDTH;
			enemies[i].body.x = static_cast<float>(GetScreenWidth() + WIDTH);

			enemies[i].aggressive = true;
			enemies[i].collision = false;
		}

		rememberPos = GetRandomValue(0, 2);
		enemies[rememberPos].aggressive = false;

		enemies[0].body.y = 50;
		enemies[1].body.y = 200;
		enemies[2].body.y = 350;
	}

	void Move()
	{
		int random = 0;

		for (int i = 0; i < MAX_ENEMIES; i++)
		{
			enemies[i].body.x -= SPEED * GetFrameTime() + Player::player.distaceRecord / 20;
		}
		
		if (enemies[0].body.x + WIDTH <= 0)
		{
			for (int i = 0; i < MAX_ENEMIES; i++)
			{
				enemies[i].body.x = static_cast<float>(GetScreenWidth() + WIDTH);
				enemies[i].aggressive = true;
				enemies[i].collision = false;
			}

			do
			{
				random = GetRandomValue(0, 2);
			} while (random == rememberPos);

			rememberPos = random;
			enemies[rememberPos].aggressive = false;

			Arrows::ChangeColor();
		}

		CollisionWithPlayer();
	}

	void Draw()
	{
		for (int i = 0; i < MAX_ENEMIES; i++)
		{
			if (enemies[i].aggressive == true)
			{
				DrawRectangleLinesEx(enemies[i].body, 10, WHITE);
			}
		}
	}

	void Reset()
	{
		rememberPos = 0;

		for (int i = 0; i < MAX_ENEMIES; i++)
		{
			enemies[i].body.x = static_cast<float>(GetScreenWidth() + WIDTH);

			enemies[i].aggressive = true;
			enemies[i].collision = false;
		}

		rememberPos = GetRandomValue(0, 2);
		enemies[rememberPos].aggressive = false;
	}

	// ----------------------------------
	// Funciones que solo funcionan en este cpp (por el static)

	static void CollisionWithPlayer()
	{
		for (int i = 0; i < MAX_ENEMIES; i++)
		{
			if (CheckCollisionRecs(Player::player.body, enemies[i].body) && enemies[i].collision == false && enemies[i].aggressive == true)
			{
				for (int j = 0; j < MAX_ENEMIES; j++)
				{
					enemies[j].collision = true;
				}
				Player::player.lives--;
			}
		}
	}
}