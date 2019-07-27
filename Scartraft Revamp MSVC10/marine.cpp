#include "marine.h"
Marine::Marine(ALLEGRO_BITMAP *load[4][MARINESPRITES],
			   ALLEGRO_BITMAP *loadDeath[4][10], 
			   ALLEGRO_BITMAP *Bar[5],
			   ALLEGRO_SAMPLE *sDeath[MARINEDEATHSAMPLES], 
			   double dif)
{
	deathsound			= false;
	movespeed			= MARINESPEED * (0.5 * dif < 1 ? 1 : 0.5 * dif);
	totalhealth			= MARINEHEALTH * (0.8 * dif < 1 ? 1 : 0.8 * dif);
	health				= MARINEHEALTH * (0.8 * dif < 1 ? 1 : 0.8 * dif);
    reward				= MARINEREWARD;
	FrameIterator		= 0;
	DeathIterator		= 0;
	Type				= marine;
	dead				= false;
	zerglingsSpawned    = false;
	actualPosX			= PosInicialX;
	actualPosY			= PosInicialY; 
	targetPosX			= Troca1X;
	targetPosY			= Troca1Y;  
	timer				= al_create_timer(4.0/60.0);
	for (int directionIterador = 0; directionIterador < 4; directionIterador++)
	{
		for (int walkIterador = 0; walkIterador < MARINESPRITES; walkIterador++)
		{
			bmp[directionIterador][walkIterador] = load[directionIterador][walkIterador];
		}
	}
	for (int i = 0; i < 5 ; i++)
		staticBar[i] = Bar[i];

	for (int directionIterador = 0; directionIterador < 4; directionIterador++)
	{
		for (int walkIterador = 0; walkIterador < 10; walkIterador++)
		{
			bmpDeath[directionIterador][walkIterador] = loadDeath[directionIterador][walkIterador];
		}
	}
	al_start_timer(timer);


	for (int i = 0; i < MARINEDEATHSAMPLES; i++)
		sampleDeath[i] = sDeath[i];

	

}

Marine::Marine(){}

void Marine::creep_plot()
{
	al_draw_tinted_bitmap(bmp[direction][FrameIterator],al_map_rgba_f(1,1,1,1), actualPosX-30-30, actualPosY-30-30,NULL);
	creepSFX.staticHealthBar(staticBar,health,totalhealth,3.5,actualPosX-30-25, actualPosY-30-25);
//  //al_draw_circle(actualPosX,actualPosY,2,al_map_rgb(255,255,255),1);
	if(al_get_timer_count(timer) >= 1)
	{
		FrameIterator++;
        if (FrameIterator >= MARINESPRITES)
			FrameIterator = 0;
		al_set_timer_count(timer, 0);		
	}
}

void Marine::death_plot()
{
	if(!deathsound)
	{
		al_play_sample(sampleDeath[rand()%MARINEDEATHSAMPLES] ,0.5,ALLEGRO_AUDIO_PAN_NONE,1,ALLEGRO_PLAYMODE_ONCE,NULL); 
		deathsound = true;
	}
	creepSFX.fadeOut(&bmpDeath[direction][DeathIterator],true,1,DONTREPEAT,
		actualPosX-35,actualPosY-35,creepSFX.getFadeOutAlpha(),1);
//	al_draw_bitmap(bmpDeath[direction][DeathIterator], actualPosX-25, actualPosY-25,NULL);
	//al_draw_scaled_bitmap(bmpDeath[direction][DeathIterator], actualPosX-25, actualPosY-25,50,50,actualPosX-25, actualPosY-25,200,200,NULL);
	creepSFX.staticHealthBar(staticBar,health,totalhealth,3.5,actualPosX-30-25, actualPosY-30-25);
	 if(al_get_timer_count(timer) >= 1)
	 {
		DeathIterator++;
        if (DeathIterator >= DEATHSPRITES)
		{
			dead = true;
			
		}
		al_set_timer_count(timer, 0);	
	 }
}