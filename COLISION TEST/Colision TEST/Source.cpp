#include <iostream>
#include <time.h>
#include <cmath>
#include "raylib.h"
using namespace std;

//CONSTANTES
const int heigth = 720;
const int width = 1150;

//VARIABLES
	//CIRCLES
		//CircleMain
			float posx;
			float posy;
			float rad;
			Vector2 centerPoint;
		//CircleMouse
			float posMousex;
			float posMousey;
			float radMouse;
			Vector2 mousePoint;
		//StraihtWithinCircleAndMouse
			
		//ImpactPoint
			float posPx;
			float posPy;
			float radPoint;
		//VectorDIRECTMainCicle-Mouse
			Vector2 vecMM;

	//COLLISIONS
	float hipo = 0;
	float high = 0;
	float base = 0;
	float resCollision = 0;
	float parameter = rad;
	float porcentageOfStraigth = 0;
	bool impact = false;

//FUNCIONES
void drawCirclesAndLines();
void placeCircles();
void checkCollision();
void calcImpactPoint();
void applyCollision();

int main(){

	InitWindow(width,heigth, "COLLISIONS");

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);

		placeCircles();
		drawCirclesAndLines();
		checkCollision();
		applyCollision();
		calcImpactPoint();

		EndDrawing();
	}



	return 0;
}

void drawCirclesAndLines(){

	DrawCircleGradient(posx,posy,rad,SKYBLUE,WHITE);
	DrawCircleGradient(posx, posy, rad - 90, BLACK, WHITE);
	DrawCircleGradient(posMousex, posMousey, radMouse, WHITE, BLUE);
	DrawCircleGradient(vecMM.x, vecMM.y, radPoint, BLACK, BLUE);
	DrawLine(posMousex,posMousey,posx,posy,WHITE);

}

void placeCircles(){

	posx = width / 2;
	posy = heigth / 2;
	rad = 100;

	posMousex = GetMouseX();
	posMousey = GetMouseY();

	radMouse = 15;
	radPoint = 5;
}

void checkCollision(){

	base = (posx - posMousex);
	high = (posy - posMousey);

	hipo = sqrt((base * base) + (high * high));

	resCollision = hipo - (rad + radMouse);

	if (resCollision > 0)
	{
		DrawText("LOS CIRCULOS -NO- COLISIONAN", width / 3, heigth - 100, 25, RED);
	}
	else if (resCollision <= 0)
	{
		DrawText("LOS CIRCULOS COLISIONAN", width / 3, heigth - 100, 25, GREEN);
	}

	if (hipo / 2.1f <= rad)//(vecMM.x,vecMM.y) <= rad)
	{
		DrawText("EL PUNTO DE IMPACTO COLISIONA CON LA CIRCUNFERENCIA", width / 6, heigth - 150, 25, GREEN);
	}
	else if(hipo / 2.1f > rad)//(vecMM.x, vecMM.y) > rad)
	{
		DrawText("EL PUNTO DE IMPACTO -NO- COLISIONA CON LA CIRCUNFERENCIA", width / 6, heigth - 150, 25, RED);
	}

	porcentageOfStraigth = hipo - rad;

}

void calcImpactPoint(){

	centerPoint.x = posx;
	centerPoint.y = posy;
	mousePoint.x = posMousex;
	mousePoint.y = posMousey;

	vecMM.x = (centerPoint.x + mousePoint.x) / 2;
	vecMM.y = (centerPoint.y + mousePoint.y) / 2;

}

void applyCollision(){


	do
	{
		if (CheckCollisionCircles(vecMM, radPoint, centerPoint, rad))
		{
			DisableCursor();
			vecMM.x = (centerPoint.x + mousePoint.x);
			vecMM.y = (centerPoint.y + mousePoint.y);

			if (true)
			{
				vecMM.x = ((centerPoint.x + mousePoint.x) / 2) + 2;
				vecMM.y = ((centerPoint.y + mousePoint.y) / 2) + 2;
			}

		}
		else
		{
			EnableCursor();
			break;
		}

	} while (!CheckCollisionCircles(vecMM, radPoint, centerPoint, rad));
	

}