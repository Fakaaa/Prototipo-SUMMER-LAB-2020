#include "player.h"

#include "arrows.h"

namespace Player
{
	PLAYER player;

	void Initialize()
	{
		player.body.height = 100;
		player.body.width = 200;
		player.body.x = 50;
		player.body.y = 200;

		player.inGame = true;
		player.lives = 1;
	}

	void Input()
	{
		/*if (IsKeyPressed(KEY_A))
		{
			player.body.y = 50;
		}
		if (IsKeyPressed(KEY_S))
		{
			player.body.y = 200;
		}
		if (IsKeyPressed(KEY_D))
		{
			player.body.y = 350;
		}*/

		//YELLOW = 0, ORANGE = 1, RED = 2, GREEN = 3, BLUE = 4, MARRON = 5;

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
		if (IsKeyPressed(KEY_KP_6)) // COLOR MARRON
		{
			for (int i = 0; i < 3; i++)
			{
				if (Arrows::arrows[i].position == 5)
				{
					player.body.y = Arrows::arrows[i].body.y;
				}
			}
		}
	}

	void Draw()
	{
		DrawRectangleRec(player.body, BEIGE);
	}
}