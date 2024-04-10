//
//  History.h
//  s24project1
//
//  Created by Cameron Maiden on 4/6/24.
//

#ifndef History_h
#define History_h

#include "globals.h"
///////////////////////////////////////////////////////////////////////////
// Type definitions
///////////////////////////////////////////////////////////////////////////

class History
{
    public:
        History(int nRows, int nCols);
        bool record(int r, int c);
        void display() const;
    
    private:
        int m_rows;
        int m_cols;
        int recordArr[MAXROWS][MAXCOLS] = {{0}}; 
    
            // Helper functions
        bool isInBounds(int r, int c) const;
};

#endif /* History_h */
