#include "player.h"

#include "arrows.h"
#include "screens/all_the_screens.h"
#include "background/background.h"

namespace Player
{
	PLAYER player;
	Font fontType;

	float fontPulse;

	static void Records();

	void Initialize()
	{
		Image submarino1;
		Image submarino2;
		Image submarino3;
		Image life;

		fontPulse = 45;
		player.body.height = 200;
		player.body.width = 300;
		player.body.x = 50;
		player.body.y = Arrows::arrowsGame[1].body.y - player.body.height / 4;

		submarino1 = LoadImage("assets/player/submarino 1.png");
		submarino2 = LoadImage("assets/player/submarino 2.png");
		submarino3 = LoadImage("assets/player/submarino 3.png");
		life = LoadImage("assets/player/vida.png");
		ImageResize(&submarino1, static_cast<int>(player.body.width), static_cast<int>(player.body.height));
		ImageResize(&submarino2, static_cast<int>(player.body.width), static_cast<int>(player.body.height));
		ImageResize(&submarino3, static_cast<int>(player.body.width), static_cast<int>(player.body.height));
		ImageResize(&life, 90, 50);
		player.threeLives = LoadTextureFromImage(submarino1);
		player.twoLives = LoadTextureFromImage(submarino2);
		player.oneLive = LoadTextureFromImage(submarino3);
		player.lifes = LoadTextureFromImage(life);

		player.inGame = true;
		player.lives = 3;
		player.distaceRecord = 0;

		UnloadImage(submarino1);
		UnloadImage(submarino2);
		UnloadImage(submarino3);
		UnloadImage(life);
	}

	void LoadFont()
	{
		fontType = LoadFontEx("assets/fonts/HighVoltageRough.ttf", 140, 0, 0);
	}

	void Unload()
	{
		UnloadTexture(player.oneLive);
		UnloadTexture(player.twoLives);
		UnloadTexture(player.threeLives);
		UnloadTexture(player.lifes);
		UnloadFont(fontType);
	}

	void InputGamePlay()
	{
		//YELLOW = 0, ORANGE = 1, RED = 2, GREEN = 3, BLUE = 4, SKYBLUE = 5;

		if (IsKeyPressed(KEY_KP_1)) // COLOR AMARILLO
		{
			for (int i = 0; i < 3; i++)
			{
				if (Arrows::arrowsGame[i].position == 0)
				{
					player.body.y = Arrows::arrowsGame[i].body.y - player.body.height / 4;
				}
			}			
		}
		if (IsKeyPressed(KEY_KP_2)) // COLOR NARANJA
		{
			for (int i = 0; i < 3; i++)
			{
				if (Arrows::arrowsGame[i].position == 1)
				{
					player.body.y = Arrows::arrowsGame[i].body.y - player.body.height / 4;
				}
			}
		}
		if (IsKeyPressed(KEY_KP_3)) // COLOR ROJO
		{
			for (int i = 0; i < 3; i++)
			{
				if (Arrows::arrowsGame[i].position == 2)
				{
					player.body.y = Arrows::arrowsGame[i].body.y - player.body.height / 4;
				}
			}
		}
		if (IsKeyPressed(KEY_KP_4)) // COLOR VERDE
		{
			for (int i = 0; i < 3; i++)
			{
				if (Arrows::arrowsGame[i].position == 3)
				{
					player.body.y = Arrows::arrowsGame[i].body.y - player.body.height / 4;
				}
			}
		}
		if (IsKeyPressed(KEY_KP_5)) // COLOR AZUL
		{
			for (int i = 0; i < 3; i++)
			{
				if (Arrows::arrowsGame[i].position == 4)
				{
					player.body.y = Arrows::arrowsGame[i].body.y - player.body.height / 4;
				}
			}
		}
		if (IsKeyPressed(KEY_KP_6)) // COLOR SKYBLUE
		{
			for (int i = 0; i < 3; i++)
			{
				if (Arrows::arrowsGame[i].position == 5)
				{
					player.body.y = Arrows::arrowsGame[i].body.y - player.body.height / 4;
				}
			}
		}

		if (IsKeyPressed(KEY_ESCAPE))
		{
			Screens::state = Screens::menu;
			Background::stopTransition = false;
		}
	}

