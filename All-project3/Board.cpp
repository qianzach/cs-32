//
//  Board.cpp
//  project3
//
//  Created by Zach Qian on 5/11/19.
//  Copyright © 2019 Zach Qian. All rights reserved.
//

#include "Board.h"

Board::Board(int nHoles, int nInitialBeansPerHole){
//    Construct a Board with the indicated number of holes per side (not counting the pot) and initial number of beans per hole. If nHoles is not positive, act as if it were 1; if nInitialBeansPerHole is negative, act as if it were 0.
    if(nHoles <= 0){
//        if holes are less than or equal t o 0, we set the member var m_holes to 1 by  default
        m_nHoles = 1;
    }
    else{
//        otherwise we set  it to the parameter value, knowing it is  valid
        m_nHoles = nHoles;
    }
    if(nInitialBeansPerHole <= 0)
//        if parameter is less than or equal to 0, we set the initial beans/hole as 0
        m_nInitialBeansPerHole = 0;
    else{
//        otherwise, we use the valid number of beans per hole
        m_nInitialBeansPerHole = nInitialBeansPerHole;
    }
    m_NorthBeans.push_back(0);
    m_SouthBeans.push_back(0);
//    0th index in the vector are always the pots for each respective side, and they start with 0
    
//  for each hole  in north and south, push m_InitialBeansPerHole into the vector's last index
    for(int i = 0;  i <  nHoles; i ++){
        m_NorthBeans.push_back(m_nInitialBeansPerHole);
        m_SouthBeans.push_back(m_nInitialBeansPerHole);
//        we push back every non 0th term with  a value of initialBeansPerHole
    }
    
}
int Board::holes() const{
    //Return the number of holes on a side (not counting the pot).
    return m_nHoles;
}


int Board::beans(Side s, int hole) const{
    if(hole < 0 || hole > m_nHoles)
//        check for invalid hole input
        return -1;
    else{
        if(s == NORTH){
//            returns the number of beans in the selected hole in North
            return m_NorthBeans[hole];
        }
//        otherwise will return the number of  beans in the South part
        return m_SouthBeans[hole];
    }
}


int Board::beansInPlay(Side s) const{
    int beanCounterSide = 0;
    if(s == NORTH){
        for(int i = 1; i < holes() + 1; i++){
            beanCounterSide += m_NorthBeans[i];
        }
    }
//    ask later to see if we need to check for incorrect enum
    else if (s == SOUTH){
        for(int i  = 1; i < holes() + 1; i++){
            beanCounterSide += m_SouthBeans[i];
        }
    }
    return beanCounterSide;

}

int Board::totalBeans() const{
    return  beansInPlay(NORTH) + beansInPlay(SOUTH) + m_SouthBeans[0] + m_NorthBeans[0];
}



