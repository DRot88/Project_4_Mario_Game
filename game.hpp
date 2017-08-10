#ifndef GAME_HPP
#define GAME_HPP
#include "character.hpp"

class Game {
private:
  Character *marioPtr;
  Character *bowserPtr;
  Character *peachPtr;
  Character *dragonPtr;
public:
  Game();
  void playGame();
};


#endif