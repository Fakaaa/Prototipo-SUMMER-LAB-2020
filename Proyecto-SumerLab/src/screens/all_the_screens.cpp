#include "all_the_screens.h"

#include "audio/audio.h"
#include "background/background.h"
#include "objects/player.h"
#include "objects/arrows.h"
#include "objects/enemies.h"

namespace Screens
{
	States state;

	static bool start = false;
	static float time = 5;

	static void Menu();
	static void Credits();
	static void TablePoints();
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
			
			case credits:
				Credits();
				break;

			case tablePoints:
				TablePoints();
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

	// -----------------------------

	static void Menu()
	{
		Player::InputMenu();
		Player::Reset();
		Player::LoadFont();
		Enemies::Reset();

		Audio::StateMenuMusic(Audio::update);
		Audio::StateMenuOceanMusic(Audio::update);

		if (IsKeyPressed(KEY_ESCAPE))
		{
			Player::player.inGame = false;
		}

		BeginDrawing();
		ClearBackground(DARKBLUE);

		Background::DrawMenu();
		DrawTextEx(Player::fontType, "Into the Deep", Vector2{ static_cast<float>(GetScreenWidth() / 3.5), static_cast<float>(GetScreenHeight() / 3)}, 150, 10,GOLD);
		DrawText("v0.7", 30, GetScreenHeight() - 60, 30, WHITE);

		Arrows::DrawMenu();

		EndDrawing();
	}

	static void Credits()
	{
		Audio::StateMenuMusic(Audio::update);
		Audio::StateMenuOceanMusic(Audio::update);

		if (IsKeyPressed(KEY_ESCAPE))
		{
			state = menu;
		}

		BeginDrawing();
		ClearBackground(DARKBLUE);

		Background::DrawCredits();

		EndDrawing();
	}

	static void TablePoints()
	{
		Audio::StateMenuMusic(Audio::update);
		Audio::StateMenuOceanMusic(Audio::update);

		if (IsKeyPressed(KEY_ESCAPE))
		{
			state = menu;
		}

		BeginDrawing();
		ClearBackground(DARKBLUE);

		Background::DrawMenu();

		DrawTextEx(Player::fontType, "Table Points", Vector2{ static_cast<float>(GetScreenWidth() / 3), static_cast<float>(GetScreenHeight() / 10) }, 140, 10, GOLD);
		Player::DrawPlayersRecordsMenu();

		EndDrawing();
	}

	static void Transition()
	{
		if (Background::stopTransition == true)
		{
			state = game;
			Audio::StateGameMusic(Audio::play);
		}

		Audio::TransitionUpdate();

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
		Player::RotationLife();

		Audio::StateGameMusic(Audio::update);

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
		Audio::StateGameMusic(Audio::stop);
		Audio::StateMenuMusic(Audio::stop);
		Audio::StateMenuOceanMusic(Audio::stop);
		
		BeginDrawing();
		ClearBackground(DARKBLUE);

		Background::DrawGamePlay();

		Timer();
		DrawTextEx(Player::fontType, FormatText("Distancia %i", static_cast<int>(Player::player.distaceRecord)), Vector2{ static_cast<float>(GetScreenWidth() / 2 - (100 * 2)), static_cast<float>(GetScreenHeight() / 6) }, 120, 10, GOLD);
		Player::DrawPlayersRecordsEndGame();

		EndDrawing();
	}

	// ---------------------------

	static void Timer()
	{
		const int FONT = 140;

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
			Audio::ResetSounds();
		}

		// -----

		if (time > 4 && time <= 5)
		{
			DrawTextEx(Player::fontType, "5", Vector2{ static_cast<float>(GetScreenWidth() / 2),  static_cast<float>(GetScreenHeight() / 2) }, FONT, 2, RED);
		}
		else if (time > 3 && time <= 4)
		{
			DrawTextEx(Player::fontType, "4", Vector2{ static_cast<float>(GetScreenWidth() / 2),  static_cast<float>(GetScreenHeight() / 2) }, FONT, 2, RED);
		}
		else if (time > 2 && time <= 3)
		{
			DrawTextEx(Player::fontType, "3", Vector2{ static_cast<float>(GetScreenWidth() / 2),  static_cast<float>(GetScreenHeight() / 2) }, FONT, 2, RED);
		}
		else if (time > 1 && time <= 2)
		{
			DrawTextEx(Player::fontType, "2", Vector2{ static_cast<float>(GetScreenWidth() / 2),  static_cast<float>(GetScreenHeight() / 2) }, FONT, 2, RED);
		}
		else if (time > 0 && time <= 1)
		{
			DrawTextEx(Player::fontType, "1", Vector2{ static_cast<float>(GetScreenWidth() / 2),  static_cast<float>(GetScreenHeight() / 2) }, FONT, 2, RED);
		}
	}
}