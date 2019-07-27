#include "SFX.h"


SFX::SFX()
{
    sense = true;
    length = 0.0;
	lengthB = 0.0;
	fadeOutAlpha = 1;
	for(int i = 0; i < 5; i++)
	{
	effectLength[i] = 0;
	towerInitialBlackLength =0;
	}
	for(int i= 0; i < 5; i++)
		barFade[i] =1;
}

float* SFX::getFadeOutAlpha()
{
	return &fadeOutAlpha;
}

void SFX::fadeIn(ALLEGRO_BITMAP **bmp, bool Active, float period, bool repeat, int posX, int posY, float *lengthParam, float alphaMultiplier)
{
	if (Active)
	{
		
		if(!repeat && *lengthParam < 1)
		{

			if (*lengthParam < 1)
			{
				*lengthParam += ONESECONDPERIOD * (period);
			}
			if (*lengthParam > 1)
			{
				*lengthParam = 1;
			}
		}
		if (sense && repeat)
		{
			if (*lengthParam <=1)
				*lengthParam += ONESECONDPERIOD * (period)  ;
			if (*lengthParam > 1)
			{
				*lengthParam = 1;
				sense  = false;
			}
		}
        else if (!sense && repeat)
        {
            if (*lengthParam >= 0)
            {
                *lengthParam -= ONESECONDPERIOD * (period);
            }
            if (*lengthParam < 0)
            {
                *lengthParam = 0 ;
                sense = true;
            }
        }
       

   }
   else
   {
       if (length >= 0)
       {
		   
           length -= ONESECONDPERIOD * (10.0*period);
       }
       if (length < 0)
       {
            length = 0 ;
            sense = true;
			
       }
  /*         length = 0;
           sense = false;*/
   }
	al_draw_tinted_bitmap(*bmp,al_map_rgba_f(*lengthParam,*lengthParam,*lengthParam,(*lengthParam)*alphaMultiplier),posX,posY,NULL);
}

float* SFX::sfxTime()
{
	return &length;
}

void SFX::setFadeInAlpha(float l)
{
	length = l;
}

bool SFX::fadeInBoolean(ALLEGRO_BITMAP **bmp, ALLEGRO_BITMAP *bar[5], float period, int posX, int posY)
{

		lengthB += ONESECONDPERIOD * (period);
	//	fadeIn(bmp, true, 1.0, DONTREPEAT,posX+40,posY+23,&effectLength[0]);
		al_draw_tinted_bitmap(*bmp,al_map_rgba_f(0, 0, 0, 6*lengthB<1?6*lengthB:1),posX,posY,NULL);
		al_draw_tinted_bitmap(*bmp,al_map_rgba_f(lengthB, lengthB, lengthB, lengthB),posX,posY,NULL);
			
			fadeIn(&bar[4], true, 2.0, DONTREPEAT,posX+40,posY+23,&effectLength[0],1);
			
		

			if(lengthB < (1.0/4.0) && (lengthB >(0)))
			{
				fadeIn(&bar[3], true, period*4.0, DONTREPEAT,posX+40,posY+23,&effectLength[1],1);
			}
			if(lengthB < (2.0/4.0) && (lengthB >= (1.0/4.0)))
			{
				al_draw_bitmap(bar[3],posX+40,posY+23,NULL);
				fadeIn(&bar[2], true, period*4.0, DONTREPEAT,posX+40,posY+23,&effectLength[2],1);
			}
			if(lengthB < (3.0/4.0) && (lengthB >= (2.0/4.0)))
			{
				al_draw_bitmap(bar[2],posX+40,posY+23,NULL);
				fadeIn(&bar[1], true, period*4.0, DONTREPEAT,posX+40,posY+23,&effectLength[3],1);
			}
			if(lengthB >= (3.0/4.0))
			{	
				al_draw_bitmap(bar[1],posX+40,posY+23,NULL);
				fadeIn(&bar[0], true, 1.0, DONTREPEAT,posX+40,posY+23,&effectLength[4],1);
			}    
        if (lengthB > 1)
        {
            lengthB = 1;
            return true;
            sense  = true;
        }
   return false;



}

