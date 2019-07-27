#include "siegetank.h"


siegetank::siegetank(int X, int Y, int V, ALLEGRO_BITMAP* BMP[7], ALLEGRO_BITMAP* BAR[5], ALLEGRO_BITMAP* EXPLOSIONBMP[EXPLOSIONNUMBER])
{
    for (int i = 0; i<5;i++)
    {
        bar[i] = BAR[i];
    }
	frame		= al_create_timer(5.0/60.0);
	timer		= al_create_timer(SIEGESPEED);
    Damage      = SIEGEDAMAGE;
    Price       = SIEGECOST;
    AttackRate  = SIEGESPEED;
    Range       = SIEGERANGE;
    posX        = X;
    posY        = Y;
    placementPos= V;
	Type        = SiegeTank;
    Active      = false;
	Attacking	= false;
	Exploding   = false;
    for(int i = 0; i < SIEGEANIMATIONNUMBER+1; i++)
		bmpSiege[i]   = BMP[i];
	FrameIterator = 0;
	ExplosionIterator = 0;
	tower_queue = al_create_event_queue();
	al_start_timer(timer);
	al_register_event_source(tower_queue, al_get_timer_event_source(timer));
	towersBuilt++;

	for (int i = 0; i < EXPLOSIONNUMBER; i++)
	{
		bmpExplosion[i] = EXPLOSIONBMP[i];
	}
	explosiontimer = al_create_timer(1.0/60.0);
	al_start_timer(explosiontimer);
}


void siegetank::towerPlot(int* posX, int* posY)
{
    if(!Active) 
    {
        Active = towerFadeIn.fadeInBoolean(&bmpSiege[0],bar,(1 / SIEGEBUILDTIME),*posX-50,*posY-50);    
		if (Active)
		{
			al_start_timer(timer);
			al_start_timer(frame);
			al_set_timer_count(frame, 0);
			al_set_timer_count(timer, 0);
		}
    }
	if (bmpSiege != NULL && Active)
	{
        al_draw_tinted_bitmap(bmpSiege[0],al_map_rgba_f(1,1,1,1),*posX-50,*posY-50,NULL);
	}
//	//al_draw_circle(*posX,*posY,Range,al_map_rgb(255,255,255),2);
//	al_draw_pixel(*posX,*posY,al_map_rgb(255,255,255));
	if (Attacking)
	{
		al_draw_bitmap(bmpSiege[FrameIterator+1],*posX-50,*posY-50,NULL);
		if ( al_get_timer_count(frame) >= 1)
		{                
			FrameIterator++;
			
			if (FrameIterator >= SIEGEANIMATIONNUMBER) //mudar pra define no creep também
			{
				FrameIterator = 0;
				Attacking = false;
			}
		al_set_timer_count(frame, 0);
		}
	}
	//if(Exploding) blablbal exploding = false frame = 0 com X e Y do creep
}

void siegetank::explosionPlot()
{
	if (Exploding)
	{
		al_draw_bitmap(bmpExplosion[ExplosionIterator],expX-60,expY-60,NULL);
		if ( al_get_timer_count(explosiontimer) >= 1)
		{                
			ExplosionIterator++;
			
			if (ExplosionIterator >= EXPLOSIONNUMBER)
			{
				ExplosionIterator = 0;
				Exploding = false;
			}
		al_set_timer_count(explosiontimer, 0);
		}
	}
}