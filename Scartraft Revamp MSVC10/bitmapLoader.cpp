#include "bitmapLoader.h"
#include "towerEngine.h"
#include "creepengine.h"
#include <string>
#include <iostream>

using std::string;

void bitmapLoader::Loader()
{
	aircraftLoad();
	backgroundLoad();
	bar1Load();
	interfaceLoad();
	towerLoad();
	explosionLoad();
	creepLoad();


}

void bitmapLoader::loadSprite(ALLEGRO_BITMAP** container, char* path, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::ostringstream oss;
		oss << path << " " << i + 1 << ".tga";
		container[i] = al_load_bitmap(oss.str().c_str());
	}
}

void bitmapLoader::explosionLoad()
{
	this->loadSprite(explosion, "Sprites\\Explosion\\Explosion ", 33);

	this->loadSprite(bulletHit, "Sprites\\HitEffects\\BulletHit\\BulletHit", 9);

	for (int i = 0; i < 33; i++)
	{
		*pAircraftEngine->getBitmap(EXPLOSION, NULL, i) = explosion[i];
		*pTowerEngine->getBitmap(EXPLOSION, i) = explosion[i];
	}
	for (int i = 0; i < BITMAP_NUMBER_BULLETHIT; i++)
	{
		//	*pAircraftEngine->getBitmap(LOADFLAG_BULLETHIT,NULL,i) = bullethit[i];
		*pTowerEngine->getBitmap(LOADFLAG_BULLETHIT, i) = bulletHit[i];
	}
}


void bitmapLoader::backgroundLoad()
{
	background = al_load_bitmap("Sprites\\Cenario\\Terran.tga");
}

void bitmapLoader::bar1Load()
{
	*pTowerEngine->getBitmap(BAR1FLAG, 0) = al_load_bitmap("Sprites\\Bars\\Bar 1.tga");
	*pTowerEngine->getBitmap(BAR1FLAG, 1) = al_load_bitmap("Sprites\\Bars\\Bar 2.tga");
	*pTowerEngine->getBitmap(BAR1FLAG, 2) = al_load_bitmap("Sprites\\Bars\\Bar 3.tga");
	*pTowerEngine->getBitmap(BAR1FLAG, 3) = al_load_bitmap("Sprites\\Bars\\Bar 4.tga");
	*pTowerEngine->getBitmap(BAR1FLAG, 4) = al_load_bitmap("Sprites\\Bars\\Bar 5.tga");
	*pCreepEngine->getBitmap(STATICBARFLAG, NULL, 0) = al_load_bitmap("Sprites\\Bars\\Bar 1.tga");
	*pCreepEngine->getBitmap(STATICBARFLAG, NULL, 1) = al_load_bitmap("Sprites\\Bars\\Bar 2.tga");
	*pCreepEngine->getBitmap(STATICBARFLAG, NULL, 2) = al_load_bitmap("Sprites\\Bars\\Bar 3.tga");
	*pCreepEngine->getBitmap(STATICBARFLAG, NULL, 3) = al_load_bitmap("Sprites\\Bars\\Bar 4.tga");
	*pCreepEngine->getBitmap(STATICBARFLAG, NULL, 4) = al_load_bitmap("Sprites\\Bars\\Bar 5.tga");
}

void bitmapLoader::interfaceLoad()
{
	*pTowerEngine->getBitmap(BEACONSFLAG, NULL) = al_load_bitmap("Sprites\\Interface\\Beacons.tga");
	sideUI = al_load_bitmap("Sprites\\Interface\\Interface.tga");
	button = al_load_bitmap("Sprites\\Interface\\Button.tga");
	creepOverlay[0] = al_load_bitmap("Sprites\\Interface\\Overlay Marine.tga");
	creepOverlay[1] = al_load_bitmap("Sprites\\Interface\\Overlay Hydralisk.tga");
	creepOverlay[2] = al_load_bitmap("Sprites\\Interface\\Overlay Goliath.tga");
	creepOverlay[3] = al_load_bitmap("Sprites\\Interface\\Overlay Arbiter.tga");
	creepOverlay[4] = al_load_bitmap("Sprites\\Interface\\Overlay Ultralisk.tga");
	miniMenu = al_load_bitmap("Sprites\\Interface\\Mini Menu.tga");
	tooltipFont = al_load_ttf_font("Prototype.ttf", 18, NULL);

	newMenu = al_load_bitmap("Sprites\\New Menu\\New Menu 1.tga");

	newMenuButton[0][0] = al_load_bitmap("Sprites\\New Menu\\Button 1.tga");
	newMenuButton[0][1] = al_load_bitmap("Sprites\\New Menu\\Button 2.tga");
	newMenuButton[0][2] = al_load_bitmap("Sprites\\New Menu\\Button 3.tga");
	newMenuButton[0][3] = al_load_bitmap("Sprites\\New Menu\\Button 4.tga");
	newMenuButton[0][4] = al_load_bitmap("Sprites\\New Menu\\Button 5.tga");

	newMenuButtonViking[0][0] = al_load_bitmap("Sprites\\New Menu\\ButtonVikingGroundDisabled.tga");
	newMenuButtonViking[0][1] = al_load_bitmap("Sprites\\New Menu\\ButtonVikingGroundEnabled.tga");
	newMenuButtonViking[1][0] = al_load_bitmap("Sprites\\New Menu\\ButtonVikingAirDisabled.tga");
	newMenuButtonViking[1][1] = al_load_bitmap("Sprites\\New Menu\\ButtonVikingAirEnabled.tga");

	newMenuButton[1][0] = al_load_bitmap("Sprites\\New Menu\\Highlight 1.tga");
	newMenuButton[1][1] = al_load_bitmap("Sprites\\New Menu\\Highlight 2.tga");
	newMenuButton[1][2] = al_load_bitmap("Sprites\\New Menu\\Highlight 3.tga");
	newMenuButton[1][3] = al_load_bitmap("Sprites\\New Menu\\Highlight 4.tga");
	newMenuButton[1][4] = al_load_bitmap("Sprites\\New Menu\\Highlight 5.tga");

	turretTooltip = al_load_bitmap("Sprites\\Towers\\Bunker\\TurretTooltip.tga");
	siegeTooltip = al_load_bitmap("Sprites\\Towers\\Bunker\\SiegeTooltip.tga");
	bunkerTooltip = al_load_bitmap("Sprites\\Towers\\Bunker\\BunkerTooltip.tga");
}

void bitmapLoader::menuLoad()
{
	menu[0] = al_load_bitmap("Sprites\\Interface\\Main Menu 1.tga");
	menu[1] = al_load_bitmap("Sprites\\Interface\\Main Menu 2.tga");
	menu[2] = al_load_bitmap("Sprites\\Interface\\Main Menu 3.tga");
}

