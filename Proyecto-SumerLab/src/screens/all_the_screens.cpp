#include "all_the_screens.h"

#include "objects/player.h"
#include "objects/arrows.h"
#include "objects/enemies.h"
#include "background/background.h"

namespace Screens
{
	States state;

	static bool start = false;
	static float time = 5;

	static void Menu();
	static void Game();
	static void EndScreen();
	static void Timer();

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

		DrawText("Into the Deep", GetScreenWidth() / 3, GetScreenHeight() / 3, 70, GOLD);
		DrawText("v0.3.2", 30, GetScreenHeight() - 60, 30, WHITE);

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

		Background::Draw();
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

		Timer();
		DrawText(FormatText("Distancia %i", static_cast<int>(Player::player.distaceRecord)), GetScreenWidth() / 2 - (100 * 2), GetScreenHeight() / 6, 80, GOLD);

		EndDrawing();
	}

	// ---------------------------

	static void Timer()
	{
		const int FONT = 80;

		if (start == false)
		{
			start = true;
			time = 5;
		}

		time -= GetFrameTime();

		if (time <= 0)
		{
			start = false;

			state = menu;
			Player::Reset();
			Enemies::Reset();
			Arrows::Reset();
		}

		// -----

		if (time > 4 && time <= 5)
		{
			DrawText("5", GetScreenWidth() / 2, GetScreenHeight() / 2, FONT, WHITE);
		}
		else if (time > 3 && time <= 4)
		{
			DrawText("4", GetScreenWidth() / 2, GetScreenHeight() / 2, FONT, WHITE);
		}
		else if (time > 2 && time <= 3)
		{
			DrawText("3", GetScreenWidth() / 2, GetScreenHeight() / 2, FONT, WHITE);
		}
		else if (time > 1 && time <= 2)
		{
			DrawText("2", GetScreenWidth() / 2, GetScreenHeight() / 2, FONT, WHITE);
		}
		else if (time > 0 && time <= 1)
		{
			DrawText("1", GetScreenWidth() / 2, GetScreenHeight() / 2, FONT, WHITE);
		}
	}
}