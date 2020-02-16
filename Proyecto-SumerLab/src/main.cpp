#include "raylib.h"

using namespace std;

const int SCREENWIDTH = 600;
const int SCREENHEIGHT = 600;

int main()
{
	InitWindow(SCREENWIDTH, SCREENHEIGHT, "Flappy Flame - Tomas Aquistapace");
	HideCursor();

	SetExitKey(KEY_BACK);
	SetTargetFPS(60);



	BeginDrawing();
	ClearBackground(BLACK);



	EndDrawing();
}