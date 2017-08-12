#include "space.hpp"
#ifndef ATRIUM_HPP
#define ATRIUM_HPP

class Atrium : public Space {
private:
  virtual void createRoom(); //2d array
public:
  Atrium();
  ~Atrium();
  virtual string getName();
};

#endif