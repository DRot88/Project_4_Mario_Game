#include "space.hpp"
#ifndef LAVAROOM_HPP
#define LAVAROOM_HPP

class LavaRoom : public Space {
private:
  virtual void createRoom(); //2d array
public:
  LavaRoom();
  ~LavaRoom();
  virtual string getName();
  virtual void moveMario();
};

#endif