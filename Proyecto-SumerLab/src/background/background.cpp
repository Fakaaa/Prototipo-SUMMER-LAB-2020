#include "background.h"

namespace Background
{
	BACKGROUND background;
	float scrollBack = 0; //Para el parallax luego
	
	void Draw()
	{
		background.posx = 0;
		background.posy = 0;

		DrawTexture(background.bg, static_cast<int>(background.posx), static_cast<int>(background.posy), WHITE);
	}

	void LoadBackground()
	{
		background.bg = LoadTexture("assets/background/bg.png");
	}
	
	void Unload()
	{
		UnloadTexture(background.bg);
	}
}
