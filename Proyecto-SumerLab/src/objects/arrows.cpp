#include "arrows.h"

namespace Arrows
{
	Color arrayOfColors[6] = { YELLOW, ORANGE, RED, GREEN, BLUE, SKYBLUE };

	ARROW arrowsGame[3];
	ARROW arrowMenu;

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
		int random3 = 0;

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

		arrowMenu.body.height = HEIGHT;
		arrowMenu.body.width = WIDTH;
		arrowMenu.body.x = static_cast<float>(GetScreenWidth() / 2 - WIDTH / 2);
		arrowMenu.body.y = static_cast<float>(GetScreenHeight() - GetScreenHeight() / 3);

		random3 = GetRandomValue(0, 5);
		arrowMenu.color = arrayOfColors[random3];
		arrowMenu.position = random3;
	}

	void Reset()
	{
		int random0 = 0;
		int random1 = 0;
		int random2 = 0;
		int random3 = 0;

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

		arrowMenu.body.x = static_cast<float>(GetScreenWidth() / 2 - WIDTH / 2);
		arrowMenu.body.y = static_cast<float>(GetScreenHeight() - GetScreenHeight() / 3);

		random3 = GetRandomValue(0, 5);
		arrowMenu.color = arrayOfColors[random3];
		arrowMenu.position = random3;
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
		DrawRectangleRec(arrowMenu.body, arrowMenu.color);
	}
}