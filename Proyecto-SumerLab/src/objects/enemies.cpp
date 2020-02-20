#include "enemies.h"

namespace Enemies
{
	const int HEIGHT = 100;
	const int WIDTH = 100;

	extern const float SPEED = 200.0f;

	ENEMIES enemies[6];

	//static void CollisionWithPlayer();

	void Initialize()
	{
		for (int i = 0; i < 6; i++)
		{
			enemies[i].body.height = HEIGHT;
			enemies[i].body.width = WIDTH;
			enemies[i].body.x = static_cast<float>(GetScreenWidth() - WIDTH);

			enemies[i].aggressive = false;
		}

		enemies[0].body.y = 50;
		enemies[1].body.y = 200;
		enemies[2].body.y = 350;
		enemies[3].body.y = 50;
		enemies[4].body.y = 200;
		enemies[5].body.y = 350;
	}

	void Move()
	{
		// moviemiento

		// consegui que en minimo uno solo de los carriles, una de las trampas no aparezca (siempre va a haber una trampa
		// por carril, la diferencia la hace si se dibuja o no la trampa)
		// psd. no importa que te quiten vidas por ahora o de que pierdas si te toca una de las trampas
	}

	void Draw()
	{
		// dibujar

		// solo de va a dibujar la trampa que tenga true en su bool "aggressive"
	}

	// ----------------------------------
	// Funciones que solo funcionan en este cpp (por el static)

	//static void CollisionWithPlayer()
	//{
	//	// primero hace que se muevan, despues decime y veo como lo hiciste y depues haces esto
	//}
}