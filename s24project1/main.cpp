//
//  main.cpp
//  s24project1
//
//  Created by Cameron Maiden on 4/6/24.
//

//#include <iostream>
//#include <string>
//#include <random>
//#include <utility>
//#include <cstdlib>
//using namespace std;

#include "Game.h"

///////////////////////////////////////////////////////////////////////////
//  main()
///////////////////////////////////////////////////////////////////////////

int main()
{
      // Create a game
      // Use this instead to create a mini-game:   Game g(3, 4, 2);
    Game g(7, 8, 25);
    //Game g(3, 4, 2);

      // Play the game
    g.play();
}


///////////////////////////////////////////////////////////////////////////
//  Test Cases
///////////////////////////////////////////////////////////////////////////

// If we replace your main.cpp file with the following, the program must build successfully under both g32 and either Visual C++ or clang++:
//#include "Tooter.h"
//#include "Game.h"
//#include "City.h"
//#include "History.h"
//#include "Player.h"
//#include "globals.h"
//    int main()
//    {}

//#include "Tooter.h"
//int main()
//{
//    if (false)  // so that this test builds, but does not write anything
//        Tooter t(nullptr, 1, 1);
//}

//#include "Player.h"
//    int main()
//    {
//        if (false)  // so that this test builds, but does not write anything
//            Player p(nullptr, 1, 1);
//    }


