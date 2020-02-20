#ifndef ENEMIES_H
#define ENEMIES_H

#include "raylib.h"

namespace Enemies
{
	struct ENEMIES
	{
		Rectangle body;
		bool aggressive; // es true si la trampa te mata, pero si es false no se tiene que dibujar
	};

	extern ENEMIES enemies[6];

	extern void Initialize();
	extern void Move();
	extern void Draw();
}

#endif // !ENEMIES_H