//
//  newSequence.cpp
//  homework1
//
//  Created by Zach Qian on 4/15/19.
//  Copyright © 2019 Zach Qian. All rights reserved.


#include "newSequence.h"

Sequence::Sequence(int sz){
    if (sz < 0)
    {
        cerr << "invalid size input" << endl;
        exit(1);
    }
    else
    {
        m_size = 0;
        m_max_cap = sz;
        m_arr = new ItemType[sz];
    }
}

//destructor
Sequence::~Sequence(){
    delete [] m_arr;
}
//copy constructor
Sequence::Sequence(const Sequence& other){
    m_size = other.m_size;
    m_max_cap = other.m_max_cap;
    m_arr = new ItemType[m_max_cap];
    for(int i = 0; i < other.size(); i++){
        m_arr[i] = other.m_arr[i];
    }
}

//operator overload
Sequence& Sequence::operator=(const Sequence&other){
    if(this == &other){
        return *this;
    }
    else{
        delete [] m_arr;
        m_size = other.m_size;
        m_max_cap = other.m_max_cap;
        m_arr = new ItemType[other.m_max_cap];
        for(int i = 0; i < other.size(); i++){
            m_arr[i] = other.m_arr[i];
        }
        return *this;
    }
    
}



bool Sequence::empty() const{
    if(m_size == 0)
        return true;
    return false;
}

int Sequence::size() const{
    return m_size;
}

int Sequence::insert(int pos, const ItemType& value){
    //    checks for invalid position input
    if(pos > size() || pos < 0){
        return -1;
    }
    //    if the insert position is at the end  of the array, then we
    else{
        if(size() == m_max_cap)
            return -1; //  check for invalid size
        m_size ++;
        if(pos == size()){
            //case for when the position is the length of the array is a different case, replace last index w/ value
            m_arr[pos] = value;
            return pos;
        }
        else{
            for(int i = size(); i > pos; i--){
                m_arr[i] = m_arr[i - 1];
            }
            m_arr[pos] = value;
            return pos;
        }
        
    }
    
}
// Insert value into the sequence so that it becomes the item at
// position pos.  The original item at position pos and those that
// follow it end up at positions one higher than they were at before.
// Return pos if 0 <= pos <= size() and the value could be
// inserted.  (It might not be, if the sequence has a fixed capacity,
// e.g., because it's implemented using a fixed-size array.)  Otherwise,
// leave the sequence unchanged and return -1.  Notice that
// if pos is equal to size(), the value is inserted at the end.

int Sequence::insert(const ItemType& value){
    int p = 0;
    if(size() >= m_max_cap){
        return -1;
    }
    for(int i = 0; i < size(); i++){
        if(value <= m_arr[i]){
            break;
        }
        p++;
    }
    for(int i = size(); i > p; i--){
        m_arr[i] = m_arr[i - 1];
    }
    m_arr[p] =  value;
    m_size++;
    return p;
    
}
// Let p be the smallest integer such that value <= the item at
// position p in the sequence; if no such item exists (i.e.,
// value > all items in the sequence), let p be size().  Insert
// value into the sequence so that it becomes the item at position
// p.  The original item at position p and those that follow it end
// up at positions one higher than before.  Return p if the value
// was actually inserted.  Return -1 if the value was not inserted
// (perhaps because the sequence has a fixed capacity and is full).

bool Sequence::get(int pos, ItemType& value) const{
    if(pos >= 0 &&  pos < size()){
        value = m_arr[pos];
        return true;
    }
    return  false;
}
// If 0 <= pos < size(), copy into value the item at position pos
// of the sequence and return true.  Otherwise, leave value unchanged
// and return false.

bool Sequence::erase(int pos){
    if(pos >= 0 && pos < size()){
        for(int i = pos; i < size()-1; i++){
            m_arr[i] = m_arr[i+1];
        }
        m_size--;
        return true;
    }
    else{
        return false;
    }
}
// If 0 <= pos < size(), remove the item at position pos from
// the sequence (so that all items that followed that item end up at
// positions one lower than they were at before), and return true.
// Otherwise, leave the sequence unchanged and return false.

int Sequence::remove(const ItemType& value){
    int counter = 0;
    while(find(value) != -1){
        erase(this->find(value));
        counter++;
    }
    return counter;
}
// Erase all items from the sequence that == value.  Return the
// number of items removed (which will be 0 if no item == value).

bool Sequence::set(int pos, const ItemType& value){
    if(pos >= 0 && pos < size()){
        m_arr[pos] = value;
        return true;
    }
    return false;
}
// If 0 <= pos < size(), replace the item at position pos in the
// sequence with value and return true.  Otherwise, leave the sequence
// unchanged and return false.

int Sequence::find(const ItemType& value) const{
    int p = 0;
    if(size() <= m_max_cap){
            for(int i = 0; i < size(); i++){
                if(m_arr[i]==value){
                    p = i;
                    return p;
                }
            }
    }
    return -1;
}
// Let p be the smallest integer such that value == the item at
// position p in the sequence; if no such item exists, let p be -1.
// Return p.

void Sequence::swap(Sequence& other){
    ItemType * temp;
    int tempSize;
    int tempMax;
    
    tempSize = m_size;
    m_size = other.m_size;
    other.m_size = tempSize;
    
    tempMax = m_max_cap;
    m_max_cap = other.m_max_cap;
    other.m_max_cap = tempMax;
    
    temp = m_arr;
    m_arr = other.m_arr;
    other.m_arr = temp;
    
}
// Exchange the contents of this sequence with the other one.

void Sequence::dump() const{
    for(int i = 0; i < size(); i++){
        std::cerr << m_arr[i] << ", ";
    }
    std::cerr << std::endl;
}

