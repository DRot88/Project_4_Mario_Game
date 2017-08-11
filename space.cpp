#include "space.hpp"
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::setw;

Space::Space(){
  north = 0;
  south = 0;
  east = 0;
  west = 0;
  rows = 15;
  cols = 15;

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
  cout << endl << "Current Room:" << endl << endl;
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


