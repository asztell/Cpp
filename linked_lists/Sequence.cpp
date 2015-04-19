/*
 =============================================================================
 Name        : Sequence.cpp
 Author      : Arpad Attila Asztalos
 Version     : 1
 Copyright   : @Arpad 2015
 Description : Sequence.cpp file for Project2 CS32 Spring 2015
 =============================================================================
 */

#include "Sequence.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Sequence::Sequence()
:m_len(0)
{
	head = new Node;
	head->m_prev = head;
	head->m_next = head;
	cout <<endl<< "==   S   ==" <<endl;
}

Sequence::~Sequence()
{
	cout<<"   ~S    "<<endl<<endl;
	if (size() == 0)
//		cout<<"size() == 0"<<endl;
		delete head;

	for (Node* p = head->m_next; p != head; p = p->m_next)
	{
		cout << " ~S  for" << endl;
		// cout<<"head == "<<head<<endl;
		// cout<<"head->m_next == "<<head->m_next<<endl;
		// cout<<"p == "<<p<<endl;
		delete p;
		// cout<<" after delete p"<<endl;
		// cout<<"p == "<<p<<endl;
	}
	cout << " ~S  end" <<endl<<endl;
	delete head;
}

Sequence& Sequence::operator=(const Sequence& other)
{
	if (this == &other)
	{
		return (*this);
	}

	if (head != head->m_next)
	{
		Node* p = head->m_next;

		while (p != p->m_next)
		{
			Node* n = p->m_next;
			delete p;
			p = n;
		}
	}

	Node* n = other.head;

	while (n != other.head)
	{
//		for (int i = 0; i < other->size(); i++)
//		{
			;
//		}
	}

	return (*this);
}

bool Sequence::insert(int pos, const ItemType& value)
{
	if ( ( pos <= 0 ) || ( pos > ( ( this->size() ) + 1) ) )
	{
		return false;
	}

	Node* p = head;

	for (int i = 1; i < pos; i++)
	{
		p = p->m_next;
	}

	Node* newNode = new Node;
	newNode->m_data = value;
	newNode->m_prev = p->m_prev;
	newNode->m_next = p;

	p->m_prev = newNode;
	p = newNode->m_prev;
	p->m_next = newNode;

	m_len++;

	return true;
}

bool Sequence::insert(const ItemType& value)
{
	cout <<endl<< "==   insert()   ==" << endl;
	Node* p = head->m_prev;		// assign head to p
	Node* newNode = new Node;	// create new Node
	newNode->m_data = value;	// give it value
//	cout<<"newNode->m_data == "<<newNode->m_data<<endl;
	
	newNode->m_prev = head->m_prev;// last pointer to new's prev
	newNode->m_next = head;		// head to new's next
	// cout<<"newNode->m_prev == "<<newNode->m_prev<<endl;
	// cout<<"newNode->m_next == "<<newNode->m_next<<endl;
	// cout<<"head->m_prev == "<<head->m_prev<<endl;
	// cout<<"head == "<<head<<endl;

	p->m_next = newNode;
	head->m_prev = newNode;
	// cout<<"p->m_next == "<<p->m_next<<endl;
	// cout<<"newNode == "<<newNode<<endl;
	// cout<<"head->m_prev == "<<head->m_prev<<endl;
//	cout<<""<<endl;
	m_len++;
	//beware of empty and one-element list!!!!
	return true;
}

bool Sequence::erase(int pos)
{
	if ( (size() != 0) && (pos >= 1) && (pos <= size()) )
	{
		cout<<"  erase()"<<endl<<endl;
		Node* p = head->m_next;

		for (int i = 1; i < pos; i++)
		{
			p = p->m_next;
		}

		Node* temp = p->m_prev;
		temp->m_next = p->m_next;

		temp = p->m_next;
		temp->m_prev = p->m_prev;

		delete p;

		m_len--;

		return true;
	}

	return false;
}

int Sequence::remove(const ItemType& value)
{	
	int removed_items = 0;

	if (size() != 0)
	{
		Node* p = head->m_next;

		int position_counter = 1;
		for (p; p != head; p = p->m_next)
		{
			if (p->m_data == value)
			{
				p = p->m_prev;

				erase(position_counter);

				removed_items++;
				position_counter--;
			}
			position_counter++;
		}
	}

	return removed_items;
}

bool Sequence::get(int pos, ItemType& value) const
{
	if ( (size() != 0) && (pos >= 1) && (pos <= size()) )
	{
		cout<<"  get()"<<endl<<endl;
		Node* p = head->m_next;

		for (int i = 1; i < pos; i++)
		{
			p = p->m_next;
		}
		cout<<"value == "<<value<<endl;
		value = p->m_data;

		return true;
	}

	return false;
}
	
bool Sequence::set(int pos, const ItemType& value)
{
	if ( (size() != 0) && (pos >= 1) && (pos <= size()) )
	{
		cout<<"  set()"<<endl<<endl;
		cout<<"value == "<<value<<endl;
		Node* p = head->m_next;

		for (int i = 1; i < pos; i++)
		{
			p = p->m_next;
		}
		cout<<"value == "<<value<<endl;
		p->m_data = value;

		return true;
	}

	return false;
}

int Sequence::find(const ItemType& value) const
{
	if (size() != 0)
	{
		Node* p = head->m_next;

		int position_counter = 1;
		for (p; p != head; p = p->m_next)
		{
			if (p->m_data == value)
			{
				return position_counter;
			}
			position_counter++;
		}
	}

	return -1;
}

void Sequence::swap(Sequence& other)
{

}

void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result)
{

}

int subsequence(const Sequence& seq1, const Sequence& seq2)
{
	return 0;
}