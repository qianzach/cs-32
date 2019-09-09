////
////  ScoreList.cpp
////  homework1
////
////  Created by Zach Qian on 4/14/19.
////  Copyright © 2019 Zach Qian. All rights reserved.
////
//////
#include "ScoreList.h"

//initializer list because m_score is an object of type Sequence
ScoreList::ScoreList(): m_score(){}

bool ScoreList::add(ItemType score){
    if(score <= 100){
            m_score.insert(score);
            return true;
    }
    return false;
}
// If the score is valid (a value from 0 to 100) and the score list
// has room for it, add it to the score list and return true.
// Otherwise, leave the score list unchanged and return false.

bool ScoreList::remove(unsigned long score){
    if(m_score.empty()== true)
        return false;
    int scorePos = m_score.find(score);
    if(m_score.find(score) != -1){
        m_score.erase(scorePos);
        return true;
    }
    else
        return false;
}
// Remove one instance of the specified score from the score list.
// Return true if a score was removed; otherwise false.

int ScoreList::size() const{
    return m_score.size();
}  // Return the number of scores in the list.

unsigned long ScoreList::minimum() const{
//    unsigned long min = 0;
//    unsigned long min2  =  0;
//    if(m_score.empty()== true)
//        return NO_SCORE;
//    else{
//        if(m_score.get(0, min) == false){
//            return NO_SCORE;
//        }
//        for(int i =  0; i < m_score.size()-1; i++){
//            m_score.get(i, min);
//            m_score.get(i+1, min2);
//            if(min > min2){
//                min =  min2;
//            }
//        }
//        return min;
//    }
    unsigned long min;
    if(m_score.size()>=1){
        m_score.get(0,min);
        return min;
    }
    return NO_SCORE;
}
// Return the lowest score in the score list.  If the list is
// empty, return NO_SCORE.

unsigned long ScoreList::maximum() const{
    unsigned long max = 0;
    if(m_score.size()>=1){
        m_score.get(m_score.size()-1,max);
        return max;
    }
    return NO_SCORE;
}

// Return the highest score in the score list.  If the list is
// empty, return NO_SCORE.5
