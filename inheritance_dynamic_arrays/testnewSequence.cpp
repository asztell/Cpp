/*
 =============================================================================
 Name        : testnewSequence.cpp
 Author      : Arpad Attila Asztalos
 Version     : 1
 Copyright   : @Arpad 2015
 Description : testnewSequence.cpp file for Homework1 CS32 Spring 2015
 =============================================================================
 */

#include "newSequence.h"
//#include "ScoreList.h"
#include <iostream>
#include <cassert>

using namespace std;

int main()
{
	Sequence a(1000);   // a can hold at most 1000 items
    Sequence b(5);      // b can hold at most 5 items
    Sequence c;         // b can hold at most DEFAULT_MAX_ITEMS items
    ItemType v = 50000;
       // No failures inserting 5 items into b
    for (int k = 0; k < 5; k++)
        assert(b.insert(v));
       // Failure if we try to insert a sixth item into b
    assert(!b.insert(v));
       // When two Sequences' contents are swapped, their capacities are
       // swapped as well:
    a.swap(b);
    assert(!a.insert(v));
    assert(b.insert(v));
	
	return 0;
}