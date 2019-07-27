#include "bunker.h"
bunker::bunker(int X, int Y, int V, ALLEGRO_BITMAP* BMP[6], ALLEGRO_BITMAP* BAR[5], ALLEGRO_BITMAP* BULLETHITBMP[BITMAP_NUMBER_BULLETHIT])
{

    for (int i = 0; i<5;i++)
    {
        bar[i] = BAR[i];
    }

	Exploding   = false;
	ExplosionIterator = 0;
	explosiontimer = al_create_timer(2.5/60.0);
	al_start_timer(explosiontimer);

	timer		= al_create_timer(BUNKERSPEED);
	frame		= al_create_timer(5.0/60.0);
    Damage      = BUNKERDAMAGE;
    Price       = BUNKERCOST;
    AttackRate  = BUNKERSPEED;
    Range       = BUNKERRANGE;
    posX        = X;
    posY        = Y;
    placementPos= V;
    Type        = Bunker;
    Active      = false;
	Attacking = false;

	for(int i = 0; i < BUNKERANIMATIONNUMBER+1; i++)
		bmpBunker[i]   = BMP[i];
	for (int i = 0; i < BITMAP_NUMBER_BULLETHIT; i++)
	{
		bmpBulletHit[i] = BULLETHITBMP[i];
	}

	FrameIterator = 0;
	
	
	tower_queue = al_create_event_queue();
	//al_start_timer(timer);
	//al_start_timer(frame);
	al_register_event_source(tower_queue, al_get_timer_event_source(timer));
	towersBuilt++;

}

bunker::bunker()
{
    Damage      = NULL;
    Price       = NULL;
    AttackRate  = NULL;
    Range       = NULL;
    bmpBunker[0]   = NULL;
}


void bunker::towerPlot(int* posX, int* posY)
{
    if(!Active) 
    {
        Active = towerFadeIn.fadeInBoolean(&bmpBunker[0],bar,(1 / BUNKERBUILDTIME),*posX-50,*posY-50); 
		
		if (Active)
		{
		al_start_timer(timer);
		al_start_timer(frame);
		al_set_timer_count(frame, 0);
		al_set_timer_count(timer, 0);
		}
    }
	if (bmpBunker != NULL && Active)
	{
        al_draw_tinted_bitmap(bmpBunker[0],al_map_rgba_f(1,1,1,1),*posX-50,*posY-50,NULL);
		
	}
	////al_draw_circle(*posX,*posY,Range,al_map_rgb(255,255,255),2);
	//al_draw_pixel(*posX,*posY,al_map_rgb(255,255,255));
	if (Attacking)
	{
		al_draw_bitmap(bmpBunker[FrameIterator+1],*posX-50,*posY-50,NULL);
		
		if ( al_get_timer_count(frame) >= 1)
		{                
			FrameIterator++;
			
			if (FrameIterator >= BUNKERANIMATIONNUMBER) //mudar pra define no creep também
			{
				FrameIterator = 0;
				Attacking = false;
			}
		al_set_timer_count(frame, 0);
		}
	}
}

void bunker::explosionPlot()
{
	if (Exploding)
	{
		al_draw_bitmap(bmpBulletHit[ExplosionIterator],expX-60,expY-60,NULL);
		if ( al_get_timer_count(explosiontimer) >= 1)
		{                
			ExplosionIterator++;
			
			if (ExplosionIterator >= BITMAP_NUMBER_BULLETHIT)
			{
				ExplosionIterator = 0;
				Exploding = false;
			}
		al_set_timer_count(explosiontimer, 0);
		}
	}
}