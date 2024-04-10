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
    //cerr << "History constructor called!" << endl;
}


bool History::record(int r, int c)
{
    if (! isInBounds(r,c))
        return false;
    else
        recordArr[r-1][c-1] += 1;
    return true;
}


void History::display() const
{
    //cerr << "History::display() function called!" << endl;
    
    // Position (row,col) in the city coordinate system is represented in
    // the array element grid[row-1][col-1]
    char grid[MAXROWS][MAXCOLS];
    int r, c;
  
      // Fill the grid with dots
    for (r = 0; r < m_rows; r++)
        for (c = 0; c < m_cols; c++)
            grid[r][c] = '.';
    
    for (r = 0; r < m_rows; r++)
    {
        for (c = 0; c < m_cols; c++)
        {
            if(recordArr[r][c] == 0)
            {
                grid[r][c] = '.';
            }
            else if (recordArr[r][c] > 0 && recordArr[r][c] <= 25)
            {
                grid[r][c] = 'A' + recordArr[r][c] - 1;
            }
            else if (recordArr[r][c] >= 26)
            {
                grid[r][c] = 'Z';
            }
        }
        cout << endl;
    }
    cout << endl;
    
    // Draw the grid
    clearScreen();
//    cerr << "The screen has been cleared!" << endl;
    
    for (r = 0; r < m_rows; r++)
    {
        for (c = 0; c < m_cols; c++)
            cout << grid[r][c];
//            cerr << recordArr[r][c];
        cout << endl;
    }
    cout << endl;
    
}

bool History::isInBounds(int r, int c) const
{
    return (r >= 1  &&  r <= m_rows  &&  c >= 1  &&  c <= m_cols);
}
