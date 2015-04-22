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
}

Sequence::Sequence(const Sequence& other)
:m_len(0)
{
	head = new Node;
	head->m_prev = head;
	head->m_next = head;

	Node* this_p = head;
	unsigned long data;

	for (int i = 1; i <= other.size(); i++)
	{
		other.get(i, data);
		insert(i, data);
	}
}

Sequence::~Sequence()
{
	if (size() == 0)
	{
		delete head;
	}
	else
	{
		for (Node* p = head->m_next; p != head; p = p->m_next)
		{
			delete p;
		}

		delete head;
	}
}

Sequence& Sequence::operator=(const Sequence& other)
{
	if (this != &other)
	{
		Sequence temp(other);
		swap(temp);
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
	Node* p = head->m_prev;		// assign head to p
	Node* newNode = new Node;	// create new Node
	newNode->m_data = value;	// give it value
	
	newNode->m_prev = head->m_prev;// last pointer to new's prev
	newNode->m_next = head;		// head to new's next

	p->m_next = newNode;
	head->m_prev = newNode;

	m_len++;

	return true;
}

bool Sequence::erase(int pos)
{
	if ( (size() != 0) && (pos >= 1) && (pos <= size()) )
	{
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
		Node* p = head->m_next;

		for (int i = 1; i < pos; i++)
		{
			p = p->m_next;
		}
		value = p->m_data;

		return true;
	}

	return false;
}
	
bool Sequence::set(int pos, const ItemType& value)
{
	if ( (size() != 0) && (pos >= 1) && (pos <= size()) )
	{
		Node* p = head->m_next;

		for (int i = 1; i < pos; i++)
		{
			p = p->m_next;
		}
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
	Node* temp = head;
	int inttemp = m_len;

	head = other.head;
	m_len = other.m_len;

	other.m_len = inttemp;
	other.head = temp;
}

void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result)
{
	Sequence s;

	if (seq1.size() == 0)
	{
		s = seq2;
	}
	else if (seq2.size() == 0)
	{
		s = seq1;
	}
	else
	{
		int smaller;
		int bigger;
		unsigned long temp_s1, temp_s2;

		if (seq1.size() >= seq2.size())
		{
			smaller = seq2.size();
			bigger = seq1.size();
		}
		else
		{
			smaller = seq1.size();
			bigger = seq2.size();
		}

		for (int i = 1; i <= smaller; i++)
		{
			seq1.get(i, temp_s1);				// i == 1	i == 2
			seq2.get(i, temp_s2);				// i == 1	i == 2
			s.insert(((2*i)-1), temp_s1);	// i == 1	i == 3	i == 5
			s.insert((2*i), temp_s2);		// i == 2 	i == 4	i == 6
		}

		if (seq1.size() > seq2.size())
		{
			for (int i = (2*smaller)+1; i <= ((bigger-smaller)+(2*smaller)); i++)
			{
				seq1.get(i, temp_s1);
				s.insert(i, temp_s1);
			}
		}
		else if (seq2.size() > seq1.size())
		{
			for (int i = (2*smaller)+1; i <= ((bigger-smaller)+(2*smaller)); i++)
			{
				seq2.get(i, temp_s2);
				s.insert(i, temp_s2);
			}
		}
	}

	result = s;
}

int subsequence(const Sequence& seq1, const Sequence& seq2)
{
	
	return 0;
}




