/*
 =============================================================================
 Name        : main.cpp
 Author      : Arpad Attila Asztalos
 Version     : 1 (duh)
 Copyright   : @Arpad 2015
 Description : main.cpp file for Project1 CS32 Spring 2015
 =============================================================================
 */

#include "Game.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
      // Initialize the random number generator.  (You don't need to
      // understand how this works.)
    srand(static_cast<unsigned int>(time(0)));

      // Create a game
      // Use this instead to create a mini-game:   Game g(3, 3, 2);
    Game g(9, 10, 40);

      // Play the game
    g.play();
}
