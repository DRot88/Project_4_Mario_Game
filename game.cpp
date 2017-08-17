#include "game.hpp"
#include "mario.hpp"
#include "space.hpp"
#include "lava.hpp"
#include "poison.hpp"
#include "confusion.hpp"
#include "dragon.hpp"
#include "dungeon.hpp"
#include "peach.hpp"
#include "validations.hpp"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;


Game::Game() {
  gameBoard = new Atrium();
  princessHealth = 300;
}

Game::~Game() {
  delete gameBoard;
  gameBoard = 0;
}

void Game::welcomeScreen() {
  cout << "\nIt was another quiet day in Mushroom Kingdom " << endl;
  cout << "when a deafening blast shook the Kings Tower." << endl;

  cout << "\nThe famous Mario was sleeping in his bed when " << endl;
  cout << "the blast woke him suddenly, fearing for the worst." << endl;
  cout << "Mario had recogized the screams of his bride to be " << endl;
  cout << "and he scrambled to see what was going on." << endl;

  cout << "\n'MARIO!! MARIO!! HELP ME!!' screamed Princess Peach." << endl;

  cout << "\nMario cause a quick glimpse of the blimp that the princess " << endl;
  cout << "was being held captive in as his arch nemesis'.. Bowser!" << endl;

  cout << "\nAfter one long and tiring week, Mario has finally tracked " << endl;
  cout << "the Princess' whereabouts to Bowsers secret fortress." << endl;

  cout << "\nYour goal is to rescue the Princess before she perishes" << endl;

  cout << "\nPress Enter to Continue..";

  string temp;
  getline(cin, temp);
  std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );

}

void Game::dragonMessage() {
  cout << endl << endl << endl;
  cout << "          <>=======()" << endl;
  cout << "           (/\\___   /|\\          ()==========<>_ " << endl;
  cout << "                 \\_/ | \\        //|\\   ______/ \\)" << endl;
  cout << "                   \\_|  \\      // | \\_/" << endl;
  cout << "                     \\|\\/|\\_   //  /\\/" << endl;
  cout << "                      (oo)\\ \\_//  /" << endl;
  cout << "                     //_/\\_\\/ /  |" << endl;
  cout << "                    @@/  |=\\  \\  |" << endl;
  cout << "                        \\_=\\_ \\ |" << endl;
  cout << "                           \\==\\ \\|\\" << endl;
  cout << "                        __(\\===\\(  )\\" << endl;
  cout << "                       (((~) __(_/   |" << endl;
  cout << "                            (((~) \\  /" << endl;
  cout << "                            ______/ /" << endl;
  cout << "                            '------'" << endl << endl;
  cout << "There is an evil dragon gaurding this room. You must find the flute" << endl;
  cout << "to put the dragon to sleep. Once you play the flute, you can sneak past the dragon." << endl;
  cout << "\nPress Enter to Continue..";

  string temp;
  getline(cin, temp);
  std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
  return;
}

void Game::congratulations() {
  cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
  cout << "\nMario and Princess Peach have successfully escape the secret lair of Bowser." << endl;
  cout << "They will be returning to Mushroom Kingdom to live happily ever after." << endl;
  cout << "That is, what they would hope for.. but Bowser always returns.. Always.." << endl;
  cout << "\nCONGRATULATIONS! YOU BEAT THE GAME!" << endl << endl;
  return;
}

void Game::lowerPrincessHealth() {
  princessHealth--;
}

int Game::getPrincessHealth() {
  return princessHealth;
}

void Game::playGame() {

  welcomeScreen();
    while (gameBoard->getGameStatus() == ATRIUM) {
      gameBoard->printBoard();
      if (princessHealth > 0) {
        cout << "\nPrincess Health Remaining: " << getPrincessHealth() << endl << endl; 
        gameBoard->displayGameOptions();
        gameBoard->moveMario();
        princessHealth--;
      } else {
        gameBoard->setGameStatus(GAME_OVER);
      } 
    }

    if (gameBoard->getGameStatus() == LAVA) {
      gameBoard = new LavaRoom();
      gameBoard->setGameStatus(LAVA);
    }

    while (gameBoard->getGameStatus() == LAVA) {
      gameBoard->printBoard();
      if (princessHealth > 0) {
        cout << "\nPrincess Health Remaining: " << getPrincessHealth() << endl << endl; 
        gameBoard->displayGameOptions();
        gameBoard->moveMario();
        princessHealth--;
      } else {
        gameBoard->setGameStatus(GAME_OVER);
      } 
    }  

    if (gameBoard->getGameStatus() == POISON) {
      gameBoard = new PoisonRoom();
      gameBoard->setGameStatus(POISON);
    }

    while (gameBoard->getGameStatus() == POISON) {
      gameBoard->printBoard();
      if (princessHealth > 0) {
        cout << "\nPrincess Health Remaining: " << getPrincessHealth() << endl << endl; 
        gameBoard->displayGameOptions();
        gameBoard->moveMario();
        princessHealth--;
      } else {
        gameBoard->setGameStatus(GAME_OVER);
      } 
    }    

    if (gameBoard->getGameStatus() == CONFUSION) {
      gameBoard = new ConfusionRoom();
      gameBoard->setGameStatus(CONFUSION);
    }

    while (gameBoard->getGameStatus() == CONFUSION) {
      gameBoard->printBoard();
      if (princessHealth > 0) {
        cout << "\nPrincess Health Remaining: " << getPrincessHealth() << endl << endl; 
        gameBoard->displayConfusedOptions();
        gameBoard->moveMario();
        princessHealth--;
      } else {
        gameBoard->setGameStatus(GAME_OVER);
      }   
    }   

    if (gameBoard->getGameStatus() == DRAGON) {
      gameBoard = new DragonRoom();
      gameBoard->setGameStatus(DRAGON);
    }
    if (princessHealth > 0) {
      dragonMessage();
    }

    while (gameBoard->getGameStatus() == DRAGON) {
      gameBoard->printBoard();
      if (princessHealth > 0) {
        cout << "\nPrincess Health Remaining: " << getPrincessHealth() << endl << endl; 
        gameBoard->displayGameOptions();
        gameBoard->moveMario();
        princessHealth--;
      } else {
        gameBoard->setGameStatus(GAME_OVER);
      } 
    }

    if (gameBoard->getGameStatus() == DUNGEON) {
      gameBoard = new Dungeon();
      gameBoard->setGameStatus(DUNGEON);
    }

    while (gameBoard->getGameStatus() == DUNGEON) {
      gameBoard->printBoard();
      if (princessHealth > 0) {
        cout << "\nPrincess Health Remaining: " << getPrincessHealth() << endl << endl; 
        gameBoard->displayGameOptions();
        gameBoard->moveMario();
        princessHealth--;
      } else {
        gameBoard->setGameStatus(GAME_OVER);
      } 
    }

    if (gameBoard->getGameStatus() == WIN) {
      congratulations();
      exit(0);
    }              

    if (gameBoard->getGameStatus() == GAME_OVER) {
      cout << "\nMario has taken too long in the search for the Princess.";
      cout << "\nPrincess Peach has met her fate and has passed away.." << endl;
      cout << "Game Over" << endl << endl;
      exit(0);
    }

  return;
}