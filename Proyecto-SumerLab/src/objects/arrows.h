#ifndef ARROWS_H
#define ARROWS_H

#include "raylib.h"

namespace Arrows
{
	extern Color arrayOfColors[6];
	extern Texture2D arrayOfArrowsColors[6];

	struct ARROW
	{
		Texture2D texture;
		Vector2 pos;
		Rectangle body;
		Color color;
		int position;
		bool initGame;
		bool initCredits;
		bool initTablePoints;
		bool exit;
	};

	extern ARROW arrowsGame[3];
	extern ARROW arrowsMenu[6];
	extern ARROW arrowExit;

	extern void Initialize();
	extern void UnLoad();
	extern void Reset();
	extern void ChangeColor();
	extern void DrawGamePlay();
	extern void DrawCredits_TalbePoints();
	extern void DrawMenu();
}

#endif // !ARROWS_H
