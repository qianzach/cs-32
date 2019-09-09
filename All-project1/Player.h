//
//  Player.hpp
//  project1
//
//  Created by Zach Qian on 4/4/19.
//  Copyright © 2019 Zach Qian. All rights reserved.
//

#ifndef Player_h
#define Player_h

#include <stdio.h>


class Arena;  // This is needed to let the compiler know that Arena is a
// type name, since it's mentioned in the Zombie declaration.
class Player
{
public:
    // Constructor
    Player(Arena *ap, int r, int c);
    
    // Accessors
    int  row() const;
    int  col() const;
    int  age() const;
    bool isDead() const;
    
    // Mutators
    void   stand();
    void   moveOrAttack(int dir);
    void   setDead();
    
private:
    Arena* m_arena;
    int    m_row;
    int    m_col;
    int    m_age;
    bool   m_dead;
};
#endif /* Player_hpp */
