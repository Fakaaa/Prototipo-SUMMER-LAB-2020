#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

namespace Player
{

	struct PLAYER
	{
		Rectangle body;
		Texture2D texture;
		bool inGame;
		int lives;
		float distaceRecord;
	};

	extern PLAYER player;

	extern void Initialize();
	extern void Input();
	extern void DistanceTraveled();
	extern void Lose();
	extern void Reset();
	extern void Draw();
}

#endif // !PLAYER

