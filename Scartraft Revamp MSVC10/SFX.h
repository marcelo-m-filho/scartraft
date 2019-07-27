#pragma once
#include "stdafx.h"

#define REPEAT     true
#define DONTREPEAT false



class SFX
{
private:
    bool	sense;
    float	length;
	float	lengthB;
//	bool	setBar[5];
	float	effectLength[5];
	float	barFade[5];
	float	towerInitialBlackLength;
	float	fadeOutAlpha;
	

public:
	float* sfxTime();
	float* getFadeOutAlpha();
	void   setFadeInAlpha(float);
    SFX();
    void fadeIn(ALLEGRO_BITMAP **bmp,bool Active, float period, bool repeat, int posX, int posY, float* LengthParam, float alphaMultiplier);
    void fadeOut(ALLEGRO_BITMAP **bmp,bool Active, float period, bool repeat, int posX, int posY, float* LengthParam, float alphaMultiplier);
	
	bool fadeInBoolean(ALLEGRO_BITMAP **bmp, ALLEGRO_BITMAP *bar[], float period, int posX, int posY);
	
	void staticHealthBar(ALLEGRO_BITMAP *bar[], float health, float totalhealth, float period, int posX, int posY);

};
