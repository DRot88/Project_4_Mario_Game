#ifndef SPACE_HPP
#define SPACE_HPP
#include "character.hpp"
#include "mario.hpp"
#include <string>
using std::string;

class Space {
protected:
  Space *north;
  Space *south;
  Space *east;
  Space *west;
  char **board; // to allocate memory for 2d grid
  Mario *marioPtr;
  char marioPos; // mario's location on map;
  int rows;
  int cols;
  bool canEnter; // changes depending on room
  virtual void createRoom() = 0; // every room has a different layout

public:
  Space(); //constructor
  virtual ~Space(); //destructor
  void printBoard();
  void displayGameOptions();
  virtual string getName() = 0;
  void moveMario();
};


#endif