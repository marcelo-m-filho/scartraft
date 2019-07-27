#include "aircraftEngine.h"

void AircraftEngine::Output(int key, bool space)
{
	ActiveCheck();
	if(pInput->isAircraftActive() && activeAircraftDequePosition != -1)
	{
	Movement(key);
	AircraftAttack(space);
	}
	
}

AircraftEngine::AircraftEngine()
{
	activeAircraftDequePosition = -1;
}

ALLEGRO_BITMAP** AircraftEngine::getBitmap(int Type, int Animation, int Frame)
{
	if (Type == VIKINGBACK)
	{
		if (Animation == STILL)
		{
			return &bmpBackVikingIdle[Frame];
		}
		else if (Animation == LEFTSTART)
		{
			return &bmpBackVikingLeftStart[Frame];
		}
		else if (Animation == LEFTMANTAIN)
		{
			return &bmpBackVikingLeftMantain[Frame];
		}
		else if (Animation == RIGHTSTART)
		{
			return &bmpBackVikingRightStart[Frame];
		}
		else if (Animation == RIGHTMANTAIN)
		{
			return &bmpBackVikingRightMantain[Frame];
		}
		else
			return NULL;
	}
	else if (Type == BULLET)
		return &bmpVikingBullet[Frame];
	else if (Type == EXPLOSION)
		return &bmpExplosion[Frame];
	else
		return NULL;
}

void AircraftEngine::ActiveCheck()
{
	if (pInput->isAircraftActive() && activeAircraftDequePosition == -1) //Se o Input de nave está ativo mas não há nenhum objeto selecionado
	{
		activeAircraftDequePosition = 0;								 //-->Seleciona um objeto
																		 //	  Posteriormente com a implementação de mais naves, 
																		 //	  este if receberia de antemão qual é o objeto que será reativado.
																		 //	  No momento, será sempre o objeto 0.
	}
	if(!pInput->isAircraftActive() && activeAircraftDequePosition != -1) //Se o input de nave está inativo mas ainda há um objeto selecionado
	{
		aircraftDeque.at(activeAircraftDequePosition)->setActive(false); //-->Desativa o objeto selecionado
		if(aircraftDeque.at(activeAircraftDequePosition)->getType() == viking)
		{
			aircraftDeque.at(activeAircraftDequePosition)->morphing = true;
		}
		activeAircraftDequePosition = -1;								 //-->Desceleciona o objeto
	}
	if(pInput->isAircraftActive() && activeAircraftDequePosition != -1) //Se o input de nave está ativo e há um objeto selecionado
	{
		aircraftDeque.at(activeAircraftDequePosition)->setActive(true); //-->Ativa o objeto selecionado
	}





	
}

void AircraftEngine::Movement(int key)
{
	if (key == LEFT)
	{
		if (aircraftDeque.at(activeAircraftDequePosition)->getStatus() != LEFTMANTAIN)
			aircraftDeque.at(activeAircraftDequePosition)->setStatus(LEFTSTART);
		aircraftDeque.at(activeAircraftDequePosition)->posX-= 2;
		aircraftDeque.at(activeAircraftDequePosition)->posY++;

		//setx--*2;
		//sety--;
	}
	else if (key == RIGHT)
	{
		if (aircraftDeque.at(activeAircraftDequePosition)->getStatus() != RIGHTMANTAIN)
			aircraftDeque.at(activeAircraftDequePosition)->setStatus(RIGHTSTART);
		aircraftDeque.at(activeAircraftDequePosition)->posX+= 2;
		aircraftDeque.at(activeAircraftDequePosition)->posY--;
		//setx++*2;
		//sety--;
	}
	else
	{
		aircraftDeque.at(activeAircraftDequePosition)->setStatus(IDLE);
		return;
	}
}

void AircraftEngine::AircraftPlot()
{
	for (unsigned int i = 0; i < aircraftDeque.size(); i++)
	{
		aircraftDeque.at(i)->aircraftPlot(aircraftDeque.at(i)->posX,aircraftDeque.at(i)->posY,pInput->isAircraftActive());
	}
}

void AircraftEngine::AircraftAttack(bool space)
{
	aircraftDeque.at(activeAircraftDequePosition)->Attack(space?true:false); //sempre chegar com falso caso a nave esteja inativa
}