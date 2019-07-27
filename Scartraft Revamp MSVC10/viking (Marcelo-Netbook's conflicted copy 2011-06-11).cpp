#include "viking.h"

#define VIKINGBACKIDLENUMBER 8
#define VIKINGBACKLEFTSTARTNUMBER 7
#define VIKINGBACKLEFTMANTAINNUMBER 6
#define VIKINGBACKRIGHTSTARTNUMBER 7
#define VIKINGBACKRIGHTMANTAINNUMBER 6

Viking::Viking(float X, float Y, 
	ALLEGRO_BITMAP* Idle[VIKINGBACKIDLENUMBER], 
	ALLEGRO_BITMAP* LeftStart[VIKINGBACKLEFTSTARTNUMBER], 
	ALLEGRO_BITMAP* LeftMantain[VIKINGBACKLEFTMANTAINNUMBER], 
	ALLEGRO_BITMAP* RightStart[VIKINGBACKRIGHTSTARTNUMBER], 
	ALLEGRO_BITMAP* RightMantain[VIKINGBACKRIGHTMANTAINNUMBER],
	ALLEGRO_BITMAP* pBullet[BULLETNUMBER],
	ALLEGRO_BITMAP* pExplosion[EXPLOSIONNUMBER])
{
	type = viking;
	morphing = false;
	active = true;
	idleFrameIterator = 0;
	leftStartFrameIterator = 0;
	leftMantainFrameIterator = 0;
	rightStartFrameIterator = 0;
	rightMantainFrameIterator = 0;
	posY = Y;
	posX = X;
	for (int i = 0; i < VIKINGBACKIDLENUMBER; i++)
	{
		bmpIdle[i] = Idle[i];
	}
	for (int i = 0; i < BULLETNUMBER; i++)
	{
		bmpBullet[i] = pBullet[i];
	}
	for (int i = 0; i < EXPLOSIONNUMBER; i++)
	{
		bmpExplosion[i] = pExplosion[i];
	}
	for (int i = 0; i < VIKINGBACKLEFTSTARTNUMBER; i++)
	{
		bmpLeftStart[i] = LeftStart[i];
	}
	for (int i = 0; i < VIKINGBACKLEFTMANTAINNUMBER; i++)
	{
		bmpLeftMantain[i] = LeftMantain[i];
	}
	for (int i = 0; i < VIKINGBACKRIGHTSTARTNUMBER; i++)
	{
		bmpRightStart[i] = RightStart[i];
	}
	for (int i = 0; i < VIKINGBACKRIGHTMANTAINNUMBER; i++)
	{
		bmpRightMantain[i] = RightMantain[i];
	}
	frame = al_create_timer(3.0/60.0);

	shootingDelay = al_create_timer(VIKINGSHOOTINGDELAY);
	al_start_timer(frame);
	al_start_timer(shootingDelay);
}

void Viking::aircraftPlot(int posX, int posY, bool active)
{
	bulletPlot();
	if (active)
		activePlot();
	if (active && morphing)
		morphPlot();
}

void Viking::bulletPlot()
{
	list<Bullet>::iterator li;
	for(li=bulletList.begin(); li!=bulletList.end();li++)
	{
		li->bulletPlot();
		li->ExplosionPlot();
	}
}

void Viking::activePlot()
{
	if (active && status == IDLE)
	{
		if (leftStartFrameIterator == 0 &&  rightStartFrameIterator == 0 )
			al_draw_bitmap(bmpIdle[idleFrameIterator],posX-40, posY-40,NULL);
		else if (leftStartFrameIterator > 0)
			al_draw_bitmap(bmpLeftStart[leftStartFrameIterator],posX-40, posY-40,NULL);
		else if (rightStartFrameIterator > 0)
			al_draw_bitmap(bmpRightStart[rightStartFrameIterator],posX-40, posY-40,NULL);

		if ( al_get_timer_count(frame) >= 1)
		{                
			if (leftStartFrameIterator == 0 &&  rightStartFrameIterator == 0 )
				idleFrameIterator++;
			else if (leftStartFrameIterator > 0)
					leftStartFrameIterator--;
			else if (rightStartFrameIterator > 0)
					rightStartFrameIterator--;
			

			if (idleFrameIterator >= VIKINGBACKIDLENUMBER) 
				idleFrameIterator = 0;

			al_set_timer_count(frame, 0);
		}

	}
	else if (active && status == LEFTSTART)
	{
		if (rightStartFrameIterator == 0)
		al_draw_bitmap(bmpLeftStart[leftStartFrameIterator],posX-40, posY-40,NULL);
		else
		al_draw_bitmap(bmpRightStart[rightStartFrameIterator],posX-40, posY-40,NULL);

		
		if ( al_get_timer_count(frame) >= 1)
		{   
			if (rightStartFrameIterator == 0)
			leftStartFrameIterator++;
			else
			rightStartFrameIterator--;
			
			if (leftStartFrameIterator >= 3)//VIKINGBACKLEFTSTARTNUMBER) 
			{
				status = LEFTMANTAIN;
			}
		al_set_timer_count(frame, 0);
		}
	}
	else if (active && status == LEFTMANTAIN)
	{
		al_draw_bitmap(bmpLeftMantain[leftMantainFrameIterator],posX-40, posY-40,NULL);
		
		if ( al_get_timer_count(frame) >= 1)
		{                
			leftMantainFrameIterator++;
			
			if (leftMantainFrameIterator >= VIKINGBACKLEFTMANTAINNUMBER) 
			{
				leftMantainFrameIterator = 0;
			}
		al_set_timer_count(frame, 0);
		}

	}
		else if (active && status == RIGHTSTART)
	{
		if (leftStartFrameIterator == 0)
		al_draw_bitmap(bmpRightStart[rightStartFrameIterator],posX-40, posY-40,NULL);
		else
		al_draw_bitmap(bmpLeftStart[leftStartFrameIterator],posX-40, posY-40,NULL);

		
		if ( al_get_timer_count(frame) >= 1)
		{                
			if (leftStartFrameIterator == 0)
			rightStartFrameIterator++;
			else
			leftStartFrameIterator--;
			
			
			if (rightStartFrameIterator >= 3)
			{
				status = RIGHTMANTAIN;
			}
		al_set_timer_count(frame, 0);
		}
	}
	else if (active && status == RIGHTMANTAIN)
	{
		al_draw_bitmap(bmpRightMantain[rightMantainFrameIterator],posX-40, posY-40,NULL);
		
		if ( al_get_timer_count(frame) >= 1)
		{                
			rightMantainFrameIterator++;
			
			if (rightMantainFrameIterator >= VIKINGBACKRIGHTMANTAINNUMBER) 
			{
				//status = RIGHTMANTAIN;
				rightMantainFrameIterator = 0;
				//Attacking = false;
			}
		al_set_timer_count(frame, 0);
		}

	}

}

void Viking::morphPlot()
{

}


void Viking::Attack(bool keypressed)
{
	//essa função também é chamada 60x/segundo
	//se space = true && bulletlist.size() = 0
	//adiciona bullet
	//trava processo de adicionar bullet (começar com 1 por vez)
	//se size()=0 && space = true
	//adiciona outra bullet

	if (keypressed) /*bulletList.size() == 0)*/
	{
		
		if(al_get_timer_count(shootingDelay) >= 1)
		{
			al_stop_timer(shootingDelay);
			al_set_timer_count(shootingDelay, 0);

			Bullet* pBullet = new Bullet(posX,posY,bmpBullet,bmpExplosion);
			bulletList.push_back(*pBullet);
			al_start_timer(shootingDelay);
		}

	}
	//else if (!keypressed && al_get_timer_count(shootingDelay) > 1)
	//	al_set_timer_count(shootingDelay, 1);

	list<Bullet>::iterator li;
	if (!bulletList.empty())
	{
		for(li=bulletList.begin(); li!=bulletList.end();li)
		{
			//li->Collision();
			if (!li->Movement()  || !li->Collision())
			{
				//delete &*li;
				li = bulletList.erase(li);
			}
			else
				li++;
		//fazer baseado em um timer depois
		}
	}
	//percorre a lista
	//realiza movimentação das bullets
	//realiza checagem e deleção da bullet
	//-> fazer a checagem na bullet e fazer ela retornar collision/out of reach
	//   caso retorne algum desses realizar procedimento e deletar bullet da lista



}