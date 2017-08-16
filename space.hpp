#ifndef SPACE_HPP
#define SPACE_HPP
#include "character.hpp"
#include "mario.hpp"
#include <string>
using std::string;

enum Status {ATRIUM, LAVA, POISON, CONFUSION, DRAGON, DUNGEON, GAME_OVER, WIN};

class Space {
protected:

  char **board; // to allocate memory for 2d grid
  Mario *marioPtr;
  char marioPos; // mario's location on map;
  int rows;
  int cols;
  bool canEnter; // changes depending on room
  Status gameStatus;
  virtual void createRoom() = 0; // every room has a different layout

public:
  Space *north;
  Space *south;
  Space *east;
  Space *west;
  Space(); //constructor
  virtual ~Space(); //destructor
  void printBoard();
  void displayGameOptions();
  void displayConfusedOptions();
  virtual string getName() = 0;
  virtual void moveMario();
  Status getGameStatus();
  void setGameStatus(Status s);
};


#endif