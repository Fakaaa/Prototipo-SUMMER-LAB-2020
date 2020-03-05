#include "background.h"

namespace Background
{
	BACKGROUND backgroundGame;
	BACKGROUND backgroundMenu;
	BACKGROUND backgroundBubbles;

	bool stopTransition = false;

	static float scrolling_menuBack;
	static float scrolling_gameBack;
	static float scrolling_bubbles;

	static void MoveTransitionsBackgrounds();

	void LoadBackground()
	{
		scrolling_menuBack = 0.0f;
		scrolling_gameBack = 0.0f;
		scrolling_bubbles = 0.0f;

		Image gamePlay;
		Image menu;
		Image bubbles;

		backgroundGame.x = 0;
		backgroundGame.y = 0;
		gamePlay = LoadImage("assets/background/bg.png");
		ImageResize(&gamePlay, GetScreenWidth(), GetScreenHeight());
		backgroundGame.texture = LoadTextureFromImage(gamePlay);
		
		backgroundMenu.x = 0;
		backgroundMenu.y = 0;
		menu = LoadImage("assets/background/BGMuelleV2.png");
		ImageResize(&menu, GetScreenWidth(), GetScreenHeight());
		backgroundMenu.texture = LoadTextureFromImage(menu);
		
		backgroundBubbles.x = 0;
		backgroundBubbles.y = 0;
		bubbles = LoadImage("assets/background/burbujas.png");
		ImageResize(&bubbles, GetScreenWidth(), GetScreenHeight());
		backgroundBubbles.texture = LoadTextureFromImage(bubbles);


		UnloadImage(gamePlay);
		UnloadImage(menu);
		UnloadImage(bubbles);
	}

	void DrawMenu()
	{
		scrolling_menuBack = 0.0f;
		scrolling_gameBack = 0.0f;
		scrolling_bubbles = 0.0f;

		DrawTextureV(backgroundMenu.texture, Vector2{ backgroundMenu.x, backgroundMenu.y }, WHITE);
	}

	void DrawTransition()
	{
		MoveTransitionsBackgrounds();

		DrawTextureV(backgroundMenu.texture, Vector2{ backgroundMenu.x, scrolling_menuBack }, WHITE);

		DrawTextureV(backgroundGame.texture, Vector2{ backgroundGame.x, backgroundGame.texture.height + scrolling_gameBack }, WHITE);

		DrawTextureV(backgroundBubbles.texture, Vector2{ backgroundBubbles.x, backgroundBubbles.texture.height + scrolling_bubbles }, WHITE);
		DrawTextureV(backgroundBubbles.texture, Vector2{ backgroundBubbles.x, backgroundBubbles.texture.height + backgroundBubbles.texture.height + scrolling_bubbles }, WHITE);
	}

	void DrawGamePlay()
	{
		DrawTextureV(backgroundGame.texture, Vector2{ backgroundGame.x, backgroundGame.y }, WHITE);
	}

	
	void Unload()
	{
		UnloadTexture(backgroundGame.texture);
		UnloadTexture(backgroundMenu.texture);
		//UnloadTexture(backgroundTrans.texture);
		UnloadTexture(backgroundBubbles.texture);
	}

	// -------------------------------------------

	static void MoveTransitionsBackgrounds()
	{
		float SPEED_BACKS = 180;
		float SPEED_BUBBLES = SPEED_BACKS * 3;

		scrolling_bubbles -= SPEED_BUBBLES * GetFrameTime();

		if ((backgroundMenu.texture.height * 2) - scrolling_menuBack > 0)
		{
			scrolling_menuBack -= SPEED_BACKS * GetFrameTime();
		}
		if (backgroundGame.texture.height + scrolling_gameBack < backgroundGame.y)
		{
			stopTransition = true;
		}
		else
		{
			scrolling_gameBack -= SPEED_BACKS * GetFrameTime();
		}
	}
}
