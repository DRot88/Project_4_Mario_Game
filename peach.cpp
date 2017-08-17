#include "peach.hpp"
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;

PrincessPeach::PrincessPeach() {
  rowPosition = 12;
  colPosition = 3;
}

PrincessPeach::~PrincessPeach() {}

string PrincessPeach::getType() {
  return "Princess Peach";
}

void PrincessPeach::decreasePeachHealth() {
  this->health -= 1;
}

int PrincessPeach::attack() { // peach does not attack
  return 0;
}

int PrincessPeach::defend(int damageReceived) { // peach does not defend
  return 0; 
}