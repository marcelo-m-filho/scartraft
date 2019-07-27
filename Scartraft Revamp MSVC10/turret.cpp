#include "turret.h"

turret::turret(int X, int Y, int V, ALLEGRO_BITMAP* BMP[3], ALLEGRO_BITMAP* BAR[5])
{
    for (int i = 0; i<5;i++)
    {
        bar[i] = BAR[i];
	}
	frame		= al_create_timer(10.0/60.0);
	timer		= al_create_timer(TURRETSPEED);
    Damage      = TURRETDAMAGE;
    Price       = TURRETCOST;
    AttackRate  = TURRETSPEED;
    Range       = TURRETRANGE;
    posX        = X;
    posY        = Y;
    placementPos   = V;
    Type        = Turret;
    Active      = false;
	Attacking	= false;
    for(int i = 0; i < TURRETANIMATIONNUMBER+1; i++)
	bmpTurret[i]   = BMP[i];
    FrameIterator = 0;
	
	tower_queue = al_create_event_queue();
	al_start_timer(timer);
	al_register_event_source(tower_queue, al_get_timer_event_source(timer));
	towersBuilt++;
}

void turret::towerPlot(int* posX, int* posY)
{
    if(!Active) 
    {
        Active = towerFadeIn.fadeInBoolean(&bmpTurret[0],bar,(1 / TURRETBUILDTIME),*posX-25-7,*posY-25-15);  
		if (Active)
		{
			al_start_timer(timer);
			al_start_timer(frame);
			al_set_timer_count(frame, 0);
			al_set_timer_count(timer, 0);
		}
    }
	if (bmpTurret != NULL && Active)
	{
        al_draw_tinted_bitmap(bmpTurret[0],al_map_rgba_f(1,1,1,1),*posX-25-7,*posY-25-15,NULL); //resizear sprite 
	}
//	//al_draw_circle(*posX,*posY,Range,al_map_rgb(255,255,255),2);
//	al_draw_pixel(*posX,*posY,al_map_rgb(255,255,255));
	if (Attacking)
	{
		al_draw_bitmap(bmpTurret[FrameIterator+1],*posX-25-7,*posY-25-15,NULL);
		if ( al_get_timer_count(frame) >= 1)
		{                
			FrameIterator++;
			
			if (FrameIterator >= TURRETANIMATIONNUMBER) //mudar pra define no creep também
			{
				FrameIterator = 0;
				Attacking = false;
			}
		al_set_timer_count(frame, 0);
		}
	}
	else
		al_set_timer_count(frame, 0);
}