void bitmapLoader::towerLoad()
{
	*pTowerEngine->getBitmap(BUNKERFLAG, 0) = al_load_bitmap("Sprites\\Towers\\Bunker\\Bunker 1.tga");
	*pTowerEngine->getBitmap(BUNKERFLAG, 1) = al_load_bitmap("Sprites\\Towers\\Bunker\\Bunker 2.tga");
	*pTowerEngine->getBitmap(BUNKERFLAG, 2) = al_load_bitmap("Sprites\\Towers\\Bunker\\Bunker 3.tga");
	*pTowerEngine->getBitmap(BUNKERFLAG, 3) = al_load_bitmap("Sprites\\Towers\\Bunker\\Bunker 4.tga");
	*pTowerEngine->getBitmap(BUNKERFLAG, 4) = al_load_bitmap("Sprites\\Towers\\Bunker\\Bunker 5.tga");
	*pTowerEngine->getBitmap(BUNKERFLAG, 5) = al_load_bitmap("Sprites\\Towers\\Bunker\\Bunker 6.tga");

	*pTowerEngine->getBitmap(TURRETFLAG, 0) = al_load_bitmap("Sprites\\Towers\\Turret\\Turret 1.tga");
	*pTowerEngine->getBitmap(TURRETFLAG, 1) = al_load_bitmap("Sprites\\Towers\\Turret\\Turret 2.tga");
	*pTowerEngine->getBitmap(TURRETFLAG, 2) = al_load_bitmap("Sprites\\Towers\\Turret\\Turret 3.tga");

	*pTowerEngine->getBitmap(SIEGETANKFLAG, 0) = al_load_bitmap("Sprites\\Towers\\Siege\\Siege Tank 1.tga");
	*pTowerEngine->getBitmap(SIEGETANKFLAG, 1) = al_load_bitmap("Sprites\\Towers\\Siege\\Siege Tank 2.tga");
	*pTowerEngine->getBitmap(SIEGETANKFLAG, 2) = al_load_bitmap("Sprites\\Towers\\Siege\\Siege Tank 3.tga");
	*pTowerEngine->getBitmap(SIEGETANKFLAG, 3) = al_load_bitmap("Sprites\\Towers\\Siege\\Siege Tank 4.tga");
	*pTowerEngine->getBitmap(SIEGETANKFLAG, 4) = al_load_bitmap("Sprites\\Towers\\Siege\\Siege Tank 5.tga");
	*pTowerEngine->getBitmap(SIEGETANKFLAG, 5) = al_load_bitmap("Sprites\\Towers\\Siege\\Siege Tank 6.tga");
	*pTowerEngine->getBitmap(SIEGETANKFLAG, 6) = al_load_bitmap("Sprites\\Towers\\Siege\\Siege Tank 7.tga");

	*pTowerEngine->getBitmap(ASSAULTVIKINGFLAG, 0) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Assault Viking 1.tga");
	*pTowerEngine->getBitmap(ASSAULTVIKINGFLAG, 1) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Assault Viking 2.tga");
	*pTowerEngine->getBitmap(ASSAULTVIKINGFLAG, 2) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Assault Viking 3.tga");
	*pTowerEngine->getBitmap(ASSAULTVIKINGFLAG, 3) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Assault Viking 4.tga");
	*pTowerEngine->getBitmap(ASSAULTVIKINGFLAG, 4) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Assault Viking 5.tga");
	*pTowerEngine->getBitmap(ASSAULTVIKINGFLAG, 5) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Assault Viking 6.tga");
	*pTowerEngine->getBitmap(ASSAULTVIKINGFLAG, 6) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Assault Viking 7.tga");
	*pTowerEngine->getBitmap(ASSAULTVIKINGFLAG, 7) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Assault Viking 8.tga");
	*pTowerEngine->getBitmap(ASSAULTVIKINGFLAG, 8) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Assault Viking 9.tga");
	*pTowerEngine->getBitmap(ASSAULTVIKINGFLAG, 9) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Assault Viking 10.tga");
	*pTowerEngine->getBitmap(ASSAULTVIKINGFLAG, 10) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Assault Viking 11.tga");
	*pTowerEngine->getBitmap(ASSAULTVIKINGFLAG, 11) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Assault Viking 12.tga");
	*pTowerEngine->getBitmap(ASSAULTVIKINGFLAG, 12) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Assault Viking 13.tga");
	*pTowerEngine->getBitmap(ASSAULTVIKINGFLAG, 13) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Assault Viking 14.tga");
	*pTowerEngine->getBitmap(ASSAULTVIKINGFLAG, 14) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Assault Viking 15.tga");
	*pTowerEngine->getBitmap(ASSAULTVIKINGFLAG, 15) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Assault Viking 16.tga");
	*pTowerEngine->getBitmap(ASSAULTVIKINGFLAG, 16) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Assault Viking 17.tga");
	*pTowerEngine->getBitmap(ASSAULTVIKINGFLAG, 17) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Assault Viking 18.tga");
	*pTowerEngine->getBitmap(ASSAULTVIKINGFLAG, 18) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Assault Viking 19.tga");
	*pTowerEngine->getBitmap(ASSAULTVIKINGFLAG, 19) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Assault Viking 20.tga");
	*pTowerEngine->getBitmap(ASSAULTVIKINGFLAG, 20) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Assault Viking 21.tga");
	*pTowerEngine->getBitmap(ASSAULTVIKINGFLAG, 21) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Assault Viking 22.tga");
	*pTowerEngine->getBitmap(ASSAULTVIKINGFLAG, 22) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Assault Viking 23.tga");
	*pTowerEngine->getBitmap(ASSAULTVIKINGFLAG, 23) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Assault Viking 24.tga");
	*pTowerEngine->getBitmap(ASSAULTVIKINGFLAG, 24) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Assault Viking 25.tga");
	*pTowerEngine->getBitmap(ASSAULTVIKINGFLAG, 25) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Assault Viking 26.tga");
	*pTowerEngine->getBitmap(ASSAULTVIKINGFLAG, 26) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Assault Viking 27.tga");
	*pTowerEngine->getBitmap(ASSAULTVIKINGFLAG, 27) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Assault Viking 28.tga");
	*pTowerEngine->getBitmap(ASSAULTVIKINGFLAG, 28) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Assault Viking 29.tga");
	*pTowerEngine->getBitmap(ASSAULTVIKINGFLAG, 29) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Assault Viking 30.tga");
	*pTowerEngine->getBitmap(ASSAULTVIKINGFLAG, 30) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Assault Viking 31.tga");
	*pTowerEngine->getBitmap(ASSAULTVIKINGFLAG, 31) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Assault Viking 32.tga");
	*pTowerEngine->getBitmap(ASSAULTVIKINGFLAG, 32) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Assault Viking 33.tga");
	*pTowerEngine->getBitmap(ASSAULTVIKINGFLAG, 33) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Assault Viking 34.tga");
	*pTowerEngine->getBitmap(ASSAULTVIKINGFLAG, 34) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Assault Viking 35.tga");
	*pTowerEngine->getBitmap(ASSAULTVIKINGFLAG, 35) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Assault Viking 36.tga");
	*pTowerEngine->getBitmap(ASSAULTVIKINGFLAG, 36) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Assault Viking 37.tga");
	*pTowerEngine->getBitmap(ASSAULTVIKINGFLAG, 37) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Assault Viking 38.tga");
	*pTowerEngine->getBitmap(ASSAULTVIKINGFLAG, 38) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Assault Viking 39.tga");
	*pTowerEngine->getBitmap(ASSAULTVIKINGFLAG, 39) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Assault Viking 40.tga");
	*pTowerEngine->getBitmap(ASSAULTVIKINGFLAG, 40) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Assault Viking 41.tga");
	*pTowerEngine->getBitmap(ASSAULTVIKINGFLAG, 41) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Assault Viking 42.tga");
	*pTowerEngine->getBitmap(ASSAULTVIKINGFLAG, 42) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Assault Viking 43.tga");
	*pTowerEngine->getBitmap(ASSAULTVIKINGFLAG, 43) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Assault Viking 44.tga");
	*pTowerEngine->getBitmap(ASSAULTVIKINGFLAG, 44) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Assault Viking 45.tga");

	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 0) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 1.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 1) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 2.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 2) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 3.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 3) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 4.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 4) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 5.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 5) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 6.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 6) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 7.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 7) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 8.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 8) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 9.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 9) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 10.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 10) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 11.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 11) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 12.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 12) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 13.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 13) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 14.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 14) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 15.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 15) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 16.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 16) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 17.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 17) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 18.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 18) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 19.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 19) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 20.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 20) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 21.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 21) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 22.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 22) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 23.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 23) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 24.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 24) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 25.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 25) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 26.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 26) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 27.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 27) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 28.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 28) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 29.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 29) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 30.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 30) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 31.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 31) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 32.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 32) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 33.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 33) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 34.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 34) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 35.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 35) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 36.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 36) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 37.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 37) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 38.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 38) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 39.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 39) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 40.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 40) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 41.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 41) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 42.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 42) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 43.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 43) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 44.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 44) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 45.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 45) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 46.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 46) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 47.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 47) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 48.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 48) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 49.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 49) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 50.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 50) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 51.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 51) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 52.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 52) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 53.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 53) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 54.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 54) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 55.tga");
	*pTowerEngine->getBitmap(ASSAULT_VIKING_BUILD_FLAG, 55) = al_load_bitmap("Sprites\\Towers\\Assault Viking\\Morph\\Viking Back Morph 56.tga");

	// *pTowerEngine->getBitmap(BUNKERTOOLTIPFLAG,0)	 = al_load_bitmap("Sprites\\Towers\\Bunker\\BunkerTooltip.tga");

}

