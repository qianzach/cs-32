//
//  Arena.hpp
//  project1
//
//  Created by Zach Qian on 4/4/19.
//  Copyright © 2019 Zach Qian. All rights reserved.
//

#ifndef Arena_h
#define Arena_h

#include <stdio.h>
#include "globals.h"
#include "History.h"

//class History;
class Zombie;
class Player;

class Arena
{
public:
    // Constructor/destructor
    Arena(int nRows, int nCols);
    ~Arena();
    
    // Accessors
    int     rows() const;
    int     cols() const;
    Player* player() const;
    int     zombieCount() const;
    int     numZombiesAt(int r, int c) const;
    bool    determineNewPosition(int& r, int& c, int dir) const;
    void    display() const;
    
    // Mutators
    bool   addZombie(int r, int c);
    bool   addPlayer(int r, int c);
    bool   attackZombieAt(int r, int c, int dir);
    bool   moveZombies();
    
    //history object
    History& history();
    
private:
    int     m_rows;
    int     m_cols;
    Player* m_player;
    Zombie* m_zombies[MAXZOMBIES];
    int     m_nZombies;
    History m_History;
};
#endif /* Arena_hpp */
