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
	};

	extern ARROW arrows[3];

	extern void Initialize();
	extern void ChangeColor();
	extern void Draw();

}

#endif // !ARROWS_H
