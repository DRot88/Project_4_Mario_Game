#include "game.hpp"
#include "mario.hpp"
#include "space.hpp"


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
  while (gameBoard->getGameStatus() == UNFINISHED) {
    gameBoard->printBoard();
    gameBoard->displayGameOptions();
    gameBoard->moveMario();
  }

  // gameBoard->board[marioPtr->getRow()][marioPtr->getCol()] = marioPosition;
  // gameBoard->printBoard();


  // marioPtr->attack();
  return;
}