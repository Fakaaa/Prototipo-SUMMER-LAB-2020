#ifndef ALL_THE_SCREENS_H
#define ALL_THE_SCREENS_H

namespace Screens
{
	enum States
	{
		menu, credits, tablePoints, transition, game, endScrene
	};

	extern States state;

	extern void Initialize();
	extern void screenControler();
}

#endif // !ALL_THE_SCREENS_H
