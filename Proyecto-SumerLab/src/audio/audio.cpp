#include "audio.h"

namespace Audio
{
	STATE state;

	Sound initGameplay;
	Sound clickMenu;
	Sound movePlayer;
	Sound loseLife;
	Sound loseGame;

	static Music menuMusic;
	static Music menuMusicOcean;
	static Music gameMusic;
	static Music bubblesMusic;

	static float time = 0;

	void Initialize()
	{
		InitAudioDevice();

		menuMusic = LoadMusicStream("assets/audio/loop musica menu.ogg");
		menuMusicOcean = LoadMusicStream("assets/audio/loop oceano menu.ogg");
		gameMusic = LoadMusicStream("assets/audio/loop musica gameplay.ogg");
		bubblesMusic = LoadMusicStream("assets/audio/burbuja real.ogg");

		initGameplay = LoadSound("assets/audio/stinger inicio gameplay.ogg");
		clickMenu = LoadSound("assets/audio/click menu.ogg");
		movePlayer = LoadSound("assets/audio/teleport.ogg");
		loseLife = LoadSound("assets/audio/chocar.ogg");
		loseGame = LoadSound("assets/audio/stinger derrota.ogg");

		SetSoundVolume(loseLife, 4.0f);

		PlayMusicStream(menuMusic);
		PlayMusicStream(menuMusicOcean);
	}

	void Unload()
	{
		UnloadMusicStream(menuMusic);
		UnloadMusicStream(menuMusicOcean);
		UnloadMusicStream(gameMusic);
		UnloadMusicStream(bubblesMusic);

		UnloadSound(initGameplay);
		UnloadSound(clickMenu);
		UnloadSound(movePlayer);
		UnloadSound(loseLife);
		UnloadSound(loseGame);

		CloseAudioDevice();
	}

	void ResetSounds()
	{
		time = 0.0f;

		SetMusicVolume(gameMusic, 0.0f);
		SetMusicVolume(menuMusic, 1.0f);
		SetMusicVolume(menuMusicOcean, 0.80f);

		StateMenuMusic(play);
		StateMenuOceanMusic(play);
	}

	void StateMenuMusic(STATE states)
	{
		switch (states)
		{
		case stop:
			StopMusicStream(menuMusic);
			break;
		case play:
			PlayMusicStream(menuMusic);
			break;
		case update:
			UpdateMusicStream(menuMusic);
			break;
		}
	}
	
	void StateMenuOceanMusic(STATE states)
	{
		switch (states)
		{
		case stop:
			StopMusicStream(menuMusicOcean);
			break;
		case play:
			PlayMusicStream(menuMusicOcean);
			break;
		case update:
			UpdateMusicStream(menuMusicOcean);
			break;
		}
	}

	void StateBubblesMusic(STATE states)
	{
		switch (states)
		{
		case stop:
			StopMusicStream(bubblesMusic);
			break;
		case play:
			PlayMusicStream(bubblesMusic);
			break;
		case update:
			UpdateMusicStream(bubblesMusic);
			break;
		}
	}

	void StateGameMusic(STATE states)
	{
		switch (states)
		{
		case stop:
			StopMusicStream(gameMusic);
			break;
		case play:
			PlayMusicStream(gameMusic);
			break;
		case update:
			UpdateMusicStream(gameMusic);
			break;
		}
	}

	void TransitionInitialize()
	{
		SetMusicVolume(gameMusic, 0.0f);
		SetMusicVolume(menuMusic, 1.0f);
		SetMusicVolume(menuMusicOcean, 0.80f);

		StateBubblesMusic(play);
	}

	void TransitionUpdate()
	{
		StateBubblesMusic(update);
		StateMenuMusic(update);
		StateMenuOceanMusic(update);

		// -----

		if (time > 0 && time <= 1)
		{
			SetMusicVolume(gameMusic, 0.20f);
			SetMusicVolume(menuMusic, 0.80f);
			SetMusicVolume(menuMusicOcean, 0.60f);
		}
		else if (time > 1 && time <= 2)
		{
			SetMusicVolume(gameMusic, 0.40f);
			SetMusicVolume(menuMusic, 0.60f);
			SetMusicVolume(menuMusicOcean, 0.40f);
		}
		else if (time > 2 && time <= 3)
		{
			SetMusicVolume(gameMusic, 0.60f);
			SetMusicVolume(menuMusic, 0.40f);
			SetMusicVolume(menuMusicOcean, 0.20f);
		}
		else if (time > 3 && time <= 4)
		{
			SetMusicVolume(gameMusic, 0.80f);
			SetMusicVolume(menuMusic, 0.20f);
			SetMusicVolume(menuMusicOcean, 0.00f);
		}
		else if (time > 4 && time <= 5)
		{
			SetMusicVolume(gameMusic, 0.80f);
			SetMusicVolume(menuMusic, 0.0f);
		}

		time += GetFrameTime();
	}
}