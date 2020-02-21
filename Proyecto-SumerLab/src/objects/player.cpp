#include "player.h"

#include "arrows.h"
#include "screens/all_the_screens.h"

namespace Player
{
	PLAYER player;

	void Initialize()
	{
		player.body.height = 100;
		player.body.width = 200;
		player.body.x = 50;
		player.body.y = 200;
		//player.texture = LoadTexture("res/raw/submarino.png");

		player.inGame = true;
		player.lives = 3;
		player.distaceRecord = 0;
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
					player.body.y = Arrows::arrows[i].body.y;
				}
			}			
		}
		if (IsKeyPressed(KEY_KP_2)) // COLOR NARANJA
		{
			for (int i = 0; i < 3; i++)
			{
				if (Arrows::arrows[i].position == 1)
				{
					player.body.y = Arrows::arrows[i].body.y;
				}
			}
		}
		if (IsKeyPressed(KEY_KP_3)) // COLOR ROJO
		{
			for (int i = 0; i < 3; i++)
			{
				if (Arrows::arrows[i].position == 2)
				{
					player.body.y = Arrows::arrows[i].body.y;
				}
			}
		}
		if (IsKeyPressed(KEY_KP_4)) // COLOR VERDE
		{
			for (int i = 0; i < 3; i++)
			{
				if (Arrows::arrows[i].position == 3)
				{
					player.body.y = Arrows::arrows[i].body.y;
				}
			}
		}
		if (IsKeyPressed(KEY_KP_5)) // COLOR AZUL
		{
			for (int i = 0; i < 3; i++)
			{
				if (Arrows::arrows[i].position == 4)
				{
					player.body.y = Arrows::arrows[i].body.y;
				}
			}
		}
		if (IsKeyPressed(KEY_KP_6)) // COLOR SKYBLUE
		{
			for (int i = 0; i < 3; i++)
			{
				if (Arrows::arrows[i].position == 5)
				{
					player.body.y = Arrows::arrows[i].body.y;
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
		player.body.y = 200;

		player.lives = 3;
		player.distaceRecord = 0;
	}

	void Draw()
	{
		DrawRectangleRec(player.body, BEIGE);

		DrawText(FormatText("vidas %i", player.lives), 30, 10, 30, GOLD);
		DrawText(FormatText("distancia %i", static_cast<int>(player.distaceRecord)), GetScreenWidth() / 2 - 10, 10, 30, GOLD);
	}
}