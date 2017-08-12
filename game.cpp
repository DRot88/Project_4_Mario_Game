#include "game.hpp"
#include "mario.hpp"


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
  gameBoard->printBoard();
  // gameBoard->board[marioPtr->getRow()][marioPtr->getCol()] = marioPosition;
  // gameBoard->printBoard();


  // marioPtr->attack();
  return;
}