//
//  Player.h
//  project3
//
//  Created by Zach Qian on 5/11/19.
//  Copyright © 2019 Zach Qian. All rights reserved.
//

#ifndef Player_h
#define Player_h

#include <stdio.h>
#include <string>
#include <iostream>
#include "Board.h"
#include "Side.h"
using namespace std;

//==========================================================================
// AlarmClock ac(numMilliseconds);  // Set an alarm clock that will time out
//                                  // after the indicated number of ms
// if (ac.timedOut())  // Will be false until the alarm clock times out; after
//                     // that, always returns true.
//==========================================================================

#include <chrono>
#include <future>
#include <atomic>

class AlarmClock
{
public:
    AlarmClock(int ms)
    {
        m_timedOut = false;
        m_isRunning = true;
        m_alarmClockFuture = std::async([=]() {
            for (int k = 0; k < ms  &&  m_isRunning; k++)
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            if (m_isRunning)
                m_timedOut = true;
        });
    }
    
    ~AlarmClock()
    {
        m_isRunning = false;
        m_alarmClockFuture.get();
    }
    
    bool timedOut() const
    {
        return m_timedOut;
    }
    
    AlarmClock(const AlarmClock&) = delete;
    AlarmClock& operator=(const AlarmClock&) = delete;
private:
    std::atomic<bool> m_isRunning;
    std::atomic<bool> m_timedOut;
    std::future<void> m_alarmClockFuture;
};


class Player{
public:
    Player(std::string name);
    std::string name()  const;
    virtual bool isInteractive() const;
    virtual int chooseMove(const Board& b, Side s) const = 0;
    virtual ~Player();
private:
    std::string m_name;
    Board* m_Board;

};

class HumanPlayer: public Player{
public:
    HumanPlayer(std::string  name);
    virtual bool isInteractive()  const;
    virtual int chooseMove(const Board&b, Side s) const;
    virtual ~HumanPlayer();

};

class BadPlayer: public Player{
public:
    BadPlayer(std::string  name);
    virtual bool isInteractive()  const;
    virtual int chooseMove(const Board&b, Side s) const;
    virtual ~BadPlayer();
};

class SmartPlayer: public Player{
public:
    SmartPlayer(std::string name);
    virtual bool isInteractive()  const;
    virtual int chooseMove(const Board&b, Side s) const;
    virtual ~SmartPlayer();
private:
//    int minimax(const Board&b, Side s, int& depth, int& bestValue, int&bestHole) const;
//    int minimax(const Board&b, Side s, int depth, bool maxPlayer) const;
    void minimax(const Board&b, Side s, int depth, int& bestValue, int&bestHole, AlarmClock& ac) const;
    int evaluate(const Board&b) const;
};

#endif /* Player_h */

