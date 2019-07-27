#pragma once
#include "creep.h"

class Thor : public virtual Creep
{
public:
	ALLEGRO_BITMAP *bmp[4][THORSPRITES];
	ALLEGRO_BITMAP *bmpDeath[4][THORSPRITES];
	ALLEGRO_SAMPLE *sampleDeath[THORDEATHSAMPLES];

	Thor(ALLEGRO_BITMAP *load[4][THORSPRITES], 
		 ALLEGRO_BITMAP *load_Death[4][10],
		 ALLEGRO_BITMAP *staticBar[5],
		 ALLEGRO_SAMPLE *sDeath[THORDEATHSAMPLES],
		 double dificuldads);
	Thor();
	void creep_plot();
	void death_plot();
	
};