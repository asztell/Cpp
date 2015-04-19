/*
 =============================================================================
 Name        : Pit.h
 Author      : Arpad Attila Asztalos
 Version     : 1 (duh)
 Copyright   : @Arpad 2015
 Description : Pit.h file for Project1 CS32 Spring 2015
 =============================================================================
 */

#ifndef PIT_INCLUDED
#define PIT_INCLUDED

#include "globals.h"
#include "History.h"
#include <string>

class Snake;
class Player;

class Pit
{
  public:
        // Constructor/destructor
    Pit(int nRows, int nCols);
    ~Pit();

        // Accessors
    int      rows() const;
    int      cols() const;
    Player*  player() const;
    int      snakeCount() const;
    int      numberOfSnakesAt(int r, int c) const;
    void     display(std::string msg) const;
    History& history();

         // Mutators
    bool   addSnake(int r, int c);
    bool   addPlayer(int r, int c);
    bool   destroyOneSnake(int r, int c);
    bool   moveSnakes();

  private:
    int     m_rows;
    int     m_cols;
    Player* m_player;
    Snake*  m_snakes[MAXSNAKES];
    int     m_nSnakes;
    History m_history;
};

#endif // PIT_INCLUDED
