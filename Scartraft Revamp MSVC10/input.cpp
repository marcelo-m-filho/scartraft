#include "input.h"

//using namespace FAISSO;

Input::Input()
{
 selection = None;
 money = 500;
 aircraftActive = true;
 morphing = false;
}

void Input::Output()
{
	menuMouseInput();
	towerPlacementMouseInput();
}

void Input::registerMouseState()
{
	al_get_mouse_state(&mState);
}

void Input::menuMouseInput()
{
	 registerMouseState();
	 if (mState.x >= TOWERBUTTONXSTART && mState.x < TOWERBUTTONXEND)
		{
			if (mState.y >= BUNKERBUTTONYSTART && mState.y < BUNKERBUTTONYEND)
			{
				if (money >= BUNKERCOST && (mState.buttons == LEFTBUTTON))
                {
                    selection = Bunker;
                }
				tooltipHandle[HOVER] = 1;
				tooltipHandle[FLAG]  = BUNKERFLAG;
				tooltipHandle[POSX]  = mState.x;
				tooltipHandle[POSY]  = mState.y;		
			}
			else
			{
				tooltipHandle[HOVER] = 0;
			}
			if (mState.y >= TURRETBUTTONYSTART && mState.y < TURRETBUTTONYEND)
			{
				if (money >= TURRETCOST && (mState.buttons == LEFTBUTTON))
                {
             		selection = Turret;
                }
				tooltipHandle[HOVER] = 1;
				tooltipHandle[FLAG]  = TURRETFLAG;
				tooltipHandle[POSX]  = mState.x;
				tooltipHandle[POSY]  = mState.y;
			}
            if (mState.y >= SIEGEBUTTONYSTART && mState.y < SIEGEBUTTONYEND)
			{
				if (money >= SIEGECOST && (mState.buttons == LEFTBUTTON))
                {
					selection = SiegeTank;
                }
				tooltipHandle[HOVER] = 1;
				tooltipHandle[FLAG]  = SIEGETANKFLAG;
				tooltipHandle[POSX]  = mState.x;
				tooltipHandle[POSY]  = mState.y;
			}	
			if (mState.y >= ASSAULTVIKINGBUTTONYSTART && mState.y < ASSAULTVIKINGBUTTONYEND)
			{
				tooltipHandle[HOVER] = 1;
				tooltipHandle[FLAG]  = SIEGETANKFLAG; //TOOLTIP PROVISÓRIA
				tooltipHandle[POSX]  = mState.x;
				tooltipHandle[POSY]  = mState.y;
			}	
		}
	else if(mState.x >= 692 && mState.x < 692+25)
	{
		if (mState.y >= 498 && mState.y < 498+25)
		{
			if (aircraftActive == true && (mState.buttons == LEFTBUTTON))
            {
				selection		= aViking;
				aircraftActive	= false;
            }
			tooltipHandle[HOVER] = 1;
			tooltipHandle[FLAG]  = SIEGETANKFLAG; //TOOLTIP PROVISÓRIA
			tooltipHandle[POSX]  = mState.x;
			tooltipHandle[POSY]  = mState.y;	
		}
		if (mState.y >= 525 && mState.y < 525+25)
		{
			if (aircraftActive == false && (mState.buttons == LEFTBUTTON))
			{
				morphing = true;
			}
		}
	}
	else
	{
			tooltipHandle[0] = 0;
	}

	
		
}

void Input::towerPlacementMouseInput()
{
	al_get_mouse_state(&mState);

	mouseX = mState.x;
	mouseY = mState.y;
	mouseB = mState.buttons;
}
