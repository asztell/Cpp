/*
 =============================================================================
 Name        : Sequence.h
 Author      : Arpad Attila Asztalos
 Version     : 1
 Copyright   : @Arpad 2015
 Description : Sequence.h file for Project2 CS32 Spring 2015
 =============================================================================
 */

#ifndef SEQUENCE_INCLUDED
#define SEQUENCE_INCLUDED

#include <string>

typedef unsigned long ItemType;
typedef struct Node Node;

class Sequence
{
  public:
    Sequence();
    ~Sequence();
    Sequence& operator=(const Sequence& other);
    bool empty() const;
    int size() const;
    bool insert(int pos, const ItemType& value);
    bool insert(const ItemType& value);
    bool erase(int pos);
    int remove(const ItemType& value);
    bool get(int pos, ItemType& value) const;
    bool set(int pos, const ItemType& value);
    int find(const ItemType& value) const;
    void swap(Sequence& other);
    void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result);
    int subsequence(const Sequence& seq1, const Sequence& seq2);
  private:
    struct Node
    {
        ItemType m_data;
        Node* m_next;
        Node* m_prev;
    };
    Node* head;
    int m_len;
};

inline
bool Sequence::empty() const
{
    return m_len == 0;
}

inline
int Sequence::size() const
{
//    cout << "m_len == " << m_len << endl;
    return m_len;
}

#endif // SEQUENCE_INCLUDED