#ifndef ARROWS_H
#define ARROWS_H

#include "raylib.h"

namespace Arrows
{
	extern Color arrayOfColors[6];

	struct ARROW
	{
		Rectangle body;
		Color color;
		int position;
		bool initGame;
	};

	extern ARROW arrowsGame[3];
	//extern ARROW arrowMenu;

	extern ARROW arrowsMenu[6];

	extern void Initialize();
	extern void Reset();
	extern void ChangeColor();
	extern void DrawGamePlay();
	extern void DrawMenu();
}

#endif // !ARROWS_H
