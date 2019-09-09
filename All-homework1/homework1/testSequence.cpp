//
//  testSequence.cpp
//  homework1
//
//  Created by Zach Qian on 4/16/19.
//  Copyright © 2019 Zach Qian. All rights reserved.
//
//
#include <stdio.h>
#include "Sequence.h"
#include <iostream>
#include <cassert>
using namespace std;

int main(){
    
    Sequence a;
    assert(a.size()==0);
    assert(a.insert(2)==0);
    assert(a.size()==1);
    assert(a.insert(7)==1);
    assert(a.size()==2);
    assert(a.insert(0,123)==0);
    a.dump();
    assert(a.insert(6)==0);
    a.dump();
    assert(a.erase(1)==1);
    a.dump();
    ItemType x = 69;
    ItemType y = 7;
    assert(a.find(x)==-1);
    assert(a.find(y)==2);
    assert(a.set(2,x)==1);
    assert(a.find(x)==2);
    a.dump();
    assert(y==7);
    assert(a.get(2,y)==1);
    cerr << y << endl;
    
    //    test for swaps in fixed, non-dynamic arrays
    Sequence b;
    b.insert(2);
    b.insert(3);
    b.insert(5);
    assert(b.size()==3);
    ItemType z = 3;
    assert(b.find(z)==1);
    assert(b.insert(1,87)==1);
    assert(b.insert(0,5)==0);
    b.insert(5);
    b.dump();
    ItemType remTest = 5;
    assert(b.remove(remTest)==3);
    ItemType findTest = 2;
    assert(b.find(findTest)==0);
    b.dump();
    assert(b.insert(2,97)==2);
    
    //    test for swap statements
    cerr << "Original Sequence: \n";
    a.dump();
    b.dump();
    int aSize = a.size();
    int bSize = b.size();
    cerr << "a size is: " << a.size() << endl;
    cerr << "b size is: " << b.size() << endl;
    cerr  << "\n";
    
    a.swap(b);
    a.dump();
    b.dump();
    cerr << "a size is NOW: " << a.size() << endl;
    assert(a.size()==bSize);
    cerr << "b size is NOW: " << b.size() << endl;
    assert(b.size()==aSize);
    
    //    revert
    cerr << "revert it" << endl;
    b.swap(a);
    a.dump();
    b.dump();
    assert(a.size()==aSize);
    assert(b.size()==bSize);
    
    cerr << "all tests passed!" << endl;
    return 0;
}
