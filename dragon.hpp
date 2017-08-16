#include "space.hpp"
#ifndef DRAGON_HPP
#define DRAGON_HPP

class DragonRoom : public Space {
private:
  virtual void createRoom(); //2d array
  bool hasKey;
public:
  DragonRoom();
  ~DragonRoom();
  virtual string getName();
  virtual void moveMario();
  void playFlute();
};

#endif