#include "player.h"

#include "arrows.h"
#include "screens/all_the_screens.h"
#include "background/background.h"
#include "audio/audio.h"

namespace Player
{
	static float playersRecords[5];

	PLAYER player;
	Font fontType;

	bool rotation;
	
	static float FONT = 45;
	static float aux_rotation;

	static void Records();
	static void SavePlayersRecords();

	void Initialize()
	{
		rotation = false;
		aux_rotation = 0;

		playersRecords[0] = 0;
		playersRecords[2] = 0;
		playersRecords[3] = 0;
		playersRecords[4] = 0;
		playersRecords[5] = 0;

		Image submarino1;
		Image submarino2;
		Image submarino3;
		Image life;

		player.body.height = 200;
		player.body.width = 250;
		player.body.x = 50;
		player.body.y = Arrows::arrowsGame[1].texturePos.y - player.body.height / 4;

		submarino1 = LoadImage("assets/player/submarino 1.png");
		submarino2 = LoadImage("assets/player/submarino 2.png");
		submarino3 = LoadImage("assets/player/submarino 3.png");
		life = LoadImage("assets/player/vida.png");
		ImageResize(&submarino1, static_cast<int>(player.body.width + 40), static_cast<int>(player.body.height));
		ImageResize(&submarino2, static_cast<int>(player.body.width + 40), static_cast<int>(player.body.height));
		ImageResize(&submarino3, static_cast<int>(player.body.width + 40), static_cast<int>(player.body.height));
		ImageResize(&life, 140, 100);
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

		if (IsKeyPressed(KEY_ONE)) // COLOR AMARILLO
		{
			//isTeleporting = true;

			for (int i = 0; i < 3; i++)
			{
				if (Arrows::arrowsGame[i].position == 0)
				{
					player.body.y = Arrows::arrowsGame[i].texturePos.y - player.body.height / 4;
					PlaySound(Audio::movePlayer);
				}
			}			
		}
		if (IsKeyPressed(KEY_TWO)) // COLOR NARANJA
		{
			for (int i = 0; i < 3; i++)
			{
				if (Arrows::arrowsGame[i].position == 1)
				{
					player.body.y = Arrows::arrowsGame[i].texturePos.y - player.body.height / 4;
					PlaySound(Audio::movePlayer);
				}
			}
		}
		if (IsKeyPressed(KEY_THREE)) // COLOR ROJO
		{
			for (int i = 0; i < 3; i++)
			{
				if (Arrows::arrowsGame[i].position == 2)
				{
					player.body.y = Arrows::arrowsGame[i].texturePos.y - player.body.height / 4;
					PlaySound(Audio::movePlayer);
				}
			}
		}
		if (IsKeyPressed(KEY_FOUR)) // COLOR VERDE
		{
			for (int i = 0; i < 3; i++)
			{
				if (Arrows::arrowsGame[i].position == 3)
				{
					player.body.y = Arrows::arrowsGame[i].texturePos.y - player.body.height / 4;
					PlaySound(Audio::movePlayer);
				}
			}
		}
		if (IsKeyPressed(KEY_FIVE)) // COLOR AZUL
		{
			for (int i = 0; i < 3; i++)
			{
				if (Arrows::arrowsGame[i].position == 4)
				{
					player.body.y = Arrows::arrowsGame[i].texturePos.y - player.body.height / 4;
					PlaySound(Audio::movePlayer);
				}
			}
		}
		if (IsKeyPressed(KEY_SIX)) // COLOR SKYBLUE
		{
			for (int i = 0; i < 3; i++)
			{
				if (Arrows::arrowsGame[i].position == 5)
				{
					player.body.y = Arrows::arrowsGame[i].texturePos.y - player.body.height / 4;
					PlaySound(Audio::movePlayer);
				}
			}
		}

		if (IsKeyPressed(KEY_ESCAPE))
		{
			Screens::state = Screens::menu;
			Background::stopTransition = false;
			Audio::ResetSounds();
		}
	}

