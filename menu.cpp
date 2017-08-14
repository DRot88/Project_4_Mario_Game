#include "menu.hpp"
#include "game.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>
using std::cout;
using std::cin;
using std::endl;
using std::streamsize;
using std::numeric_limits;

Menu::Menu() {
  return;
}

/****************************************************************
** Function: displayMenu
** Description: This will display the options for the user to 
                choose to start the game or to quit the program.
****************************************************************/

void Menu::displayMenu() {
  int choice = 0;
  cout << "\n1: Play Game" << endl;
  cout << "2: Exit" << endl << endl;
  cout << "Please choose from one of the above options: ";
  
  do {
    cin >> choice;    
    switch(choice) {
      case 1 : {
          Game newGame;
          newGame.playGame();
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          break;
      }
      case 2 : {
        cin.ignore();
        cout << "\nExiting the program." << endl << endl;
        break;
      }
      default : {
        cout << "\nInvalid choice, please choose from the valid options." << endl << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
      }
    break;
    }
  } while (choice < 1 || choice > 2);
}