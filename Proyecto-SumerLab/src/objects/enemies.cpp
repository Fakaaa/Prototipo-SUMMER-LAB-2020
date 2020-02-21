#include "enemies.h"

#include "arrows.h"
#include "player.h"

namespace Enemies
{
	const int HEIGHT = 100;
	const int WIDTH = 100;

	const float SPEED = 400.0f;

	int rememberPos;

	//Para Los Enemigos
	//int randomEnemyAggressive = 0; //Es un random para seleccionar que enemigo es agresivo
	//int AggressorsOnScreen = 0; //Cantidad de enemigos en pantalla (MAX 2)
	//int iteratorForEnemyDraw = 0; //Iterador para el arreglo de enemigos en la funcion Draw(Usando el while)
	//int iteratorForEnemyMove = 0; //Iterador para el arreglo de enemigos en la funcion Move(Usando el while)

	//bool resetEnemies = false;

	ENEMIES enemies[3];

	static void CollisionWithPlayer();

	void Initialize()
	{
		rememberPos = 0;

		for (int i = 0; i < MAX_ENEMIES; i++)
		{
			enemies[i].body.height = HEIGHT;
			enemies[i].body.width = WIDTH;
			enemies[i].body.x = static_cast<float>(GetScreenWidth() + WIDTH);

			enemies[i].aggressive = true;
			enemies[i].collision = false;
		}

		rememberPos = GetRandomValue(0, 2);
		enemies[rememberPos].aggressive = false;

		enemies[0].body.y = 50;
		enemies[1].body.y = 200;
		enemies[2].body.y = 350;
		/*enemies[3].body.y = 50;
		enemies[4].body.y = 200;
		enemies[5].body.y = 350;*/
	}

	void Move()
	{
		int random = 0;

		for (int i = 0; i < MAX_ENEMIES; i++)
		{
			enemies[i].body.x -= SPEED * GetFrameTime() + Player::player.distaceRecord / 20;
		}
		
		if (enemies[0].body.x + WIDTH <= 0)
		{
			for (int i = 0; i < MAX_ENEMIES; i++)
			{
				enemies[i].body.x = static_cast<float>(GetScreenWidth() + WIDTH);
				enemies[i].aggressive = true;
				enemies[i].collision = false;
			}

			do
			{
				random = GetRandomValue(0, 2);
			} while (random == rememberPos);

			rememberPos = random;
			enemies[rememberPos].aggressive = false;

			Arrows::ChangeColor();
		}

		CollisionWithPlayer();

		/*if (enemies[0].aggressive == true)
		{
			enemies[0].body.x -= SPEED;
		}
		if (enemies[1].aggressive == true)
		{
			enemies[1].body.x -= SPEED;
		}
		if (enemies[2].aggressive == true)
		{
			enemies[2].body.x -= SPEED;
		}
		if (enemies[3].aggressive == true)
		{			
			enemies[3].body.x -= SPEED;
		}
		if (enemies[4].aggressive == true)
		{
			enemies[4].body.x -= SPEED;
		}
		if (enemies[5].aggressive == true)
		{
			enemies[5].body.x -= SPEED;
		}

		
		if (enemies[0].body.x < -100)
		{
			enemies[0].body.x = static_cast<float>(GetScreenWidth() - WIDTH);
			resetEnemies = true;
		}
		if (enemies[1].body.x < -100)
		{
			enemies[1].body.x = static_cast<float>(GetScreenWidth() - WIDTH);
			resetEnemies = true;
		}
		if (enemies[2].body.x < -100)
		{
			enemies[2].body.x = static_cast<float>(GetScreenWidth() - WIDTH);
			resetEnemies = true;
		}
		if (enemies[3].body.x < -100)
		{
			enemies[3].body.x = static_cast<float>(GetScreenWidth() - WIDTH);
			resetEnemies = true;
		}
		if (enemies[4].body.x < -100)
		{
			enemies[4].body.x = static_cast<float>(GetScreenWidth() - WIDTH);
			resetEnemies = true;
		}
		if (enemies[5].body.x < -100)
		{
			enemies[5].body.x = static_cast<float>(GetScreenWidth() - WIDTH);
			resetEnemies = true;
		}*/

		//iteratorForEnemyMove++;
		// consegui que en minimo uno solo de los carriles, una de las trampas no aparezca (siempre va a haber una trampa
		// por carril, la diferencia la hace si se dibuja o no la trampa)
		// psd. no importa que te quiten vidas por ahora o de que pierdas si te toca una de las trampas
	}

	void Draw()
	{
		for (int i = 0; i < MAX_ENEMIES; i++)
		{
			if (enemies[i].aggressive == true)
			{
				DrawRectangleLinesEx(enemies[i].body, 10, WHITE);
			}
		}

		/*randomEnemyAggressive = GetRandomValue(1, 10);

		if (AggressorsOnScreen >= 0 && AggressorsOnScreen <= 1)
		{
			if (randomEnemyAggressive >= 1 && randomEnemyAggressive <= 5)
			{
				enemies[iteratorForEnemyDraw].aggressive = true;
				AggressorsOnScreen++;
			}
			else
			{
				enemies[iteratorForEnemyDraw].aggressive = false;
			}
		}

		if (enemies[0].aggressive == true)
		{
			DrawRectangleLinesEx(enemies[0].body, 5, RED);
		}
		if (enemies[1].aggressive == true)
		{
			DrawRectangleLinesEx(enemies[1].body, 5, BLUE);
		}
		if (enemies[2].aggressive == true)
		{
			DrawRectangleLinesEx(enemies[2].body, 5, YELLOW);
		}
		if (enemies[3].aggressive == true)
		{
			DrawRectangleLinesEx(enemies[3].body, 5, VIOLET);
		}
		if (enemies[4].aggressive == true)
		{
			DrawRectangleLinesEx(enemies[4].body, 5, GREEN);
		}
		if (enemies[5].aggressive == true)
		{
			DrawRectangleLinesEx(enemies[5].body, 5, ORANGE);
		}


		if (iteratorForEnemyDraw < 6)
		{
			iteratorForEnemyDraw++;
		}

		if (IsKeyPressed(KEY_R) || resetEnemies == true)
		{
			iteratorForEnemyDraw = 0;
			AggressorsOnScreen = 0;
			enemies[0].aggressive = false;
			enemies[1].aggressive = false;
			enemies[2].aggressive = false;
			enemies[3].aggressive = false;
			enemies[4].aggressive = false;
			enemies[5].aggressive = false;

			resetEnemies = false;
		}*/

		// solo se va a dibujar la trampa que tenga true en su bool "aggressive"

			//Para TOMI de FACU
			//Si pulsas la R los enemigos se volveran a generar en otro camino 
				//(Un random de cual es agresivo)
	}

	void Reset()
	{
		rememberPos = 0;

		for (int i = 0; i < MAX_ENEMIES; i++)
		{
			enemies[i].body.x = static_cast<float>(GetScreenWidth() + WIDTH);

			enemies[i].aggressive = true;
			enemies[i].collision = false;
		}

		rememberPos = GetRandomValue(0, 2);
		enemies[rememberPos].aggressive = false;
	}

	// ----------------------------------
	// Funciones que solo funcionan en este cpp (por el static)

	static void CollisionWithPlayer()
	{
		for (int i = 0; i < MAX_ENEMIES; i++)
		{
			if (CheckCollisionRecs(Player::player.body, enemies[i].body) && enemies[i].collision == false && enemies[i].aggressive == true)
			{
				for (int j = 0; j < MAX_ENEMIES; j++)
				{
					enemies[j].collision = true;
				}
				Player::player.lives--;
			}
		}
	}
}