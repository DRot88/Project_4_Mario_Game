#include "lava.hpp"
#include "validations.hpp"
#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::getline;

const char DOOR = '#'; // Door on map to be marked with '#'
const char MARIO = 'M'; // Mario's position to be marked with 'M'

LavaRoom::LavaRoom() {
  createRoom();
}

LavaRoom::~LavaRoom() {}

void LavaRoom::createRoom() {
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

  //create door to west
  for (int c = 0; c < 2; c++) {
    board[rows/2][c] = ' ';
    board[rows/2 + 1][c] =  DOOR;
    board[rows/2 - 1][c] = DOOR;
  }

  //create door to north
  for (int r = 0; r < 2; r++) {
    board[r][cols/2] = ' ';
    board[r][cols/2 + 1] = DOOR;
    board[r][cols/2 - 1] = DOOR;
  }

  //set Mario's initial position
  board[marioPtr->getRow()][marioPtr->getCol()] = marioPos;

  return;
}

string LavaRoom::getName() {
  return "Lava Room";
}

void LavaRoom::moveMario() {
  char userInput;
  cout << "Please enter your move from the options above: ";
  getChar(userInput, 'U', 'H', 'J', 'K', 'X'); // Movements allowed (X,H,J,K) or exit the game (X)

  if (userInput == 'U') { // move north
    int lastRow = marioPtr->getRow(); // get marios last row 
    int lastCol = marioPtr->getCol(); // get marios last column
    if (marioPtr->getRow() == 0) {
      if (marioPtr->getCol() == cols/2) {
        cout << "Mario has moved into the Posion room!" << endl;
        gameStatus = POISON;
        return;        
      }
      cout << "Mario walked into a wall!";
      return;
    }    
    marioPtr->setRow(marioPtr->getRow() - 1); // set new position for mario
    board[marioPtr->getRow()][marioPtr->getCol()] = MARIO; // place 'M' character at new position to reflect movement

    if (lastCol == 0 || lastCol == cols - 1) { // if first or last column
      board[lastRow][lastCol] = '|'; // set prior position back to original state
    }

    if (lastRow == 0 || lastRow == rows - 1) {// if first or last row
      board[lastRow][lastCol] = '-'; // set prior position back to original state
    }

    if (lastRow != 0 && lastRow != rows -1 && lastCol != 0 && lastCol != cols - 1) {
      board[lastRow][lastCol] = '.'; // if not first/last row/col set back to '.'
    }
  }

  if (userInput == 'H') { // move west
    int lastRow = marioPtr->getRow(); // get marios last row 
    int lastCol = marioPtr->getCol(); // get marios last column
    if (marioPtr->getCol() == 0) {
      if (marioPtr->getRow() == rows/2 ) {
        cout << "Mario can not move into the dungeon!";
        return;
      } else {
        cout << "Mario walked into a wall!";
        return;
      }
    }    
    marioPtr->setCol(marioPtr->getCol() - 1); // set new position for mario
    board[marioPtr->getRow()][marioPtr->getCol()] = MARIO; // place 'M' character at new position to reflect movement

    if (lastCol == 0 || lastCol == cols - 1) { // if first or last column
      board[lastRow][lastCol] = '|'; // set prior position back to original state
    }

    if (lastRow == 0 || lastRow == rows - 1) {// if first or last row
      board[lastRow][lastCol] = '-'; // set prior position back to original state
    }

    if (lastRow != 0 && lastRow != rows -1 && lastCol != 0 && lastCol != cols - 1) {
      board[lastRow][lastCol] = '.'; // if not first/last row/col set back to '.'
    }
  }

  if (userInput == 'J') { // move south
    int lastRow = marioPtr->getRow(); // get marios last row 
    int lastCol = marioPtr->getCol(); // get marios last column
    if (marioPtr->getRow() == rows - 1) {
      cout << "Mario walked into a wall!";
      return;
    }    
    marioPtr->setRow(marioPtr->getRow() + 1); // set new position for mario
    board[marioPtr->getRow()][marioPtr->getCol()] = MARIO; // place 'M' character at new position to reflect movement

    if (lastCol == 0 || lastCol == cols - 1) { // if first or last column
      board[lastRow][lastCol] = '|'; // set prior position back to original state
    }

    if (lastRow == 0 || lastRow == rows - 1) {// if first or last row
      board[lastRow][lastCol] = '-'; // set prior position back to original state
    }

    if (lastRow != 0 && lastRow != rows -1 && lastCol != 0 && lastCol != cols - 1) {
      board[lastRow][lastCol] = '.'; // if not first/last row/col set back to '.'
    }
  }

  if (userInput == 'K') { // move east
    int lastRow = marioPtr->getRow(); // get marios last row 
    int lastCol = marioPtr->getCol(); // get marios last column
    if (marioPtr->getCol() == cols - 1) {
      return;
    }
    marioPtr->setCol(marioPtr->getCol() + 1); // set new position for mario
    board[marioPtr->getRow()][marioPtr->getCol()] = MARIO; // place 'M' character at new position to reflect movement
    if (lastCol == 0 || lastCol == cols - 1) { // if first or last column
      board[lastRow][lastCol] = '|'; // set prior position back to original state
    }

    if (lastRow == 0 || lastRow == rows - 1) {// if first or last row
      board[lastRow][lastCol] = '-'; // set prior position back to original state
    }

    if (lastRow != 0 && lastRow != rows -1 && lastCol != 0 && lastCol != cols - 1) {
      board[lastRow][lastCol] = '.'; // if not first/last row/col set back to '.'
    }
  }

  if (userInput == 'X') { // X to quit game
    cout << "\nExiting Game" << endl << endl;
    exit(0);
  }
}