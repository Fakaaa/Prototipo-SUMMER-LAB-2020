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

		//YELLOW, ORANGE, RED, GREEN, BLUE, BROWN;

		if (IsKeyPressed(KEY_KP_1)) // COLOR AMARILLO
		{
			player.body.y = 50;
		}
		if (IsKeyPressed(KEY_KP_2)) // COLOR NARANJA
		{
			player.body.y = 200;
		}
		if (IsKeyPressed(KEY_KP_3)) // COLOR ROJO
		{
			player.body.y = 350;
		}
		if (IsKeyPressed(KEY_KP_4)) // COLOR VERDE
		{
			player.body.y = 50;
		}
		if (IsKeyPressed(KEY_KP_5)) // COLOR AZUL
		{
			player.body.y = 200;
		}
		if (IsKeyPressed(KEY_KP_6)) // COLOR MARRON
		{
			player.body.y = 350;
		}
	}

	void Draw()
	{
		DrawRectangleRec(player.body, BEIGE);
	}
}