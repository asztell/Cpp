/*
 =============================================================================
 Name        : Sequence.h
 Author      : Arpad Attila Asztalos
 Version     : 1
 Copyright   : @Arpad 2015
 Description : Sequence.h file for Project2 CS32 Spring 2015
 =============================================================================
 */

#include <iostream>
#include "Sequence.h"
#include <cassert>

using namespace std;

int main()
{
	Sequence a;
	a.insert(1);
	a.insert(2);
	a.insert(3);
	assert(!(a.size()==1));
	assert((a.size()==3));
	a.erase(2);
	assert((a.size()==2));
	a.insert(4);
	a.insert(5);
	assert((a.size()==4));
	a.remove(4);
	assert((a.size()==3));
	a.insert(2,6);
	Sequence b;
	b.insert(7);
	b.insert(8);
	b.insert(9);
	unsigned long x = 69;
	assert(a.get(2, x));
	unsigned long y = 69;
	assert(b.set(2, y));
	assert(b.find(7)==1);
	a.swap(b);
	Sequence c;
	c.insert(1);
	interleave(a, b, c);
//	assert(c.size() >= 4);
	cout<<"c.size()"<<c.size()<<endl;
	b = a;
	assert(b.size()==3);
	assert(a.size()==3);
//	cout << "a.size() == " << a.size() << endl;
	return 0;
}