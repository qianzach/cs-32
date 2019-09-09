//
//  newSequence.h
//  homework1
//
//  Created by Zach Qian on 4/15/19.
//  Copyright © 2019 Zach Qian. All rights reserved.


#ifndef newSequence_h
#define newSequence_h

#include <stdio.h>
#include <iostream>
using namespace std;
using ItemType = unsigned long;
const int DEFAULT_MAX_ITEMS = 250;

class Sequence
{
public:
    Sequence(int sz = DEFAULT_MAX_ITEMS);    // Create an empty sequence (i.e., one with no items)
    ~Sequence();
    Sequence(const Sequence& other);
    Sequence& operator=(const Sequence&other);
    bool empty() const;  // Return true if the sequence is empty, otherwise false.
    int size() const;    // Return the number of items in the sequence.
    int insert(int pos, const ItemType& value);

    int insert(const ItemType& value);

    bool erase(int pos);

    int remove(const ItemType& value);
    
    bool get(int pos, ItemType& value) const;
    
    bool set(int pos, const ItemType& value);
    
    int find(const ItemType& value) const;
    
    void swap(Sequence& other);
    
    void dump() const;
private:
    int m_size;
    int m_max_cap;
    ItemType * m_arr;
};
#endif /* newSequence_h */
