#include "hydralisk.h"
Hydralisk::Hydralisk (ALLEGRO_BITMAP *load[4][HYDRALISKSPRITES], 
					  ALLEGRO_BITMAP *loadDeath[4][10],
					  ALLEGRO_BITMAP *Bar[5], 
					  ALLEGRO_SAMPLE *sDeath[HYDRALISKDEATHSAMPLES],
					  double dif)
{
	 deathsound			= false;
	 movespeed			= HYDRALISKSPEED * (0.5 * dif < 1 ? 1 : 0.5 * dif);
	 totalhealth		= HYDRALISKHEALTH * (0.8 * dif < 1 ? 1 : 0.8 * dif);
	 health				= HYDRALISKHEALTH * (0.8 * dif < 1 ? 1 : 0.8 * dif);
     reward				= HYDRALISKREWARD;
	 FrameIterator		= 0;
	 DeathIterator		= 0;
	 Type				= hydralisk;
	 dead				= false;
	 zerglingsSpawned   = false;
	 actualPosX			= PosInicialX;
	 actualPosY			= PosInicialY; 
	 targetPosX			= Troca1X;
	 targetPosY			= Troca1Y;   
	 zerglingsSpawned   = false;
	 timer			    = al_create_timer(3.0/60.0);

	for (int directionIterador = 0; directionIterador < 4; directionIterador++)
	{
		for (int walkIterador = 0; walkIterador < HYDRALISKSPRITES; walkIterador++)
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
	for (int i = 0; i < HYDRALISKDEATHSAMPLES; i++)
		sampleDeath[i] = sDeath[i];
	al_start_timer(timer);
}

Hydralisk::Hydralisk(){}

void Hydralisk::creep_plot()
{
	al_draw_bitmap(bmp[direction][FrameIterator], actualPosX-30-40+3, actualPosY-30-40+3,NULL);
	creepSFX.staticHealthBar(staticBar,health,totalhealth,3.5,actualPosX-20-40+10, actualPosY-30-40);
	////al_draw_circle(actualPosX,actualPosY,2,al_map_rgb(255,255,255),1);

	if(al_get_timer_count(timer) >= 1)
	{
		FrameIterator++;
        if (FrameIterator >= HYDRALISKSPRITES)
			FrameIterator = 0;
		al_set_timer_count(timer, 0);
		
	}
}

void Hydralisk::death_plot()
{
	if(!deathsound)
	{
		al_play_sample(sampleDeath[rand()%HYDRALISKDEATHSAMPLES] ,1,ALLEGRO_AUDIO_PAN_NONE,1,ALLEGRO_PLAYMODE_ONCE,NULL); 
		deathsound = true;
	}
	al_draw_bitmap(bmpDeath[direction][DeathIterator], actualPosX-30-5, actualPosY-30-5,NULL);
	creepSFX.staticHealthBar(staticBar,health,totalhealth,3.5,actualPosX-20-40+10, actualPosY-20-40-10);
	 if(al_get_timer_count(timer) >= 1)
	 {
		DeathIterator++;
        if (DeathIterator >= DEATHSPRITES)
			dead = true;
		al_set_timer_count(timer, 0);	
	 }
}