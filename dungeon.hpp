#ifndef DUNGEON_HPP
#define DUNGEON_HPP
#include "space.hpp"
#include "character.hpp"
#include "bowser.hpp"
#include "peach.hpp"
#include "battle.hpp"

class Dungeon : public Space {
private:
  virtual void createRoom(); //2d array
  Bowser *bowserPtr;
  PrincessPeach *peachPtr;
  bool hasCellKey;
public:
  Dungeon();
  ~Dungeon();
  virtual string getName();
  virtual void moveMario();
};

#endif