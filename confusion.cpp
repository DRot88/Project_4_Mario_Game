#include "confusion.hpp"
#include "validations.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::getline;

const char DOOR = '#'; // Door on map to be marked with '#'
const char MARIO = 'M'; // Mario's position to be marked with 'M'

ConfusionRoom::ConfusionRoom() {
  marioPtr->setCol(cols-1);
  marioPtr->setRow(7);
  createRoom();
}

ConfusionRoom::~ConfusionRoom() {}

void ConfusionRoom::createRoom() {
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

  //create door to east
  for (int c = cols - 2 ; c < cols; c++) {
    board[rows/2][c] = ' ';
    board[rows/2 + 1][c] =  DOOR;
    board[rows/2 - 1][c] = DOOR;
  }

  //set Mario's initial position
  board[marioPtr->getRow()][marioPtr->getCol()] = marioPos;

  return;
}

string ConfusionRoom::getName() {
  return "Confusion Room";
}

void ConfusionRoom::moveMario() {
  char userInput;
  cout << "Please enter your move from the options above: ";
  getChar(userInput, 'U', 'H', 'J', 'K', 'X'); // Movements allowed (X,H,J,K) or exit the game (X)

  if (userInput == 'J') { // move north
    int lastRow = marioPtr->getRow(); // get marios last row 
    int lastCol = marioPtr->getCol(); // get marios last column
    if (marioPtr->getRow() == 0) {
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

  if (userInput == 'K') { // move west
    int lastRow = marioPtr->getRow(); // get marios last row 
    int lastCol = marioPtr->getCol(); // get marios last column
    if (marioPtr->getCol() == 0) {
      if (marioPtr->getRow() == rows/2 ) {
        cout << "\nAfter a few minutes, Mario's confusion has worn off." << endl;
        cout << "Mario has moved into the Dragons Lair!" << endl;
        gameStatus = DRAGON;
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

  if (userInput == 'U') { // move south
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

  if (userInput == 'H') { // move east
    int lastRow = marioPtr->getRow(); // get marios last row 
    int lastCol = marioPtr->getCol(); // get marios last column
    if (marioPtr->getCol() == cols - 1) {
      if (marioPtr->getRow() == rows/2 ) {
        cout << "The door has locked behind him, no turning back!";
        return;
      } else {
        cout << "Mario walked into a wall!";        
      }
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