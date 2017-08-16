#include "poison.hpp"
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
const char POISONGAS = 'P'; //Position position to be marked with 'P'

PoisonRoom::PoisonRoom() {
  createRoom();
  stepsRemaining = 25;
}

PoisonRoom::~PoisonRoom() {}

void PoisonRoom::createRoom() {
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

  //create door to south
  for (int r = rows - 2; r < rows; r++) {
    board[r][cols/2] = ' ';
    board[r][cols/2 + 1] = DOOR;
    board[r][cols/2 - 1] = DOOR;
  }

  //set Mario's initial position
  board[marioPtr->getRow()][marioPtr->getCol()] = marioPos;

  //set random poison positions;
  for (int x = 0; x < 50; x++) {
    int r = (rand() % 10) + 2;
    int c = (rand() % 11) + 4;
    board[r][c] = POISONGAS;
  }  

  return;
}

string PoisonRoom::getName() {
  return "Poison Room";
}

void PoisonRoom::moveMario() {

  cout << "Steps Remaining: " << stepsRemaining << endl;

  char userInput;
  cout << "Please enter your move from the options above: ";
  getChar(userInput, 'U', 'H', 'J', 'K', 'X'); // Movements allowed (X,H,J,K) or exit the game (X)

  if (userInput == 'U') { // move north
    int lastRow = marioPtr->getRow(); // get marios last row 
    int lastCol = marioPtr->getCol(); // get marios last column
    if (marioPtr->getRow() == 0) {
      cout << "Mario walked into a wall!";
      return;
    }    
    marioPtr->setRow(marioPtr->getRow() - 1); // set new position for mario
    
    if (board[marioPtr->getRow()][marioPtr->getCol()] == POISONGAS) { // decrease health if stepped into poison cloud
      marioPtr->lowerHealth(20);
      cout << "Mario has lost 20 health for choking on a poison cloud.";
      if (marioPtr->getHealth() == 0) {
        cout << "\n\nMario has choked to death!! The Princess will never be saved!" << endl << endl;
        exit(0);
      } 
    }   
   
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
        cout << "Mario has moved into the Confusion room!";
        gameStatus = CONFUSION;
        return;
      } else {
        cout << "Mario walked into a wall!";
        return;
      }
    }    
    marioPtr->setCol(marioPtr->getCol() - 1); // set new position for mario

    if (board[marioPtr->getRow()][marioPtr->getCol()] == POISONGAS) { // decrease health if stepped into poison cloud
      marioPtr->lowerHealth(20);
      cout << "Mario has lost 20 health for choking on a poison cloud.";
      if (marioPtr->getHealth() == 0) {
        cout << "\n\nMario has choked to death!! The Princess will never be saved!" << endl << endl;
        exit(0);
      } 
    }   

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
      if (marioPtr->getCol() == cols/2) {
      cout << "The door has locked behind him, no turning back!";
      return;
      } else {
        cout << "Mario walked into a wall!";
        return;        
      }
    }    
    marioPtr->setRow(marioPtr->getRow() + 1); // set new position for mario

    if (board[marioPtr->getRow()][marioPtr->getCol()] == POISONGAS) { // decrease health if stepped into poison cloud
      marioPtr->lowerHealth(20);
      cout << "Mario has lost 20 health for choking on a poison cloud.";
      if (marioPtr->getHealth() == 0) {
        cout << "\n\nMario has choked to death!! The Princess will never be saved!" << endl << endl;
        exit(0);
      } 
    } 

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
      cout << "Mario walked into a wall!";
      return;
    }
    marioPtr->setCol(marioPtr->getCol() + 1); // set new position for mario

    if (board[marioPtr->getRow()][marioPtr->getCol()] == POISONGAS) { // decrease health if stepped into poison cloud
      marioPtr->lowerHealth(20);
      cout << "Mario has lost 20 health for choking on a poison cloud.";
      if (marioPtr->getHealth() == 0) {
        cout << "\n\nMario has choked to death!! The Princess will never be saved!" << endl << endl;
        exit(0);
      } 
    } 
    
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

  //decrease reallowable steps before 'death'
  stepsRemaining--;
  if (stepsRemaining == 0) {
    cout << "\nMario has been trapped for too long in the poison room and has died.";
    cout << "\nThe Princess will forever be lost in Bowsers Dungeon.";
    cout << "\n\nGAME OVER" << endl << endl;
    exit(0);
  }
}