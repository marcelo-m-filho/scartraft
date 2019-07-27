#pragma once
#include "creep.h"

class Hydralisk : public virtual Creep
{	
public:
	ALLEGRO_BITMAP *bmp[4][HYDRALISKSPRITES];
	ALLEGRO_BITMAP *bmpDeath[4][10];
	ALLEGRO_SAMPLE *sampleDeath[HYDRALISKDEATHSAMPLES];

	Hydralisk(ALLEGRO_BITMAP *load[4][HYDRALISKSPRITES], 
			  ALLEGRO_BITMAP *load_Death[4][10],
			  ALLEGRO_BITMAP *staticBar[5], 
			  ALLEGRO_SAMPLE *sDeath[HYDRALISKDEATHSAMPLES],
			  double dificuldads);
	Hydralisk();
	virtual void creep_plot();
	virtual void death_plot();	
};