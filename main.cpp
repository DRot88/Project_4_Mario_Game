#include "menu.hpp"
#include "game.hpp"
#include "character.hpp"
#include "mario.hpp"
#include "atrium.hpp"
#include "space.hpp"
#include "lava.hpp"
#include "poison.hpp"
#include "confusion.hpp"
#include "dragon.hpp"
#include "peach.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::cin;
using std::endl;

int main() {
  srand(time(0));
  Menu gameMenu;
  gameMenu.displayMenu();
  // Atrium a;
  // a.printBoard();
  // Mario mario;
  // mario.defend(5);
  // mario.attack();
  return 0;
}