#include "creepengine.h"

creepEngine::creepEngine()
{
	waveTimer		= al_create_timer(1);
	spawnQuantity	= NULL;
	difficulty		= 1.0;
	lives			= 20;

	wave = none;
}

enemytype creepEngine::getWave()
{
	return wave;
}

int		creepEngine::getLives()
{
	return lives;
}

void creepEngine::removeLives(int l)
{
	lives -= l;
}

void creepEngine::insertIntoList()
{
		int creepCounter = 0;
		switch (wave)
		{
	
			case marine:
			{
			
				spawnQuantity = 22;
				creepList.SetCursor();
				for(creepCounter; creepCounter < spawnQuantity; creepCounter++)
				{
					creepPointer = new Marine(loadMarine, loadMarineDeath, staticBar, loadSampleMarineDeath,difficulty); // fazer funções de load
					creepPointer->setPosX(creepPointer->getPosX() +60*(creepCounter-1));
					creepPointer->setPosY(creepPointer->getPosY() -30*(creepCounter-1));
					creepList.Insert(*creepPointer);
					
				}	
				al_play_sample(SampleMarineSpawn[rand()%MARINESPAWNSAMPLES] ,0.5,ALLEGRO_AUDIO_PAN_NONE,1,ALLEGRO_PLAYMODE_ONCE,NULL); 
				break;
					
			}
			case hydralisk:
			{
				spawnQuantity = 10;
				creepList.SetCursor();
				for(creepCounter; creepCounter < spawnQuantity; creepCounter++)
				{
					creepPointer = new Hydralisk(loadHydralisk, loadHydraliskDeath, staticBar, loadSampleHydraliskDeath, difficulty); // fazer funções de load
					creepPointer->setPosX(creepPointer->getPosX() + 120*(creepCounter -1));
					creepPointer->setPosY(creepPointer->getPosY() - 60*(creepCounter -1));
					creepList.Insert(*creepPointer);
				}	
				al_play_sample(SampleHydraliskSpawn[0] ,1,ALLEGRO_AUDIO_PAN_NONE,1,ALLEGRO_PLAYMODE_ONCE,NULL); 
				break;
			}
			case thor:
			{
				spawnQuantity = 10;
				creepList.SetCursor();
				for(creepCounter; creepCounter < spawnQuantity; creepCounter++)
				{
					creepPointer = new Thor(loadThor, loadThorDeath, staticBar,loadSampleThorDeath, difficulty); // fazer funções de load
					creepPointer->setPosX(creepPointer->getPosX() + 120*(creepCounter -1));
					creepPointer->setPosY(creepPointer->getPosY() - 60*(creepCounter -1));
					creepList.Insert(*creepPointer);
				}
				al_play_sample(SampleThorSpawn[rand()%THORSPAWNSAMPLES] ,1,ALLEGRO_AUDIO_PAN_NONE,1,ALLEGRO_PLAYMODE_ONCE,NULL); 
				break;
			}
			case voidray:
			{
				spawnQuantity = 15;
				creepList.SetCursor();
				for(creepCounter; creepCounter < spawnQuantity; creepCounter++)
				{
					creepPointer = new VoidRay(loadVoidRay, loadVoidRayDeath, staticBar,loadSampleVoidRayDeath,difficulty); // fazer funções de load
					creepPointer->setPosX(creepPointer->getPosX() + 120*(creepCounter -1));
					creepPointer->setPosY(creepPointer->getPosY() - 60*(creepCounter -1));
					creepList.Insert(*creepPointer);
				}
				al_play_sample(SampleVoidRaySpawn[rand()%VOIDRAYSPAWNSAMPLES] ,1,ALLEGRO_AUDIO_PAN_NONE,1,ALLEGRO_PLAYMODE_ONCE,NULL); 
				break;
			}
			case colossus:
			{
				spawnQuantity = 3;
				creepList.SetCursor();
				for(creepCounter; creepCounter < spawnQuantity; creepCounter++)
				{
					creepPointer = new Colossus(loadColossus, loadColossusDeath, staticBar,loadSampleColossusDeath,difficulty); // fazer funções de load
					creepPointer->setPosX(creepPointer->getPosX() + 240*(creepCounter -1));
					creepPointer->setPosY(creepPointer->getPosY() - 120*(creepCounter -1));
					creepList.Insert(*creepPointer);
				}
				al_play_sample(SampleColossusSpawn[rand()%COLOSSUSSPAWNSAMPLES] ,2.5,ALLEGRO_AUDIO_PAN_NONE,1,ALLEGRO_PLAYMODE_ONCE,NULL); 
				break;
			}
		}
}

