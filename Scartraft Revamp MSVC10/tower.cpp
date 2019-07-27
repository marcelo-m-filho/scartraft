#include "tower.h"		   

int tower::towersBuilt = 0;

towertype tower::getType()
{
    return Type;
}

 const int tower::getPosX()
{
    return posX;
}

 void tower::setAttacking( const bool a)
{
	Attacking = a;
}

 const int tower::getPosY()
{
    return posY;
}

 void tower::setExplosionCoords(int x, int y)
 {
	expX = x;
	expY = y;
 }

const float tower::getDamage()
{
    return Damage;
}

 const int   tower::getPrice()
{
    return Price;
}

 const float tower::getRange()
{
    return Range;
}

  const float tower::getAttackRate()
{
    return AttackRate;
}

  void tower::setExploding(bool p)
  {
	Exploding = p;
  }









