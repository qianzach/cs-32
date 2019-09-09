//
//  Board.h
//  project3
//
//  Created by Zach Qian on 5/11/19.
//  Copyright © 2019 Zach Qian. All rights reserved.
//

#ifndef Board_h
#define Board_h

#include <stdio.h>
#include <vector>
#include "Side.h"
//The Board class is responsible for maintaining the board. A Board object knows about the holes, pots, and beans. For those functions that talk about specific holes, the holes are indicated by a Side and hole number. The holes are numbered as indicated in the diagrams above; a pot is considered hole #0. Thus, North's hole #1 is next to North's pot; South's hole #6 is next to South's pot. Notice that this numbering of holes is an aspect of the class's interface and our test code will depend on it. Of course, your implementations of the functions are free to map that numbering scheme into something more convenient for their internal use.
class Board{
public:
    Board(int nHoles, int nInitialBeansPerHole);
    int holes() const;
    int beans(Side s, int hole) const;
    int beansInPlay(Side s) const;
    int totalBeans() const;
    bool sow(Side s, int hole, Side& endSide, int& endHole);
    bool moveToPot(Side s, int hole, Side potOwner);
    bool setBeans(Side s, int hole, int beans);
private:
    int m_nHoles;
    int m_nInitialBeansPerHole;
    std::vector<int> m_NorthBeans;
    std::vector<int> m_SouthBeans;
    

};





#endif /* Board_h */