bool Board::sow(Side s, int hole, Side& endSide, int& endHole){
    if(hole <= 0 || hole > m_nHoles ||  this->beans(s,hole) ==  0){
        //        beans checks for invalid holes,  and should return -1 if so; also returns 0 if empty, which is also invalid for sow
        return false;
    }
    if(s ==  NORTH){
//        saver variable for the number of beans
        int saveNBeans = beans(NORTH,hole);
        //        empty out north beans at the given hole
        m_NorthBeans[hole] = 0;
        int northIdx  = hole-1;
        if(northIdx >= 0){
//            check to see if northIdx is valid stll after decrementing, also checks if northIdx is at 0
            while(saveNBeans > 0){
    //            go through all of north's holes while the number of beans is greater than 0 and we don't run out
                while(northIdx >= 0){
                    if(saveNBeans > 0){
//                        if we have at least 1 bean, we will add that bean to north side at the position northIdx
                        m_NorthBeans[northIdx]++;
//                        decrease the number of beans we will sow
                        saveNBeans--;
                    }
                    if(saveNBeans == 0){
//                        if we have no more beans left we set the side to NORTH and the index of the last hole at northIdx
                        endSide =  NORTH;
                        endHole =  northIdx;
                        return true;
//                        return true because  successful sow
                    }
//                    decrement northIdx to go to through the north side's vector
                    northIdx--;
                }
//                after decrementing, we perform the same check on the number of beans left
                if(saveNBeans == 0){
//                    if it is 0, then we will set the ending side to NORTH and the hole at northIDx
                    endSide = NORTH;
                    endHole = northIdx;
                    return true;
                }
//                in case the number of beans we have is greater than the 2*m_nHoles + 1, we will reset northIdx to account for this test case
                northIdx = m_nHoles;
    //            go to the south vector
                int southTracker = 10000;
//               create a south directional tracker and set it to an arbitrary number
                for(int i = 1; i < m_nHoles + 1; i++){
//                    loop through the total number of holes in the south direction, starting from the first hole
                    if(saveNBeans > 0){
//                        check to see we have a positive amount  of beans left to sow
                        m_SouthBeans[i]++;
//                        if so, we will sow it at position i in the  south side vector
                        saveNBeans--;
//                        decrement the number of beans we need to sow
                    }
                    if(saveNBeans == 0){
//                        check to see if the number of beans is 0
                        southTracker = i;
//                        if so, we will set the southTracker to position i, and set ending hole to that position and endSide to SOUTH because it doesn't loop back to north
                        endHole = southTracker;
                        endSide = SOUTH;
                        return true;
                    }
                }
                if(saveNBeans != 0){
//                    if the number of beans left is not 0 we will add to the pot because the south vector is oriented from 1 to holes() and then its pot
                    m_SouthBeans[0]++;
//                    decrement the number of beans left needed to be sown
                    saveNBeans--;
                }
                if(saveNBeans  == 0){
//                    if the number of beans is now 0, we know it ended at the pot
                    southTracker = 0;
//                    set south tracker to 0 (POT)
                    endHole = southTracker;
//                    set the endHole to 0 and side to SOUTH
                    endSide = SOUTH;
                    return true;
                }
            }
        }
    }
    else if(s == SOUTH){
        //        saver variable for the number of beans
        int saveSBeans = beans(SOUTH,hole);
        //        empty out north beans at the given hole
        m_SouthBeans[hole] = 0;
        int southIdx  = hole+1;
//        start sowing at the index right after the index
        if(hole == m_nHoles){
//            if we are at the last index, we must go to the hole (0th)
            southIdx = 0;
        }
            if(southIdx < m_nHoles + 1){
//                if the south index is less than the max number of holes we check to see if we have more than 0 beans
                while(saveSBeans > 0){
                    for(; southIdx < m_nHoles + 1 && southIdx > 0; southIdx++){
//                        loop up to the max number of holes
                        if(saveSBeans > 0){
//                            check to see if more beans are greater than 0, if so, then increase beans at southIdx
                            m_SouthBeans[southIdx]++;
//                            decrement number of beans
                            saveSBeans--;
                        }
                        if(saveSBeans == 0){
//                            if we have no more beans left to sow
                            endSide = SOUTH;
//                            set ending side to SOUTH and set the ending hole to southIdx
                            endHole = southIdx;
                            return true;
                        }
                }
                    m_SouthBeans[0]++;
//                    after looping up to the last non-pot hole, increment the pot's bean count
                    saveSBeans--;
//                    decrement  the number of beans left to sow
                    if(saveSBeans == 0){
//                        if the number of beans is 0, we will set the side  to SOUTH and set the hole to the pot (0)
                        endSide = SOUTH;
                        endHole = 0;
                        return true;
                    }
//                set southIdx to 1 to reset in case number of beans > 2*holes() + 1
                    southIdx = 1;
//              initialize a tracker for north to arbitrary value
                int northTracker = -10;
                //Sowing on the north side
                for (int i = m_nHoles; i >= 1; i--){
//                    loop from top to bottom for North side
                    if(saveSBeans > 0){
                        m_NorthBeans[i]++;
                        saveSBeans--;
                        }
                    
                    if (saveSBeans == 0){
                        endSide = NORTH;
                        endHole = i;
                        northTracker = i;
                        return true;
                        }
                    }
                }
            }
        }
    return true;
}
//If the hole indicated by (s,hole) is empty or invalid or a pot, this function returns false without changing anything. Otherwise, it will return true after sowing the beans: the beans are removed from hole (s,hole) and sown counterclockwise, including s's pot if encountered, but skipping s's opponent's pot. The parameters endSide and endHole are set to the side and hole where the last bean was placed. (This function does not make captures or multiple turns; different Kalah variants have different rules about these issues, so dealing with them should not be the responsibility of the Board class.)



bool Board::moveToPot(Side s, int hole, Side potOwner){
//If the indicated hole is invalid or a pot, return false without changing anything. Otherwise, move all the beans in hole (s,hole) into the pot belonging to potOwner and return true.
    if(beans(s, hole) == -1 || hole == 0)
//        if pot, then hole = 0 and beans checks
        return false;
    else{
        if(s == NORTH && potOwner == NORTH){
            m_NorthBeans[0] += m_NorthBeans[hole];
            m_NorthBeans[hole] = 0;
        }
        else if(s == SOUTH && potOwner == SOUTH){
            m_SouthBeans[0] += m_SouthBeans[hole];
            m_SouthBeans[hole] = 0;
        }
        else if(s == NORTH && potOwner == SOUTH){
            m_SouthBeans[0] += m_NorthBeans[hole];
            m_NorthBeans[hole] = 0;
        }
        else if(s == SOUTH && potOwner == NORTH){
            m_NorthBeans[0] += m_SouthBeans[hole];
            m_SouthBeans[hole] = 0;
        }
        return true;
    }
}
bool Board::setBeans(Side s, int hole, int beans){
    if(this->beans(s,hole) ==  -1 || beans < 0)
        return false;
    if(s == NORTH){
        m_NorthBeans[hole]  = beans;
    }
    else{
        m_SouthBeans[hole]  = beans;
    }
    return true;
    
}
//If the indicated hole is invalid or beans is negative, this function returns false without changing anything. Otherwise, it will return true after setting the number of beans in the indicated hole or pot to the value of the third parameter. (This may change what beansInPlay and totalBeans return if they are called later.) This function exists solely so that we and you can more easily test your program: None of your code that implements the member functions of any class is allowed to call this function directly or indirectly. (We'll show an example of its use below.)

