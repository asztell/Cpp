/*
 =============================================================================
 Name        : newSequence.cpp
 Author      : Arpad Attila Asztalos
 Version     : 1
 Copyright   : @Arpad 2015
 Description : newSequence.cpp file for Homework1 CS32 Spring 2015
 =============================================================================
 */

#include "newSequence.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Sequence::Sequence()
:m_len(0), m_size(DEFAULT_MAX_ITEMS)
{
	m_sequence = new ItemType[m_size];
}

Sequence::Sequence(int size)
:m_len(0), m_size(size)
{
	m_sequence = new ItemType[m_size];
}

Sequence::~Sequence()
{
	delete [] m_sequence;
}

bool Sequence::empty() const
{
	if (m_len == 0)
	{
		return true;
	}
	return false;
}

int Sequence::size() const
{
//	cout << m_len << endl;
	return m_size;
}

bool Sequence::insert(int pos, const ItemType& value)
{
	if ( ! ( 
			(pos >= 0) 
		&&	(pos <= size())
		&&	(m_len < size())
		   ) )
	{
		cout<<"ins(): if1-inside"<<endl;
		return false;
	}

	if ( size() == 0 )
	{
		cout<<"ins(): if2-beg"<<endl;
		m_sequence[0] = value;
		cout<<"m_sequence[0] == "<<m_sequence[0]<<endl;
		m_len++;
		cout<<"m_len == "<<m_len<<endl;
		return true;
	}

	for (int i = size(); i > pos; i--)
	{
		cout << "ins(): for1-beg value == " << value << endl;
		m_sequence[i] = m_sequence[i-1];
		cout << "ins(): for1-end m_sequence[" << i+1 
			<< "] == " << m_sequence[i] << endl;
	}
	m_sequence[pos] = value;
	cout << "value=="<<value<<endl<<"m_sequence["<<pos<<"]=="<<m_sequence[pos]<<endl;
	m_len++;

	cout << "ins(): end m_len == " << m_len << endl;

	return true;
}

bool Sequence::insert(const ItemType& value)
{
	if ( ! (m_len < size()) )
	{
		cout << "ins(): size() < Def_max" << endl;
		return false;
	}

	if ( size() == 0 )
	{
		m_sequence[0] = value;
		m_len++;
		return true;
	}

	int p;
	for (p = 0; p <= size(); p++)
	{
		cout << "ins(): /for1: m_sequence["<<p<<"] == " 
		<< m_sequence[p] << endl;
		cout << "ins(): /for1: value == " << value << endl;
		cout << "ins(): /for1: p == " << p << endl;
		cout << "ins(): /for1: size() == " << size() << endl;

//		if ( (size() > 0) && (value <= m_sequence[p]) )
		if ( (value <= m_sequence[p]) )
		{
			cout << "ins(): if3 " << endl;
			for (int i = size(); i > p; i--)
			{
				m_sequence[i] = m_sequence[i-1];
				cout << "ins(): for2 m_sequence["<< i <<"] == " 
				<< m_sequence[i] << endl;
//				cout << "ins(): for2 m_sequence["<< (i+1) <<"] == " 
//				<< m_sequence[i+1] << endl;
			}
			m_sequence[p] = value;
			m_len++;
			cout << "ins(): /for2-end m_len == " << m_len << endl;
			return true;
		}

		cout << "ins(): /for1-end: value == " << value         << endl;
		cout << "ins(): /for1-end: m_sequence["<< p <<"] == " 
		<< m_sequence[p] << endl;
	}
	p = size();
	cout << "ins(): /end: p == " << p << endl;
	m_sequence[p] = value;
	cout << "ins(): /end: value == " << value << endl;


	m_len++;

	return true;
}

bool Sequence::erase(int pos)
{
	if ( (pos >= 0) && (pos < size()))
	{
		for (int i = pos; i < size(); i++)
		{
			cout << "era(): for1 /before-erase m_sequence["<< i <<"] == " 
			<< m_sequence[i] << endl;
			m_sequence[i] = m_sequence[i+1];
			cout << "era(): for1 /after-erase m_sequence["<< i <<"] == " 
			<< m_sequence[i] << endl;
		}
		m_len--;
		cout << "era(): for1-end m_len == " << m_len << endl;
		return true;
	}

	return false;
}

int Sequence::remove(const ItemType& value)
{
	int removed_items = 0;

	for (int i = 0; i < size(); i++)
	{
		if (m_sequence[i] == value)
		{
			cout<<endl<<"rem(): if m_sequence["<<i<<"] == "<<m_sequence[i]<<endl<<endl;
			this->erase(i);
			removed_items++;
			i--;
		}
	}

	return removed_items;
}

bool Sequence::get(int pos, ItemType& value)
{
	if ( (pos >= 0) && (pos < size()) )
	{
		value = m_sequence[pos];

		return true;
	}

	return false;
}

bool Sequence::set(int pos, const ItemType& value)
{
	if ( (pos >= 0) && (pos < size()) )
	{
		m_sequence[pos] = value;

		return true;
	}

	return false;
}

int Sequence::find(const ItemType& value) const
{
	int p = 0;

	cout << "find(): begin value == " << value 
	<< " m_sequence["<<p<<"] ==  " << 
	m_sequence[p] << endl;

	for (p = 0; p < size(); p++)
	{
		if (m_sequence[p] == value)
		{
			cout << "find(): /for1/if1 if1 size() == " << size() << endl;
			cout << "find(): /for1/if1 " << "p == " << p << endl;
			return p;
		}
	}

	p = -1;

	return p;
}

void Sequence::swap(Sequence& other)
{
	ItemType* temp = m_sequence;
	int m_len_temp = m_len;
	int m_size_temp = m_size;

	m_sequence = other.m_sequence;
	m_len = other.m_len;
	m_size = other.m_size;
//	temp = &other;
//	swap the m_len integers
}

//	ItemType* temp;