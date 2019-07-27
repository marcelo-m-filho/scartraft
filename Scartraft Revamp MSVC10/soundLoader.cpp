#include "soundLoader.h"
#include "creepengine.h"
#include "towerEngine.h"

void soundLoader::Output()
{
	towerLoad();
	creepLoad();
}

void soundLoader::towerLoad()
{
	*pTowerEngine->getSample(BUNKERBUILDSOUNDFLAG,NULL)		= al_load_sample("Sounds\\Bunker\\BunkerBuild1.ogg");
	*pTowerEngine->getSample(SIEGEBUILDSOUNDFLAG,NULL)		= al_load_sample("Sounds\\SiegeTank\\SiegeTankBuild1.wav");
	*pTowerEngine->getSample(TURRETBUILDSOUNDFLAG,NULL)		= al_load_sample("Sounds\\Turret\\TurretBuild1.ogg");

	*pTowerEngine->getSample(TURRETATTACKSOUNDFLAG,0)   = al_load_sample("Sounds\\Turret\\Attacking\\Attack1.wav");
	*pTowerEngine->getSample(TURRETATTACKSOUNDFLAG,1)   = al_load_sample("Sounds\\Turret\\Attacking\\Attack2.wav");
	*pTowerEngine->getSample(TURRETATTACKSOUNDFLAG,2)   = al_load_sample("Sounds\\Turret\\Attacking\\Attack3.wav");

	*pTowerEngine->getSample(BUNKERATTACKSOUNDFLAG,0) = al_load_sample("Sounds\\Bunker\\Attacking\\Attack1.wav");
	*pTowerEngine->getSample(BUNKERATTACKSOUNDFLAG,1) = al_load_sample("Sounds\\Bunker\\Attacking\\Attack2.wav");
	*pTowerEngine->getSample(BUNKERATTACKSOUNDFLAG,2) = al_load_sample("Sounds\\Bunker\\Attacking\\Attack1.wav");
	*pTowerEngine->getSample(BUNKERATTACKSOUNDFLAG,3) = al_load_sample("Sounds\\Bunker\\Attacking\\Attack1.wav");
	*pTowerEngine->getSample(BUNKERATTACKSOUNDFLAG,4) = al_load_sample("Sounds\\Bunker\\Attacking\\Attack5.wav");
	*pTowerEngine->getSample(BUNKERATTACKSOUNDFLAG,5) = al_load_sample("Sounds\\Bunker\\Attacking\\Attack6.wav");
	*pTowerEngine->getSample(BUNKERATTACKSOUNDFLAG,6) = al_load_sample("Sounds\\Bunker\\Attacking\\Attack7.wav");
	*pTowerEngine->getSample(BUNKERATTACKSOUNDFLAG,7) = al_load_sample("Sounds\\Bunker\\Attacking\\Attack8.wav");
	*pTowerEngine->getSample(BUNKERATTACKSOUNDFLAG,8) = al_load_sample("Sounds\\Bunker\\Attacking\\Attack9.wav");
	*pTowerEngine->getSample(BUNKERATTACKSOUNDFLAG,9) = al_load_sample("Sounds\\Bunker\\Attacking\\Attack10.wav");

	*pTowerEngine->getSample(SIEGEATTACKSOUNDFLAG,0) = al_load_sample("Sounds\\SiegeTank\\Attacking\\Attack1.wav");
	*pTowerEngine->getSample(SIEGEATTACKSOUNDFLAG,1) = al_load_sample("Sounds\\SiegeTank\\Attacking\\Attack2.wav");
	*pTowerEngine->getSample(SIEGEATTACKSOUNDFLAG,2) = al_load_sample("Sounds\\SiegeTank\\Attacking\\Attack1.wav");
	*pTowerEngine->getSample(SIEGEATTACKSOUNDFLAG,3) = al_load_sample("Sounds\\SiegeTank\\Attacking\\Attack1.wav");
	*pTowerEngine->getSample(SIEGEATTACKSOUNDFLAG,4) = al_load_sample("Sounds\\SiegeTank\\Attacking\\Attack5.wav");
	*pTowerEngine->getSample(SIEGEATTACKSOUNDFLAG,5) = al_load_sample("Sounds\\SiegeTank\\Attacking\\Attack6.wav");
	*pTowerEngine->getSample(SIEGEATTACKSOUNDFLAG,6) = al_load_sample("Sounds\\SiegeTank\\Attacking\\Attack7.wav");
	*pTowerEngine->getSample(SIEGEATTACKSOUNDFLAG,7) = al_load_sample("Sounds\\SiegeTank\\Attacking\\Attack8.wav");
	*pTowerEngine->getSample(SIEGEATTACKSOUNDFLAG,8) = al_load_sample("Sounds\\SiegeTank\\Attacking\\Attack9.wav");
	*pTowerEngine->getSample(SIEGEATTACKSOUNDFLAG,9) = al_load_sample("Sounds\\SiegeTank\\Attacking\\Attack10.wav");
}

