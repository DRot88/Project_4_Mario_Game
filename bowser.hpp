#ifndef BOWSER_HPP
#define BOWSER_HPP
#include "character.hpp"
#include <string>
#include <ctime>
using std::string;

class Bowser : public Character {
  private:
    
  public:
    Bowser();
    ~Bowser();
    virtual int attack(); // 3 dice, slash, shell attack, fire breath
    virtual int defend(int damageReceived); // 1 die, 15 sides, 25% chance of evade
    virtual string getType();
    bool shellAttack(); // if using shell attack, 50% chance of a second roll
    bool fireBreath(); // if fire breath, 33% chance of a third roll
    void move();
    void increaseSteps();
};

#endif