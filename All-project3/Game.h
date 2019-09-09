//
//  Game.h
//  project3
//
//  Created by Zach Qian on 5/12/19.
//  Copyright © 2019 Zach Qian. All rights reserved.
//

#ifndef Game_h
#define Game_h
#include <stdio.h>
#include "Board.h"
#include "Side.h"
#include "Board.h"
#include "Player.h"


class Game{
public:
    Game(const Board& b, Player* south, Player* north);
    void display() const;
    void status(bool& over, bool& hasWinner, Side& winner) const;
    bool move();
    void play();
    int beans(Side s, int hole) const;
private:
    Board m_Board;
    Player* m_PlayerNorth;
    Player* m_PlayerSouth;
//    you need to keep track of which side's turn it is, so i created this and set default current side to SOUTH, as it says in the spec
    Side m_currentSide;


};


#endif /* Game_h */
