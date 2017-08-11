#ifndef SPACE_HPP
#define SPACE_HPP

class Space {
protected:
  Space *north;
  Space *south;
  Space *east;
  Space *west;
  char **board; // to allocate memory for 2d grid
  int rows;
  int cols;
  bool canEnter; // changes depending on room
  virtual void createRoom() = 0; // every room has a different layout
public:
  Space(); //constructor
  ~Space(); //destructor
  void printBoard();
  
};


#endif