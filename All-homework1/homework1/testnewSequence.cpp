//
//  testnewSequence.cpp
//  homework1
//
//  Created by Zach Qian on 4/16/19.
//  Copyright © 2019 Zach Qian. All rights reserved.

#include "newSequence.h"
#include <iostream>
#include <cassert>
using namespace std;

int main()
{


    Sequence testItem(2);
    assert(testItem.insert(100) == 0);
    assert(testItem.insert(202) == 1);
    assert(testItem.size() == 2);
    ItemType x;
    assert(testItem.get(0, x)  &&  x == 100);
    assert(testItem.get(1, x)  &&  x == 202);
    assert(testItem.insert(2) == -1);

    assert(testItem.erase(1) == 1);
    assert(testItem.remove(100) == 1);
    assert(testItem.empty() == 1);
    testItem.insert(10);
    testItem.insert(9);
    assert(testItem.find(10) == 1);
    assert(testItem.set(1, 69) == 1);
    assert(testItem.set(3,420) == 0);
    assert(testItem.empty() == 0);

    ItemType iTtest = 10;

    Sequence s(1000);   // s can hold at most 1000 items
    Sequence b(5);      // b can hold at most 5 items
    Sequence w;         // c can hold at most DEFAULT_MAX_ITEMS items
    Sequence q(b);
    assert(s.empty()==1);
    assert(b.empty()==1);
    assert(w.empty()==1);
    assert(q.empty()==1);

    for(int i = 0; i < 5; i++)
    {
        assert(q.insert(69) == 0);
    }

    assert(q.insert(69) == -1);

    q =w;

    for(int i = 0; i < DEFAULT_MAX_ITEMS; i++)
    {
        assert(q.insert(69) == 0);
    }

    assert(q.insert(69) == -1);

    for (int i = 0; i < DEFAULT_MAX_ITEMS; i++)
    {
        assert(w.insert(iTtest) == 0);
    }
    assert(w.insert(11) == -1);

    // No failures inserting 5 items into b
    for (int k = 0; k < 5; k++)
    {
        assert(b.insert(iTtest) != -1);
    }

    // Failure if we try to insert a sixth item into b
    assert(b.insert(iTtest) == -1);

    // When two Sequences' contents are swapped, their capacities are
    // swapped as well:
    s.swap(b);
    assert(s.insert(iTtest) == -1  &&  b.insert(iTtest) != -1);

    Sequence e;
    assert(e.empty() == 1);
    e.insert(10);
    e.insert(10);
    e.insert(10);
    e.insert(10);
    e.insert(10);
    e.insert(5);
    e.insert(20);
    assert(e.size() == 7);
    assert(e.remove(10) == 5);
    assert(e.size() == 2);
    assert(e.find(5) == 0);
    assert(e.find(20) == 1);
    assert(e.empty() == 0);
    e.erase(0);
    e.erase(0);
    assert(e.empty() == 1);
    
    cerr << "all tests passed!" << endl;
    
    return 0;
    
    
}