void bitmapLoader::aircraftLoad()
{
	*pAircraftEngine->getBitmap(BULLET, NULL, 0) = al_load_bitmap("Sprites\\Aircraft\\Bullet\\Bullet 1.TGA");
	*pAircraftEngine->getBitmap(BULLET, NULL, 1) = al_load_bitmap("Sprites\\Aircraft\\Bullet\\Bullet 2.TGA");
	*pAircraftEngine->getBitmap(BULLET, NULL, 2) = al_load_bitmap("Sprites\\Aircraft\\Bullet\\Bullet 3.TGA");
	*pAircraftEngine->getBitmap(BULLET, NULL, 3) = al_load_bitmap("Sprites\\Aircraft\\Bullet\\Bullet 4.TGA");
	*pAircraftEngine->getBitmap(BULLET, NULL, 4) = al_load_bitmap("Sprites\\Aircraft\\Bullet\\Bullet 5.TGA");
	*pAircraftEngine->getBitmap(BULLET, NULL, 5) = al_load_bitmap("Sprites\\Aircraft\\Bullet\\Bullet 6.TGA");
	*pAircraftEngine->getBitmap(BULLET, NULL, 6) = al_load_bitmap("Sprites\\Aircraft\\Bullet\\Bullet 7.TGA");
	*pAircraftEngine->getBitmap(BULLET, NULL, 7) = al_load_bitmap("Sprites\\Aircraft\\Bullet\\Bullet 8.TGA");
	*pAircraftEngine->getBitmap(BULLET, NULL, 8) = al_load_bitmap("Sprites\\Aircraft\\Bullet\\Bullet 9.TGA");
	*pAircraftEngine->getBitmap(BULLET, NULL, 9) = al_load_bitmap("Sprites\\Aircraft\\Bullet\\Bullet 10.TGA");
	*pAircraftEngine->getBitmap(BULLET, NULL, 10) = al_load_bitmap("Sprites\\Aircraft\\Bullet\\Bullet 11.TGA");
	*pAircraftEngine->getBitmap(BULLET, NULL, 11) = al_load_bitmap("Sprites\\Aircraft\\Bullet\\Bullet 12.TGA");

	*pAircraftEngine->getBitmap(VIKINGBACK, LEFTSTART, 0) = al_load_bitmap("Sprites\\Aircraft\\Viking\\Back\\Left Start\\Viking Back Left 1.tga");
	*pAircraftEngine->getBitmap(VIKINGBACK, LEFTSTART, 1) = al_load_bitmap("Sprites\\Aircraft\\Viking\\Back\\Left Start\\Viking Back Left 2.tga");
	*pAircraftEngine->getBitmap(VIKINGBACK, LEFTSTART, 2) = al_load_bitmap("Sprites\\Aircraft\\Viking\\Back\\Left Start\\Viking Back Left 3.tga");
	*pAircraftEngine->getBitmap(VIKINGBACK, LEFTSTART, 3) = al_load_bitmap("Sprites\\Aircraft\\Viking\\Back\\Left Start\\Viking Back Left 4.tga");
	*pAircraftEngine->getBitmap(VIKINGBACK, LEFTSTART, 4) = al_load_bitmap("Sprites\\Aircraft\\Viking\\Back\\Left Start\\Viking Back Left 5.tga");
	*pAircraftEngine->getBitmap(VIKINGBACK, LEFTSTART, 5) = al_load_bitmap("Sprites\\Aircraft\\Viking\\Back\\Left Start\\Viking Back Left 6.tga");
	*pAircraftEngine->getBitmap(VIKINGBACK, LEFTSTART, 6) = al_load_bitmap("Sprites\\Aircraft\\Viking\\Back\\Left Start\\Viking Back Left 7.tga");

	*pAircraftEngine->getBitmap(VIKINGBACK, LEFTMANTAIN, 0) = al_load_bitmap("Sprites\\Aircraft\\Viking\\Back\\Left Mantain\\Viking Back Left Mantain 1.tga");
	*pAircraftEngine->getBitmap(VIKINGBACK, LEFTMANTAIN, 1) = al_load_bitmap("Sprites\\Aircraft\\Viking\\Back\\Left Mantain\\Viking Back Left Mantain 2.tga");
	*pAircraftEngine->getBitmap(VIKINGBACK, LEFTMANTAIN, 2) = al_load_bitmap("Sprites\\Aircraft\\Viking\\Back\\Left Mantain\\Viking Back Left Mantain 3.tga");
	*pAircraftEngine->getBitmap(VIKINGBACK, LEFTMANTAIN, 3) = al_load_bitmap("Sprites\\Aircraft\\Viking\\Back\\Left Mantain\\Viking Back Left Mantain 4.tga");
	*pAircraftEngine->getBitmap(VIKINGBACK, LEFTMANTAIN, 4) = al_load_bitmap("Sprites\\Aircraft\\Viking\\Back\\Left Mantain\\Viking Back Left Mantain 5.tga");
	*pAircraftEngine->getBitmap(VIKINGBACK, LEFTMANTAIN, 5) = al_load_bitmap("Sprites\\Aircraft\\Viking\\Back\\Left Mantain\\Viking Back Left Mantain 6.tga");

	*pAircraftEngine->getBitmap(VIKINGBACK, RIGHTSTART, 0) = al_load_bitmap("Sprites\\Aircraft\\Viking\\Back\\Right Start\\Viking Back Right Start 1.tga");
	*pAircraftEngine->getBitmap(VIKINGBACK, RIGHTSTART, 1) = al_load_bitmap("Sprites\\Aircraft\\Viking\\Back\\Right Start\\Viking Back Right Start 2.tga");
	*pAircraftEngine->getBitmap(VIKINGBACK, RIGHTSTART, 2) = al_load_bitmap("Sprites\\Aircraft\\Viking\\Back\\Right Start\\Viking Back Right Start 3.tga");
	*pAircraftEngine->getBitmap(VIKINGBACK, RIGHTSTART, 3) = al_load_bitmap("Sprites\\Aircraft\\Viking\\Back\\Right Start\\Viking Back Right Start 4.tga");
	*pAircraftEngine->getBitmap(VIKINGBACK, RIGHTSTART, 4) = al_load_bitmap("Sprites\\Aircraft\\Viking\\Back\\Right Start\\Viking Back Right Start 5.tga");
	*pAircraftEngine->getBitmap(VIKINGBACK, RIGHTSTART, 5) = al_load_bitmap("Sprites\\Aircraft\\Viking\\Back\\Right Start\\Viking Back Right Start 6.tga");
	*pAircraftEngine->getBitmap(VIKINGBACK, RIGHTSTART, 6) = al_load_bitmap("Sprites\\Aircraft\\Viking\\Back\\Right Start\\Viking Back Right Start 7.tga");

	*pAircraftEngine->getBitmap(VIKINGBACK, RIGHTMANTAIN, 0) = al_load_bitmap("Sprites\\Aircraft\\Viking\\Back\\Right Mantain\\Viking Back Right Mantain 1.tga");
	*pAircraftEngine->getBitmap(VIKINGBACK, RIGHTMANTAIN, 1) = al_load_bitmap("Sprites\\Aircraft\\Viking\\Back\\Right Mantain\\Viking Back Right Mantain 2.tga");
	*pAircraftEngine->getBitmap(VIKINGBACK, RIGHTMANTAIN, 2) = al_load_bitmap("Sprites\\Aircraft\\Viking\\Back\\Right Mantain\\Viking Back Right Mantain 3.tga");
	*pAircraftEngine->getBitmap(VIKINGBACK, RIGHTMANTAIN, 3) = al_load_bitmap("Sprites\\Aircraft\\Viking\\Back\\Right Mantain\\Viking Back Right Mantain 4.tga");
	*pAircraftEngine->getBitmap(VIKINGBACK, RIGHTMANTAIN, 4) = al_load_bitmap("Sprites\\Aircraft\\Viking\\Back\\Right Mantain\\Viking Back Right Mantain 5.tga");
	*pAircraftEngine->getBitmap(VIKINGBACK, RIGHTMANTAIN, 5) = al_load_bitmap("Sprites\\Aircraft\\Viking\\Back\\Right Mantain\\Viking Back Right Mantain 6.tga");

	*pAircraftEngine->getBitmap(VIKINGBACK, STILL, 0) = al_load_bitmap("Sprites\\Aircraft\\Viking\\Back\\Idle\\Viking Back Idle 1.tga");
	*pAircraftEngine->getBitmap(VIKINGBACK, STILL, 1) = al_load_bitmap("Sprites\\Aircraft\\Viking\\Back\\Idle\\Viking Back Idle 2.tga");
	*pAircraftEngine->getBitmap(VIKINGBACK, STILL, 2) = al_load_bitmap("Sprites\\Aircraft\\Viking\\Back\\Idle\\Viking Back Idle 3.tga");
	*pAircraftEngine->getBitmap(VIKINGBACK, STILL, 3) = al_load_bitmap("Sprites\\Aircraft\\Viking\\Back\\Idle\\Viking Back Idle 4.tga");
	*pAircraftEngine->getBitmap(VIKINGBACK, STILL, 4) = al_load_bitmap("Sprites\\Aircraft\\Viking\\Back\\Idle\\Viking Back Idle 5.tga");
	*pAircraftEngine->getBitmap(VIKINGBACK, STILL, 5) = al_load_bitmap("Sprites\\Aircraft\\Viking\\Back\\Idle\\Viking Back Idle 6.tga");
	*pAircraftEngine->getBitmap(VIKINGBACK, STILL, 6) = al_load_bitmap("Sprites\\Aircraft\\Viking\\Back\\Idle\\Viking Back Idle 7.tga");
	*pAircraftEngine->getBitmap(VIKINGBACK, STILL, 7) = al_load_bitmap("Sprites\\Aircraft\\Viking\\Back\\Idle\\Viking Back Idle 8.tga");
}