ALLEGRO_BITMAP **creepEngine::getBitmap(int flag, int direction, int walk)
{
	if (flag == MARINEFLAG)
		return &loadMarine[direction][walk];
	if (flag == MARINEDEATHFLAG)
		return &loadMarineDeath[direction][walk];
	if (flag == HYDRALISKFLAG)
		return &loadHydralisk[direction][walk];
	if (flag == HYDRALISKDEATHFLAG)
		return &loadHydraliskDeath[direction][walk];
	if (flag == THORFLAG)
		return &loadThor[direction][walk];
	if (flag == THORDEATHFLAG)
		return &loadThorDeath[direction][walk];
	if (flag == VOIDRAYFLAG)
		return &loadVoidRay[direction][walk];
	if (flag == VOIDRAYDEATHFLAG)
		return &loadVoidRayDeath[direction][walk];
	if (flag == COLOSSUSFLAG)
		return &loadColossus[direction][walk];
	if (flag == COLOSSUSDEATHFLAG)
		return &loadColossusDeath[direction][walk];
	 if (flag == STATICBARFLAG)
		return &staticBar[walk];
	return NULL;
}

ALLEGRO_SAMPLE **creepEngine::getSample(int flag, int iterator)
{
	if (flag == SAMPLE_MARINE_SPAWN_FLAG)
		return &SampleMarineSpawn[iterator];
	if (flag == SAMPLE_HYDRALISK_SPAWN_FLAG)
		return &SampleHydraliskSpawn[iterator];
	if (flag == SAMPLE_THOR_SPAWN_FLAG)
		return &SampleThorSpawn[iterator];
	if (flag == SAMPLE_VOIDRAY_SPAWN_FLAG)
		return &SampleVoidRaySpawn[iterator];
	if (flag == SAMPLE_COLOSSUS_SPAWN_FLAG)
		return &SampleColossusSpawn[iterator];
	if (flag == SAMPLE_MARINE_DEATH_FLAG)
		return &loadSampleMarineDeath[iterator];
	if (flag == SAMPLE_HYDRALISK_DEATH_FLAG)
		return &loadSampleHydraliskDeath[iterator];
	if (flag == SAMPLE_THOR_DEATH_FLAG)
		return &loadSampleThorDeath[iterator];
	if (flag == SAMPLE_VOIDRAY_DEATH_FLAG)
		return &loadSampleVoidRayDeath[iterator];
	if (flag == SAMPLE_COLOSSUS_DEATH_FLAG)
		return &loadSampleColossusDeath[iterator];
	return NULL;
}

void creepEngine::creepMovement()
{
	status = CONTINUE;
	creepList.SetCursor(BEGINNING,0);
	while(status == CONTINUE && creepList.GetSize() != 0)
	{
		creepFromList = creepList.GetCursorData(status);
		creepList.SetCursor(FORWARD, 1);

		if(creepFromList->getType() == thor)
		{
			creepRepair();
		}
		if(creepFromList->getHealth() > 0 && creepFromList->getDead() == false)
		{
			creepFromList->movement(creepFromList->getMoveSpeed());
		}
		if(creepFromList->getHealth() <= 0 && creepFromList->getDead() == false)
		{
			creepFromList->setTargetX(creepPointer->getPosX());
			creepFromList->setTargetY(creepPointer->getPosY());
		}
		if(creepFromList->getHealth() <= 0 && creepFromList->getDead() == true)
		{
			if(creepFromList->getType() == hydralisk)
			{
				if(!creepFromList->GetZerglingsSpawned())
				{
					spawnZergling();
				}
			}
			creepFromList->setPosX(PosMorto);
			creepFromList->setPosY(PosMorto);
		}
		
	}
}

