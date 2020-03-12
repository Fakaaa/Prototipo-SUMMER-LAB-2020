#ifndef AUDIO_H
#define AUDIO_H

#include "raylib.h"

namespace Audio
{
	enum STATE
	{
		stop, play, update
	};

	extern STATE state;

	extern Sound initGameplay;
	extern Sound clickMenu;
	extern Sound movePlayer;
	extern Sound loseLife;
	extern Sound loseGame;

	extern void Initialize();
	extern void Unload();
	extern void ResetSounds();
	extern void StateMenuMusic(STATE states);
	extern void StateMenuOceanMusic(STATE states);
	extern void StateBubblesMusic(STATE states);
	extern void StateGameMusic(STATE states);

	extern void TransitionInitialize();
	extern void TransitionUpdate();
}

#endif // !AUDIO_H