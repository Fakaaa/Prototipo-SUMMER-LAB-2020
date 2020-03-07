#include "arrows.h"

#include "player.h"

namespace Arrows
{
	Color arrayOfColors[6] = { YELLOW, ORANGE, RED, GREEN, BLUE, SKYBLUE };
	Texture2D arrayOfArrowsColors[6];

	ARROW arrowsGame[3];
	//ARROW arrowMenu;

	ARROW arrowsMenu[6];

	static const int HEIGHT = 100;
	static const int WIDTH = 200;

	static int memory_random0 = 0;
	static int memory_random1 = 0;
	static int memory_random2 = 0;

	void Initialize()
	{
		int randomMenu = 0;
		int random0Text = 0;
		int random1Text = 0;
		int random2Text = 0;


		//------------

		ReScaleAndLoad();

		//------------

		arrowsGame[0].bodyTexture.height = HEIGHT;
		arrowsGame[0].bodyTexture.width = WIDTH;
		arrowsGame[0].texturePos.x = static_cast<float>(GetScreenWidth() / 2 - WIDTH / 2);
		arrowsGame[0].texturePos.y = static_cast<float>(GetScreenHeight() / 4);

		random0Text = GetRandomValue(0, 5);
		arrowsGame[0].bodyTexture = arrayOfArrowsColors[random0Text];
		arrowsGame[0].position = random0Text;

		//------------

		arrowsGame[1].bodyTexture.height = HEIGHT;
		arrowsGame[1].bodyTexture.width = WIDTH;
		arrowsGame[1].texturePos.x = static_cast<float>(GetScreenWidth() / 2 - WIDTH / 2);
		arrowsGame[1].texturePos.y = static_cast<float>(GetScreenHeight() / 4 + GetScreenHeight() / 4);

		while (random1Text == random0Text)
		{
			random1Text = GetRandomValue(0, 5);
		}
		arrowsGame[1].bodyTexture = arrayOfArrowsColors[random1Text];
		arrowsGame[1].position = random1Text;

		//------------

		arrowsGame[2].bodyTexture.height = HEIGHT;
		arrowsGame[2].bodyTexture.width = WIDTH;
		arrowsGame[2].texturePos.x = static_cast<float>(GetScreenWidth() / 2 - WIDTH / 2);
		arrowsGame[2].texturePos.y = static_cast<float>(GetScreenHeight() / 4 + GetScreenHeight() / 4 + GetScreenHeight() / 4);

		while (random2Text == random0Text || random2Text == random1Text)
		{
			random2Text = GetRandomValue(0, 5);
		}
		arrowsGame[2].bodyTexture = arrayOfArrowsColors[random2Text];
		arrowsGame[2].position = random2Text;

		//------------

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
		randomMenu = GetRandomValue(0, 5);
		arrowsMenu[randomMenu].initGame = true;

	}

	void ReScaleAndLoad()
	{
		Image arrows[6];

		arrows[0] = LoadImage("assets/arrows/arrow1.png");
		arrows[1] = LoadImage("assets/arrows/arrow2.png");
		arrows[2] = LoadImage("assets/arrows/arrow3.png");
		arrows[3] = LoadImage("assets/arrows/arrow4.png");
		arrows[4] = LoadImage("assets/arrows/arrow5.png");
		arrows[5] = LoadImage("assets/arrows/arrow6.png");

		for (int i = 0; i < 6; i++)
		{
			ImageResize(&arrows[i], WIDTH, HEIGHT);
		}

		for (int i = 0; i < 6; i++)
		{
			arrayOfArrowsColors[i] = LoadTextureFromImage(arrows[i]);
		}

		for (int i = 0; i < 6; i++)
		{
			UnloadImage(arrows[i]);
		}
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

		int random0Text = 0;
		int random1Text = 0;
		int random2Text = 0;
		int randomMenu = 0;

		//---

		arrowsGame[0].texturePos.x = static_cast<float>(GetScreenWidth() / 2 - WIDTH / 2);
		arrowsGame[0].texturePos.y = static_cast<float>(GetScreenHeight() / 4);

		random0Text = GetRandomValue(0, 5);
		arrowsGame[0].bodyTexture = arrayOfArrowsColors[random0Text];
		arrowsGame[0].position = random0Text;

		//---

		arrowsGame[1].texturePos.x = static_cast<float>(GetScreenWidth() / 2 - WIDTH / 2);
		arrowsGame[1].texturePos.y = static_cast<float>(GetScreenHeight() / 4 + GetScreenHeight() / 4);

		while (random1Text == random0Text)
		{
			random1Text = GetRandomValue(0, 5);
		}
		arrowsGame[1].bodyTexture = arrayOfArrowsColors[random1Text];
		arrowsGame[1].position = random1Text;

		//---

		arrowsGame[2].texturePos.x = static_cast<float>(GetScreenWidth() / 2 - WIDTH / 2);
		arrowsGame[2].texturePos.y = static_cast<float>(GetScreenHeight() / 4 + GetScreenHeight() / 4 + GetScreenHeight() / 4);

		while (random2Text == random0Text || random2Text == random1Text)
		{
			random2Text = GetRandomValue(0, 5);
		}
		arrowsGame[2].bodyTexture = arrayOfArrowsColors[random2Text];
		arrowsGame[2].position = random2Text;

		//---

		for (int i = 0; i < 6; i++)
		{
			arrowsMenu[i].initGame = false;
		}
		randomMenu = GetRandomValue(0, 5);
		arrowsMenu[randomMenu].initGame = true;

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
		arrowsGame[0].bodyTexture = arrayOfArrowsColors[random0Text];
		arrowsGame[0].position = random0Text;

		//---

		while (random1Text == random0Text || random1Text == memory_random1)
		{
			random1Text = GetRandomValue(0, 5);
		}
		arrowsGame[1].bodyTexture = arrayOfArrowsColors[random1Text];
		arrowsGame[1].position = random1Text;

		//---

		while (random2Text == random0Text || random2Text == random1Text || random2Text == memory_random2)
		{
			random2Text = GetRandomValue(0, 5);
		}
		arrowsGame[2].bodyTexture = arrayOfArrowsColors[random2Text];
		arrowsGame[2].position = random2Text;

		//---

		memory_random0 = random0Text;
		memory_random1 = random1Text;
		memory_random2 = random2Text;
	}

	void DrawGamePlay()
	{
		DrawTexture(arrowsGame[0].bodyTexture, static_cast<int>(arrowsGame[0].texturePos.x), static_cast<int>(arrowsGame[0].texturePos.y), WHITE);
		DrawTexture(arrowsGame[1].bodyTexture, static_cast<int>(arrowsGame[1].texturePos.x), static_cast<int>(arrowsGame[1].texturePos.y), WHITE);
		DrawTexture(arrowsGame[2].bodyTexture, static_cast<int>(arrowsGame[2].texturePos.x), static_cast<int>(arrowsGame[2].texturePos.y), WHITE);
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

	}
}