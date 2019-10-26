#pragma once
#include "creep.h"
#include "marine.h"
#include "hydralisk.h"
#include "thor.h"
#include "voidray.h"
#include "colossus.h"
#include "zergling.h"
//#include "resource.h"
#include "Structure.cpp"

//#define MARINESPAWNSAMPLES				3
//#define MARINEDEATHSAMPLES				8
//#define HYDRALISKSPAWNSAMPLES			4
//#define HYDRALISKDEATHSAMPLES			6
//#define THORSPAWNSAMPLES				2
//#define THORDEATHSAMPLES				10
//#define VOIDRAYSPAWNSAMPLES				5
//#define VOIDRAYDEATHSAMPLES				3
//#define COLOSSUSSPAWNSAMPLES			6
//#define COLOSSUSDEATHSAMPLES			4
//
//#define SAMPLE_MARINE_SPAWN_FLAG		2001
//#define SAMPLE_HYDRALISK_SPAWN_FLAG		2002
//#define SAMPLE_THOR_SPAWN_FLAG			2003
//#define SAMPLE_VOIDRAY_SPAWN_FLAG		2004
//#define SAMPLE_COLOSSUS_SPAWN_FLAG		2005
//
//#define SAMPLE_MARINE_DEATH_FLAG		101
//#define SAMPLE_HYDRALISK_DEATH_FLAG		102
//#define SAMPLE_THOR_DEATH_FLAG			103
//#define SAMPLE_VOIDRAY_DEATH_FLAG		104
//#define SAMPLE_COLOSSUS_DEATH_FLAG		105



class creepEngine
{
private:
	
	int lives;

	ALLEGRO_BITMAP *loadMarine[4][MARINESPRITES];
	ALLEGRO_BITMAP *loadMarineDeath[4][10];
	ALLEGRO_SAMPLE *SampleMarineSpawn[MARINESPAWNSAMPLES];
	ALLEGRO_SAMPLE *loadSampleMarineDeath[MARINEDEATHSAMPLES];

	ALLEGRO_BITMAP *loadHydralisk[4][HYDRALISKSPRITES];
	ALLEGRO_BITMAP *loadHydraliskDeath[4][10];
	ALLEGRO_SAMPLE *SampleHydraliskSpawn[HYDRALISKSPAWNSAMPLES];
	ALLEGRO_SAMPLE *loadSampleHydraliskDeath[HYDRALISKDEATHSAMPLES];

	ALLEGRO_BITMAP *loadThor[4][THORSPRITES];
	ALLEGRO_BITMAP *loadThorDeath[4][10];
	ALLEGRO_SAMPLE *SampleThorSpawn[2];
	ALLEGRO_SAMPLE *loadSampleThorDeath[10];

	ALLEGRO_BITMAP *loadVoidRay[4][VOIDRAYSPRITES];
	ALLEGRO_BITMAP *loadVoidRayDeath[4][10];
	ALLEGRO_SAMPLE *SampleVoidRaySpawn[5];
	ALLEGRO_SAMPLE *loadSampleVoidRayDeath[3];

	ALLEGRO_BITMAP *loadColossus[4][COLOSSUSSPRITES];
	ALLEGRO_BITMAP *loadColossusDeath[4][10];
	ALLEGRO_SAMPLE *SampleColossusSpawn[6];
	ALLEGRO_SAMPLE *loadSampleColossusDeath[4];

	ALLEGRO_BITMAP		*staticBar[5];


	float		difficulty;
	int			spawnQuantity;
	enemytype	wave;

public:
	ALLEGRO_TIMER *waveTimer;
	creepEngine();
	Status status;
	Creep *creepFromList;
	Creep *creepPointer;
	List<Creep> creepList;
	ALLEGRO_BITMAP *Bar[5];
	enemytype getWave();
	int		  getLives();
	void	  removeLives(int);
	




	
	void insertIntoList();
	void creepMovement();
	void wavePlot();
	void creep_plot();
	void death_plot();
	void waveTimerCheck();
	void spawnZergling();
	void creepRepair();




	ALLEGRO_BITMAP **getBitmap(int flag, int direction, int walk);
	ALLEGRO_SAMPLE **getSample(int flag, int iterator);

	void Output();

//	void healthPlot(); será implementada na creep_plot
};