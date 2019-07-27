#pragma once
#include "stdafx.h"
#include "SFX.h"


class tower
{
#define BEGIN 0
#define FINISH 1
protected:
    SFX                         towerFadeIn;	
	float		            	Damage;
	int			            	Price;
	float			            AttackRate;
	float			            Range;
    int                         placementPos;
    towertype                   Type;
	bool						Attacking;
	int							FrameIterator;
	int							ExplosionIterator;
	bool						Exploding;
public:
    int				            posX;
	int				            posY;
	int							expX;
	int							expY;
	void						setExplosionCoords(int x, int y);
	void						setExploding(bool p);
	bool                        Active;
	bool						Destroying[2];
    virtual	void	            towerPlot(int*, int*)=0;
	virtual void				explosionPlot()=0;
	const  float                getDamage();
	const   float               getRange();
	const   float               getAttackRate();
	const  int                  getPrice();
	const  int                  getPosX();
	const  int                  getPosY();
	void						setAttacking(const bool);
    towertype                   getType();
    ALLEGRO_BITMAP              *bar[5];
	ALLEGRO_EVENT_QUEUE			*tower_queue;
    ALLEGRO_TIMER				*timer;
	ALLEGRO_TIMER				*frame;
	ALLEGRO_EVENT				towerev;
	static int					towersBuilt;
	float						attackTicks;	
};



