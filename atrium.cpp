#include "atrium.hpp"
#include "lava.hpp"
#include <iostream>

const char DOOR = '#'; // Door on map to be marked with '#'

Atrium::Atrium() {
  east = new LavaRoom();
  createRoom();
}

Atrium::~Atrium() {}

void Atrium::createRoom() {
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      if (r == 0 || r == rows - 1) {
        board[r][c] = '-';
      } else if (c == 0 || c == cols - 1) {
        board[r][c] = '|';
      } else {
        board[r][c] = '.';
      }
    }
  }

  //create door on left
  for (int c = 0; c < 2; c++) {
    board[rows/2][c] = ' ';
    board[rows/2 + 1][c] =  DOOR;
    board[rows/2 - 1][c] = DOOR;
  }

  //create door on right
  for (int c = cols - 2; c < cols; c++) {
    board[rows/2][c] = ' ';
    board[rows/2 + 1][c] = DOOR;
    board[rows/2 - 1][c] = DOOR;
  }

  //set Mario's initial position
  board[marioPtr->getRow()][marioPtr->getCol()] = marioPos;

  return;
}

string Atrium::getName() {
  return "Atrium";
}