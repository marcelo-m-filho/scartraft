#include "plot.h"
//#include "init.h"
#include "towerEngine.h"
#include "creepengine.h"


plot::plot()
{
	cu = 0;
	sideUI				= NULL;																								  
	display				= NULL;
	background			= NULL;
	lastflag			= NULL;
}

void plot::mainMenuPlot(int flag)
{
	if (flag != 3)
		al_draw_tinted_bitmap(menu[0],al_map_rgba_f(1, 1, 1, 1),0,0,NULL);
	if (flag == 1)
		menuSFX[1].fadeIn(&menu[1], true, 2 ,DONTREPEAT,0,0,menuSFX[1].sfxTime(),1) ;    
	else
		menuSFX[1].fadeIn(&menu[1], false, 1.5 ,DONTREPEAT,0,0,menuSFX[1].sfxTime(),1) ;   
	if (flag == 2)
		menuSFX[2].fadeIn(&menu[2], true, 2,DONTREPEAT,0,0,menuSFX[2].sfxTime(),1) ;    
	else
		menuSFX[2].fadeIn(&menu[2], false, 1.5 ,DONTREPEAT,0,0,menuSFX[2].sfxTime(),1) ;
	if (flag == 3)
		menuSFX[3].fadeOut(&menu[0],true,5,DONTREPEAT,0,0,menuSFX[0].getFadeOutAlpha(),1);
}

void plot::createDisplay()
{
	if (!display)
	{	
	al_init_image_addon();
	al_init_font_addon(); // initialize the font addon
    al_init_ttf_addon();
	
	display = al_create_display(800, 600); // creates the main window
	}
}

void plot::gameOutput()
{
	if(display)
	{
		backgroundPlot();
		
		pTowerEngine->beaconPlot();
		pTowerEngine->towerPlot();
		if(pCreepEngine->creepList.GetSize() != 0)
			pCreepEngine->wavePlot();
		pTowerEngine->hitPlot();

		pAircraftEngine->AircraftPlot();
		interfacePlot();
		tooltipPlot();
	}
}

 void plot::displayFlip()
{
 {
 al_flip_display();
 }

	

}

void plot::backgroundPlot()
{
		al_draw_tinted_bitmap(background,al_map_rgba_f(0.5, 0.5, 0.5, 1),0,0,NULL);
	al_draw_tinted_bitmap(nuke[cu],al_map_rgba_f(1, 1, 1, 1),-100,-100,NULL);

	cu++;
	if (cu >=101)
		cu = 0;

}

void plot::interfacePlot()
{
	al_draw_bitmap(newMenu,630,0,NULL);
	al_draw_bitmap(miniMenu,0,7,NULL);
	al_draw_bitmap(miniMenu,0,37,NULL);

	

	al_draw_bitmap(newMenuButton[0][0],715,235,NULL);
	al_draw_bitmap(newMenuButton[0][1],715,235+65,NULL);
	al_draw_bitmap(newMenuButton[0][2],715,235+130,NULL);
	al_draw_bitmap(newMenuButton[0][3],715,235+195,NULL);
	al_draw_bitmap(newMenuButton[0][4],715,235+260,NULL);

	al_draw_bitmap(newMenuButtonViking[0][pInput->isAircraftActive()?1:0],692,498,NULL);
	al_draw_bitmap(newMenuButtonViking[1][pInput->isAircraftActive()?0:1],692,525,NULL);


	al_draw_textf(tooltipFont, al_map_rgb(255,255,255),746, 179, NULL,"%i",pInput->getMoney());
	al_draw_textf(tooltipFont, al_map_rgb(255,255,255),710, 179, NULL,"%i",pCreep->getLives());
	al_draw_text(tooltipFont, al_map_rgb(255,255,255),15 , 15 , NULL, (clock.GetTime()).c_str());
	al_draw_textf(tooltipFont, al_map_rgb(255,255,255),15, 45, NULL,"%i",/*pTowerEngine->pTower->towersBuilt);*/pTowerEngine->scoreValue);


	if (pCreepEngine->getWave() == 1)
		creepOverlaySFX[pCreepEngine->getWave()-1].fadeIn(&creepOverlay[pCreepEngine->getWave()-1],true,1,DONTREPEAT,630,0,creepOverlaySFX[pCreepEngine->getWave()-1].sfxTime(),1);
	if (pCreepEngine->getWave() > 1)
	{
		creepOverlaySFX[pCreepEngine->getWave()-2].fadeOut(&creepOverlay[pCreepEngine->getWave()-2],true,3,DONTREPEAT,630,0,creepOverlaySFX[pCreepEngine->getWave()-2].sfxTime(),1);
		creepOverlaySFX[pCreepEngine->getWave()-1].fadeIn(&creepOverlay[pCreepEngine->getWave()-1],true,1,DONTREPEAT,630,0,creepOverlaySFX[pCreepEngine->getWave()-1].sfxTime(),1);
	}
	buttonSFX[1].fadeIn(&newMenuButton[1][1],(pInput->getSelection() == Turret)?true:false,4 ,DONTREPEAT,715,235+65,buttonSFX[1].sfxTime(),1);
	buttonSFX[2].fadeIn(&newMenuButton[1][2],pInput->getSelection() == SiegeTank?true:false, 4 ,DONTREPEAT,715,235+130,buttonSFX[2].sfxTime(),1);
	buttonSFX[0].fadeIn(&newMenuButton[1][0],(pInput->getSelection() == Bunker)?true:false, 4 ,DONTREPEAT,715,235,buttonSFX[0].sfxTime(),1);
}

