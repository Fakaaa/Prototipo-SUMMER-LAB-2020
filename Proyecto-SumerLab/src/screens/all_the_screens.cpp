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
	static void Transition();
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

			case transition:
				Transition();
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
		Player::LoadFont();
		Enemies::Reset();

		if (IsKeyPressed(KEY_ESCAPE))
		{
			Player::player.inGame = false;
		}

		BeginDrawing();
		ClearBackground(DARKBLUE);

		Background::DrawMenu();
		DrawTextEx(Player::fontType, "Into the Deep", Vector2{ static_cast<float>(GetScreenWidth() / 3), static_cast<float>(GetScreenHeight() / 3)}, 140, 10,GOLD);
		DrawText("v0.4", 30, GetScreenHeight() - 60, 30, WHITE);

		Arrows::DrawMenu();

		Player::DrawPlayersRecordsMenu();

		EndDrawing();
	}

	static void Transition()
	{
		if (Background::stopTransition == true)
		{
			state = game;
		}

		BeginDrawing();
		ClearBackground(DARKBLUE);

		Background::DrawTransition();

		EndDrawing();
	}

	static void Game()
	{
		Player::InputGamePlay();
		Player::Lose();
		Player::DistanceTraveled();
		Player::DoPulseFont();

		Enemies::Move();

		BeginDrawing();
		ClearBackground(DARKBLUE);

		Background::DrawGamePlay();
		Player::Draw();
		Arrows::DrawGamePlay();
		Enemies::Draw();

		EndDrawing();
	}
	
	static void EndScreen()
	{
		BeginDrawing();
		ClearBackground(DARKBLUE);

		Background::DrawGamePlay();

		Timer();
		DrawText(FormatText("Distancia %i", static_cast<int>(Player::player.distaceRecord)), GetScreenWidth() / 2 - (100 * 2), GetScreenHeight() / 6, 80, GOLD);
		Player::DrawPlayersRecordsEndGame();

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