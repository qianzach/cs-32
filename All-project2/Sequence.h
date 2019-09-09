//
//  Sequence.hpp
//  project2
//
//  Created by Zach Qian on 4/19/19.
//  Copyright © 2019 Zach Qian. All rights reserved.
//

#ifndef Sequence_h
#define Sequence_h

#include <stdio.h>
#include <string>

using ItemType = unsigned long;
//using ItemType = std::string;

class Sequence
{
public:
    Sequence();
    ~Sequence(); //destructor
    Sequence(const Sequence& other); //sequence copy constructor
    Sequence& operator=(const Sequence&other);

    bool empty() const;
    int size() const;
    int insert(int pos, const ItemType& value);
    int insert(const ItemType& value);
    bool erase(int pos);
    int remove(const ItemType& value);
    bool get(int pos, ItemType& value) const;
    bool set(int pos, const ItemType& value);
    int find(const ItemType& value) const;
    void swap(Sequence& other);
    void dump();
    

private:
    struct Node {
    public:
        ItemType data;
        Node* next;
        Node * prev;
    };
    Node * head;
    Node * tail;
    int m_size;
//    created private member function to mutate nodes
    void setNode(Node * thisNode,ItemType value, Node * nextPtr, Node * prevPtr);
};
int subsequence(const Sequence& seq1, const Sequence& seq2);
void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result);

#endif /* Sequence_h */
