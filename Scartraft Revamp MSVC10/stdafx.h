#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>
//#include <allegro5
#include <vector>
#include <allegro5/allegro_primitives.h>
#include <string>
#include <sstream>
#include <list>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#define _USE_MATH_DEFINES

#include <math.h>

using namespace std;

namespace AircraftSettings
{
#define HOVER 0
#define FLAG  1
#define POSX  2
#define POSY  3
}

/*NOVOS*/
#define BITMAP_NUMBER_BULLETHIT 9

#define LOADFLAG_BULLETHIT 100
/*NOVOS*/


enum gameMode   {Menu,Tutorial,Game,Upgrade};
enum towertype	{None=0,Bunker, Turret, SiegeTank, aViking};
enum enemytype	{none=0, marine, hydralisk,  thor, voidray, colossus, random, zergling};
enum aircrafttype{noaircraft=0,viking};

#define LEFT 1
#define RIGHT 2
#define STILL 0
#define SPACEPRESSED true

#define VIKINGBACK 1
#define IDLE 0
#define LEFTSTART 1
#define LEFTMANTAIN 2
#define RIGHTSTART 3
#define RIGHTMANTAIN 4
#define BULLET 5
#define EXPLOSION 6

#define VIKINGSHOOTINGDELAY 0.25



#define ASSAULTVIKINGCOST			20
#define ASSAULTVIKINGDAMAGE			40.0
#define ASSAULTVIKINGRANGE			125
#define	ASSAULTVIKINGSPEED			1.5
#define ASSAULTVIKINGBUTTONYSTART	495
#define ASSAULTVIKINGBUTTONYEND		555
//#define	BUNKERDAMAGEUPGRADE		1.2
//#define	BUNKERSPEEDUPGRADE		1.2
//#define	BUNKERRANGEUPGRADE		1.1
//#define	BUNKERUPGRADECOST		30
//#define BUNKERBUTTONYSTART      235
//#define BUNKERBUTTONYEND        295
//#define BUNKERBUILDTIME			3.0

#define MARINESPAWNSAMPLES				3
#define MARINEDEATHSAMPLES				8
#define HYDRALISKSPAWNSAMPLES			4
#define HYDRALISKDEATHSAMPLES			6
#define ZERGLINGSPAWNSAMPLES			6//MUDAR
#define ZERGLINGDEATHSAMPLES			6//MUDAR 
#define THORSPAWNSAMPLES				2
#define THORDEATHSAMPLES				10
#define VOIDRAYSPAWNSAMPLES				5
#define VOIDRAYDEATHSAMPLES				3
#define COLOSSUSSPAWNSAMPLES			6
#define COLOSSUSDEATHSAMPLES			4

#define SAMPLE_MARINE_SPAWN_FLAG		2001
#define SAMPLE_HYDRALISK_SPAWN_FLAG		200243243
#define SAMPLE_THOR_SPAWN_FLAG			2003
#define SAMPLE_VOIDRAY_SPAWN_FLAG		2004
#define SAMPLE_COLOSSUS_SPAWN_FLAG		2005

#define SAMPLE_MARINE_DEATH_FLAG		101
#define SAMPLE_HYDRALISK_DEATH_FLAG		102423423
#define SAMPLE_THOR_DEATH_FLAG			103
#define SAMPLE_VOIDRAY_DEATH_FLAG		104
#define SAMPLE_COLOSSUS_DEATH_FLAG		105

#define ONESECONDPERIOD         1.0/60.0
#define TOWERBUTTONXSTART       715
#define TOWERBUTTONXEND         775

#define BEACONSFLAG				1
#define BUNKERFLAG				2
#define TURRETFLAG				3
#define SIEGETANKFLAG			4
#define BAR1FLAG				5
#define BUNKERTOOLTIPFLAG		10
#define TURRETTOOLTIPFLAG		11
#define SIEGETOOLTIPFLAG		12
#define ASSAULTVIKINGFLAG		13
#define ASSAULT_VIKING_BUILD_FLAG 14

#define BUNKERBUILDSOUNDFLAG	1
#define BUNKERATTACKSOUNDFLAG	2
#define TURRETBUILDSOUNDFLAG	3
#define TURRETATTACKSOUNDFLAG	4
#define SIEGEBUILDSOUNDFLAG		5
#define SIEGEATTACKSOUNDFLAG	6

