#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "raylib.h"

namespace Background
{
	struct BACKGROUND
	{
		Texture2D bg;
		float posy;
		float posx;
	};

	extern void Draw();
	extern void LoadBackground();
	extern void Unload();
}

#endif // !BACKGROUND_H