#include "space.hpp"
#include "character.hpp"
#include "bowser.hpp"
#include "peach.hpp"
#ifndef DUNGEON_HPP
#define DUNGEON_HPP

class Dungeon : public Space {
private:
  virtual void createRoom(); //2d array
  Bowser *bowserPtr;
  PrincessPeach *peachPtr;
public:
  Dungeon();
  ~Dungeon();
  virtual string getName();
  virtual void moveMario();
};

#endif