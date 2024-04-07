//
//  Tooter.h
//  s24project1
//
//  Created by Cameron Maiden on 4/6/24.
//

#ifndef Tooter_h
#define Tooter_h

///////////////////////////////////////////////////////////////////////////
// Type definitions
///////////////////////////////////////////////////////////////////////////

class City;  // This is needed to let the compiler know that City is a
             // type name, since it's mentioned in the Tooter declaration.

class Tooter
{
  public:
        // Constructor
    Tooter(City* cp, int r, int c);

        // Accessors
    int  row() const;
    int  col() const;

        // Mutators
    void move();

  private:
    City* m_city;
    int   m_row;
    int   m_col;
};

#endif /* Tooter_hpp */
