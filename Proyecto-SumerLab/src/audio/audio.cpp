#include "audio.h"

namespace Audio
{
	STATE state;

	//Sound jump;
	//Sound die_sound;
	//Sound screamSkull;

	static Music menuMusic;
	static Music gameMusic;
	static Music bubblesMusic;

	static float increase = 0.0f;
	static float decrease = 1.0f;

	void Initialize()
	{
		InitAudioDevice();

		menuMusic = LoadMusicStream("assets/audio/musica menu temp.ogg");
		gameMusic = LoadMusicStream("assets/audio/musica gameplay temp.ogg");
		bubblesMusic = LoadMusicStream("assets/audio/burbuja real.ogg");

		//jump = LoadSound("assets/sounds/player_sounds/jump.ogg");

		PlayMusicStream(menuMusic);
	}

	void Unload()
	{
		UnloadMusicStream(menuMusic);
		UnloadMusicStream(gameMusic);
		UnloadMusicStream(bubblesMusic);

		CloseAudioDevice();
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

	//void StateEndMusic(STATE states)
	//{
	//	/*switch (states)
	//	{
	//	case stop:
	//		StopMusicStream(endMusic);
	//		break;
	//	case play:
	//		PlayMusicStream(endMusic);
	//		break;
	//	case update:
	//		UpdateMusicStream(endMusic);
	//		break;
	//	}*/
	//}

	//void StatePlayerMusic(STATE states)
	//{
	//	/*switch (states)
	//	{
	//	case stop:
	//		StopMusicStream(player_flames);
	//		break;
	//	case play:
	//		PlayMusicStream(player_flames);
	//		break;
	//	case update:
	//		UpdateMusicStream(player_flames);
	//		break;
	//	}*/
	//}

	void TransitionInitialize()
	{
		SetMusicVolume(gameMusic, 0.0f);
		SetMusicVolume(menuMusic, 1.0f);

		StateBubblesMusic(play);
		StateGameMusic(play);
	}

	float time = 0;

	void TransitionUpdate()
	{
		StateBubblesMusic(update);
		StateGameMusic(update);
		StateMenuMusic(update);

		// -----

		if (time > 0 && time <= 1)
		{
			SetMusicVolume(gameMusic, 0.20f);
			SetMusicVolume(menuMusic, 0.80f);
		}
		else if (time > 1 && time <= 2)
		{
			SetMusicVolume(gameMusic, 0.40f);
			SetMusicVolume(menuMusic, 0.60f);
		}
		else if (time > 2 && time <= 3)
		{
			SetMusicVolume(gameMusic, 0.60f);
			SetMusicVolume(menuMusic, 0.40f);
		}
		else if (time > 3 && time <= 4)
		{
			SetMusicVolume(gameMusic, 0.80f);
			SetMusicVolume(menuMusic, 0.20f);
		}
		else if (time > 4 && time <= 5)
		{
			SetMusicVolume(gameMusic, 1.0f);
			SetMusicVolume(menuMusic, 0.0f);
		}


		time += GetFrameTime();
	}
}