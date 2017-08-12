#include "character.hpp"
#include <iostream>

Character::Character() {}

Character::~Character() {}

/****************************************************************
** Function: lowerHealth(int damageTaken)
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

int Character::getRow() {
  return rowPosition;
}

int Character::getCol() {
  return colPosition;
}

void Character::setRow(int r) {
  rowPosition = r;
}

void Character::setCol(int c) {
  colPosition = c;
}