#pragma once
#include "stdafx.h"


class creepEngine;
class towerEngine;

class soundLoader
{
	void towerLoad();
	void creepLoad();
	void interfaceLoad();
	

public:

	void Output();
	creepEngine *pCreepEngine;
	towerEngine *pTowerEngine;


};