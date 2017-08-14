#include "space.hpp"
#include "mario.hpp"
#include "validations.hpp"
#include <iostream>
#include <iomanip>
#include <cctype>
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::getline;

const char MARIO = 'M'; // Mario's position to be marked with 'M'

Space::Space(){
  north = 0;
  south = 0;
  east = 0;
  west = 0;
  rows = 15;
  cols = 15;
  marioPtr = new Mario();
  marioPos = MARIO; // To display where Mario is located in each space

  // dynamically create basic board layout
  board = new char *[rows];
  for (int r = 0; r < rows; r++) {
    board[r] = new char[cols];
  }

  gameStatus = UNFINISHED;

}

/************************************************************************
** Description: Default destructor to delete dynamically allocated board
************************************************************************/
Space::~Space(){
  for (int r = 0; r < rows; r++){
    delete [] board[r];
  }
  delete [] board;
  delete marioPtr;
  marioPtr = 0;
  north = 0;
  south = 0;
  east = 0;
  west = 0;
}

/************************************************************************
** Function: printBoard()
** Description: Function that displays the Space to the console
************************************************************************/

void Space::printBoard() {
  cout << endl << "Current Room: " << this-> getName() << endl << endl;
  cout << setw(3) << " ";
  for (int col = 0; col < cols; col++) {
    cout << setw(2) << col << " ";
  }
  cout << endl;

  for (int row = 0; row < rows; row++) {
    cout << setw(2) << row << " ";
    for (int col = 0; col < cols; col++) {
      cout << setw(2) << board[row][col] << " ";
    }
    cout << endl;
  }
  cout << endl;  
}

/************************************************************************
** Function: displayGameOptions()
** Description: Function that displays the options for the player to
                choose. This includes directions for Mario, and the
                ability to exit
************************************************************************/

void Space::displayGameOptions() {
  cout << "*************************************************" << endl;
  cout << "*                  Game Options                 *" << endl;
  cout << "*************************************************" << endl << endl;
  cout << "     'U' = Move North, 'H' = Move West" << endl;
  cout << "     'J' = Move South, 'K' = Move East" << endl << endl;
  cout << "           'X' = Exit the Game        " << endl;
  cout << endl;
}

/************************************************************************
** Function: getGameStatus()
** Description: Function that displays the current status of the game.
                Until the player has GAME_OVER or WIN, the status
                will remain UNFINISHED
************************************************************************/

Status Space::getGameStatus() {
  return gameStatus;
}

/*********************************************************************
** Function: moveMario()
** Description: This function gets user input, and based on the input
                it will move Mario depending on what is entered.
                It calls the Mario::increaseSteps function to keep 
                track of the amount of times he has moved.
**********************************************************************/
void Space::moveMario() {
  char userInput;
  cout << "Please enter your move from the options above: ";
  getChar(userInput, 'U', 'H', 'J', 'K', 'X'); // Movements allowed (X,H,J,K) or exit the game (X)

  if (userInput == 'U') { // move north
    int lastRow = marioPtr->getRow(); // get marios last row 
    int lastCol = marioPtr->getCol(); // get marios last column
    marioPtr->setRow(marioPtr->getRow() - 1); // set new position for mario
    board[marioPtr->getRow()][marioPtr->getCol()] = MARIO; // place 'M' character at new position to reflect movement

    if (lastRow == 0 || lastRow == cols - 1) {// if row 0 or last row
      board[lastRow][lastCol] = '-'; // set prior position back to original state
    } 
  }

  if (userInput == 'H') { // move west
    int lastRow = marioPtr->getRow(); // get marios last row 
    int lastCol = marioPtr->getCol(); // get marios last column
    marioPtr->setCol(marioPtr->getCol() - 1); // set new position for mario
    board[marioPtr->getRow()][marioPtr->getCol()] = MARIO; // place 'M' character at new position to reflect movement

    if (lastRow == 0 || lastRow == cols - 1) {// if row 0 or last row
      board[lastRow][lastCol] = '-'; // set prior position back to original state
    } 
  }

  if (userInput == 'J') { // move south
    int lastRow = marioPtr->getRow(); // get marios last row 
    int lastCol = marioPtr->getCol(); // get marios last column
    marioPtr->setRow(marioPtr->getRow() + 1); // set new position for mario
    board[marioPtr->getRow()][marioPtr->getCol()] = MARIO; // place 'M' character at new position to reflect movement

    if (lastRow == 0 || lastRow == cols - 1) {// if row 0 or last row
      board[lastRow][lastCol] = '-'; // set prior position back to original state
    } 
  }

  if (userInput == 'K') { // move east
    int lastRow = marioPtr->getRow(); // get marios last row 
    int lastCol = marioPtr->getCol(); // get marios last column
    marioPtr->setCol(marioPtr->getCol() + 1); // set new position for mario
    board[marioPtr->getRow()][marioPtr->getCol()] = MARIO; // place 'M' character at new position to reflect movement

    if (lastRow == 0 || lastRow == cols - 1) {// if row 0 or last row
      board[lastRow][lastCol] = '-'; // set prior position back to original state
    } 
  }

  if (userInput == 'X') { // X to quit game
    cout << "\nExiting Game" << endl << endl;
    exit(0);
  }        

  marioPtr->increaseSteps();
}
