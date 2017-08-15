#include "bowser.hpp"
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;

Bowser::Bowser() {
  armor = 5;
  health = 80;
  rowPosition = 7;
  colPosition = 7;
}

Bowser::~Bowser() {}

/****************************************************************
** Function: Bowser::attack()
** Description: Bowser will roll 1, 8 sided die, and the
                result will be returned as the attack. Each 
                additional attack can result in at most 6 more
                attack points.
****************************************************************/

int Bowser::attack() {
  int dice = (rand() % 8) + 1;
  attackTotal = dice;
  cout << "\nBowser used his slash attack! ";
  cout << "The jump caused " << dice << " damage points!" << endl;
  if (shellAttack()) {
    int dice2 = (rand() % 6) + 1;
    attackTotal += dice2;
    cout << "Wow! Bowser has whipped out his shell attack! ";
    cout << "This caused an extra " << dice2 << " damage points!" << endl;
    if (fireBreath()) {
      int dice3 = (rand() % 6) + 1;
      attackTotal += dice3;
      cout << "Amazing!!! Bowser used his legendary fire breath! ";
      cout << "This caused an extra " << dice3 << " damage points!" << endl;
    }
    cout << "Bowser has caused " << attackTotal << " total damge points!" << endl;
  }
  cout << endl;
  return attackTotal;
}

/****************************************************************
** Function: Bowser::defend(int damageReceived)
** Description: Bowsers defense will be based on a roll of a
                6 sided die. 
****************************************************************/

int Bowser::defend(int damageReceived) {
  int totalDamage = 0;
  int dice = (rand() % 8) + 1;
  defenseTotal = dice + armor;
  cout << "Bowser had a defense of: " << defenseTotal << endl;
  if (defenseTotal >= damageReceived) {
    cout << "The attack was too weak and had no effect on Bowser." << endl;
  } else {
    totalDamage = damageReceived - defenseTotal;
    lowerHealth(totalDamage);
  }
  return totalDamage;
}

bool Bowser::shellAttack() {
  int shellSmash = (rand() % 2) + 1;
  if (shellSmash == 1) {
    return true;
  }
  return false;
}

bool Bowser::fireBreath() {
  int breatheFire = (rand() % 3) + 1;
  if (breatheFire == 1) {
    return true;
  }
  return false;
}

string Bowser::getType() {
  return "Bowser";
}