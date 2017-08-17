#ifndef GAME_HPP
#define GAME_HPP
#include "character.hpp"
#include "space.hpp"
#include "atrium.hpp"
#include "poison.hpp"

class Game {
private:
  Space *gameBoard;
  int princessHealth; // to be used as game timer
public:
  Game();
  ~Game();
  void playGame();
  void welcomeScreen();
  void dragonMessage();
  void congratulations();
  void lowerPrincessHealth();
  int getPrincessHealth();
};


#endif