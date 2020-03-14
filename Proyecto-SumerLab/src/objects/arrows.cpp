#include "arrows.h"

#include "player.h"

namespace Arrows
{
	Color arrayOfColors[6] = { BLACK, BLUE, WHITE, YELLOW, ORANGE, RED };
	Texture2D arrayOfArrowsColors[6];

	ARROW arrowsGame[3];
	ARROW arrowsMenu[6];
	ARROW arrowExit;

	static const int HEIGHT = 100;
	static const int WIDTH = 200;

	static int memory_random0 = 0;
	static int memory_random1 = 0;
	static int memory_random2 = 0;

	static void ReScaleAndLoad();

	void Initialize()
	{
		int randomMenuGame = 0;
		int randomMenuCredits = 0;
		int randomMenuTablePoints = 0;
		int random0Text = 0;
		int random1Text = 0;
		int random2Text = 0;

		//------------

		ReScaleAndLoad();

		//------------

		arrowsGame[0].pos.x = static_cast<float>(GetScreenWidth() / 2 - WIDTH / 2);
		arrowsGame[0].pos.y = static_cast<float>(GetScreenHeight() / 4);

		random0Text = GetRandomValue(0, 5);
		arrowsGame[0].texture = arrayOfArrowsColors[random0Text];
		arrowsGame[0].position = random0Text;

		//------------

		arrowsGame[1].pos.x = static_cast<float>(GetScreenWidth() / 2 - WIDTH / 2);
		arrowsGame[1].pos.y = static_cast<float>(GetScreenHeight() / 4 + GetScreenHeight() / 4);

		do
		{
			random1Text = GetRandomValue(0, 5);
		} while (random1Text == random0Text);
		arrowsGame[1].texture = arrayOfArrowsColors[random1Text];
		arrowsGame[1].position = random1Text;

		//------------

		arrowsGame[2].pos.x = static_cast<float>(GetScreenWidth() / 2 - WIDTH / 2);
		arrowsGame[2].pos.y = static_cast<float>(GetScreenHeight() / 4 + GetScreenHeight() / 4 + GetScreenHeight() / 4);

		do
		{
			random2Text = GetRandomValue(0, 5);
		} while (random2Text == random0Text || random2Text == random1Text);
		arrowsGame[2].texture = arrayOfArrowsColors[random2Text];
		arrowsGame[2].position = random2Text;

		//----------------------------------

		int distance = GetScreenWidth() / 7;
		int cont = 1;

		for (int i = 0; i < 6; i++)
		{
			arrowsMenu[i].body.height = HEIGHT;
			arrowsMenu[i].body.width = WIDTH;

			arrowsMenu[i].body.x = static_cast<float>((distance * cont) - WIDTH / 2);
			
			arrowsMenu[i].body.y = static_cast<float>(GetScreenHeight() - GetScreenHeight() / 3);

			arrowsMenu[i].color = arrayOfColors[i];

			arrowsMenu[i].initGame = false;

			cont++;
		}
		randomMenuGame = GetRandomValue(0, 4);
		arrowsMenu[randomMenuGame].initGame = true;
		
		do
		{
			randomMenuCredits = GetRandomValue(0, 4);
		} while (randomMenuCredits == randomMenuGame);
		
		arrowsMenu[randomMenuCredits].initCredits = true;

		do
		{
			randomMenuTablePoints = GetRandomValue(0, 4);
		} while (randomMenuTablePoints == randomMenuGame || randomMenuTablePoints == randomMenuCredits);

		arrowsMenu[randomMenuTablePoints].initTablePoints = true;

		// ---------------------------------

		arrowExit.pos.x = static_cast<float>(HEIGHT);
		arrowExit.pos.y = static_cast<float>(GetScreenHeight() - arrowExit.texture.height);
		arrowExit.exit = true;
		arrowExit.color = arrayOfColors[5];
	}