void plot::tooltipPlot()
{
	if(pInput->getTooltipHandle(0) == 1)
	{
		if (pInput->getTooltipHandle(1) == BUNKERFLAG)
		{
			tooltipFadeIn.fadeIn(&bunkerTooltip, true, 8.0 ,DONTREPEAT,pInput->getTooltipHandle(2)-300,pInput->getTooltipHandle(3)-150,tooltipFadeIn.sfxTime(),0.8); 
			al_draw_textf(tooltipFont, al_map_rgb(255,255,255),pInput->getTooltipHandle(2)-75,pInput->getTooltipHandle(3)-48, NULL,"%i",BUNKERCOST);
			al_draw_textf(tooltipFont, al_map_rgb(255,255,255),pInput->getTooltipHandle(2)-75,pInput->getTooltipHandle(3)-24, NULL,"%.1fs",BUNKERBUILDTIME);
			al_draw_textf(tooltipFont, al_map_rgb(255,255,255),pInput->getTooltipHandle(2)-200,pInput->getTooltipHandle(3)+24-20-3, NULL,"%0.fdmg",BUNKERDAMAGE);
			al_draw_textf(tooltipFont, al_map_rgb(255,255,255),pInput->getTooltipHandle(2)-200,pInput->getTooltipHandle(3)+48-15-3, NULL,"%.1fs",BUNKERSPEED);
			al_draw_textf(tooltipFont, al_map_rgb(255,255,255),pInput->getTooltipHandle(2)-200,pInput->getTooltipHandle(3)+48+24-10-3, NULL,"%iyd",BUNKERRANGE);
			lastflag = BUNKERFLAG;
		}

		if (pInput->getTooltipHandle(1) == TURRETFLAG)
		{
			tooltipFadeIn.fadeIn(&turretTooltip, true, 8.0 ,DONTREPEAT,pInput->getTooltipHandle(2)-300,pInput->getTooltipHandle(3)-150,tooltipFadeIn.sfxTime(),0.8); 
			al_draw_textf(tooltipFont, al_map_rgb(255,255,255),pInput->getTooltipHandle(2)-75,pInput->getTooltipHandle(3)-48, NULL,"%i",TURRETCOST);
			al_draw_textf(tooltipFont, al_map_rgb(255,255,255),pInput->getTooltipHandle(2)-75,pInput->getTooltipHandle(3)-24, NULL,"%.1fs",TURRETBUILDTIME);
			al_draw_textf(tooltipFont, al_map_rgb(255,255,255),pInput->getTooltipHandle(2)-200,pInput->getTooltipHandle(3)+24-20-3, NULL,"%idmg",TURRETDAMAGE);
			al_draw_textf(tooltipFont, al_map_rgb(255,255,255),pInput->getTooltipHandle(2)-200,pInput->getTooltipHandle(3)+48-15-3, NULL,"%.1fs",TURRETSPEED);
			al_draw_textf(tooltipFont, al_map_rgb(255,255,255),pInput->getTooltipHandle(2)-200,pInput->getTooltipHandle(3)+48+24-10-3, NULL,"%iyd",TURRETRANGE);
			lastflag = TURRETFLAG;
		}

		if (pInput->getTooltipHandle(1) == SIEGETANKFLAG)
		{
			tooltipFadeIn.fadeIn(&siegeTooltip, true, 8.0 ,DONTREPEAT,pInput->getTooltipHandle(2)-300,pInput->getTooltipHandle(3)-150,tooltipFadeIn.sfxTime(),0.8); 
			al_draw_textf(tooltipFont, al_map_rgb(255,255,255),pInput->getTooltipHandle(2)-75,pInput->getTooltipHandle(3)-48, NULL,"%i",SIEGECOST);
			al_draw_textf(tooltipFont, al_map_rgb(255,255,255),pInput->getTooltipHandle(2)-75,pInput->getTooltipHandle(3)-24, NULL,"%.1fs",SIEGEBUILDTIME);
			al_draw_textf(tooltipFont, al_map_rgb(255,255,255),pInput->getTooltipHandle(2)-200,pInput->getTooltipHandle(3)+24-20-3, NULL,"%idmg",SIEGEDAMAGE);
			al_draw_textf(tooltipFont, al_map_rgb(255,255,255),pInput->getTooltipHandle(2)-200,pInput->getTooltipHandle(3)+48-15-3, NULL,"%.1fs",SIEGESPEED);
			al_draw_textf(tooltipFont, al_map_rgb(255,255,255),pInput->getTooltipHandle(2)-200,pInput->getTooltipHandle(3)+48+24-10-3, NULL,"%iyd",SIEGERANGE);
			lastflag = SIEGETANKFLAG;
		}
	}
	if (pInput->getTooltipHandle(0) == 0)
	{
		if (lastflag == BUNKERFLAG)
			tooltipFadeIn.fadeIn(&bunkerTooltip, false, 2.0 ,DONTREPEAT,pInput->getTooltipHandle(2)-300,pInput->getTooltipHandle(3)-150,tooltipFadeIn.sfxTime(),0.8);
		if (lastflag == TURRETFLAG)
			tooltipFadeIn.fadeIn(&turretTooltip, false, 2.0 ,DONTREPEAT,pInput->getTooltipHandle(2)-300,pInput->getTooltipHandle(3)-150,tooltipFadeIn.sfxTime(),0.8);
		if (lastflag == SIEGETANKFLAG)
			tooltipFadeIn.fadeIn(&siegeTooltip, false, 2.0 ,DONTREPEAT,pInput->getTooltipHandle(2)-300,pInput->getTooltipHandle(3)-150,tooltipFadeIn.sfxTime(),0.8);
	}
}

ALLEGRO_DISPLAY* plot::getDisplay()
{
	return display;
}