#ifndef BATTLE_HPP
#define BATTLE_HPP
#include "character.hpp"
#include "mario.hpp"
#include "bowser.hpp"

class Battle {
  private:
    Character *p1; // pointer to pointer fighter 1 (Mario)
    Character *p2; // pointer to pointer fighter 2 (Bowser)
  public:
    Battle();
    bool fight();
    void setFighters(Character *m, Character *b);
};

#endif