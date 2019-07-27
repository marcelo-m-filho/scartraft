#include "towerEngine.h"
int towerEngine::scoreMultiplier = 0;

towerEngine::towerEngine()
{
	//sampleBuildBunker = al_load_sample("Sounds\\Bunker\\BunkerBuild1.ogg");
	for(int i = 0; i<4; i++)
		mouseOnButton[i]	= 0;
    golds					= 50;
    BuildSelection			= None;
	AvaliablePositionX[0]	= 1;
	AvaliablePositionX[1]	= 1;
	AvaliablePositionX[2]	= 3;
	AvaliablePositionX[3]	= 3;
	AvaliablePositionX[4]	= 4;
	AvaliablePositionX[5]	= 5;
	AvaliablePositionX[6]	= 5;
	AvaliablePositionX[7]	= 5;
	AvaliablePositionX[8]	= 7;
	AvaliablePositionX[9]	= 7;
	AvaliablePositionX[10]	= 7;
	AvaliablePositionX[11]	= 8;
	AvaliablePositionX[12]	= 9;
	AvaliablePositionX[13]	= 10;
	AvaliablePositionX[14]	= 12;
	AvaliablePositionX[15]	= 12;

	AvaliablePositionY[0] = 2;
	AvaliablePositionY[1] = 6;
	AvaliablePositionY[2] = 4;
	AvaliablePositionY[3] = 7;
	AvaliablePositionY[4] = 10;
	AvaliablePositionY[5] = 2;
	AvaliablePositionY[6] = 5;
	AvaliablePositionY[7] = 8;
	AvaliablePositionY[8] = 3;
	AvaliablePositionY[9] = 6;
	AvaliablePositionY[10] = 11;
	AvaliablePositionY[11] = 8;
	AvaliablePositionY[12] = 10;
	AvaliablePositionY[13] = 5;
	AvaliablePositionY[14] = 6;
	AvaliablePositionY[15] = 9;

	AircraftVikingActive = true; //mudar, apenas true inicial por motivos de teste

    for(int i = 0; i < TOTALTOWERNUMBER;  i++)
    {
        PositionLocker[i] = false;
    }

	scoreTimer = al_create_timer(0.5);
	scoreValue = 0;
	al_start_timer(scoreTimer);
	
}

/*chega se o jogador clicou em um lugar permitido e em caso positivo leva para a buildPlacement*/
void towerEngine::buildLocationCheck(int mousex, int mousey, int mouseb)  
{   
    float SquareX = (mousex/50.0), SquareY = (mousey/50.0);

	if (pInput->getSelection() != aViking)
	{
		for(int i = 0; i < TOTALTOWERNUMBER; i++)
		{
			if (mouseb == LEFTBUTTON &&
				SquareX >=  AvaliablePositionX[i] && SquareX <  (AvaliablePositionX[i]+1) &&
				SquareY >= AvaliablePositionY[i] &&	SquareY < AvaliablePositionY[i]+1 &&
				PositionLocker[i] == false)
			{
				PositionLocker[i] = true;   
				buildPlacement(AvaliablePositionX[i]*50,AvaliablePositionY[i]*50,i);    
			}
		}
	}
	else if (pInput->getSelection() == aViking)
	{
		
		buildPlacement(pAircraftEngine->aircraftDeque.at(pAircraftEngine->activeAircraftDequePosition/*talvez transformar em get*/)->getPosX(),
					   pAircraftEngine->aircraftDeque.at(pAircraftEngine->activeAircraftDequePosition/*talvez transformar em get*/)->getPosY(),
					   NULL);   
	}
}

/*adiciona a torre no Vector*/
void towerEngine::buildPlacement(int posX, int posY, int placementPos)
{
	if (pInput->getSelection() == aViking)
	{
		tower *towerPointer = new assaultViking(posX+25, posY+25, bmpAssaultViking, bmpAssaultVikingBuild, bar); 
		pInput->setMoney(pInput->getMoney() - towerPointer->getPrice());
		towerVector.push_back(towerPointer);
        pInput->setSelection(None);
		al_play_sample(sampleBuildBunker,0.2,ALLEGRO_AUDIO_PAN_NONE,1,ALLEGRO_PLAYMODE_ONCE,NULL);
	}
    if (pInput->getSelection() == Bunker)
	{
		tower *towerPointer = new bunker(posX+25, posY+25, placementPos, bmpBunker, bar,bmpBulletHit); 
        pInput->setMoney(pInput->getMoney() - towerPointer->getPrice());
		towerVector.push_back(towerPointer);
		pInput->setSelection(None);
		al_play_sample(sampleBuildBunker,0.2,ALLEGRO_AUDIO_PAN_NONE,1,ALLEGRO_PLAYMODE_ONCE,NULL);
	}
	else if (pInput->getSelection() == Turret)
	{
		tower *towerPointer = new turret(posX+25, posY+25, placementPos, bmpTurret, bar); //Alinhar posição de ataque com posição do sprite depois
        pInput->setMoney(pInput->getMoney() - towerPointer->getPrice());
		towerVector.push_back(towerPointer);
        pInput->setSelection(None);
		al_play_sample(sampleBuildTurret,0.2,ALLEGRO_AUDIO_PAN_NONE,1,ALLEGRO_PLAYMODE_ONCE,NULL);
		
	}
	else if (pInput->getSelection() == SiegeTank)
	{
		tower *towerPointer = new siegetank(posX+25, posY+25, placementPos, bmpSiege, bar, bmpExplosion); //Alinhar posição de ataque com posição do sprite depois
        pInput->setMoney(pInput->getMoney() - towerPointer->getPrice());
		towerVector.push_back(towerPointer);
        pInput->setSelection(None);
		al_play_sample(sampleBuildSiegeTank,0.2,ALLEGRO_AUDIO_PAN_NONE,1,ALLEGRO_PLAYMODE_ONCE,NULL);

	}


}

