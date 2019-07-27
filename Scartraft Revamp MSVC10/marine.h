#pragma once
#include "creep.h"

class Marine : public virtual Creep
{
private:
	

public:
	ALLEGRO_BITMAP *bmp[4][MARINESPRITES];
	ALLEGRO_BITMAP *bmpDeath[4][10];
	ALLEGRO_SAMPLE *sampleDeath[MARINEDEATHSAMPLES]; //deixar esse publico por enquanto
	

	Marine(ALLEGRO_BITMAP *load[4][MARINESPRITES],
		   ALLEGRO_BITMAP *loadDeath[4][10], 
		   ALLEGRO_BITMAP *staticBar[5], 
		   ALLEGRO_SAMPLE *sDeath[MARINEDEATHSAMPLES],
		   double dificuldads);
	Marine();
	void creep_plot();
	void death_plot();
	
};