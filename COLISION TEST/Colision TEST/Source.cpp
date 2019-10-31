#include <iostream>
#include <time.h>
#include <cmath>
#include "raylib.h"
using namespace std;

//CONSTANTES
const int heigth = 720;
const int width = 1080;

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
		//VectorDIRECTMainCicle-Mouse
			Vector2 vecMM;

	//COLLISIONS
	float hipo = 0;
	float high = 0;
	float base = 0;
	float resCollision = 0;
	float parameter = rad;
	float porcentageOfStraigth = 0;

//FUNCIONES
void drawCirclesAndLines();
void placeCircles();
void calcCollision();
void calcImpactPoint();

int main(){

	InitWindow(width,heigth, "COLLISIONS");

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);

		placeCircles();
		drawCirclesAndLines();
		calcCollision();
		calcImpactPoint();

		EndDrawing();
	}



	return 0;
}

void drawCirclesAndLines(){

	DrawCircleGradient(posx,posy,rad,SKYBLUE,WHITE);
	DrawCircleGradient(posMousex, posMousey, radMouse, WHITE, BLUE);
	DrawCircleGradient(vecMM.x, vecMM.y, radMouse - 20, BLACK, BLUE);
	DrawLine(posMousex,posMousey,posx,posy,WHITE);

}

void placeCircles(){

	posx = width / 2;
	posy = heigth / 2;
	rad = 100;

	posMousex = GetMouseX();
	posMousey = GetMouseY();

	radMouse = 50;

}

void calcCollision(){

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


	porcentageOfStraigth = hipo - rad;

}

void calcImpactPoint(){

	vecMM.x = (centerPoint.x + mousePoint.x) /2;
	vecMM.y = (centerPoint.y + mousePoint.y) /2;

	centerPoint.x = posx;
	centerPoint.y = posy;

	mousePoint.x = posMousex;
	mousePoint.y = posMousey;
 
}