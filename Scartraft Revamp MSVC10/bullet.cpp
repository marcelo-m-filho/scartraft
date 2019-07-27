#include "bullet.h"

creepEngine* Bullet::pCreepEngine = NULL;

Bullet::Bullet(int X, int Y, ALLEGRO_BITMAP* pbmpBullet[BULLETNUMBER], ALLEGRO_BITMAP* pbmpExplosion[EXPLOSIONNUMBER])
{
frameIterator = 0;
explosionIterator = 0;
posX = X;
posY = Y;
maxdistance = 100;
distance = 0;
range = 20;
damage = 10;
exploded[BEGIN] = false;
exploded[END] = false;


for (int i = 0; i < BULLETNUMBER; i++)
{
	bmpBullet[i] = pbmpBullet[i];
}

for (int i = 0; i < EXPLOSIONNUMBER; i++)
{
	bmpExplosion[i] = pbmpExplosion[i];
}

explosion = al_create_timer(1.0/60.0);
frame = al_create_timer(1.0/60.0);
al_start_timer(frame);
al_start_timer(explosion);

}

bool Bullet::Movement()
{
	//fazer baseado em um timer depois

	if (!exploded[BEGIN])
	{
	posX-=2*2;
	posY-=1*2;
	distance+=1*2;
	}

	if (distance >= maxdistance)
	{
		
		return false;
	}
	else
		return true;

}

void Bullet::bulletPlot()
{
	if (!exploded[BEGIN])
	{
	al_draw_bitmap(bmpBullet[frameIterator],posX-20,posY-20,NULL);
	//al_draw_circle(posX,posY,range,al_map_rgba_f(1,1,1,1),1);
	
		if ( al_get_timer_count(frame) >= 1)
		{                
			frameIterator++;
			
			if (frameIterator >= BULLETNUMBER)
			{
				frameIterator = 0;
			}
			al_set_timer_count(frame, 0);
		}
	}
	
}

bool Bullet::Collision()
{
	if (!exploded[BEGIN])
	{
			pCreepEngine->status = CONTINUE;
			pCreepEngine->creepList.SetCursor(BEGINNING,0);
			
			while(pCreepEngine->status == CONTINUE && pCreepEngine->creepList.GetSize() != 0)
			{
				pCreepEngine->creepFromList = pCreepEngine->creepList.GetCursorData(pCreepEngine->status);
				pCreepEngine->creepList.SetCursor(FORWARD, 1);
				float distX = pow(((pCreepEngine->creepFromList->getPosX())-(posX)),2); //talvez aqui arrumar
				float distY = pow(((pCreepEngine->creepFromList->getPosY())-(posY)),2);
				
				
				if(range >= sqrt(distX + distY) && pCreepEngine->creepFromList->getHealth() > 0)
				{

					pCreepEngine->creepFromList->setHealth(pCreepEngine->creepFromList->getHealth() - damage);
					exploded[BEGIN] = true;
					return true;

					if (pCreepEngine->creepFromList->getHealth() <= 0)	
					{
					
					//ARRUMAR	//	golds += pCreepEngine->creepFromList->getReward();
					}
						break;
				}

			}
			return true;
	}
	else if (exploded[END])
	{
		return false;
	}
	else
		return true;


}

void Bullet::ExplosionPlot()
{
	if (exploded[BEGIN] == true)
	{
		al_draw_bitmap(bmpExplosion[explosionIterator],posX-60,posY-60,NULL);
		if ( al_get_timer_count(explosion) >= 1)
		{
			explosionIterator++;
			

		if (explosionIterator >= EXPLOSIONNUMBER)
			{
				explosionIterator = 0;
				exploded[END] = true;
				exploded[BEGIN] = true; 
			}
			al_set_timer_count(explosion,0);
		}
	}
}