void bitmapLoader::creepLoad()
{
	*pCreepEngine->getBitmap(MARINEFLAG, 0, 0) = al_load_bitmap("Sprites\\Creeps\\Marine\\Left\\Marine Left 1.tga");
	*pCreepEngine->getBitmap(MARINEFLAG, 0, 1) = al_load_bitmap("Sprites\\Creeps\\Marine\\Left\\Marine Left 2.tga");
	*pCreepEngine->getBitmap(MARINEFLAG, 0, 2) = al_load_bitmap("Sprites\\Creeps\\Marine\\Left\\Marine Left 3.tga");
	*pCreepEngine->getBitmap(MARINEFLAG, 0, 3) = al_load_bitmap("Sprites\\Creeps\\Marine\\Left\\Marine Left 4.tga");
	*pCreepEngine->getBitmap(MARINEFLAG, 0, 4) = al_load_bitmap("Sprites\\Creeps\\Marine\\Left\\Marine Left 5.tga");
	*pCreepEngine->getBitmap(MARINEFLAG, 0, 5) = al_load_bitmap("Sprites\\Creeps\\Marine\\Left\\Marine Left 6.tga");
	*pCreepEngine->getBitmap(MARINEFLAG, 0, 6) = al_load_bitmap("Sprites\\Creeps\\Marine\\Left\\Marine Left 7.tga");
	*pCreepEngine->getBitmap(MARINEFLAG, 0, 7) = al_load_bitmap("Sprites\\Creeps\\Marine\\Left\\Marine Left 8.tga");
	*pCreepEngine->getBitmap(MARINEFLAG, 0, 8) = al_load_bitmap("Sprites\\Creeps\\Marine\\Left\\Marine Left 9.tga");
	*pCreepEngine->getBitmap(MARINEFLAG, 0, 9) = al_load_bitmap("Sprites\\Creeps\\Marine\\Left\\Marine Left 10.tga");

	*pCreepEngine->getBitmap(MARINEFLAG, 1, 0) = al_load_bitmap("Sprites\\Creeps\\Marine\\Right\\Marine Right 1.tga");
	*pCreepEngine->getBitmap(MARINEFLAG, 1, 1) = al_load_bitmap("Sprites\\Creeps\\Marine\\Right\\Marine Right 2.tga");
	*pCreepEngine->getBitmap(MARINEFLAG, 1, 2) = al_load_bitmap("Sprites\\Creeps\\Marine\\Right\\Marine Right 3.tga");
	*pCreepEngine->getBitmap(MARINEFLAG, 1, 3) = al_load_bitmap("Sprites\\Creeps\\Marine\\Right\\Marine Right 4.tga");
	*pCreepEngine->getBitmap(MARINEFLAG, 1, 4) = al_load_bitmap("Sprites\\Creeps\\Marine\\Right\\Marine Right 5.tga");
	*pCreepEngine->getBitmap(MARINEFLAG, 1, 5) = al_load_bitmap("Sprites\\Creeps\\Marine\\Right\\Marine Right 6.tga");
	*pCreepEngine->getBitmap(MARINEFLAG, 1, 6) = al_load_bitmap("Sprites\\Creeps\\Marine\\Right\\Marine Right 7.tga");
	*pCreepEngine->getBitmap(MARINEFLAG, 1, 7) = al_load_bitmap("Sprites\\Creeps\\Marine\\Right\\Marine Right 8.tga");
	*pCreepEngine->getBitmap(MARINEFLAG, 1, 8) = al_load_bitmap("Sprites\\Creeps\\Marine\\Right\\Marine Right 9.tga");
	*pCreepEngine->getBitmap(MARINEFLAG, 1, 9) = al_load_bitmap("Sprites\\Creeps\\Marine\\Right\\Marine Right 10.tga");

	*pCreepEngine->getBitmap(MARINEFLAG, 2, 0) = al_load_bitmap("Sprites\\Creeps\\Marine\\Rear Left\\Marine Rear Left 1.tga");
	*pCreepEngine->getBitmap(MARINEFLAG, 2, 1) = al_load_bitmap("Sprites\\Creeps\\Marine\\Rear Left\\Marine Rear Left 2.tga");
	*pCreepEngine->getBitmap(MARINEFLAG, 2, 2) = al_load_bitmap("Sprites\\Creeps\\Marine\\Rear Left\\Marine Rear Left 3.tga");
	*pCreepEngine->getBitmap(MARINEFLAG, 2, 3) = al_load_bitmap("Sprites\\Creeps\\Marine\\Rear Left\\Marine Rear Left 4.tga");
	*pCreepEngine->getBitmap(MARINEFLAG, 2, 4) = al_load_bitmap("Sprites\\Creeps\\Marine\\Rear Left\\Marine Rear Left 5.tga");
	*pCreepEngine->getBitmap(MARINEFLAG, 2, 5) = al_load_bitmap("Sprites\\Creeps\\Marine\\Rear Left\\Marine Rear Left 6.tga");
	*pCreepEngine->getBitmap(MARINEFLAG, 2, 6) = al_load_bitmap("Sprites\\Creeps\\Marine\\Rear Left\\Marine Rear Left 7.tga");
	*pCreepEngine->getBitmap(MARINEFLAG, 2, 7) = al_load_bitmap("Sprites\\Creeps\\Marine\\Rear Left\\Marine Rear Left 8.tga");
	*pCreepEngine->getBitmap(MARINEFLAG, 2, 8) = al_load_bitmap("Sprites\\Creeps\\Marine\\Rear Left\\Marine Rear Left 9.tga");
	*pCreepEngine->getBitmap(MARINEFLAG, 2, 9) = al_load_bitmap("Sprites\\Creeps\\Marine\\Rear Left\\Marine Rear Left 10.tga");

	*pCreepEngine->getBitmap(MARINEFLAG, 3, 0) = al_load_bitmap("Sprites\\Creeps\\Marine\\Rear Right\\Marine Rear Right 1.tga");
	*pCreepEngine->getBitmap(MARINEFLAG, 3, 1) = al_load_bitmap("Sprites\\Creeps\\Marine\\Rear Right\\Marine Rear Right 2.tga");
	*pCreepEngine->getBitmap(MARINEFLAG, 3, 2) = al_load_bitmap("Sprites\\Creeps\\Marine\\Rear Right\\Marine Rear Right 3.tga");
	*pCreepEngine->getBitmap(MARINEFLAG, 3, 3) = al_load_bitmap("Sprites\\Creeps\\Marine\\Rear Right\\Marine Rear Right 4.tga");
	*pCreepEngine->getBitmap(MARINEFLAG, 3, 4) = al_load_bitmap("Sprites\\Creeps\\Marine\\Rear Right\\Marine Rear Right 5.tga");
	*pCreepEngine->getBitmap(MARINEFLAG, 3, 5) = al_load_bitmap("Sprites\\Creeps\\Marine\\Rear Right\\Marine Rear Right 6.tga");
	*pCreepEngine->getBitmap(MARINEFLAG, 3, 6) = al_load_bitmap("Sprites\\Creeps\\Marine\\Rear Right\\Marine Rear Right 7.tga");
	*pCreepEngine->getBitmap(MARINEFLAG, 3, 7) = al_load_bitmap("Sprites\\Creeps\\Marine\\Rear Right\\Marine Rear Right 8.tga");
	*pCreepEngine->getBitmap(MARINEFLAG, 3, 8) = al_load_bitmap("Sprites\\Creeps\\Marine\\Rear Right\\Marine Rear Right 9.tga");
	*pCreepEngine->getBitmap(MARINEFLAG, 3, 9) = al_load_bitmap("Sprites\\Creeps\\Marine\\Rear Right\\Marine Rear Right 10.tga");

	*pCreepEngine->getBitmap(MARINEDEATHFLAG, 0, 0) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 1.tga");
	*pCreepEngine->getBitmap(MARINEDEATHFLAG, 0, 1) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 2.tga");
	*pCreepEngine->getBitmap(MARINEDEATHFLAG, 0, 2) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 3.tga");
	*pCreepEngine->getBitmap(MARINEDEATHFLAG, 0, 3) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 4.tga");
	*pCreepEngine->getBitmap(MARINEDEATHFLAG, 0, 4) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 5.tga");
	*pCreepEngine->getBitmap(MARINEDEATHFLAG, 0, 5) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 6.tga");
	*pCreepEngine->getBitmap(MARINEDEATHFLAG, 0, 6) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 7.tga");
	*pCreepEngine->getBitmap(MARINEDEATHFLAG, 0, 7) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 8.tga");
	*pCreepEngine->getBitmap(MARINEDEATHFLAG, 0, 8) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 9.tga");
	*pCreepEngine->getBitmap(MARINEDEATHFLAG, 0, 9) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 10.tga");

	*pCreepEngine->getBitmap(MARINEDEATHFLAG, 1, 0) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 1.tga");
	*pCreepEngine->getBitmap(MARINEDEATHFLAG, 1, 1) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 2.tga");
	*pCreepEngine->getBitmap(MARINEDEATHFLAG, 1, 2) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 3.tga");
	*pCreepEngine->getBitmap(MARINEDEATHFLAG, 1, 3) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 4.tga");
	*pCreepEngine->getBitmap(MARINEDEATHFLAG, 1, 4) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 5.tga");
	*pCreepEngine->getBitmap(MARINEDEATHFLAG, 1, 5) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 6.tga");
	*pCreepEngine->getBitmap(MARINEDEATHFLAG, 1, 6) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 7.tga");
	*pCreepEngine->getBitmap(MARINEDEATHFLAG, 1, 7) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 8.tga");
	*pCreepEngine->getBitmap(MARINEDEATHFLAG, 1, 8) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 9.tga");
	*pCreepEngine->getBitmap(MARINEDEATHFLAG, 1, 9) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 10.tga");

	*pCreepEngine->getBitmap(MARINEDEATHFLAG, 2, 0) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 1.tga");
	*pCreepEngine->getBitmap(MARINEDEATHFLAG, 2, 1) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 2.tga");
	*pCreepEngine->getBitmap(MARINEDEATHFLAG, 2, 2) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 3.tga");
	*pCreepEngine->getBitmap(MARINEDEATHFLAG, 2, 3) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 4.tga");
	*pCreepEngine->getBitmap(MARINEDEATHFLAG, 2, 4) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 5.tga");
	*pCreepEngine->getBitmap(MARINEDEATHFLAG, 2, 5) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 6.tga");
	*pCreepEngine->getBitmap(MARINEDEATHFLAG, 2, 6) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 7.tga");
	*pCreepEngine->getBitmap(MARINEDEATHFLAG, 2, 7) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 8.tga");
	*pCreepEngine->getBitmap(MARINEDEATHFLAG, 2, 8) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 9.tga");
	*pCreepEngine->getBitmap(MARINEDEATHFLAG, 2, 9) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 10.tga");

	*pCreepEngine->getBitmap(MARINEDEATHFLAG, 3, 0) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 1.tga");
	*pCreepEngine->getBitmap(MARINEDEATHFLAG, 3, 1) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 2.tga");
	*pCreepEngine->getBitmap(MARINEDEATHFLAG, 3, 2) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 3.tga");
	*pCreepEngine->getBitmap(MARINEDEATHFLAG, 3, 3) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 4.tga");
	*pCreepEngine->getBitmap(MARINEDEATHFLAG, 3, 4) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 5.tga");
	*pCreepEngine->getBitmap(MARINEDEATHFLAG, 3, 5) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 6.tga");
	*pCreepEngine->getBitmap(MARINEDEATHFLAG, 3, 6) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 7.tga");
	*pCreepEngine->getBitmap(MARINEDEATHFLAG, 3, 7) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 8.tga");
	*pCreepEngine->getBitmap(MARINEDEATHFLAG, 3, 8) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 9.tga");
	*pCreepEngine->getBitmap(MARINEDEATHFLAG, 3, 9) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 10.tga");

	*pCreepEngine->getBitmap(HYDRALISKFLAG, 0, 0) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Left\\Hydralisk Left 1.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 0, 1) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Left\\Hydralisk Left 2.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 0, 2) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Left\\Hydralisk Left 3.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 0, 3) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Left\\Hydralisk Left 4.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 0, 4) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Left\\Hydralisk Left 5.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 0, 5) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Left\\Hydralisk Left 6.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 0, 6) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Left\\Hydralisk Left 7.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 0, 7) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Left\\Hydralisk Left 8.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 0, 8) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Left\\Hydralisk Left 9.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 0, 9) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Left\\Hydralisk Left 10.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 0, 10) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Left\\Hydralisk Left 11.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 0, 11) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Left\\Hydralisk Left 12.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 0, 12) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Left\\Hydralisk Left 13.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 0, 13) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Left\\Hydralisk Left 14.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 0, 14) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Left\\Hydralisk Left 15.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 0, 15) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Left\\Hydralisk Left 16.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 0, 16) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Left\\Hydralisk Left 17.tga");

	*pCreepEngine->getBitmap(HYDRALISKFLAG, 1, 0) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Right\\Hydralisk Right 1.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 1, 1) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Right\\Hydralisk Right 2.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 1, 2) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Right\\Hydralisk Right 3.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 1, 3) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Right\\Hydralisk Right 4.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 1, 4) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Right\\Hydralisk Right 5.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 1, 5) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Right\\Hydralisk Right 6.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 1, 6) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Right\\Hydralisk Right 7.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 1, 7) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Right\\Hydralisk Right 8.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 1, 8) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Right\\Hydralisk Right 9.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 1, 9) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Right\\Hydralisk Right 10.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 1, 10) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Right\\Hydralisk Right 11.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 1, 11) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Right\\Hydralisk Right 12.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 1, 12) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Right\\Hydralisk Right 13.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 1, 13) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Right\\Hydralisk Right 14.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 1, 14) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Right\\Hydralisk Right 15.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 1, 15) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Right\\Hydralisk Right 16.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 1, 16) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Right\\Hydralisk Right 17.tga");

	*pCreepEngine->getBitmap(HYDRALISKFLAG, 2, 0) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Rear Left\\Hydralisk Rear Left 1.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 2, 1) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Rear Left\\Hydralisk Rear Left 2.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 2, 2) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Rear Left\\Hydralisk Rear Left 3.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 2, 3) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Rear Left\\Hydralisk Rear Left 4.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 2, 4) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Rear Left\\Hydralisk Rear Left 5.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 2, 5) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Rear Left\\Hydralisk Rear Left 6.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 2, 6) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Rear Left\\Hydralisk Rear Left 7.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 2, 7) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Rear Left\\Hydralisk Rear Left 8.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 2, 8) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Rear Left\\Hydralisk Rear Left 9.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 2, 9) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Rear Left\\Hydralisk Rear Left 10.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 2, 10) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Rear Left\\Hydralisk Rear Left 11.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 2, 11) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Rear Left\\Hydralisk Rear Left 12.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 2, 12) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Rear Left\\Hydralisk Rear Left 13.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 2, 13) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Rear Left\\Hydralisk Rear Left 14.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 2, 14) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Rear Left\\Hydralisk Rear Left 15.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 2, 15) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Rear Left\\Hydralisk Rear Left 16.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 2, 16) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Rear Left\\Hydralisk Rear Left 17.tga");

	*pCreepEngine->getBitmap(HYDRALISKFLAG, 3, 0) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Rear Right\\Hydralisk Rear Right 1.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 3, 1) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Rear Right\\Hydralisk Rear Right 2.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 3, 2) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Rear Right\\Hydralisk Rear Right 3.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 3, 3) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Rear Right\\Hydralisk Rear Right 4.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 3, 4) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Rear Right\\Hydralisk Rear Right 5.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 3, 5) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Rear Right\\Hydralisk Rear Right 6.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 3, 6) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Rear Right\\Hydralisk Rear Right 7.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 3, 7) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Rear Right\\Hydralisk Rear Right 8.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 3, 8) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Rear Right\\Hydralisk Rear Right 9.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 3, 9) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Rear Right\\Hydralisk Rear Right 10.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 3, 10) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Rear Right\\Hydralisk Rear Right 11.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 3, 11) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Rear Right\\Hydralisk Rear Right 12.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 3, 12) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Rear Right\\Hydralisk Rear Right 13.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 3, 13) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Rear Right\\Hydralisk Rear Right 14.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 3, 14) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Rear Right\\Hydralisk Rear Right 15.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 3, 15) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Rear Right\\Hydralisk Rear Right 16.tga");
	*pCreepEngine->getBitmap(HYDRALISKFLAG, 3, 16) = al_load_bitmap("Sprites\\Creeps\\Hydralisk\\Rear Right\\Hydralisk Rear Right 17.tga");

	*pCreepEngine->getBitmap(HYDRALISKDEATHFLAG, 0, 0) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 1.tga");
	*pCreepEngine->getBitmap(HYDRALISKDEATHFLAG, 0, 1) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 2.tga");
	*pCreepEngine->getBitmap(HYDRALISKDEATHFLAG, 0, 2) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 3.tga");
	*pCreepEngine->getBitmap(HYDRALISKDEATHFLAG, 0, 3) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 4.tga");
	*pCreepEngine->getBitmap(HYDRALISKDEATHFLAG, 0, 4) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 5.tga");
	*pCreepEngine->getBitmap(HYDRALISKDEATHFLAG, 0, 5) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 6.tga");
	*pCreepEngine->getBitmap(HYDRALISKDEATHFLAG, 0, 6) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 7.tga");
	*pCreepEngine->getBitmap(HYDRALISKDEATHFLAG, 0, 7) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 8.tga");
	*pCreepEngine->getBitmap(HYDRALISKDEATHFLAG, 0, 8) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 9.tga");
	*pCreepEngine->getBitmap(HYDRALISKDEATHFLAG, 0, 9) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 10.tga");

	*pCreepEngine->getBitmap(HYDRALISKDEATHFLAG, 1, 0) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 1.tga");
	*pCreepEngine->getBitmap(HYDRALISKDEATHFLAG, 1, 1) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 2.tga");
	*pCreepEngine->getBitmap(HYDRALISKDEATHFLAG, 1, 2) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 3.tga");
	*pCreepEngine->getBitmap(HYDRALISKDEATHFLAG, 1, 3) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 4.tga");
	*pCreepEngine->getBitmap(HYDRALISKDEATHFLAG, 1, 4) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 5.tga");
	*pCreepEngine->getBitmap(HYDRALISKDEATHFLAG, 1, 5) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 6.tga");
	*pCreepEngine->getBitmap(HYDRALISKDEATHFLAG, 1, 6) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 7.tga");
	*pCreepEngine->getBitmap(HYDRALISKDEATHFLAG, 1, 7) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 8.tga");
	*pCreepEngine->getBitmap(HYDRALISKDEATHFLAG, 1, 8) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 9.tga");
	*pCreepEngine->getBitmap(HYDRALISKDEATHFLAG, 1, 9) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 10.tga");

	*pCreepEngine->getBitmap(HYDRALISKDEATHFLAG, 2, 0) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 1.tga");
	*pCreepEngine->getBitmap(HYDRALISKDEATHFLAG, 2, 1) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 2.tga");
	*pCreepEngine->getBitmap(HYDRALISKDEATHFLAG, 2, 2) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 3.tga");
	*pCreepEngine->getBitmap(HYDRALISKDEATHFLAG, 2, 3) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 4.tga");
	*pCreepEngine->getBitmap(HYDRALISKDEATHFLAG, 2, 4) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 5.tga");
	*pCreepEngine->getBitmap(HYDRALISKDEATHFLAG, 2, 5) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 6.tga");
	*pCreepEngine->getBitmap(HYDRALISKDEATHFLAG, 2, 6) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 7.tga");
	*pCreepEngine->getBitmap(HYDRALISKDEATHFLAG, 2, 7) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 8.tga");
	*pCreepEngine->getBitmap(HYDRALISKDEATHFLAG, 2, 8) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 9.tga");
	*pCreepEngine->getBitmap(HYDRALISKDEATHFLAG, 2, 9) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 10.tga");

	*pCreepEngine->getBitmap(HYDRALISKDEATHFLAG, 3, 0) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 1.tga");
	*pCreepEngine->getBitmap(HYDRALISKDEATHFLAG, 3, 1) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 2.tga");
	*pCreepEngine->getBitmap(HYDRALISKDEATHFLAG, 3, 2) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 3.tga");
	*pCreepEngine->getBitmap(HYDRALISKDEATHFLAG, 3, 3) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 4.tga");
	*pCreepEngine->getBitmap(HYDRALISKDEATHFLAG, 3, 4) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 5.tga");
	*pCreepEngine->getBitmap(HYDRALISKDEATHFLAG, 3, 5) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 6.tga");
	*pCreepEngine->getBitmap(HYDRALISKDEATHFLAG, 3, 6) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 7.tga");
	*pCreepEngine->getBitmap(HYDRALISKDEATHFLAG, 3, 7) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 8.tga");
	*pCreepEngine->getBitmap(HYDRALISKDEATHFLAG, 3, 8) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 9.tga");
	*pCreepEngine->getBitmap(HYDRALISKDEATHFLAG, 3, 9) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 10.tga");

	*pCreepEngine->getBitmap(THORFLAG, 0, 0) = al_load_bitmap("Sprites\\Creeps\\Thor\\Left\\Thor Left 1.tga");
	*pCreepEngine->getBitmap(THORFLAG, 0, 1) = al_load_bitmap("Sprites\\Creeps\\Thor\\Left\\Thor Left 2.tga");
	*pCreepEngine->getBitmap(THORFLAG, 0, 2) = al_load_bitmap("Sprites\\Creeps\\Thor\\Left\\Thor Left 3.tga");
	*pCreepEngine->getBitmap(THORFLAG, 0, 3) = al_load_bitmap("Sprites\\Creeps\\Thor\\Left\\Thor Left 4.tga");
	*pCreepEngine->getBitmap(THORFLAG, 0, 4) = al_load_bitmap("Sprites\\Creeps\\Thor\\Left\\Thor Left 5.tga");
	*pCreepEngine->getBitmap(THORFLAG, 0, 5) = al_load_bitmap("Sprites\\Creeps\\Thor\\Left\\Thor Left 6.tga");
	*pCreepEngine->getBitmap(THORFLAG, 0, 6) = al_load_bitmap("Sprites\\Creeps\\Thor\\Left\\Thor Left 7.tga");
	*pCreepEngine->getBitmap(THORFLAG, 0, 7) = al_load_bitmap("Sprites\\Creeps\\Thor\\Left\\Thor Left 8.tga");
	*pCreepEngine->getBitmap(THORFLAG, 0, 8) = al_load_bitmap("Sprites\\Creeps\\Thor\\Left\\Thor Left 9.tga");
	*pCreepEngine->getBitmap(THORFLAG, 0, 9) = al_load_bitmap("Sprites\\Creeps\\Thor\\Left\\Thor Left 10.tga");
	*pCreepEngine->getBitmap(THORFLAG, 0, 10) = al_load_bitmap("Sprites\\Creeps\\Thor\\Left\\Thor Left 11.tga");
	*pCreepEngine->getBitmap(THORFLAG, 0, 11) = al_load_bitmap("Sprites\\Creeps\\Thor\\Left\\Thor Left 12.tga");
	*pCreepEngine->getBitmap(THORFLAG, 0, 12) = al_load_bitmap("Sprites\\Creeps\\Thor\\Left\\Thor Left 13.tga");
	*pCreepEngine->getBitmap(THORFLAG, 0, 13) = al_load_bitmap("Sprites\\Creeps\\Thor\\Left\\Thor Left 14.tga");
	*pCreepEngine->getBitmap(THORFLAG, 0, 14) = al_load_bitmap("Sprites\\Creeps\\Thor\\Left\\Thor Left 15.tga");

	*pCreepEngine->getBitmap(THORFLAG, 1, 0) = al_load_bitmap("Sprites\\Creeps\\Thor\\Right\\Thor Right 1.tga");
	*pCreepEngine->getBitmap(THORFLAG, 1, 1) = al_load_bitmap("Sprites\\Creeps\\Thor\\Right\\Thor Right 2.tga");
	*pCreepEngine->getBitmap(THORFLAG, 1, 2) = al_load_bitmap("Sprites\\Creeps\\Thor\\Right\\Thor Right 3.tga");
	*pCreepEngine->getBitmap(THORFLAG, 1, 3) = al_load_bitmap("Sprites\\Creeps\\Thor\\Right\\Thor Right 4.tga");
	*pCreepEngine->getBitmap(THORFLAG, 1, 4) = al_load_bitmap("Sprites\\Creeps\\Thor\\Right\\Thor Right 5.tga");
	*pCreepEngine->getBitmap(THORFLAG, 1, 5) = al_load_bitmap("Sprites\\Creeps\\Thor\\Right\\Thor Right 6.tga");
	*pCreepEngine->getBitmap(THORFLAG, 1, 6) = al_load_bitmap("Sprites\\Creeps\\Thor\\Right\\Thor Right 7.tga");
	*pCreepEngine->getBitmap(THORFLAG, 1, 7) = al_load_bitmap("Sprites\\Creeps\\Thor\\Right\\Thor Right 8.tga");
	*pCreepEngine->getBitmap(THORFLAG, 1, 8) = al_load_bitmap("Sprites\\Creeps\\Thor\\Right\\Thor Right 9.tga");
	*pCreepEngine->getBitmap(THORFLAG, 1, 9) = al_load_bitmap("Sprites\\Creeps\\Thor\\Right\\Thor Right 10.tga");
	*pCreepEngine->getBitmap(THORFLAG, 1, 10) = al_load_bitmap("Sprites\\Creeps\\Thor\\Right\\Thor Right 11.tga");
	*pCreepEngine->getBitmap(THORFLAG, 1, 11) = al_load_bitmap("Sprites\\Creeps\\Thor\\Right\\Thor Right 12.tga");
	*pCreepEngine->getBitmap(THORFLAG, 1, 12) = al_load_bitmap("Sprites\\Creeps\\Thor\\Right\\Thor Right 13.tga");
	*pCreepEngine->getBitmap(THORFLAG, 1, 13) = al_load_bitmap("Sprites\\Creeps\\Thor\\Right\\Thor Right 14.tga");
	*pCreepEngine->getBitmap(THORFLAG, 1, 14) = al_load_bitmap("Sprites\\Creeps\\Thor\\Right\\Thor Right 15.tga");


	*pCreepEngine->getBitmap(THORFLAG, 2, 0) = al_load_bitmap("Sprites\\Creeps\\Thor\\Rear Left\\Thor Rear Left 1.tga");
	*pCreepEngine->getBitmap(THORFLAG, 2, 1) = al_load_bitmap("Sprites\\Creeps\\Thor\\Rear Left\\Thor Rear Left 2.tga");
	*pCreepEngine->getBitmap(THORFLAG, 2, 2) = al_load_bitmap("Sprites\\Creeps\\Thor\\Rear Left\\Thor Rear Left 3.tga");
	*pCreepEngine->getBitmap(THORFLAG, 2, 3) = al_load_bitmap("Sprites\\Creeps\\Thor\\Rear Left\\Thor Rear Left 4.tga");
	*pCreepEngine->getBitmap(THORFLAG, 2, 4) = al_load_bitmap("Sprites\\Creeps\\Thor\\Rear Left\\Thor Rear Left 5.tga");
	*pCreepEngine->getBitmap(THORFLAG, 2, 5) = al_load_bitmap("Sprites\\Creeps\\Thor\\Rear Left\\Thor Rear Left 6.tga");
	*pCreepEngine->getBitmap(THORFLAG, 2, 6) = al_load_bitmap("Sprites\\Creeps\\Thor\\Rear Left\\Thor Rear Left 7.tga");
	*pCreepEngine->getBitmap(THORFLAG, 2, 7) = al_load_bitmap("Sprites\\Creeps\\Thor\\Rear Left\\Thor Rear Left 8.tga");
	*pCreepEngine->getBitmap(THORFLAG, 2, 8) = al_load_bitmap("Sprites\\Creeps\\Thor\\Rear Left\\Thor Rear Left 9.tga");
	*pCreepEngine->getBitmap(THORFLAG, 2, 9) = al_load_bitmap("Sprites\\Creeps\\Thor\\Rear Left\\Thor Rear Left 10.tga");
	*pCreepEngine->getBitmap(THORFLAG, 2, 10) = al_load_bitmap("Sprites\\Creeps\\Thor\\Rear Left\\Thor Rear Left 11.tga");
	*pCreepEngine->getBitmap(THORFLAG, 2, 11) = al_load_bitmap("Sprites\\Creeps\\Thor\\Rear Left\\Thor Rear Left 12.tga");
	*pCreepEngine->getBitmap(THORFLAG, 2, 12) = al_load_bitmap("Sprites\\Creeps\\Thor\\Rear Left\\Thor Rear Left 13.tga");
	*pCreepEngine->getBitmap(THORFLAG, 2, 13) = al_load_bitmap("Sprites\\Creeps\\Thor\\Rear Left\\Thor Rear Left 14.tga");
	*pCreepEngine->getBitmap(THORFLAG, 2, 14) = al_load_bitmap("Sprites\\Creeps\\Thor\\Rear Left\\Thor Rear Left 15.tga");


	*pCreepEngine->getBitmap(THORFLAG, 3, 0) = al_load_bitmap("Sprites\\Creeps\\Thor\\Rear Right\\Thor Rear Right 1.tga");
	*pCreepEngine->getBitmap(THORFLAG, 3, 1) = al_load_bitmap("Sprites\\Creeps\\Thor\\Rear Right\\Thor Rear Right 2.tga");
	*pCreepEngine->getBitmap(THORFLAG, 3, 2) = al_load_bitmap("Sprites\\Creeps\\Thor\\Rear Right\\Thor Rear Right 3.tga");
	*pCreepEngine->getBitmap(THORFLAG, 3, 3) = al_load_bitmap("Sprites\\Creeps\\Thor\\Rear Right\\Thor Rear Right 4.tga");
	*pCreepEngine->getBitmap(THORFLAG, 3, 4) = al_load_bitmap("Sprites\\Creeps\\Thor\\Rear Right\\Thor Rear Right 5.tga");
	*pCreepEngine->getBitmap(THORFLAG, 3, 5) = al_load_bitmap("Sprites\\Creeps\\Thor\\Rear Right\\Thor Rear Right 6.tga");
	*pCreepEngine->getBitmap(THORFLAG, 3, 6) = al_load_bitmap("Sprites\\Creeps\\Thor\\Rear Right\\Thor Rear Right 7.tga");
	*pCreepEngine->getBitmap(THORFLAG, 3, 7) = al_load_bitmap("Sprites\\Creeps\\Thor\\Rear Right\\Thor Rear Right 8.tga");
	*pCreepEngine->getBitmap(THORFLAG, 3, 8) = al_load_bitmap("Sprites\\Creeps\\Thor\\Rear Right\\Thor Rear Right 9.tga");
	*pCreepEngine->getBitmap(THORFLAG, 3, 9) = al_load_bitmap("Sprites\\Creeps\\Thor\\Rear Right\\Thor Rear Right 10.tga");
	*pCreepEngine->getBitmap(THORFLAG, 3, 10) = al_load_bitmap("Sprites\\Creeps\\Thor\\Rear Right\\Thor Rear Right 11.tga");
	*pCreepEngine->getBitmap(THORFLAG, 3, 11) = al_load_bitmap("Sprites\\Creeps\\Thor\\Rear Right\\Thor Rear Right 12.tga");
	*pCreepEngine->getBitmap(THORFLAG, 3, 12) = al_load_bitmap("Sprites\\Creeps\\Thor\\Rear Right\\Thor Rear Right 13.tga");
	*pCreepEngine->getBitmap(THORFLAG, 3, 13) = al_load_bitmap("Sprites\\Creeps\\Thor\\Rear Right\\Thor Rear Right 14.tga");
	*pCreepEngine->getBitmap(THORFLAG, 3, 14) = al_load_bitmap("Sprites\\Creeps\\Thor\\Rear Right\\Thor Rear Right 15.tga");

	*pCreepEngine->getBitmap(THORDEATHFLAG, 0, 0) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 1.tga");
	*pCreepEngine->getBitmap(THORDEATHFLAG, 0, 1) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 2.tga");
	*pCreepEngine->getBitmap(THORDEATHFLAG, 0, 2) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 3.tga");
	*pCreepEngine->getBitmap(THORDEATHFLAG, 0, 3) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 4.tga");
	*pCreepEngine->getBitmap(THORDEATHFLAG, 0, 4) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 5.tga");
	*pCreepEngine->getBitmap(THORDEATHFLAG, 0, 5) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 6.tga");
	*pCreepEngine->getBitmap(THORDEATHFLAG, 0, 6) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 7.tga");
	*pCreepEngine->getBitmap(THORDEATHFLAG, 0, 7) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 8.tga");
	*pCreepEngine->getBitmap(THORDEATHFLAG, 0, 8) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 9.tga");
	*pCreepEngine->getBitmap(THORDEATHFLAG, 0, 9) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 10.tga");

	*pCreepEngine->getBitmap(THORDEATHFLAG, 1, 0) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 1.tga");
	*pCreepEngine->getBitmap(THORDEATHFLAG, 1, 1) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 2.tga");
	*pCreepEngine->getBitmap(THORDEATHFLAG, 1, 2) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 3.tga");
	*pCreepEngine->getBitmap(THORDEATHFLAG, 1, 3) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 4.tga");
	*pCreepEngine->getBitmap(THORDEATHFLAG, 1, 4) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 5.tga");
	*pCreepEngine->getBitmap(THORDEATHFLAG, 1, 5) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 6.tga");
	*pCreepEngine->getBitmap(THORDEATHFLAG, 1, 6) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 7.tga");
	*pCreepEngine->getBitmap(THORDEATHFLAG, 1, 7) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 8.tga");
	*pCreepEngine->getBitmap(THORDEATHFLAG, 1, 8) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 9.tga");
	*pCreepEngine->getBitmap(THORDEATHFLAG, 1, 9) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 10.tga");

	*pCreepEngine->getBitmap(THORDEATHFLAG, 2, 0) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 1.tga");
	*pCreepEngine->getBitmap(THORDEATHFLAG, 2, 1) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 2.tga");
	*pCreepEngine->getBitmap(THORDEATHFLAG, 2, 2) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 3.tga");
	*pCreepEngine->getBitmap(THORDEATHFLAG, 2, 3) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 4.tga");
	*pCreepEngine->getBitmap(THORDEATHFLAG, 2, 4) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 5.tga");
	*pCreepEngine->getBitmap(THORDEATHFLAG, 2, 5) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 6.tga");
	*pCreepEngine->getBitmap(THORDEATHFLAG, 2, 6) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 7.tga");
	*pCreepEngine->getBitmap(THORDEATHFLAG, 2, 7) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 8.tga");
	*pCreepEngine->getBitmap(THORDEATHFLAG, 2, 8) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 9.tga");
	*pCreepEngine->getBitmap(THORDEATHFLAG, 2, 9) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 10.tga");

	*pCreepEngine->getBitmap(THORDEATHFLAG, 3, 0) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 1.tga");
	*pCreepEngine->getBitmap(THORDEATHFLAG, 3, 1) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 2.tga");
	*pCreepEngine->getBitmap(THORDEATHFLAG, 3, 2) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 3.tga");
	*pCreepEngine->getBitmap(THORDEATHFLAG, 3, 3) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 4.tga");
	*pCreepEngine->getBitmap(THORDEATHFLAG, 3, 4) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 5.tga");
	*pCreepEngine->getBitmap(THORDEATHFLAG, 3, 5) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 6.tga");
	*pCreepEngine->getBitmap(THORDEATHFLAG, 3, 6) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 7.tga");
	*pCreepEngine->getBitmap(THORDEATHFLAG, 3, 7) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 8.tga");
	*pCreepEngine->getBitmap(THORDEATHFLAG, 3, 8) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 9.tga");
	*pCreepEngine->getBitmap(THORDEATHFLAG, 3, 9) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 10.tga");



	*pCreepEngine->getBitmap(VOIDRAYFLAG, 0, 0) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Left\\Void Ray Left 1.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 0, 1) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Left\\Void Ray Left 2.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 0, 2) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Left\\Void Ray Left 3.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 0, 3) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Left\\Void Ray Left 4.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 0, 4) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Left\\Void Ray Left 5.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 0, 5) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Left\\Void Ray Left 6.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 0, 6) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Left\\Void Ray Left 7.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 0, 7) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Left\\Void Ray Left 8.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 0, 8) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Left\\Void Ray Left 9.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 0, 9) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Left\\Void Ray Left 10.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 0, 10) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Left\\Void Ray Left 11.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 0, 11) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Left\\Void Ray Left 12.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 0, 12) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Left\\Void Ray Left 13.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 0, 13) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Left\\Void Ray Left 14.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 0, 14) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Left\\Void Ray Left 15.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 0, 15) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Left\\Void Ray Left 16.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 0, 16) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Left\\Void Ray Left 17.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 0, 17) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Left\\Void Ray Left 18.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 0, 18) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Left\\Void Ray Left 19.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 0, 19) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Left\\Void Ray Left 20.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 0, 20) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Left\\Void Ray Left 21.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 0, 21) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Left\\Void Ray Left 22.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 0, 22) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Left\\Void Ray Left 23.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 0, 23) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Left\\Void Ray Left 24.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 0, 24) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Left\\Void Ray Left 25.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 0, 25) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Left\\Void Ray Left 26.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 0, 26) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Left\\Void Ray Left 27.tga");

	*pCreepEngine->getBitmap(VOIDRAYFLAG, 1, 0) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Right\\Void Ray Right 1.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 1, 1) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Right\\Void Ray Right 2.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 1, 2) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Right\\Void Ray Right 3.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 1, 3) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Right\\Void Ray Right 4.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 1, 4) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Right\\Void Ray Right 5.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 1, 5) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Right\\Void Ray Right 6.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 1, 6) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Right\\Void Ray Right 7.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 1, 7) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Right\\Void Ray Right 8.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 1, 8) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Right\\Void Ray Right 9.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 1, 9) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Right\\Void Ray Right 10.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 1, 10) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Right\\Void Ray Right 11.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 1, 11) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Right\\Void Ray Right 12.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 1, 12) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Right\\Void Ray Right 13.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 1, 13) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Right\\Void Ray Right 14.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 1, 14) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Right\\Void Ray Right 15.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 1, 15) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Right\\Void Ray Right 16.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 1, 16) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Right\\Void Ray Right 17.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 1, 17) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Right\\Void Ray Right 18.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 1, 18) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Right\\Void Ray Right 19.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 1, 19) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Right\\Void Ray Right 20.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 1, 20) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Right\\Void Ray Right 21.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 1, 21) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Right\\Void Ray Right 22.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 1, 22) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Right\\Void Ray Right 23.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 1, 23) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Right\\Void Ray Right 24.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 1, 24) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Right\\Void Ray Right 25.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 1, 25) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Right\\Void Ray Right 26.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 1, 26) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Right\\Void Ray Right 27.tga");

	*pCreepEngine->getBitmap(VOIDRAYFLAG, 2, 0) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Left\\Void Ray Rear Left 1.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 2, 1) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Left\\Void Ray Rear Left 2.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 2, 2) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Left\\Void Ray Rear Left 3.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 2, 3) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Left\\Void Ray Rear Left 4.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 2, 4) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Left\\Void Ray Rear Left 5.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 2, 5) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Left\\Void Ray Rear Left 6.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 2, 6) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Left\\Void Ray Rear Left 7.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 2, 7) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Left\\Void Ray Rear Left 8.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 2, 8) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Left\\Void Ray Rear Left 9.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 2, 9) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Left\\Void Ray Rear Left 10.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 2, 10) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Left\\Void Ray Rear Left 11.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 2, 11) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Left\\Void Ray Rear Left 12.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 2, 12) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Left\\Void Ray Rear Left 13.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 2, 13) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Left\\Void Ray Rear Left 14.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 2, 14) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Left\\Void Ray Rear Left 15.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 2, 15) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Left\\Void Ray Rear Left 16.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 2, 16) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Left\\Void Ray Rear Left 17.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 2, 17) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Left\\Void Ray Rear Left 18.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 2, 18) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Left\\Void Ray Rear Left 19.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 2, 19) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Left\\Void Ray Rear Left 20.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 2, 20) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Left\\Void Ray Rear Left 21.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 2, 21) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Left\\Void Ray Rear Left 22.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 2, 22) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Left\\Void Ray Rear Left 23.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 2, 23) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Left\\Void Ray Rear Left 24.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 2, 24) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Left\\Void Ray Rear Left 25.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 2, 25) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Left\\Void Ray Rear Left 26.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 2, 26) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Left\\Void Ray Rear Left 27.tga");

	*pCreepEngine->getBitmap(VOIDRAYFLAG, 3, 0) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Right\\Void Ray Rear Right 1.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 3, 1) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Right\\Void Ray Rear Right 2.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 3, 2) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Right\\Void Ray Rear Right 3.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 3, 3) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Right\\Void Ray Rear Right 4.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 3, 4) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Right\\Void Ray Rear Right 5.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 3, 5) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Right\\Void Ray Rear Right 6.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 3, 6) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Right\\Void Ray Rear Right 7.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 3, 7) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Right\\Void Ray Rear Right 8.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 3, 8) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Right\\Void Ray Rear Right 9.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 3, 9) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Right\\Void Ray Rear Right 10.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 3, 10) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Right\\Void Ray Rear Right 11.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 3, 11) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Right\\Void Ray Rear Right 12.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 3, 12) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Right\\Void Ray Rear Right 13.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 3, 13) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Right\\Void Ray Rear Right 14.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 3, 14) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Right\\Void Ray Rear Right 15.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 3, 15) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Right\\Void Ray Rear Right 16.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 3, 16) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Right\\Void Ray Rear Right 17.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 3, 17) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Right\\Void Ray Rear Right 18.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 3, 18) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Right\\Void Ray Rear Right 19.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 3, 19) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Right\\Void Ray Rear Right 20.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 3, 20) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Right\\Void Ray Rear Right 21.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 3, 21) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Right\\Void Ray Rear Right 22.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 3, 22) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Right\\Void Ray Rear Right 23.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 3, 23) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Right\\Void Ray Rear Right 24.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 3, 24) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Right\\Void Ray Rear Right 25.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 3, 25) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Right\\Void Ray Rear Right 26.tga");
	*pCreepEngine->getBitmap(VOIDRAYFLAG, 3, 26) = al_load_bitmap("Sprites\\Creeps\\Void Ray\\Rear Right\\Void Ray Rear Right 27.tga");


	*pCreepEngine->getBitmap(VOIDRAYDEATHFLAG, 0, 0) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 1.tga");
	*pCreepEngine->getBitmap(VOIDRAYDEATHFLAG, 0, 1) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 2.tga");
	*pCreepEngine->getBitmap(VOIDRAYDEATHFLAG, 0, 2) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 3.tga");
	*pCreepEngine->getBitmap(VOIDRAYDEATHFLAG, 0, 3) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 4.tga");
	*pCreepEngine->getBitmap(VOIDRAYDEATHFLAG, 0, 4) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 5.tga");
	*pCreepEngine->getBitmap(VOIDRAYDEATHFLAG, 0, 5) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 6.tga");
	*pCreepEngine->getBitmap(VOIDRAYDEATHFLAG, 0, 6) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 7.tga");
	*pCreepEngine->getBitmap(VOIDRAYDEATHFLAG, 0, 7) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 8.tga");
	*pCreepEngine->getBitmap(VOIDRAYDEATHFLAG, 0, 8) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 9.tga");
	*pCreepEngine->getBitmap(VOIDRAYDEATHFLAG, 0, 9) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 10.tga");

	*pCreepEngine->getBitmap(VOIDRAYDEATHFLAG, 1, 0) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 1.tga");
	*pCreepEngine->getBitmap(VOIDRAYDEATHFLAG, 1, 1) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 2.tga");
	*pCreepEngine->getBitmap(VOIDRAYDEATHFLAG, 1, 2) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 3.tga");
	*pCreepEngine->getBitmap(VOIDRAYDEATHFLAG, 1, 3) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 4.tga");
	*pCreepEngine->getBitmap(VOIDRAYDEATHFLAG, 1, 4) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 5.tga");
	*pCreepEngine->getBitmap(VOIDRAYDEATHFLAG, 1, 5) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 6.tga");
	*pCreepEngine->getBitmap(VOIDRAYDEATHFLAG, 1, 6) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 7.tga");
	*pCreepEngine->getBitmap(VOIDRAYDEATHFLAG, 1, 7) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 8.tga");
	*pCreepEngine->getBitmap(VOIDRAYDEATHFLAG, 1, 8) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 9.tga");
	*pCreepEngine->getBitmap(VOIDRAYDEATHFLAG, 1, 9) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 10.tga");

	*pCreepEngine->getBitmap(VOIDRAYDEATHFLAG, 2, 0) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 1.tga");
	*pCreepEngine->getBitmap(VOIDRAYDEATHFLAG, 2, 1) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 2.tga");
	*pCreepEngine->getBitmap(VOIDRAYDEATHFLAG, 2, 2) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 3.tga");
	*pCreepEngine->getBitmap(VOIDRAYDEATHFLAG, 2, 3) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 4.tga");
	*pCreepEngine->getBitmap(VOIDRAYDEATHFLAG, 2, 4) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 5.tga");
	*pCreepEngine->getBitmap(VOIDRAYDEATHFLAG, 2, 5) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 6.tga");
	*pCreepEngine->getBitmap(VOIDRAYDEATHFLAG, 2, 6) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 7.tga");
	*pCreepEngine->getBitmap(VOIDRAYDEATHFLAG, 2, 7) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 8.tga");
	*pCreepEngine->getBitmap(VOIDRAYDEATHFLAG, 2, 8) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 9.tga");
	*pCreepEngine->getBitmap(VOIDRAYDEATHFLAG, 2, 9) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 10.tga");

	*pCreepEngine->getBitmap(VOIDRAYDEATHFLAG, 3, 0) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 1.tga");
	*pCreepEngine->getBitmap(VOIDRAYDEATHFLAG, 3, 1) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 2.tga");
	*pCreepEngine->getBitmap(VOIDRAYDEATHFLAG, 3, 2) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 3.tga");
	*pCreepEngine->getBitmap(VOIDRAYDEATHFLAG, 3, 3) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 4.tga");
	*pCreepEngine->getBitmap(VOIDRAYDEATHFLAG, 3, 4) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 5.tga");
	*pCreepEngine->getBitmap(VOIDRAYDEATHFLAG, 3, 5) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 6.tga");
	*pCreepEngine->getBitmap(VOIDRAYDEATHFLAG, 3, 6) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 7.tga");
	*pCreepEngine->getBitmap(VOIDRAYDEATHFLAG, 3, 7) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 8.tga");
	*pCreepEngine->getBitmap(VOIDRAYDEATHFLAG, 3, 8) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 9.tga");
	*pCreepEngine->getBitmap(VOIDRAYDEATHFLAG, 3, 9) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 10.tga");

	*pCreepEngine->getBitmap(COLOSSUSFLAG, 0, 0) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Left\\Colossus Left 1.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 0, 1) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Left\\Colossus Left 2.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 0, 2) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Left\\Colossus Left 3.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 0, 3) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Left\\Colossus Left 4.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 0, 4) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Left\\Colossus Left 5.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 0, 5) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Left\\Colossus Left 6.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 0, 6) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Left\\Colossus Left 7.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 0, 7) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Left\\Colossus Left 8.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 0, 8) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Left\\Colossus Left 9.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 0, 9) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Left\\Colossus Left 10.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 0, 10) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Left\\Colossus Left 11.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 0, 11) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Left\\Colossus Left 12.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 0, 12) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Left\\Colossus Left 13.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 0, 13) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Left\\Colossus Left 14.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 0, 14) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Left\\Colossus Left 15.tga");

	*pCreepEngine->getBitmap(COLOSSUSFLAG, 1, 0) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Right\\Colossus Right 1.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 1, 1) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Right\\Colossus Right 2.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 1, 2) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Right\\Colossus Right 3.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 1, 3) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Right\\Colossus Right 4.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 1, 4) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Right\\Colossus Right 5.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 1, 5) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Right\\Colossus Right 6.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 1, 6) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Right\\Colossus Right 7.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 1, 7) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Right\\Colossus Right 8.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 1, 8) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Right\\Colossus Right 9.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 1, 9) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Right\\Colossus Right 10.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 1, 10) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Right\\Colossus Right 11.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 1, 11) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Right\\Colossus Right 12.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 1, 12) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Right\\Colossus Right 13.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 1, 13) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Right\\Colossus Right 14.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 1, 14) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Right\\Colossus Right 15.tga");

	*pCreepEngine->getBitmap(COLOSSUSFLAG, 2, 0) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Rear Left\\Colossus Rear Left 1.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 2, 1) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Rear Left\\Colossus Rear Left 2.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 2, 2) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Rear Left\\Colossus Rear Left 3.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 2, 3) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Rear Left\\Colossus Rear Left 4.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 2, 4) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Rear Left\\Colossus Rear Left 5.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 2, 5) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Rear Left\\Colossus Rear Left 6.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 2, 6) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Rear Left\\Colossus Rear Left 7.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 2, 7) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Rear Left\\Colossus Rear Left 8.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 2, 8) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Rear Left\\Colossus Rear Left 9.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 2, 9) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Rear Left\\Colossus Rear Left 10.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 2, 10) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Rear Left\\Colossus Rear Left 11.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 2, 11) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Rear Left\\Colossus Rear Left 12.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 2, 12) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Rear Left\\Colossus Rear Left 13.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 2, 13) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Rear Left\\Colossus Rear Left 14.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 2, 14) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Rear Left\\Colossus Rear Left 15.tga");

	*pCreepEngine->getBitmap(COLOSSUSFLAG, 3, 0) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Rear Right\\Colossus Rear Right 1.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 3, 1) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Rear Right\\Colossus Rear Right 2.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 3, 2) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Rear Right\\Colossus Rear Right 3.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 3, 3) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Rear Right\\Colossus Rear Right 4.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 3, 4) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Rear Right\\Colossus Rear Right 5.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 3, 5) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Rear Right\\Colossus Rear Right 6.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 3, 6) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Rear Right\\Colossus Rear Right 7.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 3, 7) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Rear Right\\Colossus Rear Right 8.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 3, 8) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Rear Right\\Colossus Rear Right 9.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 3, 9) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Rear Right\\Colossus Rear Right 10.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 3, 10) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Rear Right\\Colossus Rear Right 11.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 3, 11) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Rear Right\\Colossus Rear Right 12.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 3, 12) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Rear Right\\Colossus Rear Right 13.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 3, 13) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Rear Right\\Colossus Rear Right 14.tga");
	*pCreepEngine->getBitmap(COLOSSUSFLAG, 3, 14) = al_load_bitmap("Sprites\\Creeps\\Ultralisk\\Rear Right\\Colossus Rear Right 15.tga");

	*pCreepEngine->getBitmap(COLOSSUSDEATHFLAG, 0, 0) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 1.tga");
	*pCreepEngine->getBitmap(COLOSSUSDEATHFLAG, 0, 1) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 2.tga");
	*pCreepEngine->getBitmap(COLOSSUSDEATHFLAG, 0, 2) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 3.tga");
	*pCreepEngine->getBitmap(COLOSSUSDEATHFLAG, 0, 3) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 4.tga");
	*pCreepEngine->getBitmap(COLOSSUSDEATHFLAG, 0, 4) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 5.tga");
	*pCreepEngine->getBitmap(COLOSSUSDEATHFLAG, 0, 5) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 6.tga");
	*pCreepEngine->getBitmap(COLOSSUSDEATHFLAG, 0, 6) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 7.tga");
	*pCreepEngine->getBitmap(COLOSSUSDEATHFLAG, 0, 7) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 8.tga");
	*pCreepEngine->getBitmap(COLOSSUSDEATHFLAG, 0, 8) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 9.tga");
	*pCreepEngine->getBitmap(COLOSSUSDEATHFLAG, 0, 9) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 10.tga");

	*pCreepEngine->getBitmap(COLOSSUSDEATHFLAG, 1, 0) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 1.tga");
	*pCreepEngine->getBitmap(COLOSSUSDEATHFLAG, 1, 1) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 2.tga");
	*pCreepEngine->getBitmap(COLOSSUSDEATHFLAG, 1, 2) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 3.tga");
	*pCreepEngine->getBitmap(COLOSSUSDEATHFLAG, 1, 3) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 4.tga");
	*pCreepEngine->getBitmap(COLOSSUSDEATHFLAG, 1, 4) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 5.tga");
	*pCreepEngine->getBitmap(COLOSSUSDEATHFLAG, 1, 5) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 6.tga");
	*pCreepEngine->getBitmap(COLOSSUSDEATHFLAG, 1, 6) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 7.tga");
	*pCreepEngine->getBitmap(COLOSSUSDEATHFLAG, 1, 7) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 8.tga");
	*pCreepEngine->getBitmap(COLOSSUSDEATHFLAG, 1, 8) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 9.tga");
	*pCreepEngine->getBitmap(COLOSSUSDEATHFLAG, 1, 9) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 10.tga");

	*pCreepEngine->getBitmap(COLOSSUSDEATHFLAG, 2, 0) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 1.tga");
	*pCreepEngine->getBitmap(COLOSSUSDEATHFLAG, 2, 1) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 2.tga");
	*pCreepEngine->getBitmap(COLOSSUSDEATHFLAG, 2, 2) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 3.tga");
	*pCreepEngine->getBitmap(COLOSSUSDEATHFLAG, 2, 3) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 4.tga");
	*pCreepEngine->getBitmap(COLOSSUSDEATHFLAG, 2, 4) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 5.tga");
	*pCreepEngine->getBitmap(COLOSSUSDEATHFLAG, 2, 5) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 6.tga");
	*pCreepEngine->getBitmap(COLOSSUSDEATHFLAG, 2, 6) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 7.tga");
	*pCreepEngine->getBitmap(COLOSSUSDEATHFLAG, 2, 7) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 8.tga");
	*pCreepEngine->getBitmap(COLOSSUSDEATHFLAG, 2, 8) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 9.tga");
	*pCreepEngine->getBitmap(COLOSSUSDEATHFLAG, 2, 9) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 10.tga");

	*pCreepEngine->getBitmap(COLOSSUSDEATHFLAG, 3, 0) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 1.tga");
	*pCreepEngine->getBitmap(COLOSSUSDEATHFLAG, 3, 1) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 2.tga");
	*pCreepEngine->getBitmap(COLOSSUSDEATHFLAG, 3, 2) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 3.tga");
	*pCreepEngine->getBitmap(COLOSSUSDEATHFLAG, 3, 3) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 4.tga");
	*pCreepEngine->getBitmap(COLOSSUSDEATHFLAG, 3, 4) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 5.tga");
	*pCreepEngine->getBitmap(COLOSSUSDEATHFLAG, 3, 5) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 6.tga");
	*pCreepEngine->getBitmap(COLOSSUSDEATHFLAG, 3, 6) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 7.tga");
	*pCreepEngine->getBitmap(COLOSSUSDEATHFLAG, 3, 7) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 8.tga");
	*pCreepEngine->getBitmap(COLOSSUSDEATHFLAG, 3, 8) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 9.tga");
	*pCreepEngine->getBitmap(COLOSSUSDEATHFLAG, 3, 9) = al_load_bitmap("Sprites\\Creeps\\Blood\\Blood 10.tga");
}