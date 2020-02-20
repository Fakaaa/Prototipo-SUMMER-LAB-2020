#include "raylib.h"

#include "objects/player.h"
#include "objects/arrows.h"
#include "objects/enemies.h"

const int SCREENWIDTH = 1600;
const int SCREENHEIGHT = 500;

static void Initialize();

int main()
{
	Initialize();

	while (!WindowShouldClose() && Player::player.inGame == true)
	{
		Player::Input();
		Arrows::ChangeColor();
		Enemies::Move();

		BeginDrawing();
		ClearBackground(BLACK);
		
		Player::Draw();
		Arrows::Draw();
		Enemies::Draw();

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
	Arrows::Initialize();
	Enemies::Initialize();
}