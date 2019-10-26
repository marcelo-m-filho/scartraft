#include "init.h"


init::init()
{
	redraw								= true;
	refreshRate							= 60.0;
	pPlot								= new plot;
	pTowerEngine						= new towerEngine;
	pCreepEngine						= new creepEngine;
	pSoundLoader						= new soundLoader;
	pAircraftEngine						= new AircraftEngine;
	pInput								= new Input;


	pPlot		->pTowerEngine			= pTowerEngine;
	pPlot		->pCreepEngine			= pCreepEngine;
	pPlot		->pAircraftEngine		= pAircraftEngine;
	pPlot		->pInput				= pInput;
	pSoundLoader->pCreepEngine			= pCreepEngine;
	pSoundLoader->pTowerEngine			= pTowerEngine;
	pTowerEngine->pCreepEngine			= pCreepEngine;
	pTowerEngine->pAircraftEngine		= pAircraftEngine;
	pTowerEngine->pInput				= pInput;
	pAircraftEngine->pInput				= pInput;

	Bullet::pCreepEngine = pCreepEngine;
	
	
	pPlot		->createDisplay();
	pTowerEngine->vectorHandling();

	al_install_mouse();
	al_install_keyboard();
	al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();
	al_install_audio();
	al_init_acodec_addon();
	al_reserve_samples(10);
	al_init_primitives_addon();
	start();
}

void init::mainMenu()
{
	
	srand(time(NULL));

	pPlot->menuLoad();
	int flag = 0;


	double fixedDownTime = 1.0f / refreshRate;
	double oldTime = al_current_time();
	double gameTime = al_current_time(); 
	bool done = false;
	while (!done)
	{  
		double downTime = al_current_time() - oldTime;
		al_rest(fixedDownTime - downTime);
		downTime = al_current_time() - oldTime;
		oldTime = al_current_time();

		if(oldTime - gameTime > downTime)
		{
			downTime += fixedDownTime * floor((oldTime - gameTime) / fixedDownTime);
		}
	 
		double start_time = al_current_time();
		while(oldTime - gameTime >= 0)
		{
			gameTime += fixedDownTime;
			al_get_mouse_state(&mousestate);
			
			if(mousestate.buttons == LEFTBUTTON) //Condição principal da função
			{      
				if(mousestate.x >= 554 && mousestate.x <=743 && mousestate.y >= 332 && mousestate.y <=393 )
				{   	
					game2(); 
				}

				if(mousestate.x >= 590 && mousestate.x <=730 && mousestate.y >= 470 && mousestate.y <=510 )
				{      
					_CrtDumpMemoryLeaks();
					exit(1);

				}

			}
			else if (mousestate.buttons == 0 && flag != 3)
			{
				if(mousestate.x >= 554 && mousestate.x <=743 && mousestate.y >= 332 && mousestate.y <=393 )
				{       
					pPlot->mainMenuPlot(flag = 1);
				}

				else if(mousestate.x >= 590 && mousestate.x <=730 && mousestate.y >= 470 && mousestate.y <=510 )
				{    
					pPlot->mainMenuPlot(flag = 2);
				}

				else if (flag != 3)
				{
				pPlot->mainMenuPlot(flag = 0);
				}
			} 
	    if(al_current_time() - start_time > fixedDownTime)
	      break;
	  }
	  al_wait_for_vsync();
	  al_flip_display();
	}
}

void init::start()
{
	mainMenu();
}

void init::game2()
{

	pPlot		->Loader();
    pTowerEngine->vectorHandling();
	pCreepEngine->waveTimer		= al_create_timer(1);	
	pSoundLoader->Output();
	music1 = al_load_sample("Sounds\\Music\\Terran.ogg");
	al_play_sample(music1,0.4,ALLEGRO_AUDIO_PAN_NONE,1,ALLEGRO_PLAYMODE_ONCE,NULL); 

	double fixedDownTime = 1.0f / refreshRate;
	double oldTime = al_current_time();
	double gameTime = al_current_time(); 
	bool done = false;
	al_start_timer(pCreepEngine->waveTimer);
	Aircraft *aircraftPointer = new Viking(300,300,pAircraftEngine->bmpBackVikingIdle,pAircraftEngine->bmpBackVikingLeftStart,pAircraftEngine->bmpBackVikingLeftMantain,pAircraftEngine->bmpBackVikingRightStart,pAircraftEngine->bmpBackVikingRightMantain,pAircraftEngine->bmpVikingBullet,pAircraftEngine->bmpExplosion);
	pAircraftEngine->aircraftDeque.push_back(aircraftPointer);
	while (!done)
	{  

	  double downTime = al_current_time() - oldTime;
	  al_rest(fixedDownTime - downTime);
	  downTime = al_current_time() - oldTime;
	  oldTime = al_current_time();

	  /*
	  Esta parte do código faz com que quando o timer do jogo fique muito atrasado,
	  a lógica no jogo não entre em um período de hiperatividade depois de certo tempo.
	  -->> CAUSA PROBLEMAS COM JOGOS EM REDE, gameTime nesse caso deve ser sincronizado com as outras máquinas
	  */
	  if(oldTime - gameTime > downTime)
	  {
	    downTime += fixedDownTime * floor((oldTime - gameTime) / fixedDownTime);
	  }
	  double start_time = al_current_time();
	  while(oldTime - gameTime >= 0)
	  {
		  al_get_keyboard_state(&keyboardstate);

		
	    gameTime += fixedDownTime;
	    al_get_mouse_state(&mousestate);
		pInput->Output();
		pTowerEngine->Output(mousestate.x,mousestate.y,mousestate.buttons);  
		if		(al_key_down(&keyboardstate,ALLEGRO_KEY_SPACE))
		{
			if	(al_key_down(&keyboardstate,ALLEGRO_KEY_LEFT))
				pAircraftEngine->Output(LEFT,SPACEPRESSED);
			else if (al_key_down(&keyboardstate,ALLEGRO_KEY_RIGHT))
				pAircraftEngine->Output(RIGHT,SPACEPRESSED);
			else 
				pAircraftEngine->Output(STILL,SPACEPRESSED);
		}
		else
		{
			if	(al_key_down(&keyboardstate,ALLEGRO_KEY_LEFT))
				pAircraftEngine->Output(LEFT,0);
			else if (al_key_down(&keyboardstate,ALLEGRO_KEY_RIGHT))
				pAircraftEngine->Output(RIGHT,0);
			else 
				pAircraftEngine->Output(STILL,0);
		}

		pCreepEngine->Output();
		pPlot->clock = pPlot->clock+1;
		if (mousestate.x >= 716 && mousestate.x < 736 && mousestate.y >= 573 && mousestate.y < 593 && mousestate.buttons == LEFTBUTTON)
			//delete this;
			return;
	    if(al_current_time() - start_time > fixedDownTime)
			break;
	  }
	  pPlot->gameOutput();

	  al_wait_for_vsync();
	  al_flip_display();
	}
	return;
}

