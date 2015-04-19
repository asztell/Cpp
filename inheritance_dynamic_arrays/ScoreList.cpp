/*
 =============================================================================
 Name        : ScoreList.cpp
 Author      : Arpad Attila Asztalos
 Version     : 1
 Copyright   : @Arpad 2015
 Description : ScoreList.cpp file for Homework1 CS32 Spring 2015
 =============================================================================
 */
#include "ScoreList.h"
#include "Sequence.h"

ScoreList::ScoreList()
{}

bool ScoreList::add(unsigned long score)
{
    if ((score >= 0)&&(score <= 100))
    {
        m_list.insert(score);
        return true;
    }
    return false;
}
  // If the score is valid (a value from 0 to 100) and the score list
  // has room for it, add it to the score list and return true.
  // Otherwise, leave the score list unchanged and return false.

bool ScoreList::remove(unsigned long score)
{
    if ((score >= 0)&&(score <= 100))
    {
        int index_of_score = 0;
        index_of_score = m_list.find(score);
        m_list.erase(index_of_score);
        return true;
    }
    return false;
}
  // Remove one instance of the specified score from the score list.
  // Return true if a score was removed; otherwise false.

int ScoreList::size() const
{
    return m_list.size();
}
  // Return the number of scores in the list.

unsigned long ScoreList::minimum() const
{
    if (m_list.empty())
    {
        return NO_SCORE;
    }

    unsigned long result;
    m_list.get(0, result);

    for (int i = 1; i < size(); i++)
    {
        unsigned long temp;
        m_list.get(i, temp);

        if (temp < result)
        {
            result = temp;
        }
    }
    return result;
}
  // Return the lowest score in the score list.  If the list is
  // empty, return NO_SCORE.

unsigned long ScoreList::maximum() const
{
    if (m_list.empty())
    {
        return NO_SCORE;
    }

    unsigned long result;
    m_list.get(0, result);

    for (int i = 1; i < size(); i++)
    {
        unsigned long temp;
        m_list.get(i, temp);

        if (temp > result)
        {
            result = temp;
        }
    }

    return result;
}
  // Return the highest score in the score list.  If the list is
  // empty, return NO_SCORE.