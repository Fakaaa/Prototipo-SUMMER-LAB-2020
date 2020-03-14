#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

namespace Player
{
	struct PLAYER
	{
		Rectangle body;
		Texture2D lifes;
		Texture2D threeLives;
		Texture2D twoLives;
		Texture2D oneLive;
		bool inGame;
		int lives;
		float distaceRecord;
	};

	extern PLAYER player;
	extern Font fontType;
	extern bool rotation;

	extern void Initialize();
	extern void Unload();
	extern void InputGamePlay();
	extern void InputMenu();
	extern void InputOptions();
	extern void DistanceTraveled();
	extern void RotationLife();
	extern void Lose();
	extern void Reset();
	extern void Draw();
	extern void DrawPlayersRecordsEndGame();
	extern void DrawPlayersRecordsMenu();
}

#endif // !PLAYER

