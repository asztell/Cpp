/*
 =============================================================================
 Name        : globals.h
 Author      : Arpad Attila Asztalos
 Version     : 1 (duh)
 Copyright   : @Arpad 2015
 Description : globals.h file for Project1 CS32 Spring 2015
 =============================================================================
 */

#ifndef GLOBALS_INCLUDED
#define GLOBALS_INCLUDED

///////////////////////////////////////////////////////////////////////////
// Global constants
///////////////////////////////////////////////////////////////////////////


const int MAXROWS = 20;             // max number of rows in the pit
const int MAXCOLS = 40;             // max number of columns in the pit
const int MAXSNAKES = 180;          // max number of snakes allowed

const int UP    = 0;
const int DOWN  = 1;
const int LEFT  = 2;
const int RIGHT = 3;

///////////////////////////////////////////////////////////////////////////
//  Utility function declarations
///////////////////////////////////////////////////////////////////////////

int decodeDirection(char dir);
bool directionToDeltas(int dir, int& rowDelta, int& colDelta);
void clearScreen();

#endif // GLOBALS_INCLUDED
