#pragma once
#include "stdafx.h"
#include "bullet.h"



class Aircraft
{
protected:
	float speed;
	float damage;

	bool active;
	int  status;
public:
	float posX;
	float posY;
	bool morphing;

	float getSpeed(){return speed;}
	float getDamage(){return damage;}
	float getPosX(){return posX;}
	float getPosY(){return posY;}
	bool  getActive(){return active;}
	void  setActive(bool p){active = p;}
	int  getStatus(){return status;}
	aircrafttype getType(){return type;}
	void setStatus(int s){status = s;}
	virtual	void  aircraftPlot(int, int, bool) = 0;
	virtual void  Attack(bool) = 0;
	list<Bullet> bulletList;
	ALLEGRO_TIMER *shootingDelay;
	aircrafttype type;
	
	
};