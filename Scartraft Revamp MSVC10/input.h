#pragma once
#include "stdafx.h"
using namespace AircraftSettings;
class Attributes
{
protected:
	int money;
public:
	int getMoney(){return money;}
	void setMoney(int p){money = p;}
};

class Input: public Attributes
{
private:
	ALLEGRO_MOUSE_STATE	mState;
	towertype			selection;
	int					tooltipHandle[4];
	int					mouseX;
	int					mouseY;
	int					mouseB;
	bool				aircraftActive;
	void				registerMouseState();
	bool				morphing;
public:
	bool		isMorphing(){return morphing;}
	void		menuMouseInput();
	void		towerPlacementMouseInput();
	void        Output();
	int			getX(){return mouseX;}
	int			getY(){return mouseY;}
	int			getB(){return mouseB;}
	int			getTooltipHandle(int i){return tooltipHandle[i];}
	towertype	getSelection(){return selection;}
	void		setSelection(towertype p){selection = p;}
	bool		isAircraftActive(){return aircraftActive;}
	void		setAircraftActivity(bool p){aircraftActive = p;}
	void		setMorphing(bool p){morphing = p;}
	Input();
};