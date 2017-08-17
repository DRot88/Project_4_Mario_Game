#include "dragon.hpp"
#include "validations.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <limits>
using std::streamsize;
using std::numeric_limits;
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::getline;

const char DOOR = '#'; // Door on map to be marked with '#'
const char MARIO = 'M'; // Mario's position to be marked with 'M'
const char FLUTE = '~'; // Flute's position to be marked with '~';
const char DRAGONSYMBOL = 'D'; //Dragon to be marked with multiple 'D' characters on map
const char KEY = 'K'; // Key to be marked on the map

DragonRoom::DragonRoom() {
  marioPtr->setCol(cols-1);
  marioPtr->setRow(7);
  createRoom();
  hasKey = false;
}

DragonRoom::~DragonRoom() {}

void DragonRoom::createRoom() {
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

  //create door to south
  for (int r = rows - 2; r < rows; r++) {
    board[r][cols/2] = ' ';
    board[r][cols/2 + 1] = DOOR;
    board[r][cols/2 - 1] = DOOR;
  }

  //create door to east
  for (int c = cols - 2 ; c < cols; c++) {
    board[rows/2][c] = ' ';
    board[rows/2 + 1][c] =  DOOR;
    board[rows/2 - 1][c] = DOOR;
  }

  //set Mario's initial position
  board[marioPtr->getRow()][marioPtr->getCol()] = marioPos;

  //set flute position
  board[2][2] = FLUTE;

  //set dragon position
  board[11][6] = DRAGONSYMBOL;
  board[11][7] = DRAGONSYMBOL;
  board[11][8] = DRAGONSYMBOL;
  board[10][6] = DRAGONSYMBOL;
  board[10][7] = DRAGONSYMBOL;
  board[10][8] = DRAGONSYMBOL;

  return;
}

string DragonRoom::getName() {
  return "Dragon Room";
}

void DragonRoom::playFlute() {
cout << endl << endl << endl;

  board[11][6] = '.';
  board[11][7] = '.';
  board[11][8] = '.';
  board[10][6] = '.';
  board[10][7] = '.';
  board[10][8] = KEY;

  board[1][11] = DRAGONSYMBOL;
  board[1][12] = DRAGONSYMBOL;
  board[1][13] = DRAGONSYMBOL;
  board[2][11] = DRAGONSYMBOL;
  board[2][12] = DRAGONSYMBOL;  
  board[2][13] = DRAGONSYMBOL; 

cout << "Mario begain to play the flute and the dragon has moved to the corner" << endl;
cout << "of the room to sleep. He has dropped a KEY. Once obtained, you can " << endl;
cout << "enter the Dungeon, where the princess is being locked up." << endl;
cout << "\nPress Enter to Continue..";

string temp;
getline(cin, temp);
std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );  
}

void DragonRoom::moveMario() {
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

    if (board[marioPtr->getRow()][marioPtr->getCol()] == FLUTE) { // add flute to bag
      cout << "\nMario has obtained the flute!";
      marioPtr->addToBag(FLUTE);
      playFlute();
    }

    if (board[marioPtr->getRow()][marioPtr->getCol()] == KEY) { // add flute to bag
      cout << "\nMario has obtained the Key!";
      marioPtr->addToBag(KEY);
      hasKey = true;
    }       

    if (board[marioPtr->getRow()][marioPtr->getCol()] == DRAGONSYMBOL) { // add flute to bag
      cout << "\nThe Dragon used his mighty fire breath and killed Mario." << endl;
      cout << "\nGAME OVER!" << endl;
      exit(0);
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
        cout << "Mario walked into a wall!";
        return;
    }    
    marioPtr->setCol(marioPtr->getCol() - 1); // set new position for mario

    if (board[marioPtr->getRow()][marioPtr->getCol()] == FLUTE) { // add flute to bag
      cout << "\nMario has obtained the flute!";
      marioPtr->addToBag(FLUTE);
      playFlute();
    }

    if (board[marioPtr->getRow()][marioPtr->getCol()] == KEY) { // add flute to bag
      cout << "\nMario has obtained the Key!";
      marioPtr->addToBag(KEY);
      hasKey = true;
    }    

    if (board[marioPtr->getRow()][marioPtr->getCol()] == DRAGONSYMBOL) { // add flute to bag
      cout << "\nThe Dragon used his mighty fire breath and killed Mario." << endl;
      cout << "\nGAME OVER!" << endl;
      exit(0);
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
      if (marioPtr->getCol() == cols/2 && hasKey) {
      cout << "Mario has reached the Dungeon!!! The Princess is in a cell nearby!";
      gameStatus = DUNGEON;
      return;
      } else {
        cout << "Mario walked into a wall!";
        return;        
      }
    }    
    marioPtr->setRow(marioPtr->getRow() + 1); // set new position for mario

    if (board[marioPtr->getRow()][marioPtr->getCol()] == FLUTE) { // add flute to bag
      cout << "\nMario has obtained the flute!";
      marioPtr->addToBag(FLUTE);
      playFlute();
    }

    if (board[marioPtr->getRow()][marioPtr->getCol()] == KEY) { // add flute to bag
      cout << "\nMario has obtained the Key!";
      marioPtr->addToBag(KEY);
      hasKey = true;
    }       

    if (board[marioPtr->getRow()][marioPtr->getCol()] == DRAGONSYMBOL) { // add flute to bag
      cout << "\nThe Dragon used his mighty fire breath and killed Mario." << endl;
      cout << "\nGAME OVER!" << endl;
      exit(0);
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
      if (marioPtr->getRow() == rows - 1) {
      cout << "The door has locked behind him, no turning back!";
      }
      cout << "Mario walked into a wall!";
      return;
    }
    marioPtr->setCol(marioPtr->getCol() + 1); // set new position for mario

    if (board[marioPtr->getRow()][marioPtr->getCol()] == FLUTE) { // add flute to bag
      cout << "\nMario has obtained the flute!";
      marioPtr->addToBag(FLUTE);
      playFlute();
    }

    if (board[marioPtr->getRow()][marioPtr->getCol()] == KEY) { // add flute to bag
      cout << "\nMario has obtained the Key!";
      marioPtr->addToBag(KEY);
      hasKey = true;      
    }       

    if (board[marioPtr->getRow()][marioPtr->getCol()] == DRAGONSYMBOL) { // add flute to bag
      cout << "\nThe Dragon used his mighty fire breath and killed Mario." << endl;
      cout << "\nGAME OVER!" << endl;
      exit(0);
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
}