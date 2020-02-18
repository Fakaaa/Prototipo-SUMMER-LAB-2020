#ifndef ENEMIES_H
#define ENEMIES_H

#include "raylib.h"

namespace Enemies
{
	struct ENEMIES
	{
		Rectangle body;
		Color color;
		int type;
	};

	extern const float SPEED = 200.0f;

	extern ENEMIES enemies[6];

	extern void Initialize();
	extern void Move();
	extern void Draw();

}

#endif // !ENEMIES_H