void SFX::staticHealthBar(ALLEGRO_BITMAP *bar[5], float health, float totalhealth, float period, int posX, int posY)
{			////---FAZER IF DE FADE OUT PARA < 0----->

			if(health<= 0)
			{
				al_draw_bitmap(bar[4],posX+40,posY+23,NULL);//1/4
				fadeOut(&bar[3], true, period, DONTREPEAT,posX+40,posY+23,&barFade[3],1);
				fadeOut(&bar[2], true, period, DONTREPEAT,posX+40,posY+23,&barFade[2],1);
				fadeOut(&bar[1], true, period, DONTREPEAT,posX+40,posY+23,&barFade[1],1);
				fadeOut(&bar[0], true, period, DONTREPEAT,posX+40,posY+23,&barFade[0],1);
			}
			if(health <= (1.0/4.0)*totalhealth && (health >(0)))
			{
				al_draw_bitmap(bar[3],posX+40,posY+23,NULL);//1/4
				fadeOut(&bar[2], true, period, DONTREPEAT,posX+40,posY+23,&barFade[2],1);
				fadeOut(&bar[1], true, period, DONTREPEAT,posX+40,posY+23,&barFade[1],1);
				fadeOut(&bar[0], true, period, DONTREPEAT,posX+40,posY+23,&barFade[0],1);
			}
			if(health <= (2.0/4.0)*totalhealth && (health > (1.0/4.0)*totalhealth))
			{
				al_draw_bitmap(bar[2],posX+40,posY+23,NULL);//2/4
				fadeOut(&bar[1], true, period, DONTREPEAT,posX+40,posY+23,&barFade[1],1);
				fadeOut(&bar[0], true, period, DONTREPEAT,posX+40,posY+23,&barFade[0],1);
			}
			if(health <= (3.0/4.0*totalhealth) && (health > (2.0/4.0*totalhealth))) //Quando a vida descer pra esse intervalo
			{
				al_draw_bitmap(bar[1],posX+40,posY+23,NULL);//3/4
				fadeOut(&bar[0], true, period, DONTREPEAT,posX+40,posY+23,&barFade[0],1);
			//fazer fade out da barra de vida anterior
			}
			if(health > (3.0/4.0)*totalhealth) 
			{	
				al_draw_bitmap(bar[0],posX+40,posY+23,NULL);//Barra cheia
				//fadeOut(&bar[0], true, 1.0, DONTREPEAT,posX+40,posY+23,&barFade[4],1);
			} 
}

void SFX::fadeOut(ALLEGRO_BITMAP **bmp, bool Active, float period, bool repeat, int posX, int posY, float *lengthParam, float alphaMultiplier)
{
	if (Active) //ivnerter o else em baixo de 1->0
	{
		
		if(!repeat && *lengthParam > 0)
		{

			if (*lengthParam >= 0)
			{
				*lengthParam -= ONESECONDPERIOD * (period);
			}
			if (*lengthParam < 0)
			{
				*lengthParam = 0;
			}
		}
		/*if (sense && repeat)
		{
			if (*lengthParam <=1)
				*lengthParam += ONESECONDPERIOD * (period)  ;
			if (*lengthParam > 1)
			{
				*lengthParam = 1;
				sense  = false;
			}
		}
        else if (!sense && repeat)
        {
            if (*lengthParam >= 0)
            {
                *lengthParam -= ONESECONDPERIOD * (period);
            }
            if (*lengthParam < 0)
            {
                *lengthParam = 0 ;
                sense = true;
            }
        }*/
       

   }
   //else//inverter
   //{
   //    if (length <= 0)
   //    {
		 //  
   //        length -= ONESECONDPERIOD * (10.0*period);
   //    }
   //    if (length < 0)
   //    {
   //         length = 0 ;
   //         sense = true;
			//
   //    }
  /*         length = 0;
           sense = false;*/
  // }
	al_draw_tinted_bitmap(*bmp,al_map_rgba_f(*lengthParam,*lengthParam,*lengthParam,(*lengthParam)*alphaMultiplier),posX,posY,NULL);
}


