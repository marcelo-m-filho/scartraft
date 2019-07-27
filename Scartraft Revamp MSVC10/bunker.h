#pragma once
#include "tower.h"

class bunker:public tower
{
private:
	ALLEGRO_BITMAP *bmpBunker[6];
	ALLEGRO_BITMAP *bmpBulletHit[BITMAP_NUMBER_BULLETHIT];
    void bitmapLoad();
	ALLEGRO_TIMER *explosiontimer;

public:
	void			setBitmap(ALLEGRO_BITMAP *bmp); 
					

	void			towerPlot(int*, int*);
	void explosionPlot();
	bunker(int, int, int, ALLEGRO_BITMAP*[],ALLEGRO_BITMAP*[], ALLEGRO_BITMAP* []);
    bunker();
};