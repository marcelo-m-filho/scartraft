#pragma once
#include "tower.h"

class siegetank:public tower
{
private:
	ALLEGRO_BITMAP *bmpSiege[7];
	ALLEGRO_BITMAP *bmpExplosion[EXPLOSIONNUMBER];
    void bitmapLoad();
	ALLEGRO_TIMER *explosiontimer;

public:
	void			setBitmp(ALLEGRO_BITMAP *bmp); 

	void			towerPlot(int*, int*);
	void explosionPlot();
	siegetank(int, int, int, ALLEGRO_BITMAP*[],ALLEGRO_BITMAP*[],ALLEGRO_BITMAP*[]);

};