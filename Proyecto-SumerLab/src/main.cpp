#include "raylib.h"

#include "objects/player.h"

const int SCREENWIDTH = 1600;
const int SCREENHEIGHT = 500;

static void Initialize();

int main()
{
	Initialize();

	while (!WindowShouldClose() && Player::player.inGame == true)
	{
		Player::Input();
		
		BeginDrawing();
		ClearBackground(BLACK);
		
		Player::Draw();

		EndDrawing();
	}
	return 0;
}

static void Initialize()
{
	InitWindow(SCREENWIDTH, SCREENHEIGHT, "Super Submarino!! - Sumer Lab");
	HideCursor();

	SetExitKey(KEY_BACK);
	SetTargetFPS(60);

	Player::Initialize();
}