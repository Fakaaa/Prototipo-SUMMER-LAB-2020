#include "arrows.h"

namespace Arrows
{
	Color arrayOfColors[6] = { YELLOW, ORANGE, RED, GREEN, BLUE, SKYBLUE };

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
		int random0 = 0;
		int random1 = 0;
		int random2 = 0;
		int randomMenu = 0;

		//---

		arrowsGame[0].body.height = HEIGHT;
		arrowsGame[0].body.width = WIDTH;
		arrowsGame[0].body.x = static_cast<float>(GetScreenWidth() / 2 - WIDTH / 2);
		arrowsGame[0].body.y = static_cast<float>(GetScreenHeight() / 4);

		random0 = GetRandomValue(0, 5);
		arrowsGame[0].color = arrayOfColors[random0];
		arrowsGame[0].position = random0;

		//---

		arrowsGame[1].body.height = HEIGHT;
		arrowsGame[1].body.width = WIDTH;
		arrowsGame[1].body.x = static_cast<float>(GetScreenWidth() / 2 - WIDTH / 2);
		arrowsGame[1].body.y = static_cast<float>(GetScreenHeight() / 4 + GetScreenHeight() / 4);

		while (random1 == random0)
		{
			random1 = GetRandomValue(0, 5);
		}
		arrowsGame[1].color = arrayOfColors[random1];
		arrowsGame[1].position = random1;

		//---

		arrowsGame[2].body.height = HEIGHT;
		arrowsGame[2].body.width = WIDTH;
		arrowsGame[2].body.x = static_cast<float>(GetScreenWidth() / 2 - WIDTH / 2);
		arrowsGame[2].body.y = static_cast<float>(GetScreenHeight() / 4 + GetScreenHeight() / 4 + GetScreenHeight() / 4);

		while (random2 == random0 || random2 == random1)
		{
			random2 = GetRandomValue(0, 5);
		}
		arrowsGame[2].color = arrayOfColors[random2];
		arrowsGame[2].position = random2;

		//---

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

	void Reset()
	{
		int random0 = 0;
		int random1 = 0;
		int random2 = 0;
		int randomMenu = 0;

		//---

		arrowsGame[0].body.x = static_cast<float>(GetScreenWidth() / 2 - WIDTH / 2);
		arrowsGame[0].body.y = static_cast<float>(GetScreenHeight() / 4);

		random0 = GetRandomValue(0, 5);
		arrowsGame[0].color = arrayOfColors[random0];
		arrowsGame[0].position = random0;

		//---

		arrowsGame[1].body.x = static_cast<float>(GetScreenWidth() / 2 - WIDTH / 2);
		arrowsGame[1].body.y = static_cast<float>(GetScreenHeight() / 4 + GetScreenHeight() / 4);

		while (random1 == random0)
		{
			random1 = GetRandomValue(0, 5);
		}
		arrowsGame[1].color = arrayOfColors[random1];
		arrowsGame[1].position = random1;

		//---

		arrowsGame[2].body.x = static_cast<float>(GetScreenWidth() / 2 - WIDTH / 2);
		arrowsGame[2].body.y = static_cast<float>(GetScreenHeight() / 4 + GetScreenHeight() / 4 + GetScreenHeight() / 4);

		while (random2 == random0 || random2 == random1)
		{
			random2 = GetRandomValue(0, 5);
		}
		arrowsGame[2].color = arrayOfColors[random2];
		arrowsGame[2].position = random2;

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
		int random0 = 0;
		int random1 = 0;
		int random2 = 0;

		while (random0 == memory_random0)
		{
			random0 = GetRandomValue(0, 5);
		}
		arrowsGame[0].color = arrayOfColors[random0];
		arrowsGame[0].position = random0;

		//---

		while (random1 == random0 || random1 == memory_random1)
		{
			random1 = GetRandomValue(0, 5);
		}
		arrowsGame[1].color = arrayOfColors[random1];
		arrowsGame[1].position = random1;

		//---

		while (random2 == random0 || random2 == random1 || random2 == memory_random2)
		{
			random2 = GetRandomValue(0, 5);
		}
		arrowsGame[2].color = arrayOfColors[random2];
		arrowsGame[2].position = random2;

		memory_random0 = random0;
		memory_random1 = random1;
		memory_random2 = random2;
	}

	void DrawGamePlay()
	{
		DrawRectangleRec(arrowsGame[0].body, arrowsGame[0].color);
		DrawRectangleRec(arrowsGame[1].body, arrowsGame[1].color);
		DrawRectangleRec(arrowsGame[2].body, arrowsGame[2].color);
	}
	
	void DrawMenu()
	{
		float radius = 40;

		DrawRectangleRec(arrowsMenu[0].body, arrowsMenu[0].color);
		DrawRectangleRec(arrowsMenu[1].body, arrowsMenu[1].color);
		DrawRectangleRec(arrowsMenu[2].body, arrowsMenu[2].color);
		DrawRectangleRec(arrowsMenu[3].body, arrowsMenu[3].color);
		DrawRectangleRec(arrowsMenu[4].body, arrowsMenu[4].color);
		DrawRectangleRec(arrowsMenu[5].body, arrowsMenu[5].color);


		if (arrowsMenu[0].initGame == true)
		{

			//DrawText("START", static_cast<int>(arrowsMenu[0].body.x + WIDTH / 2), static_cast<int>(arrowsMenu[0].body.y + WIDTH), 20, WHITE);
			DrawCircleV( Vector2{ arrowsMenu[0].body.x + WIDTH / 2, arrowsMenu[0].body.y + WIDTH }, radius, GRAY);

		}
		if (arrowsMenu[1].initGame == true)
		{
			DrawCircleV(Vector2{ arrowsMenu[1].body.x + WIDTH / 2, arrowsMenu[1].body.y + WIDTH }, radius, GRAY);
		}
		if (arrowsMenu[2].initGame == true)
		{
			DrawCircleV(Vector2{ arrowsMenu[2].body.x + WIDTH / 2, arrowsMenu[2].body.y + WIDTH }, radius, GRAY);
		}
		if (arrowsMenu[3].initGame == true)
		{
			DrawCircleV(Vector2{ arrowsMenu[3].body.x + WIDTH / 2, arrowsMenu[3].body.y + WIDTH }, radius, GRAY);
		}
		if (arrowsMenu[4].initGame == true)
		{
			DrawCircleV(Vector2{ arrowsMenu[4].body.x + WIDTH / 2, arrowsMenu[4].body.y + WIDTH }, radius, GRAY);
		}
		if (arrowsMenu[5].initGame == true)
		{
			DrawCircleV(Vector2{ arrowsMenu[5].body.x + WIDTH / 2, arrowsMenu[5].body.y + WIDTH }, radius, GRAY);
		}




	}
}