#ifndef MARIO_HPP
#define MARIO_HPP
#include "character.hpp"
#include <string>
#include <ctime>
#include <vector>
using std::string;
using std::vector;

class Mario : public Character {
  private:
    int stepCount;
    vector<char> bag;
  public:
    Mario();
    ~Mario();
    virtual int attack(); // 3 dice, single jump, double jump, triple jump
    virtual int defend(int damageReceived); // 1 die, 10 sides, 25% chance of evade
    virtual string getType();
    bool doubleJump(); // if using jump attack, 50% chance of a second roll
    bool tripleJump(); // if double jump, 33% chance of a third roll
    bool evade(); // when defending, mario has 25% chance of evading attack
    void move();
    void increaseSteps();
    void addToBag(char item);
    void displayBag();
};

#endif