void creepEngine::wavePlot()
{
	Status status = CONTINUE;
	creepList.SetCursor(BEGINNING,0);

	while(status == CONTINUE)
	{
		creepFromList = creepList.GetCursorData(status);
		creepList.SetCursor(FORWARD, 1);
		if(creepFromList->getHealth() > 0 &&  creepFromList->getDead() == false){creepFromList->creep_plot();}
		if(creepFromList->getHealth() <= 0 && creepFromList->getDead() == false){creepFromList->death_plot();}	
	}
}

void creepEngine::waveTimerCheck()
{
	if(al_get_timer_count(waveTimer) >= 10 && wave == none)
	{
		wave = marine;
		insertIntoList();
		al_set_timer_count(waveTimer, 0);
	}
	if(al_get_timer_count(waveTimer) >= 35 && wave == marine)
	{
		wave = hydralisk;
		insertIntoList();
		al_set_timer_count(waveTimer, 0);
	}
	if(al_get_timer_count(waveTimer) >= 35 && wave == hydralisk)
	{
		wave = thor;
		insertIntoList();
		al_set_timer_count(waveTimer, 0);
	}
	if(al_get_timer_count(waveTimer) >= 35 && wave == thor)
	{
		wave = voidray;
		insertIntoList();
		al_set_timer_count(waveTimer, 0);
	}
	if(al_get_timer_count(waveTimer) >= 35 && wave == voidray)
	{
		wave = colossus;
		insertIntoList();
		al_set_timer_count(waveTimer, 0);
	}
	if(al_get_timer_count(waveTimer) >= 35 && wave == colossus)
	{
		difficulty += 1;
		wave = marine;
		insertIntoList();
		al_set_timer_count(waveTimer, 0);
	}
}

void creepEngine::Output()
{
		waveTimerCheck();
		creepMovement();
}

void creepEngine::spawnZergling()
{
	spawnQuantity = 2;
	creepList.SetCursor();
	for(int creepCounter = 0; creepCounter < spawnQuantity; creepCounter++)
	{
		creepPointer = new Zergling(loadHydralisk, 
									loadHydraliskDeath, 
									staticBar, 
									loadSampleHydraliskDeath, 
									difficulty,
									PosInicialX,  //creepFromList->getPosX(),
									PosInicialY,  //creepFromList->getPosY(), 
									Troca1X,      //creepFromList->getTargetPosX(), 
									Troca1Y);     //creepFromList->getTargetPosY());
		creepPointer->setPosX(creepPointer->getPosX() + 120*(creepCounter -1));
		creepPointer->setPosY(creepPointer->getPosY() - 60*(creepCounter -1));
		creepList.Insert(*creepPointer);
	}	
	al_play_sample(SampleHydraliskSpawn[0] ,1,ALLEGRO_AUDIO_PAN_NONE,1,ALLEGRO_PLAYMODE_ONCE,NULL);
	creepFromList->SetZerglingsSpawned(true);
}

void creepEngine::creepRepair()
{
	if (creepFromList->getHealth() > 0) //creepFromList->health*0.1)
	{
		creepFromList->autoRepair(creepFromList->getHealth(), creepFromList->getTotalHealth());
		creepFromList->setHealth((creepFromList->getHealth()+creepFromList->getHpRegen()));
		if(creepFromList->getHealth() > creepFromList->getTotalHealth())
		{
			creepFromList->setHealth(creepFromList->getTotalHealth());
		}	
	}
}
