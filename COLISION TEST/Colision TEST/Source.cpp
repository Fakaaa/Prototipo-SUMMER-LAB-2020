#include <iostream>
#include <time.h>
using namespace std;

//CONST & VARIABLES
const int rows = 40;
const int columns = 40;
const int minimumValueOfCenter = 15;


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
void printBoard(char matriz[][columns]);
void placeCircle(Circles &circle1, Circles &circle2);

int main()
{
	srand(time(NULL));

	placeCircle(circle1,circle2);
	printBoard(matriz);


	system("pause");
	return 0;
}

void printBoard(char matriz[][columns])
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (isPrinted == false)
			{
				matriz[i][j] = '\0';
			}	
			cout <<  matriz[i][j];
		}
		cout << endl;
		isPrinted = true;
	}
}

void placeCircle(Circles &circle1, Circles &circle2)
{
	circle1.center.x = rand() % 10 + minimumValueOfCenter;
	circle1.center.y = rand() % 10 + minimumValueOfCenter;
	circle2.center.x = rand() % 10 + minimumValueOfCenter;
	circle2.center.y = rand() % 10 + minimumValueOfCenter;
	
	matriz[circle1.center.x][circle1.center.y] = circle1.centerCh;
	matriz[circle2.center.x][circle2.center.y] = circle2.centerCh;

}

void colisionTest()
{




}