#pragma once
#include "stdafx.h"
#include "tower.h"
#include "aircraftEngine.h"
#include "input.h"


class towerEngine;
class creepEngine;
class init;
class bitmapLoader
{
private:
protected:
	ALLEGRO_BITMAP *miniMenu;
	ALLEGRO_BITMAP *background;
	ALLEGRO_BITMAP *sideUI;
	ALLEGRO_BITMAP *button;
	ALLEGRO_BITMAP *creepOverlay[5];
	ALLEGRO_BITMAP *turretTooltip;
	ALLEGRO_BITMAP *siegeTooltip;
	ALLEGRO_BITMAP *bunkerTooltip;
	ALLEGRO_BITMAP *menu[3];
	ALLEGRO_BITMAP *newMenu;
	ALLEGRO_BITMAP *newMenuButton[2][5];
	ALLEGRO_BITMAP *newMenuButtonViking[2][2];
	ALLEGRO_BITMAP *explosion[33];
	ALLEGRO_BITMAP *bulletHit[9];
	ALLEGRO_FONT *tooltipFont;
	ALLEGRO_BITMAP *nuke[102];

	void backgroundLoad();
	void explosionLoad();

public:
	void Loader();
	void loadSprite(ALLEGRO_BITMAP** container, char* path, int size);
	void bar1Load();
	creepEngine *pCreepEngine;
	towerEngine *pTowerEngine;
	Input		*pInput;
	AircraftEngine *pAircraftEngine;
	void interfaceLoad();

	void menuLoad();
	void towerLoad();
	void creepLoad();
	void aircraftLoad();


};