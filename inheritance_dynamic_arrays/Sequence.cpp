/*
 =============================================================================
 Name        : Sequence.cpp
 Author      : Arpad Attila Asztalos
 Version     : 1
 Copyright   : @Arpad 2015
 Description : Sequence.cpp file for Homework1 CS32 Spring 2015
 =============================================================================
 */

#include "Sequence.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Sequence::Sequence()
:m_len(0)
{}

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
	return m_len;
}

bool Sequence::insert(int pos, const ItemType& value)
{
	if ( ! ( 
			(pos >= 0) 
		&&	(pos <= size())
		&&	(size() < DEFAULT_MAX_ITEMS-2)
		   ) )
	{
//		cout<<"ins(): if1-inside"<<endl;
		return false;
	}

	if ( size() == 0 )
	{
//		cout<<"ins(): if2-beg"<<endl;
		m_sequence[0] = value;
//		cout<<"m_sequence[0] == "<<m_sequence[0]<<endl;
		m_len++;
//		cout<<"m_len == "<<m_len<<endl;
		return true;
	}

	for (int i = size(); i > pos; i--)
	{
//		cout << "ins(): for1-beg value == " << value << endl;
		m_sequence[i] = m_sequence[i-1];
//		cout << "ins(): for1-end m_sequence[" << i+1 
//			<< "] == " << m_sequence[i] << endl;
	}
	m_sequence[pos] = value;
//	cout << "value=="<<value<<endl<<"m_sequence["<<pos<<"]=="<<m_sequence[pos]<<endl;
	m_len++;

//	cout << "ins(): end m_len == " << m_len << endl;

	return true;
}

bool Sequence::insert(const ItemType& value)
{
	if ( ! (size() < DEFAULT_MAX_ITEMS-2 ) )
	{
//		cout << "ins(): size() < Def_max" << endl;
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
		// cout << "ins(): /for1: m_sequence["<<p<<"] == " 
		// << m_sequence[p] << endl;
		// cout << "ins(): /for1: value == " << value << endl;
		// cout << "ins(): /for1: p == " << p << endl;
		// cout << "ins(): /for1: size() == " << size() << endl;

//		if ( (size() > 0) && (value <= m_sequence[p]) )
		if ( (value <= m_sequence[p]) )
		{
//			cout << "ins(): if3 " << endl;
			for (int i = size(); i > p; i--)
			{
				m_sequence[i] = m_sequence[i-1];
				// cout << "ins(): for2 m_sequence["<< i <<"] == " 
				// << m_sequence[i] << endl;
//				cout << "ins(): for2 m_sequence["<< (i+1) <<"] == " 
//				<< m_sequence[i+1] << endl;
			}
			m_sequence[p] = value;
			m_len++;
//			cout << "ins(): /for2-end m_len == " << m_len << endl;
			return true;
		}

		// cout << "ins(): /for1-end: value == " << value         << endl;
		// cout << "ins(): /for1-end: m_sequence["<< p <<"] == " 
		// << m_sequence[p] << endl;
	}
	p = size();
//	cout << "ins(): /end: p == " << p << endl;
	m_sequence[p] = value;
//	cout << "ins(): /end: value == " << value << endl;


	m_len++;

	return true;
}

bool Sequence::erase(int pos)
{
	if ( (pos >= 0) && (pos < size()))
	{
		for (int i = pos; i < size(); i++)
		{
			// cout << "era(): for1 /before-erase m_sequence["<< i <<"] == " 
			// << m_sequence[i] << endl;
			m_sequence[i] = m_sequence[i+1];
			// cout << "era(): for1 /after-erase m_sequence["<< i <<"] == " 
			// << m_sequence[i] << endl;
		}
		m_len--;
//		cout << "era(): for1-end m_len == " << m_len << endl;
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
//			cout<<endl<<"rem(): if m_sequence["<<i<<"] == "<<m_sequence[i]<<endl<<endl;
			this->erase(i);
			removed_items++;
			i--;
		}
	}

	return removed_items;
}

bool Sequence::get(int pos, ItemType& value) const
{
	if ( (pos < 0) || (pos >= size()) )
	{
		return false;
	}

	value = m_sequence[pos];

	return true;
}
	
bool Sequence::set(int pos, const ItemType& value)
{
	if ( (pos < 0) || (pos >= size()) )
	{
		return false;
	}

	m_sequence[pos] = value;

	return true;
}

int Sequence::find(const ItemType& value) const
{
	int p = 0;

	// cout << "find(): begin value == " << value 
	// << " m_sequence["<<p<<"] ==  " << 
	// m_sequence[p] << endl;

	for (p = 0; p < size(); p++)
	{
		if (m_sequence[p] == value)
		{
			// cout << "find(): /for1/if1 if1 size() == " << size() << endl;
			// cout << "find(): /for1/if1 " << "p == " << p << endl;
			return p;
		}
	}

	p = -1;

	return p;
}

void Sequence::swap(Sequence& other)
{
//	cout << endl << "swp(): begin " << endl;
	int bigger_size = 0;
	if (size() >= other.size())
	{
		bigger_size = size();
	}
	else
	{
		bigger_size = other.size();
	}

	ItemType temp;
//	ItemType* temp;

	for (int i = 0; i < bigger_size; i++)
	{
		// cout << " for1-beg other.size() == " << other.size()
		// 	 << " this->size() == " 			   << this->size() 
		// 	 << endl;
		// cout << "m_sequence["<<i<<"] == "<<m_sequence[i]<<endl;
		temp = m_sequence[i];
//		cout << " after temp = m_sequence["<<i<<"]; temp == "<< temp << endl;
		m_sequence[i] = other.m_sequence[i];
		// cout << " after m_sequence["<<i<<"] = other.m_sequence["<<i
		// 	<<"]; m_sequence["<<i<<"] == "
		// << m_sequence[i] << endl;
		other.m_sequence[i] = temp;
		// cout << " after other.m_sequence["<<i<<"] = temp; other.m_sequence["<<i
		// 	<<"] == " 
		// << other.m_sequence[i] << endl << endl;

		// cout << " for1-end after swap "<<i+1<<endl
		// << " m_sequence["<<i<<"] == " 	    << m_sequence[i]
		// << " other.m_sequence["<<i<<"] == " << other.m_sequence[i]
		// << " other.size() == " << other.size()
		// << " this->size() == " << this->size() 
		// << endl << endl;
	}

	int this_temp_size = m_len;
	m_len = other.size();
	other.m_len = this_temp_size;

	// cout << " end other.size() == " << other.size()
	// 	 << " this->size() == " 		  << this->size() 
	// 	 << endl;
	// cout << " end other.m_sequence["<< other.size()-1
	// 	 <<"] == " 						  << other.size()
	// 	 << " this->m_sequence["		  << this->size()-1
	// 	 <<"] == " 						  << this->size() 
	// 	 << endl;
}
