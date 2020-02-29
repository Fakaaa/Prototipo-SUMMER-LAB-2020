#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

namespace Player
{

	struct PLAYER
	{
		Rectangle body;
		Texture2D threeLives;
		Texture2D twoLives;
		Texture2D oneLive;
		bool inGame;
		int lives;
		float distaceRecord;
	};

	extern PLAYER player;

	extern void Initialize();
	extern void Unload();
	extern void InputGamePlay();
	extern void InputMenu();
	extern void DistanceTraveled();
	extern void Lose();
	extern void Reset();
	extern void Draw();
}

#endif // !PLAYER

