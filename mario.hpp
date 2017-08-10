#ifndef MARIO_HPP
#define MARIO_HPP
#include "character.hpp"
#include <string>
using std::string;

class Mario : public Character {
  private:
    
  public:
    Mario();
    ~Mario();
    virtual int attack(); // 3 dice, single jump, double jump, triple jump
    virtual int defend(int damageReceived); // 3 dice, single jump, double jump, triple jump
    virtual string getType();
    bool doubleJump(); // if using jump attack, 50% chance of a second roll
    bool tripleJump(); // if double jump, 33% chance of a third roll
    bool evade(); // when defending, mario has 25% chance of evading attack
};

#endif