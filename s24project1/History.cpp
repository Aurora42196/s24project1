//
//  History.cpp
//  s24project1
//
//  Created by Cameron Maiden on 4/6/24.
//

#include <iostream>
#include "History.h"
#include "globals.h" // required to run the clearScreen() function
#include "City.h"

using namespace std;

History::History(int nRows, int nCols)
 : m_rows(nRows), m_cols(nCols)
{
    cerr << "History constructor called!" << endl;
}


bool History::record(int r, int c)
{
    if (! isInBounds(r,c))
        return false;
    return true;
}


void History::display() const
{
    cerr << "History display() function called!" << endl;
    clearScreen();
    
    cerr << "The screen has been cleared!" << endl;
}

bool History::isInBounds(int r, int c) const
{
    return (r >= 1  &&  r <= m_rows  &&  c >= 1  &&  c <= m_cols);
}