#define STATICBARFLAG			1001
#define MARINEFLAG				1
#define MARINEDEATHFLAG			2
#define HYDRALISKFLAG			3
#define HYDRALISKDEATHFLAG		4
#define THORFLAG				5
#define THORDEATHFLAG			6
#define VOIDRAYFLAG				7
#define VOIDRAYDEATHFLAG		8
#define COLOSSUSFLAG			9
#define COLOSSUSDEATHFLAG		10


#define LEFTBUTTON              1

#define TOTALTOWERNUMBER		16
#define BUNKERCOST				20
#define BUNKERDAMAGE			15.0
#define BUNKERRANGE				125
#define	BUNKERSPEED				0.7
#define	BUNKERDAMAGEUPGRADE		1.2
#define	BUNKERSPEEDUPGRADE		1.2
#define	BUNKERRANGEUPGRADE		1.1
#define	BUNKERUPGRADECOST		30
#define BUNKERBUTTONYSTART      235
#define BUNKERBUTTONYEND        295
#define BUNKERBUILDTIME			3.0


#define TURRETCOST				40
#define TURRETDAMAGE			42
#define TURRETRANGE				150
#define TURRETSPEED				1.1
#define	TURRETDAMAGEUPGRADE		1.2
#define	TURRETSPEEDUPGRADE		1.1
#define	TURRETRANGEUPGRADE		1.4
#define	TURRETUPGRADECOST		30
#define TURRETBUTTONYSTART      300
#define TURRETBUTTONYEND        360
#define TURRETBUILDTIME			4.0

#define SIEGECOST				50	
#define SIEGEDAMAGE				50
#define	SIEGERANGE				150
#define	SIEGESPEED				1.2
#define	SIEGEDAMAGEUPGRADE		1.4
#define	SIEGESPEEDUPGRADE		1.1
#define	SIEGERANGEUPGRADE		1.2
#define	SIEGEUPGRADECOST		30
#define SIEGEBUTTONYSTART		365
#define SIEGEBUTTONYEND		    425
#define SIEGEBUILDTIME			6.0

#define SIEGEANIMATIONNUMBER	6
#define TURRETANIMATIONNUMBER	2
#define BUNKERANIMATIONNUMBER	5
#define BULLETANIMATIONNUMBER	12
#define ASSAULTVIKINGBITMAPNUMBER 45
#define ASSAULT_VIKING_BUILD_BITMAP_NUMBER 56

#define BULLETNUMBER 12
#define EXPLOSIONNUMBER 33



#define PosInicialX 597+25
#define PosInicialY -61+25

#define PosMorto -60

#define Troca1X 395+25
#define Troca1Y 40+25

#define Troca2X 537+25
#define Troca2Y 112+25

#define Troca3X 333+25
#define Troca3Y 214+25

#define Troca4X 137+25
#define Troca4Y 116+25

#define Troca5X -5+25
#define Troca5Y 187+25

#define Troca6X 333+25
#define Troca6Y 356+25

#define Troca7X 473+25
#define Troca7Y 286+25

#define Troca8X 593+25
#define Troca8Y 346+25

#define Troca9X 193+25
#define Troca9Y 546+25

#define MARINESPRITES		10
#define DEATHSPRITES		10
#define HYDRALISKSPRITES	17
#define THORSPRITES			15
#define	VOIDRAYSPRITES		27
#define COLOSSUSSPRITES		15

#define MARINEHEALTH		20.0
#define MARINEREWARD		2.0
#define MARINESPEED			1.2

#define HYDRALISKHEALTH		50.0
#define HYDRALISKREWARD		4.0
#define HYDRALISKSPEED		1.2

#define ZERGLINGHEALTH		10.0
#define ZERGLINGREWARD		0.0
#define ZERGLINGSPEED		1.9

#define THORHEALTH			80.0
#define THORREWARD			5.0
#define THORSPEED			1.2

#define VOIDRAYHEALTH		84.0
#define VOIDRAYREWARD		8.0
#define VOIDRAYSPEED		1.5

#define COLOSSUSHEALTH		1000.0
#define COLOSSUSREWARD		50.0
#define COLOSSUSSPEED		0.4

