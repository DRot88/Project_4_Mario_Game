#include "character.hpp"
#include <iostream>

Character::Character() {}

Character::~Character() {}

/****************************************************************
** Function: lowerStrengthPoints(int damageTaken)
** Description: This function will lower the health of the
                Characters until there is no health remaining.
****************************************************************/

void Character::lowerHealth(int damageTaken) {
  health -= damageTaken;
  if (health < 0)
  {
    health = 0;
  }
}

int Character::getHealth() {
  return health;
}