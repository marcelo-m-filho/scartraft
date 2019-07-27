#pragma once
#include "stdafx.h"
#include "aircraft.h"
#include "tower.h"

class Viking: public Aircraft
{
private:
	ALLEGRO_BITMAP *bmpIdle[8];
	ALLEGRO_BITMAP *bmpLeftStart[7];
	ALLEGRO_BITMAP *bmpLeftMantain[6];
	ALLEGRO_BITMAP *bmpRightStart[7];
	ALLEGRO_BITMAP *bmpRightMantain[6];
	ALLEGRO_BITMAP *bmpBullet[BULLETNUMBER];
	ALLEGRO_BITMAP *bmpExplosion[EXPLOSIONNUMBER];
	int idleFrameIterator;
	int leftStartFrameIterator;
	int leftMantainFrameIterator;
	int rightStartFrameIterator;
	int rightMantainFrameIterator;
	ALLEGRO_TIMER *frame;

	void bulletPlot();
	void activePlot();
	void morphPlot();
	
	
public:
	void aircraftPlot(int, int, bool);
	void Attack(bool);
	Viking(float posX, float posY, ALLEGRO_BITMAP* Idle[], ALLEGRO_BITMAP* LeftStart[], ALLEGRO_BITMAP* LeftMantain[], ALLEGRO_BITMAP* RightStart[], ALLEGRO_BITMAP* RightMantain[], ALLEGRO_BITMAP* pBullet[], ALLEGRO_BITMAP *pExplosion[]);
};