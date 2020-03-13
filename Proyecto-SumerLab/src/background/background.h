#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "raylib.h"

namespace Background
{
	struct BACKGROUND
	{
		Texture2D texture;
		float y;
		float x;
	};

	extern bool stopTransition;

	extern void LoadBackground();
	extern void Unload();
	extern void DrawMenu();
	extern void DrawCredits();
	extern void DrawTransition();
	extern void DrawGamePlay();
}

#endif // !BACKGROUND_H