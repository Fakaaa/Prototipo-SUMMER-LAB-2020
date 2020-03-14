#include "enemies.h"

#include "arrows.h"
#include "player.h"
#include "audio/audio.h"

namespace Enemies
{
	const int HEIGHT = 250;
	const int WIDTH = 250;

	const float SPEED = 400.0f;

	static int rememberPos;
	static float frameCounter;
	static const float frameSpeed = 0.75f;

	ENEMIES enemies[3];

	Texture2D type[5];
	Texture2D typeAnim[4];

	static void CollisionWithPlayer();

	void Initialize()
	{
		Image obstacle1;
		Image obstacle2;
		Image obstacle3;
		Image obstacle4;
		Image obstacle5;
		Image obstacle1Anim;
		Image obstacle2Anim;
		Image obstacle3Anim;
		Image obstacle5Anim;

		frameCounter = 0;
		rememberPos = 0;

		for (int i = 0; i < MAX_ENEMIES; i++)
		{
			enemies[i].body.height = HEIGHT;
			enemies[i].body.width = WIDTH;
			enemies[i].body.x = static_cast<float>(GetScreenWidth() + WIDTH);

			enemies[i].aggressive = true;
			enemies[i].collision = false;
			enemies[i].numTexture = GetRandomValue(0, 4);
		}

		rememberPos = GetRandomValue(0, 2);
		enemies[rememberPos].aggressive = false;	

		enemies[0].body.y = static_cast<float>((GetScreenHeight() / 4) - 35);
		enemies[1].body.y = static_cast<float>((GetScreenHeight() / 4 + GetScreenHeight() / 4) - 45);
		enemies[2].body.y = static_cast<float>((GetScreenHeight() / 4 + GetScreenHeight() / 4 + GetScreenHeight() / 4) - 45);

		obstacle1 = LoadImage("assets/enemies/obstaculo 1.png");
		obstacle2 = LoadImage("assets/enemies/obstaculo 2.png");
		obstacle3 = LoadImage("assets/enemies/obstaculo 3.png");
		obstacle4 = LoadImage("assets/enemies/obstaculo 4.png");
		obstacle5 = LoadImage("assets/enemies/obstaculo 5.png");
		obstacle1Anim = LoadImage("assets/enemies/obstaculo 1-2.png");
		obstacle2Anim = LoadImage("assets/enemies/obstaculo 2-2.png");
		obstacle3Anim = LoadImage("assets/enemies/obstaculo 3-2.png");
		obstacle5Anim = LoadImage("assets/enemies/obstaculo 5-2.png");
		ImageResize(&obstacle1, WIDTH, HEIGHT);
		ImageResize(&obstacle2, WIDTH, HEIGHT);
		ImageResize(&obstacle3, WIDTH, HEIGHT);
		ImageResize(&obstacle4, WIDTH + 60, HEIGHT);
		ImageResize(&obstacle5, WIDTH, HEIGHT);
		ImageResize(&obstacle1Anim, WIDTH, HEIGHT);
		ImageResize(&obstacle2Anim, WIDTH, HEIGHT);
		ImageResize(&obstacle3Anim, WIDTH, HEIGHT);
		ImageResize(&obstacle5Anim, WIDTH, HEIGHT);
		type[0] = LoadTextureFromImage(obstacle1);
		type[1] = LoadTextureFromImage(obstacle2);
		type[2] = LoadTextureFromImage(obstacle3);
		type[3] = LoadTextureFromImage(obstacle4);
		type[4] = LoadTextureFromImage(obstacle5);
		typeAnim[0] = LoadTextureFromImage(obstacle1Anim);
		typeAnim[1] = LoadTextureFromImage(obstacle2Anim);
		typeAnim[2] = LoadTextureFromImage(obstacle3Anim);
		typeAnim[3] = LoadTextureFromImage(obstacle5Anim);

		UnloadImage(obstacle1);
		UnloadImage(obstacle2);
		UnloadImage(obstacle3);
		UnloadImage(obstacle4);
		UnloadImage(obstacle5);
		UnloadImage(obstacle1Anim);
		UnloadImage(obstacle2Anim);
		UnloadImage(obstacle3Anim);
		UnloadImage(obstacle5Anim);
	}

	void Unload()
	{
		for (int i = 0; i < 5; i++)
		{
			UnloadTexture(type[i]);

			if (i < 4)
			{
				UnloadTexture(typeAnim[i]);
			}
		}
	}

	void Move()
	{
		const float DIV_SPEED = 10.0f;
		int random = 0;

		for (int i = 0; i < MAX_ENEMIES; i++)
		{
			enemies[i].body.x -= (SPEED + Player::player.distaceRecord / DIV_SPEED) * GetFrameTime();
		}
		
		if (enemies[0].body.x + WIDTH <= 0)
		{
			for (int i = 0; i < MAX_ENEMIES; i++)
			{
				enemies[i].body.x = static_cast<float>(GetScreenWidth() + WIDTH);
				enemies[i].aggressive = true;
				enemies[i].collision = false;
				enemies[i].numTexture = GetRandomValue(0, 4);
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

	void Reset()
	{
		rememberPos = 0;

		for (int i = 0; i < MAX_ENEMIES; i++)
		{
			enemies[i].body.x = static_cast<float>(GetScreenWidth() + WIDTH);

			enemies[i].aggressive = true;
			enemies[i].collision = false;
			enemies[i].numTexture = GetRandomValue(0, 4);
		}

		rememberPos = GetRandomValue(0, 2);
		enemies[rememberPos].aggressive = false;
	}

	void Draw()
	{
			frameCounter += GetFrameTime();

			if (frameCounter >= frameSpeed / 2)
			{
				for (int i = 0; i < MAX_ENEMIES; i++)
				{
					if (enemies[i].aggressive == true)
					{
						DrawTexture(type[enemies[i].numTexture], static_cast<int>(enemies[i].body.x), static_cast<int>(enemies[i].body.y), WHITE);
					}
				}
				
				if (frameCounter >= frameSpeed)
				{
					frameCounter = 0;
				}
			}
			else if (frameCounter < frameSpeed / 2)
			{
				for (int i = 0; i < MAX_ENEMIES; i++)
				{
					if (enemies[i].aggressive == true)
					{
						if (enemies[i].numTexture == 3 || enemies[i].numTexture == 4)
						{
							DrawTexture(type[enemies[i].numTexture], static_cast<int>(enemies[i].body.x), static_cast<int>(enemies[i].body.y), WHITE);
						}
						else
						{
							DrawTexture(typeAnim[enemies[i].numTexture], static_cast<int>(enemies[i].body.x), static_cast<int>(enemies[i].body.y), WHITE);
						}
					}
				}
			}
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
					PlaySound(Audio::loseLife);
				}
				Player::player.lives--;
				Player::rotation = true;
			}
		}
	}
}