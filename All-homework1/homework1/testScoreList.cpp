//
//  testScoreList.cpp
//  homework1
//
//  Created by Zach Qian on 4/16/19.
//  Copyright © 2019 Zach Qian. All rights reserved.
//
//
#include <stdio.h>
#include "ScoreList.h"
#include <iostream>
#include <cassert>
using namespace std;


int main()
{
    ScoreList s;
    assert(s.maximum() == NO_SCORE);
    assert(s.minimum() == NO_SCORE);
    assert(s.size()==0);
    assert(s.add(131)==0);
    assert(s.add(10));
    //    s.add(10);
    s.add(50);
    s.add(97);

    s.add(60);
    s.add(60);
    assert(s.maximum() == 97);
    assert(s.minimum() == 10);
    assert(s.size() == 5);
    assert(s.remove(60) == 1);
    assert(s.remove(97) == 1);
    assert(s.size() == 3);
    assert(s.maximum() == 60);
    assert(s.remove(102) == 0);
    assert(s.remove(69) == 0);
    //
        cerr << "all tests are passed" << endl;
    return 0;
}
