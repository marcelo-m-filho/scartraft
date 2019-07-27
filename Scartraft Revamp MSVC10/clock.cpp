#include "clock.h"

Clock::Clock()
{
	seconds		= 0;
	minutes		= 0;
	hours       = 0;
	clockTicks  = 0;

	clockTimer	= al_create_timer(1);
	al_start_timer(clockTimer);
}
Clock::Clock(ALLEGRO_TIMER *InvalidClockTimer)
{
	seconds		= 0;
	minutes		= 0;
	hours       = 0;
	clockTicks  = 0;
	InvalidClockTimer =  NULL;
}

Clock Clock::operator+(const int t)
{
	Clock clock(clockTimer); 
	clock = (*this);
	if(clock.clockTicks != al_get_timer_count(this->clockTimer))
	{
		clock.seconds += t;
		if (clock.seconds >= 60) 
		{
			clock.seconds -= 60;
			clock.minutes++;
		}
		if (clock.minutes >= 60) 
		{
			clock.minutes -= 60;
			clock.hours++;
		}
		clock.clockTicks = al_get_timer_count(this->clockTimer);
	}
	
	return clock;
}

void Clock::operator=(Clock clockObj)
{
	seconds = clockObj.seconds;
	minutes = clockObj.minutes;
	hours = clockObj.hours;
	clockTicks = clockObj.clockTicks;
	clockTimer = clockObj.clockTimer;
}

string Clock::GetTime()
{
	stringstream strConcatenation;
	strConcatenation << hours << ":" << minutes << ":" << seconds;
	string time = strConcatenation.str();

	return time;
}


int Clock::GetClockTicks()
{
	return clockTicks;
}

int Clock::GetSeconds()
{
	return seconds;
}

int Clock::GetMinutes()
{
	return minutes;
}

int Clock::GetHours()
{
	return hours;
}




