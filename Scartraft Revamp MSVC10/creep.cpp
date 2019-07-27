#include "creep.h"
Creep::Creep(){}

int Creep::playerLives = 20;

void Creep::movement(double movespeed)
{
	  if (targetPosX == Troca1X && targetPosY == Troca1Y)
      {
          direction = 0;

          actualPosX -=  movespeed;
          actualPosY +=  movespeed/2;
          
         if(actualPosX - movespeed <= Troca1X &&
             actualPosY + movespeed/2 >= Troca1Y)
          {
            actualPosX = Troca1X;
            targetPosX = Troca2X;
            actualPosY = Troca1Y;
            targetPosY = Troca2Y;  
          }
      }
      if (targetPosX == Troca2X && targetPosY == Troca2Y)
      {
          direction = 1;
          actualPosX +=  movespeed;
          actualPosY +=  movespeed/2;
          if(actualPosX + movespeed >= Troca2X &&
             actualPosY + movespeed/2 >= Troca2Y)
          {
            actualPosX = Troca2X;
            targetPosX = Troca3X;
            actualPosY = Troca2Y;
            targetPosY = Troca3Y;
          }        
      }
      if (targetPosX == Troca3X && targetPosY == Troca3Y)
      {
          direction = 0;
          actualPosX -=  movespeed;
          actualPosY +=  movespeed/2;
          if(actualPosX - movespeed <= Troca3X &&
             actualPosY + movespeed/2 >= Troca3Y)
          {
            actualPosX = Troca3X;
            targetPosX = Troca4X;
            actualPosY = Troca3Y;
            targetPosY = Troca4Y;
          }  
      }  
      if (targetPosX == Troca4X && targetPosY == Troca4Y)
      {
          direction = 2;
          actualPosX -=  movespeed;
          actualPosY -=  movespeed/2;
          if(actualPosX - movespeed <= Troca4X &&
             actualPosY - movespeed/2 <= Troca4Y)
          {
            actualPosX = Troca4X;
            targetPosX = Troca5X;
            actualPosY = Troca4Y;
            targetPosY = Troca5Y;
          }          
      }
      if (targetPosX == Troca5X && targetPosY == Troca5Y)
      {
          direction = 0;
          actualPosX -=  movespeed;
          actualPosY +=  movespeed/2;
          if(actualPosX - movespeed <= Troca5X &&
             actualPosY + movespeed/2 >= Troca5Y)
          {
            actualPosX = Troca5X;
            targetPosX = Troca6X;
            actualPosY = Troca5Y;
            targetPosY = Troca6Y;
          }          
      }
      if (targetPosX == Troca6X && targetPosY == Troca6Y)
      {
          direction = 1;
          actualPosX +=  movespeed;
          actualPosY +=  movespeed/2;
          if(actualPosX + movespeed >= Troca6X &&
             actualPosY + movespeed/2 >= Troca6Y)
          {
            actualPosX = Troca6X;
            targetPosX = Troca7X;
            actualPosY = Troca6Y;
            targetPosY = Troca7Y;
          }          
      }
      if (targetPosX == Troca7X && targetPosY == Troca7Y)
      {
          direction = 3;
          actualPosX +=  movespeed;
          actualPosY -=  movespeed/2;
          if(actualPosX + movespeed >= Troca7X &&
             actualPosY - movespeed/2 <= Troca7Y)
          {
            actualPosX = Troca7X;
            targetPosX = Troca8X;
            actualPosY = Troca7Y;
            targetPosY = Troca8Y;
          }          
      }
      if (targetPosX == Troca8X && targetPosY == Troca8Y)
      {
          direction = 1;
          actualPosX +=  movespeed;
          actualPosY +=  movespeed/2;
          if(actualPosX + movespeed >= Troca8X &&
             actualPosY + movespeed/2 >= Troca8Y)
          {
            actualPosX = Troca8X;
            targetPosX = Troca9X;
            actualPosY = Troca8Y;
            targetPosY = Troca9Y;
          }          
      }
      if (targetPosX == Troca9X && targetPosY == Troca9Y)
      {
          direction = 0;
          actualPosX -=  movespeed;
          actualPosY +=  movespeed/2;
          if(actualPosX - movespeed <= Troca9X &&
             actualPosY + movespeed/2 >= Troca9Y)
          {
            actualPosX = Troca9X;
            //targetPosX = 0;
            actualPosY = Troca9Y;
            //targetPosY = 0;
          }          
      }      
      if(actualPosX == Troca9X && actualPosY == Troca9Y)
      {
	  	  playerLives--;
		  //-------------------> decidir onde colocar as variáveis como lives e golds
		  actualPosX = PosMorto;
          actualPosY = PosMorto;
          targetPosX = PosMorto;
          targetPosY = PosMorto;
      }
     


}

void Creep::autoRepair(double health, double totalhealth)
{
	hpRegen = (totalhealth*(pow(M_E,-(health/50)))/100);
}

double Creep::getPosX()
{
	return actualPosX;
}

double Creep::getPosY()
{
	return actualPosY;
}

double Creep::getHealth()
{
	return health;
}

double Creep::getTotalHealth()
{
	return totalhealth;
}

double Creep::getHpRegen()
{
	return hpRegen;
}

void Creep::setHealth(double newhealth)
{
	health = newhealth;
}

enemytype Creep::getType()
{
	return Type;
}

double Creep::getReward()
{
	return reward;
}

double Creep::getMoveSpeed()
{
	return movespeed;
}

void Creep::setDead(bool condition)
{
	dead = condition;
}

void Creep::setPosX(double X)
{
	actualPosX = X;
}

void Creep::setPosY(double Y)
{
	actualPosY = Y;
}

bool Creep::getDead()
{
	return dead;
}

void Creep::setTargetX(double X)
{
	targetPosX = X;
}

void Creep::setTargetY(double Y)
{
	targetPosY = Y;
}

const int Creep::getLives(void)
{
	return playerLives;
}

double Creep::getTargetPosX()
{
	return targetPosX;	
}

double Creep::getTargetPosY()
{
	return targetPosY;	
}

bool Creep::GetZerglingsSpawned()
{
	return zerglingsSpawned;
}

void Creep::SetZerglingsSpawned(bool condition)
{
	zerglingsSpawned = condition;
}