#ifndef _CLOCK_H_
#define _CLOCK_H_

#include "stdafx.h"

class Clock
{
private:

	int seconds;
	int minutes;
	int hours;

	int clockTicks;
	ALLEGRO_TIMER		*clockTimer;

public:
	Clock();
	Clock(ALLEGRO_TIMER *InvalidClockTimer);
	
	string GetTime();
	int GetClockTicks();
	int GetSeconds();
	int GetMinutes();
	int GetHours();
	
	Clock operator + (const int t);
	void operator = (Clock clockObj);

};

#endif