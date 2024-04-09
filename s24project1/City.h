//
//  City.h
//  s24project1
//
//  Created by Cameron Maiden on 4/6/24.
//

#ifndef City_h
#define City_h

#include "globals.h"
#include "History.h"

///////////////////////////////////////////////////////////////////////////
// Type definitions
///////////////////////////////////////////////////////////////////////////

class Player;
class Tooter;

class City
{
  public:
        // Constructor/destructor
    City(int nRows, int nCols);
    ~City();

        // Accessors
    int     rows() const;
    int     cols() const;
    Player* player() const;
    bool    isPlayerAt(int r, int c) const;
    int     tooterCount() const;
    int     nTootersAt(int r, int c) const;
    bool    determineNewPosition(int& r, int& c, int dir) const;
    void    display() const;
    History& history(); // returns a reference to the City's History object

        // Mutators
    bool addTooter(int r, int c);
    bool addPlayer(int r, int c);
    void preachToTootersAroundPlayer();
    void moveTooters();

  private:
    int     m_rows;
    int     m_cols;
    Player* m_player;
    Tooter* m_tooters[MAXTOOTERS];
    int     m_nTooters;
    History m_history;

      // Helper functions
    bool isInBounds(int r, int c) const;
};

#endif /* City_h */
