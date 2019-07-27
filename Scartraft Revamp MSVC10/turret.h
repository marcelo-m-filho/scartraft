#pragma once
#include "tower.h"

class turret:public tower
{
  private:
	ALLEGRO_BITMAP *bmpTurret[3];
    void bitmapLoad();

public:
	void			setBitmap(ALLEGRO_BITMAP *bmp); 

	void			towerPlot(int*, int*);
	void explosionPlot(){}
	turret(int, int, int, ALLEGRO_BITMAP*[],ALLEGRO_BITMAP*[]);

};