//
//  Tooter.cpp
//  s24project1
//
//  Created by Cameron Maiden on 4/6/24.
//

#include <iostream>
#include "Tooter.h"
#include "City.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////
//  Tooter implementation
///////////////////////////////////////////////////////////////////////////

Tooter::Tooter(City* cp, int r, int c)
 : m_city(cp), m_row(r), m_col(c)
{
    if (cp == nullptr)
    {
        cout << "***** A Tooter must be created in some City!" << endl;
        exit(1);
    }
    if (r < 1  ||  r > cp->rows()  ||  c < 1  ||  c > cp->cols())
    {
        cout << "***** Tooter created with invalid coordinates (" << r << ","
             << c << ")!" << endl;
        exit(1);
    }
}

int Tooter::row() const
{
    return m_row;
}

int Tooter::col() const
{
    return m_col;
}

void Tooter::move()
{
      // Attempt a move in a random direction; if it can't move, don't move.
      // If player is there, don't move.
    int dir = randInt(0, NUMDIRS-1);  // dir is now UP, DOWN, LEFT, or RIGHT
    int r = m_row;
    int c = m_col;
    m_city->determineNewPosition(r, c, dir);
    if ( ! m_city->isPlayerAt(r, c))
    {
        m_row = r;
        m_col = c;
    }
}
