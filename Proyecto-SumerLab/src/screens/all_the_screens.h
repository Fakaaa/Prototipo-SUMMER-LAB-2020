#ifndef ALL_THE_SCREENS_H
#define ALL_THE_SCREENS_H

namespace Screens
{
	enum States
	{
		menu, game, endScrene
	};

	extern States state;

	extern void Initialize();
	extern void screenControler();
}

#endif // !ALL_THE_SCREENS_H
