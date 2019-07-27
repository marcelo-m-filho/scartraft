#pragma once
#include "creep.h"

class VoidRay : public virtual Creep
{
public:
	ALLEGRO_BITMAP *bmp[4][VOIDRAYSPRITES];
	ALLEGRO_BITMAP *bmpDeath[4][10];
	ALLEGRO_SAMPLE *sampleDeath[VOIDRAYDEATHSAMPLES];

	VoidRay(ALLEGRO_BITMAP *load[4][VOIDRAYSPRITES], 
		    ALLEGRO_BITMAP *load_Death[4][10],
			ALLEGRO_BITMAP *staticBar[5],
		    ALLEGRO_SAMPLE *sDeath[VOIDRAYDEATHSAMPLES],
			double dificuldads);
	VoidRay();
	void creep_plot();
	void death_plot();
	
};