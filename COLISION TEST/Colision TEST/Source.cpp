#include <iostream>
#include <time.h>
#include <cmath>
#include "raylib.h"
using namespace std;

//CONST & VARIABLES
const int rows = 40;
const int columns = 40;
const int minimumValueOfCenter = 105;
int hipotenus = 0;
int catet1 = 0;
int catet2 = 0;
int colision = 0;
bool areColliding = false;

//STUCTS

struct Pos
{
	int x;
	int y;
};

struct Circles
{
	Pos center;
	int rad;
	char centerCh = '.';
};

char matriz[rows][columns];
Circles circle1;
Circles circle2;
bool isPrinted = false;


//FUNCTIONS
void placeCircle(Circles &circle1, Circles &circle2);
void colisionTest(Circles &circle1, Circles &circle2, int &colision, int &hipotenus, int &catet1, int &catet2);

int main()
{
	srand(time(NULL));
	InitWindow(800,460,"FACUNDO");
	placeCircle(circle1,circle2);
	while(!WindowShouldClose())
	{
		colisionTest(circle1, circle2, colision,hipotenus,catet1,catet2);
		BeginDrawing();
		ClearBackground(WHITE);
		DrawCircle(circle1.center.x, circle1.center.y,circle1.rad,GREEN);
		DrawCircle(circle2.center.x, circle2.center.y, circle2.rad, RED);
		EndDrawing();
	}


	return 0;
}

void placeCircle(Circles &circle1, Circles &circle2)
{
	circle1.center.x = rand() % 200 + minimumValueOfCenter;
	circle1.center.y = rand() % 200 + minimumValueOfCenter;
	circle2.center.x = rand() % 200 + minimumValueOfCenter;
	circle2.center.y = rand() % 200 + minimumValueOfCenter;

	circle1.rad = rand() % 20+ 40;
	circle2.rad = rand() % 20 + 40;
}

void colisionTest(Circles &circle1, Circles &circle2, int &colision, int &hipotenus, int &catet1, int &catet2)
{

	catet1 = circle1.center.x - circle2.center.x;
	catet2 = circle1.center.y - circle2.center.y;

	hipotenus = sqrt((catet1 * catet1) + (catet2 * catet2));

	colision = hipotenus - (circle1.rad + circle2.rad);

	if (colision <= 0)
	{
		areColliding = true;
	}
	else if (colision > 0)
	{
		areColliding = false;
	}

	if (areColliding == true)
	{
		DrawText("LAS CIRCUNFERENCIAS ESTAN COLISIONANDO", 100, 435, 25, GREEN);
	}
	else if(areColliding == false)
	{
		DrawText("LAS CIRCUNFERENCIAS NO ESTAN COLISIONANDO", 100, 435, 25, RED);
	}
}