#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

namespace Player
{

	struct PLAYER
	{
		Rectangle body;
		bool inGame;
		int lives;
	};

	extern PLAYER player;

	extern void Initialize();
	extern void Input();
	extern void Draw();

}

#endif // !PLAYER

