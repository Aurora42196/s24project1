//
//  Player.cpp
//  s24project1
//
//  Created by Cameron Maiden on 4/6/24.
//

#include <iostream>
#include <cstdlib> 
#include "Player.h"
#include "globals.h"
#include "City.h"
using namespace std;

///////////////////////////////////////////////////////////////////////////
//  Player implementations
///////////////////////////////////////////////////////////////////////////

Player::Player(City* cp, int r, int c)
 : m_city(cp), m_row(r), m_col(c), m_health(INITIAL_PLAYER_HEALTH), m_age(0)
{
    if (cp == nullptr)
    {
        cout << "***** The player must be created in some City!" << endl;
        exit(1);
    }
    if (r < 1  ||  r > cp->rows()  ||  c < 1  ||  c > cp->cols())
    {
        cout << "**** Player created with invalid coordinates (" << r
             << "," << c << ")!" << endl;
        exit(1);
    }
}

int Player::row() const
{
    return m_row;
}

int Player::col() const
{
    return m_col;
}

int Player::age() const
{
    return m_age;
}

int Player::health() const
{
    return m_health;
}

bool Player::isPassedOut() const
{
    return m_health <= 0;
}

void Player::preach()
{
    m_age++;
    m_city->preachToTootersAroundPlayer();
}

void Player::move(int dir)
{
    m_age++;
    int r = m_row;
    int c = m_col;
    if (m_city->determineNewPosition(r, c, dir))
    {
          // If there are no Tooters in the new position
        if (m_city->nTootersAt(r, c) == 0)
        {
            m_row = r;
            m_col = c;
        }
    }
}

void Player::getGassed()
{
    m_health--;
}

