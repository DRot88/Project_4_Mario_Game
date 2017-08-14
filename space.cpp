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

void Space::displayGameOptions() {
  cout << "*************************************************" << endl;
  cout << "*                  Game Options                 *" << endl;
  cout << "*************************************************" << endl << endl;
  cout << "     'U' = Move North, 'H' = Move West" << endl;
  cout << "     'J' = Move South, 'K' = Move East" << endl << endl;
  cout << "           'X' = Exit the Game        " << endl;
  cout << endl;
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

  if (userInput == 'U') {
    marioPtr->setRow(marioPtr->getRow() - 1);
    board[marioPtr->getRow()][marioPtr->getCol()] = MARIO;
  }

  marioPtr->increaseSteps();
}
