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
		Player::InputMenu();
		Player::Reset();
		Enemies::Reset();

		if (IsKeyPressed(KEY_ESCAPE))
		{
			Player::player.inGame = false;
		}

		BeginDrawing();
		ClearBackground(DARKBLUE);

		DrawText("Into the Deep", GetScreenWidth() / 3, GetScreenHeight() / 2, 70, GOLD);
		DrawText("presione ENTER", GetScreenWidth() / 3, GetScreenHeight() / 2 + 80, 20, WHITE);
		DrawText("v0.3", 30, GetScreenHeight() - 60, 30, WHITE);

		Arrows::DrawMenu();

		EndDrawing();
	}

	static void Game()
	{
		Player::InputGamePlay();
		Player::Lose();
		Player::DistanceTraveled();

		Enemies::Move();

		BeginDrawing();
		ClearBackground(DARKBLUE);

		Player::Draw();
		Arrows::DrawGamePlay();
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
			Arrows::Reset();
		}

		BeginDrawing();
		ClearBackground(DARKBLUE);

		DrawText("HAS MUERTO! - Presiona ENTER para jugar de nuevo", GetScreenWidth() / 4, GetScreenHeight() / 2, 40, WHITE);
		DrawText(FormatText("distance %i", static_cast<int>(Player::player.distaceRecord)), GetScreenWidth() / 2 - (45 * 2), GetScreenHeight() / 10, 45, GOLD);

		EndDrawing();
	}
}