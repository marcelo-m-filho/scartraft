#pragma once
#include "creep.h"

class Colossus : public virtual Creep
{
public:
	ALLEGRO_BITMAP *bmp[4][COLOSSUSSPRITES];
	ALLEGRO_BITMAP *bmpDeath[4][10];
	ALLEGRO_SAMPLE *sampleDeath[COLOSSUSDEATHSAMPLES];

	Colossus(ALLEGRO_BITMAP *load[4][COLOSSUSSPRITES],
			 ALLEGRO_BITMAP *load_Death[4][10],
			 ALLEGRO_BITMAP *staticBar[5], 
		     ALLEGRO_SAMPLE *sDeath[COLOSSUSDEATHSAMPLES],
			 double dificuldads);
	Colossus();
	void creep_plot();
	void death_plot();
	
};

