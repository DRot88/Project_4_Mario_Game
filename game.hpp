#ifndef GAME_HPP
#define GAME_HPP
#include "character.hpp"
#include "space.hpp"
#include "atrium.hpp"

class Game {
private:
  // Character *marioPtr;
  // Character *bowserPtr;
  // Character *peachPtr;
  // Character *dragonPtr;
  Space *gameBoard;
public:
  Game();
  ~Game();
  void playGame();
};


#endif