	void InputMenu()
	{
		if (IsKeyPressed(KEY_ONE)) // COLOR AMARILLO
		{
			if (Arrows::arrowsMenu[0].initGame == true)
			{
				Screens::state = Screens::transition;
				Audio::TransitionInitialize();
				PlaySound(Audio::clickMenu);
			}
		}
		if (IsKeyPressed(KEY_TWO)) // COLOR NARANJA
		{
			if (Arrows::arrowsMenu[1].initGame == true)
			{
				Screens::state = Screens::transition;
				Audio::TransitionInitialize();
				PlaySound(Audio::clickMenu);
			}		
		}
		if (IsKeyPressed(KEY_THREE)) // COLOR ROJO
		{
			if (Arrows::arrowsMenu[2].initGame == true)
			{
				Screens::state = Screens::transition;
				Audio::TransitionInitialize();
				PlaySound(Audio::clickMenu);
			}			
		}
		if (IsKeyPressed(KEY_FOUR)) // COLOR VERDE
		{
			if (Arrows::arrowsMenu[3].initGame == true)
			{
				Screens::state = Screens::transition;
				Audio::TransitionInitialize();
				PlaySound(Audio::clickMenu);
			}			
		}
		if (IsKeyPressed(KEY_FIVE)) // COLOR AZUL
		{
			if (Arrows::arrowsMenu[4].initGame == true)
			{
				Screens::state = Screens::transition;
				Audio::TransitionInitialize();
				PlaySound(Audio::clickMenu);
			}
		}
		if (IsKeyPressed(KEY_SIX)) // COLOR SKYBLUE
		{			
			if (Arrows::arrowsMenu[5].initGame == true)
			{
				Screens::state = Screens::transition;
				Audio::TransitionInitialize();
				PlaySound(Audio::clickMenu);
			}			
		}
	}

	void DistanceTraveled()
	{
		player.distaceRecord += GetFrameTime() * 5;
	}

	void RotationLife()
	{
		float SPEED_ROTATION = 100;

		if (rotation == true)
		{
			aux_rotation += SPEED_ROTATION * GetFrameTime();
		}
		if (aux_rotation >= 360)
		{
			rotation = false;
			aux_rotation = 0;
		}
	}

	void Lose()
	{
		if (player.lives <= 0)
		{
			Screens::state = Screens::endScrene;
			Background::stopTransition = false;
			SavePlayersRecords();
			PlaySound(Audio::loseGame);
		}
	}

	void Reset()
	{
		player.body.x = 50;
		player.body.y = Arrows::arrowsGame[1].texturePos.y - player.body.height / 4;

		player.lives = 3;
		player.distaceRecord = 0;
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
			DrawTexture(player.lifes, 100 + i * 100, 100, WHITE);
		}

		if (rotation == true)
		{
			DrawTextureEx(player.lifes, Vector2{ (100 + (player.lives + 1) * 100 + aux_rotation / 2), (100 + aux_rotation) }, aux_rotation, 1, WHITE);
		}
			   		 	  	  
		DrawTextEx(fontType, FormatText("Distancia %i", static_cast<int>(player.distaceRecord)), Vector2 { static_cast<float>(GetScreenWidth() / 2 - (60 * 2)), static_cast<float>(GetScreenHeight() / 10) },FONT,10,GOLD);

