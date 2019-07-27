#pragma once
#include "stdafx.h"
#include "bunker.h"
#include "turret.h"
#include "siegetank.h"
#include "SFX.h"
#include "plot.h"
#include "creepengine.h"
#include "assaultViking.h"
#include "aircraftEngine.h"
#include "input.h"

class towerEngine
{
private:
	std::vector<tower*> towerVector;

    SFX			beaconPulse; 
	towertype	BuildSelection;

    //-Allegro-Attributes->
	ALLEGRO_BITMAP *beacons;
    ALLEGRO_BITMAP *bmpBunker[6];
	ALLEGRO_BITMAP *bmpTurret[3];
	ALLEGRO_BITMAP *bmpSiege[7];
	ALLEGRO_BITMAP *bmpAssaultViking[ASSAULTVIKINGBITMAPNUMBER];
	ALLEGRO_BITMAP *bmpAssaultVikingBuild[ASSAULT_VIKING_BUILD_BITMAP_NUMBER];
    ALLEGRO_BITMAP *bar[5];
	ALLEGRO_BITMAP *bmpExplosion[EXPLOSIONNUMBER];
	ALLEGRO_BITMAP *bmpBulletHit[BITMAP_NUMBER_BULLETHIT];

	ALLEGRO_SAMPLE *sampleBunkerAttack[10]; 
	ALLEGRO_SAMPLE *sampleTurretAttack[3];
	ALLEGRO_SAMPLE *sampleSiegeAttack[10];
	ALLEGRO_SAMPLE *sampleBuildBunker; 
	ALLEGRO_SAMPLE *sampleBuildSiegeTank;
	ALLEGRO_SAMPLE *sampleBuildTurret;
	ALLEGRO_SAMPLE *sampleAttackTurret1;


	
	

    //-Tower-Logic-------->
    void buildLocationCheck(int,int,int);
    void buildPlacement(int, int, int);
	void upgradeInput(int*,int*, int*);
	void attack();
	void towerAttack();
	void towerDelete();
	int score();
	static int scoreMultiplier;
	ALLEGRO_TIMER *scoreTimer;
 
    

    //-Attributes--------->
    int			AvaliablePositionX[TOTALTOWERNUMBER];
    int			AvaliablePositionY[TOTALTOWERNUMBER];
    bool		PositionLocker[TOTALTOWERNUMBER];
	int			upgradeVectorPosition;
	bool		AircraftVikingActive;
	
public:

	tower* pTower; // Acesso ao atributo estático
	AircraftEngine* pAircraftEngine;
	Input* pInput;

	
	int scoreValue;

    //----Gets/Sets------->
    ALLEGRO_EVENT_QUEUE* get_input_queue();

    //----Cons/Destructor->
	towerEngine();

	//----Output Methods--->
	ALLEGRO_BITMAP	**getBitmap(int, int);
	ALLEGRO_SAMPLE	**getSample(int, int);
	towertype		*getBuildSelection();

    void			towerPlot();
    void			beaconPlot();
	void			hitPlot();
    void			vectorHandling();
	void			Output(int,int,int);

	creepEngine		*pCreepEngine;	
	int				mouseOnButton[4]; //Para tooltip
	int				golds; // retirar daqui
	
};