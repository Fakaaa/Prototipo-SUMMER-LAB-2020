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
	extern float fontPulse;
	extern Font fontType;

	extern void Initialize();
	extern void LoadFont();
	extern void Unload();
	extern void InputGamePlay();
	extern void InputMenu();
	extern void DistanceTraveled();
	extern void DoPulseFont();
	extern void Lose();
	extern void Reset();
	extern void Draw();
	extern void DrawPlayersRecordsEndGame();
	extern void DrawPlayersRecordsMenu();
}

#endif // !PLAYER

