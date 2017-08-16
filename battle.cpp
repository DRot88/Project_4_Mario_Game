#include "battle.hpp"
#include <iostream>
#include <limits>
using std::cout;
using std::cin;
using std::endl;
using std::streamsize;
using std::numeric_limits;

Battle::Battle() {
  p1 = 0;
  p2 = 0;
}

/*********************************************************************
** Function: Battle::fight()
** Description: This function will call the setFighters() method to 
                ask the users what fighter they would like to use and
                assign each member pointer to the specific creature of
                choice. From there is will loop through a battle
                scenario until either one of the players has lost all
                of there health (strength) points. It will then present
                the winner of the game. 
**********************************************************************/

bool Battle::fight() {
  bool marioWins = false; // if p1 wins, set to true
  int roundNum = 1;
  cout << "\nTime to battle!" << endl << endl;

  while (p1->getHealth() > 0 && p2->getHealth() > 0) {
    cout << "Round # " << roundNum << endl << endl;

    int p1attack = p1->attack();
    cout << "Mario's Attack: " << p1attack << endl;
    int p2defend = p2->defend(p1attack);
    cout << "Bowser's Damage Taken: " << p2defend << endl;
    cout << "Mario's " << p1->getType() << " Health Remaining: " << p1->getHealth() << endl;
    cout << "Bowser's " << p2->getType() << " Health Remaining: " << p2->getHealth() << endl << endl;

    if (p1->getHealth() > 0 && p2->getHealth() > 0) {
      int p2attack = p2->attack();
      cout << "Bowser's Attack: " << p2attack << endl;
      int p1defend = p1->defend(p2attack);
      cout << "Mario's Damage Taken: " << p1defend << endl;
      cout << "Mario's Health Remaining: " << p1->getHealth() << endl;
      cout << "Bowser's Health Remaining: " << p2->getHealth() << endl << endl;
   }
    roundNum++;

   if (p1->getHealth() == 0) {
    cout << "Bowser has won the battle!" << endl << endl;
      p1 = 0;
      p2 = 0;  
      return marioWins;
   } else if (p2->getHealth() == 0) {
      cout << "Mario has won the battle!" << endl << endl;
      p1 = 0;
      p2 = 0;  
      marioWins = true;
      return marioWins;
   }
  }
  return marioWins;
}

void Battle::setFighters(Character *m, Character *b) {
  p1 = m;
  p2 = b;
}