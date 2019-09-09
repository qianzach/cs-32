//
//  Player.cpp
//  project3
//
//  Created by Zach Qian on 5/11/19.
//  Copyright © 2019 Zach Qian. All rights reserved.
//

#include "Player.h"


//Player implementations
Player::Player(std::string name):m_name(name){}
std::string Player::name()const{return m_name;}
bool Player::isInteractive() const{
    return false;
}
Player::~Player(){}



////////////////////////////////////////////////////////////////////////
//Human player implementations
HumanPlayer::HumanPlayer(std::string name):Player(name){}
//all human players are interactive, so we return true
bool HumanPlayer::isInteractive()const{return true;}
int HumanPlayer::chooseMove(const Board&b, Side s) const{
    int huHole = -100;
//    pick a dummy number so we can tell that the move  is a  invalid one or invalid
    std::cout << "Pick a hole to sow: " << std::endl;
//    create a flag to exit out of a while loop
    bool flag = true;
    while(flag){
        std::cin >> huHole;
        //        first check for invalid hole inputs in terms of its value; in other words if hole is less than
//        or equal to 0, or if it  is  greater than the board's hole limit
        if(huHole <=0 || huHole > b.holes()){
            std::cout << "Please select a valid hole number from 1 to " << b.holes() << "." << std::endl;
            std::cout << " Again, pick a hole to move: " << endl;
        }
//        check to see if the hole has no beans, if it is valid
        else if(b.beans(s, huHole) == 0){
            std::cout << "There are no beans left in this hole at the moment. Please select a valid hole number: "
            << endl;
            std::cout <<"Pick a non-empty hole to move to:  " << std::endl;
            
        }
        else{
            flag = false;
            //            set flag to false and break; it could be unnecessary, i know.
            break;
        }
    }
    return huHole;
}
HumanPlayer::~HumanPlayer(){}


/////////////////////////////////////////////////////////////////
//  BadPlayer Implementation
BadPlayer::BadPlayer(std::string name): Player(name){}
bool BadPlayer::isInteractive()const{return false;}
int BadPlayer::chooseMove(const Board &b, Side s) const{
    int smallestHole = -1;
    //    the approach for chooseMove for the BadPlayer is to find the smallest index of a valid hole number with at least one bean in the hole; if there are none, i returned-1
    for(int i = 1; i < b.holes() + 1; i++){
        if(b.beans(s, i) > 0){
//            check for a valid instance
            smallestHole  =  i;
            break;
        }
    }
    if(smallestHole < 0){
        cerr << "Player is out of moves." << endl;
        return smallestHole;
    }
    cerr  << this->name() << " picked this hole: " << smallestHole << endl;
    return smallestHole;
}
BadPlayer::~BadPlayer(){}


////////////////////////////////////////////////////////////////////
//SmartPlayer Implementation
SmartPlayer::SmartPlayer(std::string name): Player(name){}

bool SmartPlayer::isInteractive()const{return false;}

SmartPlayer::~SmartPlayer(){}
int SmartPlayer::chooseMove(const Board &b, Side s) const{
    AlarmClock ac(4900);
    int bestValue;
    int bestHole = -1;
    this->minimax(b, s, 7, bestValue, bestHole,ac);
    if(bestHole == -1){
        cerr << "Can't move AI loses" << endl;
        cerr << "AI Picked: " << bestHole << endl;
        return bestHole;
    }
    else{
        cerr << this->name() << " picked hole: " << bestHole << endl;
        return bestHole;
    }
}


int SmartPlayer::evaluate(const Board&b) const{
    if(b.beansInPlay(SOUTH) == 0 || b.beansInPlay(NORTH) == 0){
        if(b.beans(SOUTH, POT) > b.beans(NORTH, POT)){
            return -100000;
        }
        else if(b.beans(NORTH, POT) > b.beans(SOUTH, POT)){
            return 100000;
        }
        else{
            return 0;
        }
    }
    else{
        if (b.beans(NORTH, POT) > b.totalBeans() / 2)
        {
            return -100000;
        }
        else if (b.beans(SOUTH, POT) > b.totalBeans() / 2)
        {
            return 100000;
        }
        else{
            return b.beans(NORTH, POT) - b.beans(SOUTH,POT);
        }
    }
}


void SmartPlayer::minimax(const Board&b, Side s, int depth, int& bestValue, int&bestHole, AlarmClock& ac) const{
    if(b.beansInPlay(s) == 0 || b.beansInPlay(opponent(s)) == 0){
        bestHole = -1;
        bestValue = evaluate(b);
        return;
    }
    if(ac.timedOut()){
        bestHole = -1;
//        cout << "Timed OUT!" <<  endl;
        bestValue = evaluate(b);
        return;
    }
    if(depth == 0){
        bestHole = -1;
        bestValue = evaluate(b);
        return;
    }
    if(s == SOUTH){
        bestValue = 92300000;
    }
    else{
        bestValue = -92300000;
    }
    for(int i = 1; i < b.holes() + 1;  i++){
        if(b.beans(s, i) == 0){
            continue;
        }
        Board copy(b);
        Side es;
        int eh;
        copy.sow(s, i, es, eh);
        //        Case 1: capture
        if(es == s && eh != POT && copy.beans(s, eh) == 1 && copy.beans(opponent(s), eh) != 0){
            copy.moveToPot(s, eh, s);
            copy.moveToPot(opponent(s), eh, s);
        }
        //        Case 2: sow to pot
        int tempHole;
        int tempVal;
        while(es == s && eh == POT){
            this->minimax(copy, s, depth -1, tempVal ,tempHole,ac);
            copy.sow(s, tempHole, es, eh);
//            break case if we cannot find tempHole that suits an optimal move
            if(tempHole == -1){
                break;
            }
        }
        int oppVal;
        int oppHole;
//        cout << "opp hole " << oppHole << endl;
        this->minimax(copy, opponent(s), depth -1, oppVal, oppHole,ac);
        if(s == SOUTH){
            if(oppVal < bestValue){
                bestValue = oppVal;
                bestHole = i;
//                cout << oppHole << endl;
//                cout << "index i: " << i << endl;
            }
        }
        else{
            if(oppVal > bestValue){
                bestValue = oppVal;
                bestHole = i;
            }
        }
    }
    return;
    
}