	void InputMenu()
	{
		if (IsKeyPressed(KEY_KP_1)) // COLOR AMARILLO
		{
			if (Arrows::arrowsMenu[0].initGame == true)
			{
				Screens::state = Screens::transition;
			}
		}
		if (IsKeyPressed(KEY_KP_2)) // COLOR NARANJA
		{
			if (Arrows::arrowsMenu[1].initGame == true)
			{
				Screens::state = Screens::transition;
			}		
		}
		if (IsKeyPressed(KEY_KP_3)) // COLOR ROJO
		{
			if (Arrows::arrowsMenu[2].initGame == true)
			{
				Screens::state = Screens::transition;
			}			
		}
		if (IsKeyPressed(KEY_KP_4)) // COLOR VERDE
		{
			if (Arrows::arrowsMenu[3].initGame == true)
			{
				Screens::state = Screens::transition;
			}			
		}
		if (IsKeyPressed(KEY_KP_5)) // COLOR AZUL
		{
			
			if (Arrows::arrowsMenu[4].initGame == true)
			{
				Screens::state = Screens::transition;
			}
		}
		if (IsKeyPressed(KEY_KP_6)) // COLOR SKYBLUE
		{			
			if (Arrows::arrowsMenu[5].initGame == true)
			{
				Screens::state = Screens::transition;
			}			
		}
	}

	void DistanceTraveled()
	{
		player.distaceRecord += GetFrameTime() * 5;
	}

	void Lose()
	{
		if (player.lives <= 0)
		{
			Screens::state = Screens::endScrene;
			Background::stopTransition = false;
		}
	}

	void Reset()
	{
		player.body.x = 50;
		player.body.y = Arrows::arrowsGame[1].body.y - player.body.height / 4;

		player.lives = 3;
		player.distaceRecord = 0;
	}

	void DoPulseFont()
	{
		if (fontPulse <= 45)
		{
			fontPulse += GetFrameTime() * 5;
		}

		if (fontPulse >= 65)
		{
			fontPulse -= GetFrameTime() * 5;
		}
	}

	void Draw()
	{
		if (player.lives == 3) 
		{
			DrawTexture(player.threeLives, static_cast<int>(player.body.x), static_cast<int>(player.body.y), WHITE);
		}
		else if (player.lives == 2)
		{
			DrawTexture(player.twoLives, static_cast<int>(player.body.x), static_cast<int>(player.body.y), WHITE);
		}
		else if (player.lives == 1)
		{
			DrawTexture(player.oneLive, static_cast<int>(player.body.x), static_cast<int>(player.body.y), WHITE);
		}

		for (int i = 0; i < player.lives; i++)
		{
			DrawTexture(player.lifes, 100 + i * 100, 100, RED);
		}

		DrawTextEx(fontType, FormatText("Distancia %i", static_cast<int>(player.distaceRecord)), Vector2 { static_cast<float>(GetScreenWidth() / 2 - (60 * 2)), static_cast<float>(GetScreenHeight() / 10) },fontPulse,10,GOLD);


		Records();
	}

	// ----------------------

	static void Records()
	{
		if (player.distaceRecord < 100)
		{
			DrawTextEx(fontType, "Proximo Objetivo 100", Vector2{ static_cast<float>(GetScreenWidth() / 2 + GetScreenWidth() / 5), static_cast<float>(GetScreenHeight() / 10) }, fontPulse, 10, GREEN);
		}
		else if (player.distaceRecord >= 100 && player.distaceRecord < 200)
		{
			DrawTextEx(fontType, "Proximo Objetivo 200", Vector2{ static_cast<float>(GetScreenWidth() / 2 + GetScreenWidth() / 5), static_cast<float>(GetScreenHeight() / 10) }, fontPulse, 10, GREEN);
		}
		else if (player.distaceRecord >= 200 && player.distaceRecord < 500)
		{
			DrawTextEx(fontType, "Proximo Objetivo 500", Vector2{ static_cast<float>(GetScreenWidth() / 2 + GetScreenWidth() / 5), static_cast<float>(GetScreenHeight() / 10) }, fontPulse, 10, GREEN);
		}
		else if (player.distaceRecord >= 500 && player.distaceRecord < 1000)
		{
			DrawTextEx(fontType, "Proximo Objetivo 1000", Vector2{ static_cast<float>(GetScreenWidth() / 2 + GetScreenWidth() / 5), static_cast<float>(GetScreenHeight() / 10) }, fontPulse, 10, GREEN);
		}
		else if (player.distaceRecord >= 1000 && player.distaceRecord < 1500)
		{
			DrawTextEx(fontType, "Proximo Objetivo 1500", Vector2{ static_cast<float>(GetScreenWidth() / 2 + GetScreenWidth() / 5), static_cast<float>(GetScreenHeight() / 10) }, fontPulse, 10, GREEN);
		}
		else if (player.distaceRecord >= 1500 && player.distaceRecord < 2300)
		{
			DrawTextEx(fontType, "Proximo Objetivo 2300", Vector2{ static_cast<float>(GetScreenWidth() / 2 + GetScreenWidth() / 5), static_cast<float>(GetScreenHeight() / 10) }, fontPulse, 10, GREEN);
		}
		else if (player.distaceRecord >= 2300)
		{
			DrawTextEx(fontType, "Proximo Objetivo 3000", Vector2{ static_cast<float>(GetScreenWidth() / 2 + GetScreenWidth() / 5), static_cast<float>(GetScreenHeight() / 10) }, fontPulse, 10, GREEN);
		}
	}
}