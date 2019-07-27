#include "assaultViking.h"
assaultViking::assaultViking(int X, int Y, ALLEGRO_BITMAP* BMP[ASSAULTVIKINGBITMAPNUMBER],ALLEGRO_BITMAP* BMPBUILD[ASSAULT_VIKING_BUILD_BITMAP_NUMBER], ALLEGRO_BITMAP* BAR[5])
{

    for (int i = 0; i<5;i++)
    {
        bar[i] = BAR[i];
    }

	timer		= al_create_timer(ASSAULTVIKINGSPEED);
	frame		= al_create_timer(1.0/60.0);
	buildframe  = al_create_timer(3.0/60.0);
    Damage      = ASSAULTVIKINGDAMAGE;
    Price       = ASSAULTVIKINGCOST;
    AttackRate  = ASSAULTVIKINGSPEED;
    Range       = ASSAULTVIKINGRANGE;
    posX        = X;
    posY        = Y;
	FrameIterator = 0;
	BuildFrameIterator = ASSAULT_VIKING_BUILD_BITMAP_NUMBER-1;
	Type        = aViking;
    Active      = false;
	Attacking	= false;
	Destroying[0] = false;
	Destroying[1]  = false;

	for(int i = 0; i < ASSAULTVIKINGBITMAPNUMBER; i++)
		bmpViking[i]		= BMP[i];
	for(int i = 0; i < ASSAULT_VIKING_BUILD_BITMAP_NUMBER; i++)
		bmpVikingBuild[i]   = BMPBUILD[i];
	al_start_timer(buildframe);
	al_start_timer(timer);
}

void assaultViking::towerPlot(int* posX, int* posY)
{
	if(!Active) 
    {
		//Active = towerFadeIn.fadeInBoolean(&bmpViking[0],bar,(1 / BUNKERBUILDTIME),*posX-50,*posY-50); 
		al_draw_bitmap(bmpVikingBuild[FrameIterator],*posX-40-25,*posY-40-25,NULL);
		
		if ( al_get_timer_count(buildframe) >= 1)
		{                
			FrameIterator++;
			
			if (FrameIterator >= ASSAULT_VIKING_BUILD_BITMAP_NUMBER) //mudar pra define no creep também
			{
				FrameIterator = 0;
				Active = true;
			}
		al_set_timer_count(buildframe, 0);
		}



		if (Active)
		{
		/*al_start_timer(timer);*/
		al_start_timer(frame);
		al_set_timer_count(frame, 0);
		al_set_timer_count(timer, 0);
		}
    }
	if(Destroying[BEGIN])
	{
		al_draw_bitmap(bmpVikingBuild[BuildFrameIterator],*posX-40-25,*posY-40-25,NULL);
		
		if ( al_get_timer_count(buildframe) >= 1)
		{                
			BuildFrameIterator--;
			
			if (BuildFrameIterator < 0) //mudar pra define no creep também
			{
				BuildFrameIterator = 0;
				Destroying[FINISH] = true;
			}
		al_set_timer_count(buildframe, 0);
		}
	}

	if (bmpViking != NULL && Active && !Destroying[BEGIN])
	{
        al_draw_tinted_bitmap(bmpViking[0],al_map_rgba_f(1,1,1,1),*posX-40-25,*posY-40-25,NULL);
		
	}
	////al_draw_circle(*posX,*posY,Range,al_map_rgb(255,255,255),2);
	//al_draw_pixel(*posX,*posY,al_map_rgb(255,255,255));
	if (Attacking)
	{
		al_draw_bitmap(bmpViking[FrameIterator+1],*posX-40-25,*posY-40-25,NULL);
		
		if ( al_get_timer_count(frame) >= 1)
		{                
			FrameIterator++;
			
			if (FrameIterator >= ASSAULTVIKINGBITMAPNUMBER-1) //mudar pra define no creep também
			{
				FrameIterator = 0;
				Attacking = false;
			}
		al_set_timer_count(frame, 0);
		}
	}

}