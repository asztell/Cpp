/*
 =============================================================================
 Name        : Player.h
 Author      : Arpad Attila Asztalos
 Version     : 1 (duh)
 Copyright   : @Arpad 2015
 Description : Player.h file for Project1 CS32 Spring 2015
 =============================================================================
 */

#ifndef PLAYER_INCLUDED
#define PLAYER_INCLUDED

class Pit;

class Player
{
  public:
        // Constructor
    Player(Pit *pp, int r, int c);

        // Accessors
    int  row() const;
    int  col() const;
    int  age() const;
    bool isDead() const;

         // Mutators
    void   stand();
    void   move(int dir);
    void   setDead();

  private:
    Pit*  m_pit;
    int   m_row;
    int   m_col;
    int   m_age;
    bool  m_dead;
};

#endif // PLAYER_INCLUDED
