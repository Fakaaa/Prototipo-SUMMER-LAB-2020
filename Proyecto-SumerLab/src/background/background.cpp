#include "background.h"

namespace Background
{
	BACKGROUND backgroundGame;
	BACKGROUND backgroundMenu;
	//float scrollBack = 0; //Para el parallax luego
	
	void DrawMenu()
	{
		DrawTexture(backgroundMenu.texture, static_cast<int>(backgroundMenu.x), static_cast<int>(backgroundMenu.y), WHITE);
	}

	void DrawGamePlay()
	{
		DrawTexture(backgroundGame.texture, static_cast<int>(backgroundGame.x), static_cast<int>(backgroundGame.y), WHITE);
	}

	void LoadBackground()
	{
		Image GamePlay;
		Image Menu;

		backgroundGame.x = 0;
		backgroundGame.y = 0;
		GamePlay = LoadImage("assets/background/bg.png");
		ImageResize(&GamePlay, GetScreenWidth(), GetScreenHeight());
		backgroundGame.texture = LoadTextureFromImage(GamePlay);
		
		backgroundMenu.x = 0;
		backgroundMenu.y = 0;
		Menu = LoadImage("assets/background/BGMuelleV2.png");
		ImageResize(&Menu, GetScreenWidth(), GetScreenHeight());
		backgroundMenu.texture = LoadTextureFromImage(Menu);


		UnloadImage(GamePlay);
		UnloadImage(Menu);
	}
	
	void Unload()
	{
		UnloadTexture(backgroundGame.texture);
		UnloadTexture(backgroundMenu.texture);
	}
}
