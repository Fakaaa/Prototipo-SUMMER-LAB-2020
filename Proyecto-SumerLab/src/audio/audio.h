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

	extern void Initialize();
	extern void Unload();
	extern void StateMenuMusic(STATE states);
	extern void StateBubblesMusic(STATE states);
	extern void StateGameMusic(STATE states);
	/*extern void StateEndMusic(STATE states);
	extern void StatePlayerMusic(STATE states);*/

	extern void TransitionInitialize();
	extern void TransitionUpdate();
}

#endif // !AUDIO_H

