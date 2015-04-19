/*
 =============================================================================
 Name        : Game.h
 Author      : Arpad Attila Asztalos
 Version     : 1 (duh)
 Copyright   : @Arpad 2015
 Description : Game.h file for Project1 CS32 Spring 2015
 =============================================================================
 */

#ifndef GAME_INCLUDED
#define GAME_INCLUDED

class Pit;

class Game
{
  public:
        // Constructor/destructor
    Game(int rows, int cols, int nSnakes);
    ~Game();

        // Mutators
    void play();

  private:
    Pit* m_pit;
};

#endif // GAME_INCLUDED
