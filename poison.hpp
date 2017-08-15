#include "space.hpp"
#ifndef POISON_HPP
#define POISON_HPP

class PoisonRoom : public Space {
private:
  virtual void createRoom(); //2d array
public:
  PoisonRoom();
  ~PoisonRoom();
  virtual string getName();
  virtual void moveMario();
};

#endif