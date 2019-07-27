#pragma once
#include "stdafx.h"
#include "viking.h"
#include "input.h"
#include <deque>


class AircraftEngine
{
public:
	void Movement();
	deque<Aircraft*> aircraftDeque;
	int activeAircraftDequePosition;

	ALLEGRO_BITMAP *bmpBackVikingIdle[8];
	ALLEGRO_BITMAP *bmpBackVikingLeftStart[7];
	ALLEGRO_BITMAP *bmpBackVikingLeftMantain[6];
	ALLEGRO_BITMAP *bmpBackVikingRightStart[7];
	ALLEGRO_BITMAP *bmpBackVikingRightMantain[6];
	ALLEGRO_BITMAP *bmpVikingBullet[12];
	ALLEGRO_BITMAP *bmpExplosion[33];

public:
	Input* pInput;
	void Output(int, bool);
	void ActiveCheck();
	void Movement(int);
	void AircraftPlot();
	void AircraftAttack(bool);
	ALLEGRO_BITMAP** getBitmap(int, int, int);
	AircraftEngine();
};