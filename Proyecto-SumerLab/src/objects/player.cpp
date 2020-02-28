#include "player.h"

#include "arrows.h"
#include "screens/all_the_screens.h"

namespace Player
{
	PLAYER player;

	void Initialize()
	{
		Image submarino1;
		Image submarino2;
		Image submarino3;

		player.body.height = 200;
		player.body.width = 300;
		player.body.x = 50;
		player.body.y = static_cast<float>(GetScreenHeight() / 4 + GetScreenHeight() / 4);

		submarino1 = LoadImage("../res/assets/player/submarino 1.png");
		submarino2 = LoadImage("../res/assets/player/submarino 2.png");
		submarino3 = LoadImage("../res/assets/player/submarino 3.png");
		ImageResize(&submarino1, static_cast<int>(player.body.width), static_cast<int>(player.body.height));
		ImageResize(&submarino2, static_cast<int>(player.body.width), static_cast<int>(player.body.height));
		ImageResize(&submarino3, static_cast<int>(player.body.width), static_cast<int>(player.body.height));
		player.threeLives = LoadTextureFromImage(submarino1);
		player.twoLives = LoadTextureFromImage(submarino2);
		player.oneLive = LoadTextureFromImage(submarino3);

		player.inGame = true;
		player.lives = 3;
		player.distaceRecord = 0;

		UnloadImage(submarino1);
		UnloadImage(submarino2);
		UnloadImage(submarino3);
	}

	void Unload()
	{
		UnloadTexture(player.oneLive);
		UnloadTexture(player.twoLives);
		UnloadTexture(player.threeLives);
	}

	void Input()
	{
		//YELLOW = 0, ORANGE = 1, RED = 2, GREEN = 3, BLUE = 4, SKYBLUE = 5;

		if (IsKeyPressed(KEY_KP_1)) // COLOR AMARILLO
		{
			for (int i = 0; i < 3; i++)
			{
				if (Arrows::arrows[i].position == 0)
				{
					player.body.y = Arrows::arrows[i].body.y - player.body.height / 4;
				}
			}			
		}
		if (IsKeyPressed(KEY_KP_2)) // COLOR NARANJA
		{
			for (int i = 0; i < 3; i++)
			{
				if (Arrows::arrows[i].position == 1)
				{
					player.body.y = Arrows::arrows[i].body.y - player.body.height / 4;
				}
			}
		}
		if (IsKeyPressed(KEY_KP_3)) // COLOR ROJO
		{
			for (int i = 0; i < 3; i++)
			{
				if (Arrows::arrows[i].position == 2)
				{
					player.body.y = Arrows::arrows[i].body.y - player.body.height / 4;
				}
			}
		}
		if (IsKeyPressed(KEY_KP_4)) // COLOR VERDE
		{
			for (int i = 0; i < 3; i++)
			{
				if (Arrows::arrows[i].position == 3)
				{
					player.body.y = Arrows::arrows[i].body.y - player.body.height / 4;
				}
			}
		}
		if (IsKeyPressed(KEY_KP_5)) // COLOR AZUL
		{
			for (int i = 0; i < 3; i++)
			{
				if (Arrows::arrows[i].position == 4)
				{
					player.body.y = Arrows::arrows[i].body.y - player.body.height / 4;
				}
			}
		}
		if (IsKeyPressed(KEY_KP_6)) // COLOR SKYBLUE
		{
			for (int i = 0; i < 3; i++)
			{
				if (Arrows::arrows[i].position == 5)
				{
					player.body.y = Arrows::arrows[i].body.y - player.body.height / 4;
				}
			}
		}

		if (IsKeyPressed(KEY_ESCAPE))
		{
			Screens::state = Screens::menu;
		}
	}

	void DistanceTraveled()
	{
		player.distaceRecord += GetFrameTime() * 5;
	}

	void Lose()
	{
		if (player.lives <= 0)
			Screens::state = Screens::endScrene;
	}

	void Reset()
	{
		player.body.x = 50;
		player.body.y = static_cast<float>(GetScreenHeight() / 4 + GetScreenHeight() / 4);

		player.lives = 3;
		player.distaceRecord = 0;
	}

	void Draw()
	{

		if (player.lives == 3) 
		{
			DrawTexture(player.threeLives, static_cast<int>(player.body.x), static_cast<int>(player.body.y), WHITE);
		}
		else if (player.lives == 2)
		{
			DrawTexture(player.twoLives, static_cast<int>(player.body.x), static_cast<int>(player.body.y), WHITE);
		}
		else if (player.lives == 1)
		{
			DrawTexture(player.oneLive, static_cast<int>(player.body.x), static_cast<int>(player.body.y), WHITE);
		}

		//DrawText(FormatText("vidas %i", player.lives), 30, 50, 30, GOLD);
		DrawText(FormatText("distancia %i", static_cast<int>(player.distaceRecord)), GetScreenWidth() / 2 - (45 * 2), GetScreenHeight() / 10, 45, GOLD);
	}
}