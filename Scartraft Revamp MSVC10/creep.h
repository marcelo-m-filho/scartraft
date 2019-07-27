#pragma once
#include "stdafx.h"
#include "SFX.h"


class Creep
{
private:
	static int playerLives;
protected:

	SFX					creepSFX;
	double				actualPosX;
	double				actualPosY;
	double				targetPosX;
	double				targetPosY;
	double				deathPosX;
	double				deathPosY;
	int					direction;
	int					FrameIterator;
	int					DeathIterator;
	enemytype			Type;
	double				movespeed;
	double				totalhealth;
	double				health;
	double				hpRegen;
	double				reward;
	bool				dead;
	bool				deathsound;
	ALLEGRO_TIMER		*timer;
	ALLEGRO_BITMAP		*staticBar[5];
	bool                zerglingsSpawned;
	
public:
	double		getPosX();
	double		getPosY();
	double		getTargetPosX();
	double		getTargetPosY();
	double		getHealth();
	double		getTotalHealth();
	double      getHpRegen();
	enemytype	getType();
	double		getReward();
	double		getMoveSpeed();
	bool		getDead();
	bool		GetZerglingsSpawned();
	const int	getLives(void);
	

	void		setDead(bool);
	void		setHealth(double);
	void		setPosX(double);
	void		setPosY(double);
	void		setTargetX(double);
	void		setTargetY(double);
	void		SetZerglingsSpawned(bool codition);

	Creep();
	void		 movement(double movespeed);
	void		 autoRepair(double health, double totalhealth);

	virtual void death_plot(void) = 0;
	virtual void creep_plot(void) = 0;
};

