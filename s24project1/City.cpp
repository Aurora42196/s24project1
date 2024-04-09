//
//  City.cpp
//  s24project1
//
//  Created by Cameron Maiden on 4/6/24.
//

#include <iostream>
#include <cstdlib>
#include "City.h"
#include "Player.h"
#include "Tooter.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////
//  City implementations
///////////////////////////////////////////////////////////////////////////

City::City(int nRows, int nCols)
 : m_rows(nRows), m_cols(nCols), m_player(nullptr), m_nTooters(0)
{
    if (nRows <= 0  ||  nCols <= 0  ||  nRows > MAXROWS  ||  nCols > MAXCOLS)
    {
        cout << "***** City created with invalid size " << nRows << " by "
             << nCols << "!" << endl;
        exit(1);
    }
}

City::~City()
{
    for (int k = 0; k < m_nTooters; k++)
        delete m_tooters[k];
    delete m_player;
}

int City::rows() const
{
    return m_rows;
}

int City::cols() const
{
    return m_cols;
}

Player* City::player() const
{
    return m_player;
}

bool City::isPlayerAt(int r, int c) const
{
    return m_player != nullptr  &&
           m_player->row() == r  &&  m_player->col() == c;
}

int City::tooterCount() const
{
    return m_nTooters;
}

int City::nTootersAt(int r, int c) const
{
    int count = 0;
    for (int k = 0; k < m_nTooters; k++)
    {
        const Tooter* tp = m_tooters[k];
        if (tp->row() == r  &&  tp->col() == c)
            count++;
    }
    return count;
}

bool City::determineNewPosition(int& r, int& c, int dir) const
{
    switch (dir)
    {
      case UP:     if (r <= 1)      return false; else r--; break;
      case DOWN:   if (r >= rows()) return false; else r++; break;
      case LEFT:   if (c <= 1)      return false; else c--; break;
      case RIGHT:  if (c >= cols()) return false; else c++; break;
      default:     return false;
    }
    return true;
}

void City::display() const
{
      // Position (row,col) in the city coordinate system is represented in
      // the array element grid[row-1][col-1]
    char grid[MAXROWS][MAXCOLS];
    int r, c;
    
        // Fill the grid with dots
    for (r = 0; r < rows(); r++)
        for (c = 0; c < cols(); c++)
            grid[r][c] = '.';

        // Indicate each Tooter's position
    for (int k = 0; k < m_nTooters; k++)
    {
        const Tooter* tp = m_tooters[k];
        char& gridChar = grid[tp->row()-1][tp->col()-1];
        switch (gridChar)
        {
          case '.':  gridChar = 'T'; break;
          case 'T':  gridChar = '2'; break;
          case '9':  break;
          default:   gridChar++; break;  // '2' through '8'
        }
    }

        // Indicate player's position
    if (m_player != nullptr)
    {
          // Set the char to '@', unless there's also a Tooter there
          // (which should never happen), in which case set it to '*'.
        char& gridChar = grid[m_player->row()-1][m_player->col()-1];
        if (gridChar == '.')
            gridChar = '@';
        else
            gridChar = '*';
    }

        // Draw the grid
    clearScreen();
    for (r = 0; r < rows(); r++)
    {
        for (c = 0; c < cols(); c++)
            cout << grid[r][c];
        cout << endl;
    }
    cout << endl;

        // Write message, Tooter, and player info
    cout << "There are " << m_nTooters << " unconverted Tooters remaining." << endl;
    if (m_player == nullptr)
        cout << "There is no player." << endl;
    else
    {
        if (m_player->age() > 0)
            cout << "The player has lasted " << m_player->age() << " steps." << endl;
        if (m_player->isPassedOut())
            cout << "The player has passed out." << endl;
        else
            cout << "The player's health level is " << m_player->health() << endl;
    }
}

bool City::addTooter(int r, int c)
{
    if ( ! isInBounds(r, c))
        return false;

      // Don't add a Tooter on a spot with a player
    if (m_player != nullptr  &&  m_player->row() == r  &&  m_player->col() == c)
        return false;

      // Dynamically allocate a new Tooter and add it to the city
    if (m_nTooters == MAXTOOTERS)
        return false;
    m_tooters[m_nTooters] = new Tooter(this, r, c);
    m_nTooters++;
    return true;
}

bool City::addPlayer(int r, int c)
{
    if ( ! isInBounds(r, c))
        return false;

      // Don't add a player if one already exists
    if (m_player != nullptr)
        return false;

      // Don't add a player on a spot with a Tooter
    if (nTootersAt(r, c) > 0)
        return false;

      // Dynamically allocate new Player and add it to the city
    m_player = new Player(this, r, c);
    return true;
}

void City::preachToTootersAroundPlayer()
{
      // Preach to Tooters orthogonally or diagonally adjacent to player.  If a
      // Tooter is converted, then since the order of the Tooters in the array
      // doesn't matter, we can replace the converted Tooter we remove from the
      // game by the last one in the array.
    if (m_player == nullptr)
        return;

    for (int k = 0; k < m_nTooters; )
    {
        Tooter* tp = m_tooters[k];
        int rowdiff = tp->row() - m_player->row();
        int coldiff = tp->col() - m_player->col();

          // if orthogonally or diagonally adjacent and conversion succeeds
        if (rowdiff >= -1  &&  rowdiff <= 1  &&
            coldiff >= -1  &&  coldiff <= 1  &&
            randInt(1, 3) <= 2)  // 2/3 probability
        {
            delete m_tooters[k];
            m_tooters[k] = m_tooters[m_nTooters-1];
            m_nTooters--;
        }
        else
            k++;
    }
}

void City::moveTooters()
{
    for (int k = 0; k < m_nTooters; k++)
    {
        Tooter* tp = m_tooters[k];
        tp->move();
        if (m_player == nullptr)
            continue;
        int rowdiff = tp->row() - m_player->row();
        int coldiff = tp->col() - m_player->col();
          // if orthogonally adjacent
        if  ((rowdiff == 0  &&  (coldiff == 1  ||  coldiff == -1))  ||
             (coldiff == 0  &&  (rowdiff == 1  ||  rowdiff == -1)) )
            m_player->getGassed();
    }
}

bool City::isInBounds(int r, int c) const
{
    return (r >= 1  &&  r <= m_rows  &&  c >= 1  &&  c <= m_cols);
}
