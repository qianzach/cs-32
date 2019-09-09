//
//  Game.hpp
//  project1
//
//  Created by Zach Qian on 4/4/19.
//  Copyright © 2019 Zach Qian. All rights reserved.
//

#ifndef Game_h
#define Game_h

#include <stdio.h>
#include "globals.h"

class Arena;  // This is needed to let the compiler know that Arena is a
// type name, since it's mentioned in the Zombie declaration.
class Game
{
public:
    // Constructor/destructor
    Game(int rows, int cols, int nZombies);
    ~Game();
    
    // Mutators
    void play();
    
private:
    Arena* m_arena;
};
#endif /* Game_hpp */