void soundLoader::creepLoad()
{
	*pCreepEngine->getSample(SAMPLE_MARINE_SPAWN_FLAG,0) = al_load_sample("Sounds\\Creeps\\Marine\\Spawn\\Marine_Spawn00.ogg");
	*pCreepEngine->getSample(SAMPLE_MARINE_SPAWN_FLAG,1) = al_load_sample("Sounds\\Creeps\\Marine\\Spawn\\Marine_Spawn01.ogg");
	*pCreepEngine->getSample(SAMPLE_MARINE_SPAWN_FLAG,2) = al_load_sample("Sounds\\Creeps\\Marine\\Spawn\\Marine_Spawn02.ogg");

	*pCreepEngine->getSample(SAMPLE_HYDRALISK_SPAWN_FLAG,0) = al_load_sample("Sounds\\Creeps\\Hydralisk\\Spawn\\Hydralisk_Spawn0.ogg");
	*pCreepEngine->getSample(SAMPLE_HYDRALISK_SPAWN_FLAG,1) = al_load_sample("Sounds\\Creeps\\Hydralisk\\Spawn\\Hydralisk_Spawn1.ogg");
	*pCreepEngine->getSample(SAMPLE_HYDRALISK_SPAWN_FLAG,2) = al_load_sample("Sounds\\Creeps\\Hydralisk\\Spawn\\Hydralisk_Spawn2.ogg");
	*pCreepEngine->getSample(SAMPLE_HYDRALISK_SPAWN_FLAG,3) = al_load_sample("Sounds\\Creeps\\Hydralisk\\Spawn\\Hydralisk_Spawn3.ogg");

	*pCreepEngine->getSample(SAMPLE_THOR_SPAWN_FLAG,0) = al_load_sample("Sounds\\Creeps\\Thor\\Spawn\\Thor_Spawn00.ogg");
	*pCreepEngine->getSample(SAMPLE_THOR_SPAWN_FLAG,1) = al_load_sample("Sounds\\Creeps\\Thor\\Spawn\\Thor_Spawn01.ogg");

	*pCreepEngine->getSample(SAMPLE_VOIDRAY_SPAWN_FLAG,0) = al_load_sample("Sounds\\Creeps\\VoidRay\\Spawn\\VoidRay_Spawn0.ogg");
	*pCreepEngine->getSample(SAMPLE_VOIDRAY_SPAWN_FLAG,1) = al_load_sample("Sounds\\Creeps\\VoidRay\\Spawn\\VoidRay_Spawn1.ogg");
	*pCreepEngine->getSample(SAMPLE_VOIDRAY_SPAWN_FLAG,2) = al_load_sample("Sounds\\Creeps\\VoidRay\\Spawn\\VoidRay_Spawn2.ogg");
	*pCreepEngine->getSample(SAMPLE_VOIDRAY_SPAWN_FLAG,3) = al_load_sample("Sounds\\Creeps\\VoidRay\\Spawn\\VoidRay_Spawn3.ogg");
	*pCreepEngine->getSample(SAMPLE_VOIDRAY_SPAWN_FLAG,4) = al_load_sample("Sounds\\Creeps\\VoidRay\\Spawn\\VoidRay_Spawn4.ogg");

	*pCreepEngine->getSample(SAMPLE_COLOSSUS_SPAWN_FLAG,0) = al_load_sample("Sounds\\Creeps\\Colossus\\Spawn\\Colossus_Spawn0.ogg");
	*pCreepEngine->getSample(SAMPLE_COLOSSUS_SPAWN_FLAG,1) = al_load_sample("Sounds\\Creeps\\Colossus\\Spawn\\Colossus_Spawn1.ogg");
	*pCreepEngine->getSample(SAMPLE_COLOSSUS_SPAWN_FLAG,2) = al_load_sample("Sounds\\Creeps\\Colossus\\Spawn\\Colossus_Spawn2.ogg");
	*pCreepEngine->getSample(SAMPLE_COLOSSUS_SPAWN_FLAG,3) = al_load_sample("Sounds\\Creeps\\Colossus\\Spawn\\Colossus_Spawn3.ogg");
	*pCreepEngine->getSample(SAMPLE_COLOSSUS_SPAWN_FLAG,4) = al_load_sample("Sounds\\Creeps\\Colossus\\Spawn\\Colossus_Spawn4.ogg");
	*pCreepEngine->getSample(SAMPLE_COLOSSUS_SPAWN_FLAG,5) = al_load_sample("Sounds\\Creeps\\Colossus\\Spawn\\Colossus_Spawn5.ogg");

	*pCreepEngine->getSample(SAMPLE_MARINE_DEATH_FLAG,0) = al_load_sample("Sounds\\Creeps\\Marine\\Death\\Marine_Death00.wav");
	*pCreepEngine->getSample(SAMPLE_MARINE_DEATH_FLAG,1) = al_load_sample("Sounds\\Creeps\\Marine\\Death\\Marine_Death01.wav");
	*pCreepEngine->getSample(SAMPLE_MARINE_DEATH_FLAG,2) = al_load_sample("Sounds\\Creeps\\Marine\\Death\\Marine_Death02.wav");
	*pCreepEngine->getSample(SAMPLE_MARINE_DEATH_FLAG,3) = al_load_sample("Sounds\\Creeps\\Marine\\Death\\Marine_Death03.wav");
	*pCreepEngine->getSample(SAMPLE_MARINE_DEATH_FLAG,4) = al_load_sample("Sounds\\Creeps\\Marine\\Death\\Marine_Death04.wav");
	*pCreepEngine->getSample(SAMPLE_MARINE_DEATH_FLAG,5) = al_load_sample("Sounds\\Creeps\\Marine\\Death\\Marine_Death05.wav");
	*pCreepEngine->getSample(SAMPLE_MARINE_DEATH_FLAG,6) = al_load_sample("Sounds\\Creeps\\Marine\\Death\\Marine_Death06.wav");
	*pCreepEngine->getSample(SAMPLE_MARINE_DEATH_FLAG,7) = al_load_sample("Sounds\\Creeps\\Marine\\Death\\Marine_Death07.wav");

	*pCreepEngine->getSample(SAMPLE_HYDRALISK_DEATH_FLAG,0) = al_load_sample("Sounds\\Creeps\\Hydralisk\\Death\\Hydralisk_Death0.wav");
	*pCreepEngine->getSample(SAMPLE_HYDRALISK_DEATH_FLAG,1) = al_load_sample("Sounds\\Creeps\\Hydralisk\\Death\\Hydralisk_Death1.wav");
	*pCreepEngine->getSample(SAMPLE_HYDRALISK_DEATH_FLAG,2) = al_load_sample("Sounds\\Creeps\\Hydralisk\\Death\\Hydralisk_Death2.wav");
	*pCreepEngine->getSample(SAMPLE_HYDRALISK_DEATH_FLAG,3) = al_load_sample("Sounds\\Creeps\\Hydralisk\\Death\\Hydralisk_Death3.wav");
	*pCreepEngine->getSample(SAMPLE_HYDRALISK_DEATH_FLAG,4) = al_load_sample("Sounds\\Creeps\\Hydralisk\\Death\\Hydralisk_Death4.wav");
	*pCreepEngine->getSample(SAMPLE_HYDRALISK_DEATH_FLAG,5) = al_load_sample("Sounds\\Creeps\\Hydralisk\\Death\\Hydralisk_Death5.wav");

	*pCreepEngine->getSample(SAMPLE_THOR_DEATH_FLAG,0) = al_load_sample("Sounds\\Creeps\\Thor\\Death\\Terran_ExplosionSmall0.wav");
	*pCreepEngine->getSample(SAMPLE_THOR_DEATH_FLAG,1) = al_load_sample("Sounds\\Creeps\\Thor\\Death\\Terran_ExplosionSmall1.wav");
	*pCreepEngine->getSample(SAMPLE_THOR_DEATH_FLAG,2) = al_load_sample("Sounds\\Creeps\\Thor\\Death\\Terran_ExplosionSmall2.wav");
	*pCreepEngine->getSample(SAMPLE_THOR_DEATH_FLAG,3) = al_load_sample("Sounds\\Creeps\\Thor\\Death\\Terran_ExplosionSmall3.wav");
	*pCreepEngine->getSample(SAMPLE_THOR_DEATH_FLAG,4) = al_load_sample("Sounds\\Creeps\\Thor\\Death\\Terran_ExplosionSmall4.wav");
	*pCreepEngine->getSample(SAMPLE_THOR_DEATH_FLAG,5) = al_load_sample("Sounds\\Creeps\\Thor\\Death\\Terran_ExplosionSmall5.wav");
	*pCreepEngine->getSample(SAMPLE_THOR_DEATH_FLAG,6) = al_load_sample("Sounds\\Creeps\\Thor\\Death\\Terran_ExplosionSmall6.wav");
	*pCreepEngine->getSample(SAMPLE_THOR_DEATH_FLAG,7) = al_load_sample("Sounds\\Creeps\\Thor\\Death\\Terran_ExplosionSmall7.wav");
	*pCreepEngine->getSample(SAMPLE_THOR_DEATH_FLAG,8) = al_load_sample("Sounds\\Creeps\\Thor\\Death\\Terran_ExplosionSmall8.wav");
	*pCreepEngine->getSample(SAMPLE_THOR_DEATH_FLAG,9) = al_load_sample("Sounds\\Creeps\\Thor\\Death\\Terran_ExplosionSmall9.wav");

	*pCreepEngine->getSample(SAMPLE_VOIDRAY_DEATH_FLAG,0) = al_load_sample("Sounds\\Creeps\\VoidRay\\Death\\Protoss_DeathFX0.wav");
	*pCreepEngine->getSample(SAMPLE_VOIDRAY_DEATH_FLAG,1) = al_load_sample("Sounds\\Creeps\\VoidRay\\Death\\Protoss_DeathFX1.wav");
	*pCreepEngine->getSample(SAMPLE_VOIDRAY_DEATH_FLAG,2) = al_load_sample("Sounds\\Creeps\\VoidRay\\Death\\Protoss_DeathFX2.wav");

	*pCreepEngine->getSample(SAMPLE_COLOSSUS_DEATH_FLAG,0) = al_load_sample("Sounds\\Creeps\\Colossus\\Death\\Archon_Death00.wav");
	*pCreepEngine->getSample(SAMPLE_COLOSSUS_DEATH_FLAG,1) = al_load_sample("Sounds\\Creeps\\Colossus\\Death\\Archon_Death01.wav");
	*pCreepEngine->getSample(SAMPLE_COLOSSUS_DEATH_FLAG,2) = al_load_sample("Sounds\\Creeps\\Colossus\\Death\\Archon_Death02.wav");
	*pCreepEngine->getSample(SAMPLE_COLOSSUS_DEATH_FLAG,3) = al_load_sample("Sounds\\Creeps\\Colossus\\Death\\Archon_Death03.wav");












}