	static void ReScaleAndLoad()
	{
		Image arrows[6];
		Image button;

		arrows[0] = LoadImage("assets/arrows/arrow1.png");
		arrows[1] = LoadImage("assets/arrows/arrow2.png");
		arrows[2] = LoadImage("assets/arrows/arrow3.png");
		arrows[3] = LoadImage("assets/arrows/arrow4.png");
		arrows[4] = LoadImage("assets/arrows/arrow5.png");
		arrows[5] = LoadImage("assets/arrows/arrow6.png");
		
		button = LoadImage("assets/arrows/boton de salir.png");

		for (int i = 0; i < 6; i++)
		{
			ImageResize(&arrows[i], WIDTH, HEIGHT);
			arrayOfArrowsColors[i] = LoadTextureFromImage(arrows[i]);
		}

		ImageResize(&button, WIDTH * 2, HEIGHT * 2);
		arrowExit.texture = LoadTextureFromImage(button);

		for (int i = 0; i < 6; i++)
		{
			UnloadImage(arrows[i]);
		}
		UnloadImage(button);
	}

	void UnLoad()
	{
		for (int i = 0; i < 6; i++)
		{
			UnloadTexture(arrayOfArrowsColors[i]);
		}
	}

	void Reset()
	{
		int randomMenuGame = 0;
		int randomMenuCredits = 0;
		int randomMenuTablePoints = 0;
		int random0Text = 0;
		int random1Text = 0;
		int random2Text = 0;

		//---

		arrowsGame[0].pos.x = static_cast<float>(GetScreenWidth() / 2 - WIDTH / 2);
		arrowsGame[0].pos.y = static_cast<float>(GetScreenHeight() / 4);

		random0Text = GetRandomValue(0, 5);
		arrowsGame[0].texture = arrayOfArrowsColors[random0Text];
		arrowsGame[0].position = random0Text;

		//---

		arrowsGame[1].pos.x = static_cast<float>(GetScreenWidth() / 2 - WIDTH / 2);
		arrowsGame[1].pos.y = static_cast<float>(GetScreenHeight() / 4 + GetScreenHeight() / 4);

		do
		{
			random1Text = GetRandomValue(0, 5);
		} while (random1Text == random0Text);
		arrowsGame[1].texture = arrayOfArrowsColors[random1Text];
		arrowsGame[1].position = random1Text;

		//---

		arrowsGame[2].pos.x = static_cast<float>(GetScreenWidth() / 2 - WIDTH / 2);
		arrowsGame[2].pos.y = static_cast<float>(GetScreenHeight() / 4 + GetScreenHeight() / 4 + GetScreenHeight() / 4);

		do
		{
			random2Text = GetRandomValue(0, 5);
		} while (random2Text == random0Text || random2Text == random1Text);
		arrowsGame[2].texture = arrayOfArrowsColors[random2Text];
		arrowsGame[2].position = random2Text;

		//---

		for (int i = 0; i < 6; i++)
		{
			arrowsMenu[i].initGame = false;
			arrowsMenu[i].initCredits = false;
			arrowsMenu[i].initTablePoints = false;
		}

		randomMenuGame = GetRandomValue(0, 4);
		arrowsMenu[randomMenuGame].initGame = true;

		do
		{
			randomMenuCredits = GetRandomValue(0, 4);
		} while (randomMenuCredits == randomMenuGame);

		arrowsMenu[randomMenuCredits].initCredits = true;

		do
		{
			randomMenuTablePoints = GetRandomValue(0, 4);
		} while (randomMenuTablePoints == randomMenuGame || randomMenuTablePoints == randomMenuCredits);

		arrowsMenu[randomMenuTablePoints].initTablePoints = true;
	}

	void ChangeColor()
	{
		int random0Text = 0;
		int random1Text = 0;
		int random2Text = 0;


		while (random0Text == memory_random0)
		{
			random0Text = GetRandomValue(0, 5);
		}
		arrowsGame[0].texture = arrayOfArrowsColors[random0Text];
		arrowsGame[0].position = random0Text;

		//---

		while (random1Text == random0Text || random1Text == memory_random1)
		{
			random1Text = GetRandomValue(0, 5);
		}
		arrowsGame[1].texture = arrayOfArrowsColors[random1Text];
		arrowsGame[1].position = random1Text;

		//---

		while (random2Text == random0Text || random2Text == random1Text || random2Text == memory_random2)
		{
			random2Text = GetRandomValue(0, 5);
		}
		arrowsGame[2].texture = arrayOfArrowsColors[random2Text];
		arrowsGame[2].position = random2Text;

		//---

		memory_random0 = random0Text;
		memory_random1 = random1Text;
		memory_random2 = random2Text;
	}

