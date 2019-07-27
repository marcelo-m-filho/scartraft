#pragma once
#include "stdafx.h"
#include "creepengine.h"



class Bullet
{
#define BEGIN 0
#define END 1

	int posX;
	int posY;
	int frameIterator;
	int explosionIterator;
	int distance;
	int maxdistance;
	float range;
	float damage;
	ALLEGRO_TIMER *frame;
	ALLEGRO_TIMER *explosion;
	ALLEGRO_BITMAP *bmpBullet[BULLETNUMBER];
	ALLEGRO_BITMAP *bmpExplosion[EXPLOSIONNUMBER];

	bool exploded[2];




public:
	Bullet(){}
//	~Bullet(){delete this;}
	void destroyObject(){delete this;}
	static creepEngine* pCreepEngine;
	int getPosX(){return posX;}
	int getPosY(){return posY;}
	int getRange(){return range;}

	//fazer baseado em um timer depois
	bool Movement();
	void bulletPlot();
	bool Collision();
	void ExplosionPlot();
	Bullet(int X, int Y, ALLEGRO_BITMAP *pbmpBullet[], ALLEGRO_BITMAP *pbmpExplosion[]);
	

};

