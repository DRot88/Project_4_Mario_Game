#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <string>
using std::string;

class Character {
  protected:
    int armor;
    int health;
    int attackTotal;
    int defenseTotal;
  public:
    Character();
    virtual ~Character();
    virtual int attack() = 0; // pure virtual function
    virtual int defend(int damageTaken) = 0; // pure virtual function
    virtual string getType() = 0; // pure virtual function to return fighter time
    virtual void lowerHealth(int damageReceived);
    virtual int getHealth();
};

#endif