int towerEngine::score()
{
	
	

	if( scoreMultiplier < pTower->towersBuilt)
	{
		scoreMultiplier++;
		score();
		return -1;
	}
	else
		return ( scoreMultiplier * al_get_timer_count(scoreTimer));
		


}

void towerEngine::towerPlot()
{
  	for (unsigned int i = 0; i < towerVector.size(); i++)
	{
      towerVector.at(i)->towerPlot((&towerVector.at(i)->posX),(&towerVector.at(i)->posY));
			towerVector.at(i)->explosionPlot();
    }
}

void towerEngine::hitPlot()
{
	for (unsigned int i = 0; i < towerVector.size(); i++)
	{
			towerVector.at(i)->explosionPlot();
    }
}

void towerEngine::beaconPlot()
{
	(pInput->getSelection() != None)  ? beaconPulse.fadeIn(&beacons, true, 4.0 ,DONTREPEAT,0,0,beaconPulse.sfxTime(),1) : beaconPulse.fadeIn(&beacons,false, 1.0,DONTREPEAT,0,0,beaconPulse.sfxTime(),1);       
}

void towerEngine::towerAttack()
{
	
	for (unsigned int i = 0; i < towerVector.size(); i++)
	{
		if (towerVector.at(i)->Active && al_get_timer_count(towerVector.at(i)->timer) >= 1)
	    {

			pCreepEngine->status = CONTINUE;
			pCreepEngine->creepList.SetCursor(BEGINNING,0);
			
			while(pCreepEngine->status == CONTINUE && pCreepEngine->creepList.GetSize() != 0)
			{
				pCreepEngine->creepFromList = pCreepEngine->creepList.GetCursorData(pCreepEngine->status);
				pCreepEngine->creepList.SetCursor(FORWARD, 1);
				
				float distX = pow(((pCreepEngine->creepFromList->getPosX())-(towerVector.at(i)->posX)),2); //talvez aqui arrumar
				float distY = pow(((pCreepEngine->creepFromList->getPosY())-(towerVector.at(i)->posY)),2);
				
				if(towerVector.at(i)->getRange() >= sqrt(distX + distY) && pCreepEngine->creepFromList->getHealth() > 0)
				{
					if (towerVector.at(i)->getType() == Turret && pCreepEngine->creepFromList->getType() == voidray)
					{
						pCreepEngine->creepFromList->setHealth(pCreepEngine->creepFromList->getHealth() - towerVector.at(i)->getDamage());
						towerVector.at(i)->setAttacking(true);
						
	
						al_play_sample(sampleTurretAttack[rand()%2] ,0.5,ALLEGRO_AUDIO_PAN_NONE,1,ALLEGRO_PLAYMODE_ONCE,NULL);
					}
					if (towerVector.at(i)->getType() == SiegeTank && pCreepEngine->creepFromList->getType() != voidray)
					{
						pCreepEngine->creepFromList->setHealth(pCreepEngine->creepFromList->getHealth() - towerVector.at(i)->getDamage());
						towerVector.at(i)->setAttacking(true);////////////PASSAR X e Y DO CREEP POR PARAMETRO PARA EXPLOSAO
						towerVector.at(i)->setExplosionCoords(pCreepEngine->creepFromList->getPosX(),pCreepEngine->creepFromList->getPosY());
						towerVector.at(i)->setExploding(true);

						//passar o controle de play da sample pro objeto da torre depois
						al_play_sample(sampleSiegeAttack[rand()%9] ,0.5,ALLEGRO_AUDIO_PAN_NONE,1,ALLEGRO_PLAYMODE_ONCE,NULL);
					}
					if (towerVector.at(i)->getType() == Bunker)
					{
						pCreepEngine->creepFromList->setHealth(pCreepEngine->creepFromList->getHealth() - towerVector.at(i)->getDamage());
						towerVector.at(i)->setAttacking(true);////////////PASSAR X e Y DO CREEP POR PARAMETRO PARA EXPLOSAO
						towerVector.at(i)->setExplosionCoords(pCreepEngine->creepFromList->getPosX(),pCreepEngine->creepFromList->getPosY());
						towerVector.at(i)->setExploding(true);

						//passar o controle de play da sample pro objeto da torre depois
						al_play_sample(sampleBunkerAttack[rand()%9] ,0.2,ALLEGRO_AUDIO_PAN_NONE,1,ALLEGRO_PLAYMODE_ONCE,NULL); 
					}
					 
					if (towerVector.at(i)->getType() == aViking && !pInput->isMorphing())
					{
						pCreepEngine->creepFromList->setHealth(pCreepEngine->creepFromList->getHealth() - towerVector.at(i)->getDamage());
						towerVector.at(i)->setAttacking(true);

						//passar o controle de play da sample pro objeto da torre depois
						al_play_sample(sampleBunkerAttack[rand()%9] ,0.2,ALLEGRO_AUDIO_PAN_NONE,1,ALLEGRO_PLAYMODE_ONCE,NULL); 
					}

					if (pCreepEngine->creepFromList->getHealth() <= 0)	
					{
					
						pInput->setMoney(pInput->getMoney() + pCreepEngine->creepFromList->getReward());
					}
						break;
				}
			}

				al_set_timer_count(towerVector.at(i)->timer, 0);	
			//		towerVector.at(i)->OldTowerTicks  = TowerTicks;
				



		   
	//	al_play_sample(sampleAttackTurret1,0.3,ALLEGRO_AUDIO_PAN_NONE,1,ALLEGRO_PLAYMODE_ONCE,NULL);   
		}
    }
}

