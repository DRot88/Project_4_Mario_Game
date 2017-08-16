#ifndef PRINCESSPEACH_HPP
#define PRINCESSPEACH_HPP
#include "character.hpp"
#include <string>
#include <ctime>
using std::string;

class PrincessPeach : public Character {
  private:

  public:
    PrincessPeach();
    ~PrincessPeach();
    virtual int attack(); 
    virtual int defend(int damageReceived); 
    virtual string getType();
    void decreasePeachHealth();
};

#endif