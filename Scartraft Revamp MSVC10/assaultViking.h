#pragma once
#include "tower.h"


class assaultViking: public tower
{
private:
	ALLEGRO_BITMAP *bmpViking[ASSAULTVIKINGBITMAPNUMBER];
	ALLEGRO_BITMAP *bmpVikingBuild[ASSAULT_VIKING_BUILD_BITMAP_NUMBER];
	ALLEGRO_TIMER  *buildframe;
	int BuildFrameIterator;//depois mudar pra Tower caso for criar mais torres com animações de build


public:
	void towerPlot(int*, int*);
	void explosionPlot(){}

	assaultViking(int X, int Y, ALLEGRO_BITMAP* BMP[ASSAULTVIKINGBITMAPNUMBER],ALLEGRO_BITMAP* BMPBUILD[ASSAULT_VIKING_BUILD_BITMAP_NUMBER], ALLEGRO_BITMAP* BAR[5]);

};