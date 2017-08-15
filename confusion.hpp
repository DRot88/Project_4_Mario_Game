#include "space.hpp"
#ifndef CONFUSION_HPP
#define CONFUSION_HPP

class ConfusionRoom : public Space {
private:
  virtual void createRoom(); //2d array
public:
  ConfusionRoom();
  ~ConfusionRoom();
  virtual string getName();
  virtual void moveMario();
};

#endif