		Records();
	}

	void DrawPlayersRecordsEndGame()
	{
		DrawTextEx(fontType, FormatText("1ra posicion - %i", static_cast<int>(playersRecords[0])), Vector2{ 200, 300}, 50, 2, WHITE);
		DrawTextEx(fontType, FormatText("2da posicion - %i", static_cast<int>(playersRecords[1])), Vector2{ 200, 500}, 50, 2, WHITE);
		DrawTextEx(fontType, FormatText("3ra posicion - %i", static_cast<int>(playersRecords[2])), Vector2{ 200, 700}, 50, 2, WHITE);
		DrawTextEx(fontType, FormatText("4ta posicion - %i", static_cast<int>(playersRecords[3])), Vector2{ 200, 900}, 50, 2, WHITE);
		DrawTextEx(fontType, FormatText("5ta posicion - %i", static_cast<int>(playersRecords[4])), Vector2{ 200, 1100}, 50, 2, WHITE);
	}
	
	void DrawPlayersRecordsMenu()
	{
		DrawTextEx(fontType, FormatText("1ra posicion - %i", static_cast<int>(playersRecords[0])), Vector2{ 50, 50}, 50, 2, WHITE);
		DrawTextEx(fontType, FormatText("2da posicion - %i", static_cast<int>(playersRecords[1])), Vector2{ 50, 150}, 50, 2, WHITE);
		DrawTextEx(fontType, FormatText("3ra posicion - %i", static_cast<int>(playersRecords[2])), Vector2{ 50, 250}, 50, 2, WHITE);
		DrawTextEx(fontType, FormatText("4ta posicion - %i", static_cast<int>(playersRecords[3])), Vector2{ 50, 350}, 50, 2, WHITE);
		DrawTextEx(fontType, FormatText("5ta posicion - %i", static_cast<int>(playersRecords[4])), Vector2{ 50, 450}, 50, 2, WHITE);
	}

	// ----------------------

	static void Records()
	{
		if (player.distaceRecord < 100)
		{
			DrawTextEx(fontType, "Proximo Objetivo 100", Vector2{ static_cast<float>(GetScreenWidth() / 2 + GetScreenWidth() / 5), static_cast<float>(GetScreenHeight() / 10) }, FONT, 10, GREEN);
		}
		else if (player.distaceRecord >= 100 && player.distaceRecord < 200)
		{
			DrawTextEx(fontType, "Proximo Objetivo 200", Vector2{ static_cast<float>(GetScreenWidth() / 2 + GetScreenWidth() / 5), static_cast<float>(GetScreenHeight() / 10) }, FONT, 10, GREEN);
		}
		else if (player.distaceRecord >= 200 && player.distaceRecord < 500)
		{
			DrawTextEx(fontType, "Proximo Objetivo 500", Vector2{ static_cast<float>(GetScreenWidth() / 2 + GetScreenWidth() / 5), static_cast<float>(GetScreenHeight() / 10) }, FONT, 10, GREEN);
		}
		else if (player.distaceRecord >= 500 && player.distaceRecord < 1000)
		{
			DrawTextEx(fontType, "Proximo Objetivo 1000", Vector2{ static_cast<float>(GetScreenWidth() / 2 + GetScreenWidth() / 5), static_cast<float>(GetScreenHeight() / 10) }, FONT, 10, GREEN);
		}
		else if (player.distaceRecord >= 1000 && player.distaceRecord < 1500)
		{
			DrawTextEx(fontType, "Proximo Objetivo 1500", Vector2{ static_cast<float>(GetScreenWidth() / 2 + GetScreenWidth() / 5), static_cast<float>(GetScreenHeight() / 10) }, FONT, 10, GREEN);
		}
		else if (player.distaceRecord >= 1500 && player.distaceRecord < 2300)
		{
			DrawTextEx(fontType, "Proximo Objetivo 2300", Vector2{ static_cast<float>(GetScreenWidth() / 2 + GetScreenWidth() / 5), static_cast<float>(GetScreenHeight() / 10) }, FONT, 10, GREEN);
		}
		else if (player.distaceRecord >= 2300)
		{
			DrawTextEx(fontType, "Proximo Objetivo 3000", Vector2{ static_cast<float>(GetScreenWidth() / 2 + GetScreenWidth() / 5), static_cast<float>(GetScreenHeight() / 10) }, FONT, 10, GREEN);
		}
	}

	static void SavePlayersRecords()
	{
		float aux = 0;
		float newDat = player.distaceRecord;


		for (int i = 0; i < 5; i++)
		{
			if (newDat > playersRecords[i])
			{
				aux = playersRecords[i];

				playersRecords[i] = newDat;

				newDat = aux;
			}
		}
	}
}