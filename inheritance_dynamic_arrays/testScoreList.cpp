/*
 =============================================================================
 Name        : testScoreList.cpp
 Author      : Arpad Attila Asztalos
 Version     : 1
 Copyright   : @Arpad 2015
 Description : testScoreList.cpp file for Homework1 CS32 Spring 2015
 =============================================================================
 */

#include "Sequence.h"
#include "ScoreList.h"
#include <iostream>
#include <cassert>

using namespace std;

int main()
{
	ScoreList s1;
	s1.add(40);
	assert(s1.minimum() == 40);

	cout << "Passed all tests" << endl;

	return 0;
}