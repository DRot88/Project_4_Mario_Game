#include "mario.hpp"
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;

Mario::Mario() {
  armor = 0;
  health = 10;
}

Mario::~Mario() {}

/****************************************************************
** Function: Mario::attack()
** Description: Mario will roll 2, 6 sided die, and the
                result will be returned as the attack.
****************************************************************/

int Mario::attack() {
  int dice1 = (rand() % 6) + 1;
  int dice2 = (rand() % 6) + 1;
  attackTotal = dice1 + dice2;
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

string Mario::getType() {
  return "Mario";
}