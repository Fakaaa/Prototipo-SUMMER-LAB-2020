#ifndef ENEMIES_H
#define ENEMIES_H

#include "raylib.h"

namespace Enemies
{
	struct ENEMIES
	{
		Rectangle body;
		bool aggressive;
		bool collision;
	};

	const int MAX_ENEMIES = 3;

	extern ENEMIES enemies[MAX_ENEMIES];

	extern void Initialize();
	extern void Move();
	extern void Reset();
	extern void Draw();
}

#endif // !ENEMIES_H