void towerEngine::towerDelete()
{
		for (unsigned int i = 0; i < towerVector.size(); i++)
		{
			if (towerVector.at(i)->getType() == aViking && pInput->isMorphing())
				towerVector.at(i)->Destroying[BEGIN] = true;

			if (towerVector.at(i)->getType() == aViking && towerVector.at(i)->Destroying[FINISH])
			{
				towerVector.erase(towerVector.begin()+i);
				pInput->setAircraftActivity(true);
				pInput->setMorphing(false);
			}
		}
	
}

void towerEngine::Output(int mousex, int mousey, int mouseb)
{
		scoreValue = score();
//	    buildInput(pInput->getX(),pInput->getY(),pInput->getB());
		if(pInput->getSelection() != None)                    
            buildLocationCheck(pInput->getX(),pInput->getY(),pInput->getB());
		if (!towerVector.empty())
			towerAttack();
		towerDelete();
}

void towerEngine::vectorHandling()
{
    towerVector.reserve(16);
}

ALLEGRO_BITMAP **towerEngine::getBitmap(int flag, int animation)
{
	if (flag == BEACONSFLAG)
		return &beacons;
	else if (flag == BUNKERFLAG)
		return &bmpBunker[animation];
	else if (flag == TURRETFLAG)
		return &bmpTurret[animation];
	else if (flag == SIEGETANKFLAG)
		return &bmpSiege[animation];
	else if (flag == BAR1FLAG)
		return &bar[animation];
	else if (flag == ASSAULTVIKINGFLAG)
		return &bmpAssaultViking[animation];
	else if (flag == ASSAULT_VIKING_BUILD_FLAG)
		return &bmpAssaultVikingBuild[animation];
	else if (flag == EXPLOSION)
		return &bmpExplosion[animation];
	else if (flag == LOADFLAG_BULLETHIT)
		return &bmpBulletHit[animation];
	else
		return NULL;
}

ALLEGRO_SAMPLE **towerEngine::getSample(int flag, int iterator)
{
	if (flag == BUNKERBUILDSOUNDFLAG)
		return &sampleBuildBunker;
	if (flag == TURRETBUILDSOUNDFLAG)
		return &sampleBuildTurret;
	if (flag == SIEGEBUILDSOUNDFLAG)
		return &sampleBuildSiegeTank;
	if (flag == BUNKERATTACKSOUNDFLAG)
		return &sampleBunkerAttack[iterator];
	if (flag == TURRETATTACKSOUNDFLAG)
		return &sampleTurretAttack[iterator];
	if (flag == SIEGEATTACKSOUNDFLAG)
		return &sampleSiegeAttack[iterator];
	return NULL;
	
}

towertype *towerEngine::getBuildSelection()
{
	return &BuildSelection;
}

void towerEngine::upgradeInput(int *mousex, int *mousey, int *mouseb)
{
	float SquareX = *mousex/50, SquareY = *mousey/50;

	if (!towerVector.empty())
	{
		for (unsigned int vi = 0; vi < towerVector.size(); vi++) //itera pelo vector
		{
			for(int pi = 0; pi < TOTALTOWERNUMBER; pi++) //itera pelas posicoes das torres no mapa
			{
				if (SquareX >= AvaliablePositionX[pi] && SquareX < AvaliablePositionX[pi]+1 &&
					SquareY >= AvaliablePositionY[pi] && SquareY < AvaliablePositionY[pi]+1 &&
					PositionLocker[pi] == true)
				{
					upgradeVectorPosition = vi;
				}
			}
		}
	}
}
