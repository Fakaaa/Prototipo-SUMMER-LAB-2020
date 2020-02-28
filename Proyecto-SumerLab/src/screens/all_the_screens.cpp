#include "all_the_screens.h"

#include "objects/player.h"
#include "objects/arrows.h"
#include "objects/enemies.h"

namespace Screens
{
	States state;

	static void Menu();
	static void Game();
	static void EndScreen();

	void Initialize()
	{
		state = menu;
	}

	void screenControler()
	{
		while (!WindowShouldClose() && Player::player.inGame == true)
		{
			switch (state)
			{
			case menu:
				Menu();
				break;

			case game:
				Game();
				break;

			case endScrene:
				EndScreen();
				break;
			}
		}
	}

	static void Menu()
	{
		if (IsKeyPressed(KEY_ENTER))
		{
			state = game;
			Player::Reset();
			Enemies::Reset();
		}
		if (IsKeyPressed(KEY_ESCAPE))
		{
			Player::player.inGame = false;
		}

		BeginDrawing();
		ClearBackground(DARKBLUE);

		DrawText("Super Submarino!!", GetScreenWidth() / 3, GetScreenHeight() / 2, 70, GOLD);
		DrawText("presiona ENTER", GetScreenWidth() / 3, GetScreenHeight() / 2 + 80, 20, WHITE);

		EndDrawing();
	}

	static void Game()
	{
		Player::Input();
		Player::Lose();
		Player::DistanceTraveled();

		Enemies::Move();

		BeginDrawing();
		ClearBackground(DARKBLUE);

		Player::Draw();
		Arrows::Draw();
		Enemies::Draw();

		EndDrawing();
	}
	
	static void EndScreen()
	{
		if (IsKeyPressed(KEY_ENTER))
		{
			state = game;
			Player::Reset();
			Enemies::Reset();
		}

		BeginDrawing();
		ClearBackground(DARKBLUE);

		DrawText("PERDISTE! - Presiona ENTER para volver a intentar", GetScreenWidth() / 4, GetScreenHeight() / 2, 40, WHITE);
		DrawText(FormatText("distancia %i", static_cast<int>(Player::player.distaceRecord)), GetScreenWidth() / 2 - (45 * 2), GetScreenHeight() / 10, 45, GOLD);

		EndDrawing();
	}


}