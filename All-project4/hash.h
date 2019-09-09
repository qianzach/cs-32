//
//  hash.h
//  project4
//
//  Created by Zach Qian on 6/1/19.
//  Copyright © 2019 Zach Qian. All rights reserved.
//

#ifndef hash_h
#define hash_h

#include <stdio.h>
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <functional>
using namespace std;
const int CHUNK_SIZE = 8;
struct Node
{
    string chunk;
    unsigned int key;
    int offset;
};
class Hash{
public:
    Hash();
    ~Hash();
    void insert(string chunk, int offset);
    bool contains(string chunk, int &offset, bool exactOffset);
    int getOffset(string chunk) const;
    void print();
private:
    int m_size;
//    size of the entire array of buckets
    int m_count = 0;
//    the count to track and ensure that load factor is not exceeded
    list<Node>* buckets;
    const double load_factor = 0.75;
    unsigned int rs_hash(const string &chunk) const;
    void rehash();
};



#endif /* hash_h */
