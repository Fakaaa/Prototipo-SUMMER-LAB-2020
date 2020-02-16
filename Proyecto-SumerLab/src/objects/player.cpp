#include "player.h"

namespace Player
{
	PLAYER player;

	void Initialize()
	{
		player.body.height = 100;
		player.body.width = 200;
		player.body.x = 50;
		player.body.y = 450;

		player.inGame = true;
		player.lives = 1;
	}

	void Input()
	{
		if (IsKeyPressed(KEY_A))
		{
			player.body.y = 50;
		}
		if (IsKeyPressed(KEY_S))
		{
			player.body.y = 250;
		}
		if (IsKeyPressed(KEY_D))
		{
			player.body.y = 450;
		}
		if (IsKeyPressed(KEY_F))
		{
			player.body.y = 650;
		}
		if (IsKeyPressed(KEY_G))
		{
			player.body.y = 850;
		}
	}

	void Draw()
	{

		DrawRectangleRec(player.body, YELLOW);

	}

}