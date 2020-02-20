#include "arrows.h"

namespace Arrows
{
	Color arrayOfColors[6] = { YELLOW, ORANGE, RED, GREEN, BLUE, SKYBLUE };

	ARROW arrows[3];

	const int HEIGHT = 100;
	const int WIDTH = 200;

	int memory_random0 = 0;
	int memory_random1 = 0;
	int memory_random2 = 0;

	void Initialize()
	{
		int random0 = 0;
		int random1 = 0;
		int random2 = 0;

		//---

		arrows[0].body.height = HEIGHT;
		arrows[0].body.width = WIDTH;
		arrows[0].body.x = static_cast<float>(GetScreenWidth() / 2 - WIDTH / 2);
		arrows[0].body.y = 50;

		random0 = GetRandomValue(0, 5);
		arrows[0].color = arrayOfColors[random0];
		arrows[0].position = random0;

		//---

		arrows[1].body.height = HEIGHT;
		arrows[1].body.width = WIDTH;
		arrows[1].body.x = static_cast<float>(GetScreenWidth() / 2 - WIDTH / 2);
		arrows[1].body.y = 200;

		while (random1 == random0)
		{
			random1 = GetRandomValue(0, 5);
		}
		arrows[1].color = arrayOfColors[random1];
		arrows[1].position = random1;

		//---

		arrows[2].body.height = HEIGHT;
		arrows[2].body.width = WIDTH;
		arrows[2].body.x = static_cast<float>(GetScreenWidth() / 2 - WIDTH / 2);
		arrows[2].body.y = 350;

		while (random2 == random0 || random2 == random1)
		{
			random2 = GetRandomValue(0, 5);
		}
		arrows[2].color = arrayOfColors[random2];
		arrows[2].position = random2;
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
		arrows[0].color = arrayOfColors[random0];
		arrows[0].position = random0;

		//---

		while (random1 == random0 || random1 == memory_random1)
		{
			random1 = GetRandomValue(0, 5);
		}
		arrows[1].color = arrayOfColors[random1];
		arrows[1].position = random1;

		//---

		while (random2 == random0 || random2 == random1 || random2 == memory_random2)
		{
			random2 = GetRandomValue(0, 5);
		}
		arrows[2].color = arrayOfColors[random2];
		arrows[2].position = random2;

		memory_random0 = random0;
		memory_random1 = random1;
		memory_random2 = random2;

		//if (IsKeyPressed(KEY_SPACE))
		//{
		//	int random0 = 0;
		//	int random1 = 0;
		//	int random2 = 0;

		//	while (random0 == memory_random0)
		//	{
		//		random0 = GetRandomValue(0, 5);
		//	}
		//	arrows[0].color = arrayOfColors[random0];
		//	arrows[0].position = random0;

		//	//---

		//	while (random1 == random0 || random1 == memory_random1)
		//	{
		//		random1 = GetRandomValue(0, 5);
		//	}
		//	arrows[1].color = arrayOfColors[random1];
		//	arrows[1].position = random1;

		//	//---

		//	while (random2 == random0 || random2 == random1 || random2 == memory_random2)
		//	{
		//		random2 = GetRandomValue(0, 5);
		//	}
		//	arrows[2].color = arrayOfColors[random2];
		//	arrows[2].position = random2;

		//	memory_random0 = random0;
		//	memory_random1 = random1;
		//	memory_random2 = random2;
		//}
	}

	void Draw()
	{
		DrawRectangleRec(arrows[0].body, arrows[0].color);
		DrawRectangleRec(arrows[1].body, arrows[1].color);
		DrawRectangleRec(arrows[2].body, arrows[2].color);
	}
}