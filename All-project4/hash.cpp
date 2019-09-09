//
//  hash.cpp
//  project4
//
//  Created by Zach Qian on 6/1/19.
//  Copyright © 2019 Zach Qian. All rights reserved.
//

#include "hash.h"

//Public member functions
Hash::Hash(): m_size(200023){
    buckets = new list<Node>[200023];
}

Hash::~Hash(){
    delete[] buckets;
}

bool Hash::contains(string chunk, int&offset, bool exactoffset){
    unsigned int key = rs_hash(chunk);
    list<Node>::iterator it;
    it = buckets[key].begin();
    if(exactoffset == false){
        for(;it != buckets[key].end();it++){
            Node check = *it;
            if(check.chunk == chunk){
                offset = check.offset;
                return true;
            }
        }
    }
    else{
        for(;it != buckets[key].end();it++){
            Node check = *it;
            if(check.chunk == chunk && offset == check.offset){
                return true;
            }
        }
    }
    return false;
}

int Hash::getOffset(string chunk) const{
    unsigned int key = rs_hash(chunk);
    list<Node>::const_iterator it;
    it = buckets[key].begin();
    for(;it != buckets[key].end();it++){
        Node check = *it;
        if(check.chunk == chunk)
            return check.offset;
    }
    return -1;
}

void Hash::insert(string chunk, int offset){
    unsigned int key = rs_hash(chunk);
    Node inserted = {chunk,key,offset};
    // use separate chaining at the key location, set a new list of Nodes
    buckets[key].push_back(inserted);
//    increment the number of buckets that are actually filled to determine the load factor
    m_count++;
    if((m_count / m_size) > load_factor)
        rehash();
}



//Private member functions
unsigned int Hash::rs_hash(const std::string &chunk)const{
    std::hash<std::string> str_hash;
//    static cast from size_t to unsigned int
    unsigned int hashVal = static_cast<int>(str_hash(chunk));
    unsigned int bucketNum = hashVal % m_size;
    return bucketNum;
}

void Hash::rehash(){
    list<Node>* rebuckets = new list<Node>[m_size*2];
    for (int i = 0; i < m_size; i++)
    {
        for (Node& n : buckets[i])
        {
            unsigned int key = rs_hash(n.chunk);    // rehash key
            rebuckets[key].push_back(n);
        }
    }
    // resize
    m_size *= 2;
    // reassign buckets
    delete[] buckets;
    buckets = rebuckets;
    
}


void Hash::print()
{
    for (int i = 0; i < m_size; i++)
    {
        cout << "[" << i << "]: ";
        for (Node& n : buckets[i])
            // cout << "(" << n.seq << ", " << n.key << ", " << n.offset << ") ";
            cout << "\"" << n.chunk << "\" ";
        cout << endl;
    }
}
