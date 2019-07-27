#include "voidray.h"
VoidRay::VoidRay(ALLEGRO_BITMAP *load[4][VOIDRAYSPRITES],
				 ALLEGRO_BITMAP *loadDeath[4][10], 
				 ALLEGRO_BITMAP *Bar[5], 
				 ALLEGRO_SAMPLE *sDeath[VOIDRAYDEATHSAMPLES],
				 double dif)
{

	 deathsound		= false;
	 movespeed = VOIDRAYSPEED * (0.5 * dif < 1 ? 1 : 0.5 * dif);
	 totalhealth = VOIDRAYHEALTH * (0.8 * dif < 1 ? 1 : 0.8 * dif);
	 health = VOIDRAYHEALTH * (0.8 * dif < 1 ? 1 : 0.8 * dif);
     reward = VOIDRAYREWARD;
	 FrameIterator = 0;
	 DeathIterator = 0;
	// DeathFrameTotal = 10;
	// FrameTotal = 10;
	 Type = voidray;
	 

	 dead = false;
	 zerglingsSpawned   = false;
	 actualPosX = PosInicialX;
	 actualPosY = PosInicialY; 
	 targetPosX = Troca1X;
	 targetPosY = Troca1Y;   

	 timer = al_create_timer(3.0/60.0);

	for (int directionIterador = 0; directionIterador < 4; directionIterador++)
	{
		for (int walkIterador = 0; walkIterador < VOIDRAYSPRITES; walkIterador++)
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
	for (int i = 0; i < VOIDRAYDEATHSAMPLES; i++)
		sampleDeath[i] = sDeath[i];
	al_start_timer(timer);
}

VoidRay::VoidRay(){}

void VoidRay::creep_plot()
{
	al_draw_bitmap(bmp[direction][FrameIterator], actualPosX-30-25-25, actualPosY-30-25-25,NULL);
	creepSFX.staticHealthBar(staticBar,health,totalhealth,3.5,actualPosX-30-25-15, actualPosY-30-25-25);
	////al_draw_circle(actualPosX,actualPosY,2,al_map_rgb(255,255,255),1);

	if(al_get_timer_count(timer) >= 1)
	{
		FrameIterator++;
        if (FrameIterator >= VOIDRAYSPRITES)
			FrameIterator = 0;
		al_set_timer_count(timer, 0);
		
	}
}

void VoidRay::death_plot()
{
	if(!deathsound)
	{
		al_play_sample(sampleDeath[rand()%VOIDRAYDEATHSAMPLES] ,1,ALLEGRO_AUDIO_PAN_NONE,1,ALLEGRO_PLAYMODE_ONCE,NULL); 
		deathsound = true;
	}
	al_draw_bitmap(bmpDeath[direction][DeathIterator], actualPosX-25-10, actualPosY-25-10,NULL);
	creepSFX.staticHealthBar(staticBar,health,totalhealth,3.5,actualPosX-30-25-15, actualPosY-30-25-25);
	 if(al_get_timer_count(timer) >= 1)
	 {
		DeathIterator++;
        if (DeathIterator >= DEATHSPRITES)
			dead = true;
		al_set_timer_count(timer, 0);	
	 }
}