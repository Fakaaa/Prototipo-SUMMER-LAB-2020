#include "raylib.h"

#include "objects/player.h"
#include "objects/arrows.h"
#include "objects/enemies.h"
#include "background/background.h"
#include "screens/all_the_screens.h"
#include "audio/audio.h"

static void Initialize();
static void UnloadAssets();

int main()
{
	Initialize();
	
	Screens::screenControler();

	UnloadAssets();

	return 0;
}

// ----------------------------

static void Initialize()
{
	InitWindow(GetScreenWidth(), GetScreenHeight(), "Into the Deep - Sumer Lab");
	HideCursor();

	ToggleFullscreen();

	SetExitKey(KEY_BACK);
	SetTargetFPS(60);

	Background::LoadBackground();
	Player::Initialize();
	Arrows::Initialize();
	Enemies::Initialize();
	Screens::Initialize();
	Audio::Initialize();
}

static void UnloadAssets()
{
	Background::Unload();
	Player::Unload();
	Arrows::UnLoad();
	Enemies::Unload();
	Audio::Unload();
	Screens::Unload();
	CloseWindow();
}