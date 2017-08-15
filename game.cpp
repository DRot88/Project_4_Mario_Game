#include "game.hpp"
#include "mario.hpp"
#include "space.hpp"
#include "lava.hpp"
#include <iostream>
using std::cout;
using std::endl;


Game::Game() {
  // marioPtr = new Mario();
  gameBoard = new Atrium();
//   bowserPtr = new Bowser();
//   peachPtr = new PrincessPeach();
//   dragonPtr = new Dragon();
}

Game::~Game() {
  delete gameBoard;
  gameBoard = 0;
}

void Game::playGame() {
  while (gameBoard->getGameStatus() == ATRIUM) {
    gameBoard->printBoard();
    gameBoard->displayGameOptions();
    gameBoard->moveMario();
  }

  if (gameBoard->getGameStatus() == LAVA) {
    gameBoard = new LavaRoom();
    gameBoard->setGameStatus(LAVA);
  }

  while (gameBoard->getGameStatus() == LAVA) {
    gameBoard->printBoard();
    gameBoard->displayGameOptions();
    gameBoard->moveMario();
  }  

  if (gameBoard->getGameStatus() == WIN) {
    cout << "\nCONGRATULATIONS!! YOU SAVED PRINCESS PEACH!" << endl;
  }

  if (gameBoard->getGameStatus() == GAME_OVER) {
    cout << "\nPrincess Peach has met her fate and has passed away.." << endl;
    cout << "Game Over" << endl;
  }

  return;
}