#pragma once
#include "stdafx.h"
#include "tower.h"
#include "bitmapLoader.h"
#include "clock.h"
#include "Explosion.h"


class towerEngine;
class creepEngine;
class Creep;
class init;


class plot: public bitmapLoader, public Clock
{
private:
	ALLEGRO_FONT *font;
	ALLEGRO_DISPLAY *display;

	SFX tooltipFadeIn;
	SFX buttonSFX[5];
	SFX	creepOverlaySFX[5];

	int lastflag;
	
	int oldWave;

	void backgroundPlot();
	void interfacePlot();
	void doodadsPlot();
	void tooltipPlot();
	SFX menuSFX[3];



public:
	Clock clock;
	Creep *pCreep;

	
	plot();

	void createDisplay();
	void displayFlip();
	void mainPlot();
	void mainMenuPlot(int);
	void gameOutput();
	


	ALLEGRO_DISPLAY* getDisplay();
	
};