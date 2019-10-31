#include <iostream>
#include <time.h>
#include <cmath>
#include "raylib.h"
using namespace std;

//CONSTANTES
const int heigth = 720;
const int width = 1080;

//VARIABLES
float posx;
float posy;
float posMousex;
float posMousey;

float rad;
float radMouse;

float hipo = 0;
float high = 0;
float base = 0;
float resCollision = 0;

//FUNCIONES
void drawCircles();
void placeCircles();
void calcCollision();

int main(){

	InitWindow(width,heigth, "COLLISIONS");

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);

		placeCircles();
		drawCircles();
		calcCollision();

		EndDrawing();
	}



	return 0;
}

void drawCircles(){

	DrawCircleGradient(posx,posy,rad,SKYBLUE,WHITE);
	DrawCircleGradient(posMousex, posMousey, radMouse, WHITE, BLUE);

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

}