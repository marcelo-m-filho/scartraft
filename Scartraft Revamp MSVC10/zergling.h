#pragma once
#include "hydralisk.h"

class Zergling : public Hydralisk
{
public:
	ALLEGRO_BITMAP *bmp[4][HYDRALISKSPRITES];
	ALLEGRO_BITMAP *bmpDeath[4][10];
	ALLEGRO_SAMPLE *sampleDeath[HYDRALISKDEATHSAMPLES];

	Zergling (ALLEGRO_BITMAP *load[4][HYDRALISKSPRITES], 
			  ALLEGRO_BITMAP *load_Death[4][10],
			  ALLEGRO_BITMAP *staticBar[5], 
			  ALLEGRO_SAMPLE *sDeath[HYDRALISKDEATHSAMPLES],
			  double dificuldads,
			  double hydraliskActualPosX, double hydraliskActualPosY,
			  double hydraliskTargetPosX, double hydraliskTargetPosY);
	Zergling();
	void creep_plot();
	void death_plot();
	
};