#include "mario.hpp"
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;

Mario::Mario() {
  armor = 0;
  health = 100;
}

Mario::~Mario() {}

/****************************************************************
** Function: Mario::attack()
** Description: Mario will roll 1, 10 sided die, and the
                result will be returned as the attack. Each 
                additional jump attack can result in at most 5 more
                attack points.
****************************************************************/

int Mario::attack() {
  int dice = (rand() % 10) + 1;
  attackTotal = dice;
  cout << "\nMario showed off his signature jump attack! ";
  cout << "The jump caused " << dice << " damage points!" << endl;
  if (doubleJump()) {
    int dice2 = (rand() % 5) + 1;
    attackTotal += dice2;
    cout << "Wow! Mario has whipped out his double jump! ";
    cout << "This caused an extra " << dice2 << " damage points!" << endl;
    if (tripleJump()) {
      int dice3 = (rand() % 5) + 1;
      attackTotal += dice3;
      cout << "Amazing!!! Mario used his legendary triple jump! ";
      cout << "This caused an extra " << dice3 << " damage points!" << endl;
    }
    cout << "Mario has caused " << attackTotal << " total damge points!" << endl;
  }
  cout << endl;
  return attackTotal;
}

/****************************************************************
** Function: Mario::defend(int damageReceived)
** Description: Marios defense will be based on a roll of a
                10 sided die. There is a 25% chance that he will
                be able to use the 'evade' technique, in which
                he will succesfully escape the attack, taking
                no damage.
****************************************************************/

int Mario::defend(int damageReceived) {
  int totalDamage = 0;
  int dice = (rand() % 10) + 1;
  defenseTotal = dice + armor;
  cout << "Mario had a defense of: " << defenseTotal << endl;
  if (defenseTotal >= damageReceived) {
    cout << "The attack was too weak and had no effect on Mario." << endl;
  } else {
    totalDamage = damageReceived - defenseTotal;
    lowerHealth(totalDamage);
    if (evade()) {
      cout << "Mario is too quick and has evaded the attack!" << endl;
      totalDamage = 0;
    }
  }
  return totalDamage;
}

/****************************************************************
** Function: Mario::evade()
** Description: When defending, mario has 25% chance of 
                successfully evading attacks. If true is returned
                it will be used to adjust the defend action.
****************************************************************/

bool Mario::evade() {
  int dice1 = (rand() % 4) + 1;
  if (dice1 == 1){
    return true;
  }
  return false;
}

bool Mario::doubleJump() {
  int jumpAgain = (rand() % 2) + 1;
  if (jumpAgain == 1) {
    return true;
  }
  return false;
}

bool Mario::tripleJump() {
  int jumpAgain = (rand() % 3) + 1;
  if (jumpAgain == 1) {
    return true;
  }
  return false;
}

string Mario::getType() {
  return "Mario";
}