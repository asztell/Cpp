/*
 =============================================================================
 Name        : Snake.h
 Author      : Arpad Attila Asztalos
 Version     : 1 (duh)
 Copyright   : @Arpad 2015
 Description : Snake.h file for Project1 CS32 Spring 2015
 =============================================================================
 */

#ifndef SNAKE_INCLUDED
#define SNAKE_INCLUDED

class Pit;

class Snake
{
  public:
        // Constructor
    Snake(Pit* pp, int r, int c);

        // Accessors
    int  row() const;
    int  col() const;

         // Mutators
    void move();

  private:
    Pit* m_pit;
    int  m_row;
    int  m_col;
};

#endif // SNAKE_INCLUDED