	void DrawGamePlay()
	{
		DrawTexture(arrowsGame[0].texture, static_cast<int>(arrowsGame[0].pos.x), static_cast<int>(arrowsGame[0].pos.y), WHITE);
		DrawTexture(arrowsGame[1].texture, static_cast<int>(arrowsGame[1].pos.x), static_cast<int>(arrowsGame[1].pos.y), WHITE);
		DrawTexture(arrowsGame[2].texture, static_cast<int>(arrowsGame[2].pos.x), static_cast<int>(arrowsGame[2].pos.y), WHITE);
	}

	void DrawCredits_TalbePoints()
	{
		DrawTexture(arrowExit.texture, static_cast<int>(arrowExit.pos.x), static_cast<int>(arrowExit.pos.y), WHITE);
	}
	
	void DrawMenu()
	{
		float FONT = 60;

		DrawRectangleRec(arrowsMenu[0].body, arrowsMenu[0].color);
		DrawRectangleRec(arrowsMenu[1].body, arrowsMenu[1].color);
		DrawRectangleRec(arrowsMenu[2].body, arrowsMenu[2].color);
		DrawRectangleRec(arrowsMenu[3].body, arrowsMenu[3].color);
		DrawRectangleRec(arrowsMenu[4].body, arrowsMenu[4].color);
		DrawRectangleRec(arrowsMenu[5].body, arrowsMenu[5].color);


		if (arrowsMenu[0].initGame == true)
		{
			DrawTextEx(Player::fontType, "START", Vector2 { ((arrowsMenu[0].body.x + arrowsMenu[0].body.width / 2) - (MeasureText("START", static_cast<int>(70)) / 4)), arrowsMenu[0].body.y + arrowsMenu[0].body.height / 4 } , FONT, 2, BLACK);
		}
		if (arrowsMenu[1].initGame == true)
		{
			DrawTextEx(Player::fontType, "START", Vector2{ ((arrowsMenu[1].body.x + arrowsMenu[1].body.width / 2) - (MeasureText("START", static_cast<int>(70)) / 4)), arrowsMenu[1].body.y + arrowsMenu[1].body.height / 4 }, FONT, 2, BLACK);
		}
		if (arrowsMenu[2].initGame == true)
		{
			DrawTextEx(Player::fontType, "START", Vector2{ ((arrowsMenu[2].body.x + arrowsMenu[2].body.width / 2) - (MeasureText("START", static_cast<int>(70)) / 4)), arrowsMenu[2].body.y + arrowsMenu[2].body.height / 4 }, FONT, 2, BLACK);
		}
		if (arrowsMenu[3].initGame == true)
		{
			DrawTextEx(Player::fontType, "START", Vector2{ ((arrowsMenu[3].body.x + arrowsMenu[3].body.width / 2) - (MeasureText("START", static_cast<int>(70)) / 4)), arrowsMenu[3].body.y + arrowsMenu[3].body.height / 4 }, FONT, 2, BLACK);
		}
		if (arrowsMenu[4].initGame == true)
		{
			DrawTextEx(Player::fontType, "START", Vector2{ ((arrowsMenu[4].body.x + arrowsMenu[4].body.width / 2) - (MeasureText("START", static_cast<int>(70)) / 4)), arrowsMenu[4].body.y + arrowsMenu[4].body.height / 4 }, FONT, 2, BLACK);
		}
		if (arrowsMenu[5].initGame == true)
		{
			DrawTextEx(Player::fontType, "START", Vector2{ ((arrowsMenu[5].body.x + arrowsMenu[5].body.width / 2) - (MeasureText("START", static_cast<int>(70)) / 4)), arrowsMenu[5].body.y + arrowsMenu[5].body.height / 4 }, FONT, 2, BLACK);
		}



		if (arrowsMenu[0].initCredits == true)
		{
			DrawTextEx(Player::fontType, "CREDITS", Vector2{ ((arrowsMenu[0].body.x + arrowsMenu[0].body.width / 2) - (MeasureText("START", static_cast<int>(85)) / 4)), arrowsMenu[0].body.y + arrowsMenu[0].body.height / 4 }, FONT, 2, BLACK);
		}
		if (arrowsMenu[1].initCredits == true)
		{
			DrawTextEx(Player::fontType, "CREDITS", Vector2{ ((arrowsMenu[1].body.x + arrowsMenu[1].body.width / 2) - (MeasureText("START", static_cast<int>(85)) / 4)), arrowsMenu[1].body.y + arrowsMenu[1].body.height / 4 }, FONT, 2, BLACK);
		}
		if (arrowsMenu[2].initCredits == true)
		{
			DrawTextEx(Player::fontType, "CREDITS", Vector2{ ((arrowsMenu[2].body.x + arrowsMenu[2].body.width / 2) - (MeasureText("START", static_cast<int>(85)) / 4)), arrowsMenu[2].body.y + arrowsMenu[2].body.height / 4 }, FONT, 2, BLACK);
		}
		if (arrowsMenu[3].initCredits == true)
		{
			DrawTextEx(Player::fontType, "CREDITS", Vector2{ ((arrowsMenu[3].body.x + arrowsMenu[3].body.width / 2) - (MeasureText("START", static_cast<int>(85)) / 4)), arrowsMenu[3].body.y + arrowsMenu[3].body.height / 4 }, FONT, 2, BLACK);
		}
		if (arrowsMenu[4].initCredits == true)
		{
			DrawTextEx(Player::fontType, "CREDITS", Vector2{ ((arrowsMenu[4].body.x + arrowsMenu[4].body.width / 2) - (MeasureText("START", static_cast<int>(85)) / 4)), arrowsMenu[4].body.y + arrowsMenu[4].body.height / 4 }, FONT, 2, BLACK);
		}
		if (arrowsMenu[5].initCredits == true)
		{
			DrawTextEx(Player::fontType, "CREDITS", Vector2{ ((arrowsMenu[5].body.x + arrowsMenu[5].body.width / 2) - (MeasureText("START", static_cast<int>(85)) / 4)), arrowsMenu[5].body.y + arrowsMenu[5].body.height / 4 }, FONT, 2, BLACK);
		}



		if (arrowsMenu[0].initTablePoints == true)
		{
			DrawTextEx(Player::fontType, "POINTS", Vector2{ ((arrowsMenu[0].body.x + arrowsMenu[0].body.width / 2) - (MeasureText("START", static_cast<int>(70)) / 4)), arrowsMenu[0].body.y + arrowsMenu[0].body.height / 4 }, FONT, 2, BLACK);
		}
		if (arrowsMenu[1].initTablePoints == true)
		{
			DrawTextEx(Player::fontType, "POINTS", Vector2{ ((arrowsMenu[1].body.x + arrowsMenu[1].body.width / 2) - (MeasureText("START", static_cast<int>(70)) / 4)), arrowsMenu[1].body.y + arrowsMenu[1].body.height / 4 }, FONT, 2, BLACK);
		}
		if (arrowsMenu[2].initTablePoints == true)
		{
			DrawTextEx(Player::fontType, "POINTS", Vector2{ ((arrowsMenu[2].body.x + arrowsMenu[2].body.width / 2) - (MeasureText("START", static_cast<int>(70)) / 4)), arrowsMenu[2].body.y + arrowsMenu[2].body.height / 4 }, FONT, 2, BLACK);
		}
		if (arrowsMenu[3].initTablePoints == true)
		{
			DrawTextEx(Player::fontType, "POINTS", Vector2{ ((arrowsMenu[3].body.x + arrowsMenu[3].body.width / 2) - (MeasureText("START", static_cast<int>(70)) / 4)), arrowsMenu[3].body.y + arrowsMenu[3].body.height / 4 }, FONT, 2, BLACK);
		}
		if (arrowsMenu[4].initTablePoints == true)
		{
			DrawTextEx(Player::fontType, "POINTS", Vector2{ ((arrowsMenu[4].body.x + arrowsMenu[4].body.width / 2) - (MeasureText("START", static_cast<int>(70)) / 4)), arrowsMenu[4].body.y + arrowsMenu[4].body.height / 4 }, FONT, 2, BLACK);
		}
		if (arrowsMenu[5].initTablePoints == true)
		{
			DrawTextEx(Player::fontType, "POINTS", Vector2{ ((arrowsMenu[5].body.x + arrowsMenu[5].body.width / 2) - (MeasureText("START", static_cast<int>(70)) / 4)), arrowsMenu[5].body.y + arrowsMenu[5].body.height / 4 }, FONT, 2, BLACK);
		}

	}
}