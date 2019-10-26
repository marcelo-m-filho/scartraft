#pragma once
#include "stdafx.h"
#include "plot.h"
//class towerEngine;
#include "towerEngine.h"
#include "creepengine.h"
#include "aircraftEngine.h"
#include "soundLoader.h"
#include "aircraft.h"
#include "input.h"

class init
{
private:
	void				start();
	void				game2();
	void				mainMenu();

	bool				redraw;

	int					refreshRate;

	//ALLEGRO_EVENT_QUEUE *event_queue;
	void	deletar(){delete this;}
    ALLEGRO_EVENT_QUEUE *mouse_queue;
	ALLEGRO_SAMPLE		*musica;
	ALLEGRO_FONT        *font;
	ALLEGRO_TIMER		*timer;
	ALLEGRO_TIMER		*flaisso;
	ALLEGRO_SAMPLE		*music1;
	ALLEGRO_MOUSE_STATE		mousestate;
	ALLEGRO_KEYBOARD_STATE keyboardstate;

	

	

public:
	towerEngine		*pTowerEngine;
	creepEngine		*pCreepEngine;
	AircraftEngine	*pAircraftEngine;
	soundLoader		*pSoundLoader;
	plot			*pPlot;
	Input			*pInput;


	init();
};