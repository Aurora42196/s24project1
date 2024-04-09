//
//  History.cpp
//  s24project1
//
//  Created by Cameron Maiden on 4/6/24.
//

#include <iostream>
#include "History.h"
#include "globals.h" // required to run the clearScreen() function

using namespace std;

History::History(int nRows, int nCols)
{
    
}


bool History::record(int r, int c)
{
    return false;
}


void History::display() const
{
    cerr << "History display() function called!" << endl;
    clearScreen();
    
    cerr << "The screen has been cleared!" << endl;
}
