#ifndef AUDIO_H
#define AUDIO_H

#include "raylib.h"

namespace audio
{

	struct AUDIO
	{
		Wave audio;
	};

	extern AUDIO audio;

	extern void LoadAudio();
	extern void UnLoad();


}


#endif // !AUDIO_H

