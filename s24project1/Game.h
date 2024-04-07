//
//  Game.h
//  s24project1
//
//  Created by Cameron Maiden on 4/6/24.
//

#ifndef Game_h
#define Game_h

///////////////////////////////////////////////////////////////////////////
// Type definitions
///////////////////////////////////////////////////////////////////////////

class City;     // This is needed to let the compiler know that City is a
                // type name, since it's mentioned in the Game declaration.

class Game
{
  public:
        // Constructor/destructor
    Game(int rows, int cols, int nTooters);
    ~Game();

        // Mutators
    void play();

  private:
    City* m_city;
};

#endif /* Game_hpp */
