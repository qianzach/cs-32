//
//  Sequence.cpp
//  project2
//
//  Created by Zach Qian on 4/19/19.
//  Copyright © 2019 Zach Qian. All rights reserved.
//

#include "Sequence.h"
#include <iostream>
using namespace std;

Sequence::Sequence(){
    head = nullptr;
//    head->next = nullptr;
//    head->prev = nullptr;
    tail = nullptr;
    m_size = 0;
}

//private member function
void Sequence::setNode(Node *thisNode, ItemType value, Node *nextPtr, Node *prevPtr){
//    set the value to this node's data, set the previous pointer to prevptr and set next pointer to nextptr
    thisNode->data = value;
    thisNode->next  = nextPtr;
    thisNode->prev = prevPtr;
}

Sequence::~Sequence(){
    if(this->empty() == false){
        Node * curr = head;
        while(curr != nullptr){
            Node * currNext = curr->next;
            delete curr;
            curr = currNext;
        }
    }
}

Sequence::Sequence(const Sequence& other):m_size(0){
    head = nullptr;
    Node * temp = other.head;
    for(int i = 0; i < other.size() && temp !=nullptr; i++){
        ItemType tempVal;
        other.get(i, tempVal);
        insert(i, tempVal);
    }
}


void Sequence::swap(Sequence &other){
//    swap the sizes
    int otherSize = other.m_size;
    other.m_size = m_size;
    m_size = otherSize;
//    swap the head node objects
    Node * temp = other.head;
    other.head = head;
    head = temp;
//    swap the tail node objects
    Node * tempTail = other.tail;
    other.tail = tail;
    tail = tempTail;
}

Sequence& Sequence::operator=(const Sequence&other){
    if(this == &other){
        return *this;
    }
    else{
        Sequence temp(other);
        swap(temp);
        return *this;
    }
}

int subsequence(const Sequence &seq1, const Sequence &seq2){
//    check if both sequences are empty
    if(seq1.empty()==true || seq2.empty() == true){
        return -1;
    }
//    check to see if 2nd sequence is bigger in size than sequence 1, which is invalid
    else if(seq1.size() < seq2.size()){
        return -1;
    }
    else{
//        first access the first value of sequence 2
        ItemType seq2FirstData;
        seq2.get(0, seq2FirstData);
//        create item type values to compare seq1 and seq2
        ItemType seq1Comp;
        ItemType seq2Comp;
        for(int i = 0; i <seq1.size(); i++){
//            traverse through seq1
            seq1.get(i, seq1Comp);
//            retrieve ith value of seq1
            int marker = 1;
//            create a marker that resets if the next loop is exited to compare next value in seq1 with first val of seq2
            if(seq2FirstData == seq1Comp){
//                value comparison between values
//                cerr << "i is "  << i << endl;
                for(int j = i+1; j < i + seq1.size(); j++ ){
//                    if its true, then we check continuously
                    seq1.get(j,seq1Comp);
//                    cerr << "val at j is " << seq1Comp << endl;
                    seq2.get(marker,seq2Comp);
//                    cerr << "j is " << j << endl;
//                    cerr << "marker " << marker << endl;
//                    cerr << "val at marker is " << seq2Comp << endl;
                    if(seq1Comp != seq2Comp){
//                    if the next values are not the same, then we exit this loop and re-do the entire process
//                        cerr << "break at " << i << endl;
//                        cerr << "broken value at " << seq1Comp << endl;
                        break;
                    }
                    else{
                        if(marker ==seq2.size()-1){
//                            this means we are at  the last index of the seq2 subset. thus, we know that the sequence exists
//                            cerr << "sequence is there"  << i << endl;
                            return i;
                        }
                        else{
//                            increment marker to continuously check the next values
                            marker++;
                        }
                    }
                }
            }
        }
        return -1;
    }
}

void interleave(const Sequence &seq1, const Sequence &seq2, Sequence &result){
    /*    there are essentially "six" cases:
     if:
     1. both LL are empty
     2. if the first LL is not empty while the other one is empty
     3. the first LL is empty while the other one is not
     4. both LL are nonzero length, but are of equal length
     5. both LL have nonzero length, but the first LL has a greater length than the second LL
     6. both LL have nonzero length, but the first LL has less length than the second LL
     */
    while(result.empty()==false){
        for(int i = 0; i < result.size() ; i++){
            result.erase(i);
        }
        
    }

    if(seq1.empty() && seq2.empty()){
        result = seq1;
    }
    else if(seq1.empty() && seq2.size()>0){
        result = seq2;
    }
    else if(seq1.size()>0 && seq2.empty()){
        result = seq1;
    }
    else if(seq1.size()==seq2.size()){
//        create an algorithm that has the  first  sequence get all even indices and 0 (ie. 0,2,4,6,8, etc)
//        create an algorithm that has the second  sequence get all odd indexes(ie. 1,3,5,7,9, etc)
        ItemType s1Saver;
        ItemType s2Saver;
        for(int i = 0; i < seq1.size(); i++){
            seq1.get(i, s1Saver);
            seq2.get(i,s2Saver);
            result.insert(2*i, s1Saver);
            result.insert(2*i + 1, s2Saver);
        }

    }
    else if (seq1.size() > seq2.size()){
//        same algorithm, except  after, set a counter to insert the remaining LL values in the list
        ItemType s1Saver;
        ItemType s2Saver;
        int counter = 0;
        for(int i = 0; i < seq2.size(); i++){
            seq1.get(i, s1Saver);
//            cerr << "s1 value at s3's " << 2*i << ": " << s1Saver << endl;
            seq2.get(i,s2Saver);
//            cerr << "s2 value at s3's " << (2*i + 1) << ": " << s2Saver << endl;
            result.insert(2*i, s1Saver);
//            ItemType results1;
//            result.get(i,results1);
//            cerr << "what was actually put in s3: "   << results1 << " at: " << result.find(results1) << endl;
            result.insert((2*i + 1), s2Saver);
//            ItemType results2;
//            result.get(i+1,results2);
//            cerr << "what was actually put in s3: "   << results2 <<" at: " << result.find(results2)<<  endl;
            counter ++;
        }
        int counter2 = 2*counter;
        for(int j = counter2; j < seq1.size()+seq2.size(); j++){
            seq1.get(counter, s1Saver);
            result.insert(j, s1Saver);
            counter++;
//            cerr << j << " is the index we put this at" << endl;
//            cerr << "s1 value at s3's " << j << ": " << s1Saver << endl;

        }
    }
    else if (seq1.size() < seq2.size()){
        ItemType s1Saver;
        ItemType s2Saver;
        int counter = 0;
        for(int i = 0; i < seq1.size(); i++){
            seq1.get(i, s1Saver);
            //            cerr << "s1 value at s3's " << 2*i << ": " << s1Saver << endl;
            seq2.get(i,s2Saver);
            //            cerr << "s2 value at s3's " << (2*i + 1) << ": " << s2Saver << endl;
            result.insert(2*i, s1Saver);
            //            ItemType results1;
            //            result.get(i,results1);
            //            cerr << "what was actually put in s3: "   << results1 << " at: " << result.find(results1) << endl;
            result.insert((2*i + 1), s2Saver);
//            cerr << "done with iteration" << endl;
//            cerr << result.find(s2Saver) << " is in the " << 2*i + 1 << "th position";
            //            ItemType results2;
            //            result.get(i+1,results2);
            //            cerr << "what was actually put in s3: "   << results2 <<" at: " << result.find(results2)<<  endl;
            counter ++;
        }
//        cerr << "counter is " << counter;
        int counter2 = 2*counter;
        for(int j = counter2; j < seq1.size()+seq2.size(); j++){
            seq2.get(counter, s2Saver);
            result.insert(j, s2Saver);
            counter++;
            //            cerr << j << " is the index we put this at" << endl;
            //            cerr << "s1 value at s3's " << j << ": " << s1Saver << endl;
            
        }
    }
    
}


bool Sequence::empty() const{
    if(m_size ==0){
//        check the size of the linked list and ensures that if the head is a nullptr, then it is an empty list
        return true;
    }
    else{
        return false;
    }
}

int Sequence::size() const{
    return m_size;
}

int Sequence::insert(int pos, const ItemType &value){
//    my approach was to first test for valid pos, then within valid position, test for size, then insert accordingly
    if(pos < 0 || pos > size()){
        return -1;
    }
    else if(pos ==0){
//        if position is 0 we have to test if the size is nonzero or not
        if(size()==0){
//            different case if sequence is empty, so we just do a simple link and set tail and head to same value
            head = new Node;
            this->setNode(head, value, nullptr, nullptr);
            tail = head;
            m_size++;
            return pos;
        }
        else{
//            link the new node with the original first node, increase size
            Node * newHead = new Node;
            Node * temp = head;
            this->setNode(newHead, value, temp, nullptr);
            head = newHead;
            temp->prev = newHead;
            m_size++;
            return pos;
        }
    }
    else{ // case for if position is greater than 0
        Node * current = head;
//        traverse through up to the position where we want to insert the value
        for(int i = 0; i < pos-1 && current->next != nullptr; i++){
            current = current->next;
        }
        if(current == tail){
//            if we want to insert at the last index, we have to change tail values, so we link the new node with the original tail
            Node * newTail = new Node;
            Node * temp = current;
            this->setNode(newTail , value , nullptr, temp);
//            newTail->data = value;
            tail = newTail;
            temp->next = newTail;
//            newTail -> prev = temp;
//            increase size
            m_size++;
            return pos;
        }
        else{
/*           this  means it  is not an edge case, so we have to link the previous with the new node, and link with the next node
            */
            Node * newNode = new Node;
            Node * temp1 = current;
            Node * temp2 = current->next;
            this->setNode(newNode, value, temp2, temp1);
//            use the private member function for easier initialization of new node
//            newNode->data = value;
            temp1->next = newNode;
//            newNode->prev  = temp1;
//            newNode->next = temp2;
            temp2->prev = newNode;
            m_size++;
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
    int  p = 0;
    Node * current = head;
    if(head==nullptr){
        this->insert(p, value);
        return p;
    }
    while(current != nullptr){
        if(current-> data >= value){
            this->insert(p, value);
            return p;
        }
        p++;
        current = current->next;
    }
    this->insert(p, value);
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
    if(pos < 0 || pos >= m_size){
        return false;
    }
    else{
        Node * p = head;
        int i = 0;
        while(p != nullptr && i < pos){
            p = p->next;
            i++;
        }
        value = p->data;
        return true;
    }
}
// If 0 <= pos < size(), copy into value the item at position pos
// of the sequence and return true.  Otherwise, leave value unchanged
// and return false.

bool Sequence::set(int pos, const ItemType& value){
    if(pos >= 0 && pos < size()){
        Node * p = head;
        for(int i = 0; i < pos && p!=nullptr; i++){
            p = p->next;
        }
        p->data = value;
        return true;
    }
    return false;
}
// If 0 <= pos < size(), replace the item at position pos in the
// sequence with value and return true.  Otherwise, leave the sequence
// unchanged and return false.

int Sequence::find(const ItemType &value)const {
    Node * current = head;
    int p = 0;
    while(current != nullptr){
        if(current->data == value){
            return p;
        }
        p++;
        current = current->next;
    }
    return -1;
}
// Let p be the smallest integer such that value == the item at
// position p in the sequence; if no such item exists, let p be -1.
// Return p.


bool Sequence::erase(int pos){
//    check for invalid sizes, or if the  position is invalid
    if(size()== 0 || pos < 0 || pos > size())
        return false;
    else{
        if(size()==1){
//            case if the LL is of length 1, we only need to delete the head and decrement the size
            delete head;
            m_size--;
            return true;
        }
        else if(pos == 0){
//        case if we want to remove the 0th index
            Node * oldHead = head;
//            set the head to the next, while creating a temp to save the original head
            head = head->next;
//            delete the oldhead
            delete oldHead;
//            set previous for new head as nullptr
            head->prev = nullptr;
//            decrement the size
            m_size--;
            return true;
        }
        else{
            Node * current = head;
            for(int i = 0; i < pos && current->next!= nullptr; i++){
//                loop up to tail
                current = current->next;
            }
            if(current==tail){
//                case that pos is at the last spot in the LL
                Node * temp = tail;
//                create a temp for the original tail, and then making the new tail as the node at the original's previous
                tail = tail->prev;
                tail->next = nullptr;
//                set the new tail's next as nullptr  and delete the last node
                delete temp;
                m_size--;
                return true;
            }
            else{
//                something here
                Node * temp = current->next;
//                create a temp  node and set temp's previous to current's prev
                temp->prev = current->prev;
                current->prev->next = temp;
//                deleting old pos th node
                delete current;
//                decrement size
                m_size--;
                return true;
            }
        }
    }
}
// If 0 <= pos < size(), remove the item at position pos from
// the sequence (so that all items that followed that item end up at
// positions one lower than they were at before), and return true.
// Otherwise, leave the sequence unchanged and return false.

int Sequence::remove(const ItemType &value){
    if(size() == 0)
        return -1;
    else{
        int counter = 0;
        int i = 0;
        while(find(value) != -1){
//            traverse while we can find the value
            i = find(value);
//            set i to the index where the value was found
            this->erase(i);
//            erase the ith node
//            increase the counter  to see how many nodes with value  as their data are there and how many we removed
            counter++;
        }
        return counter;
    }
}
// Erase all items from the sequence that == value.  Return the
// number of items removed (which will be 0 if no item == value).


void Sequence::dump() {
    Node * current = head;
//    cerr <<"Head: " << head << endl;
//    cerr << "Tail " << tail << endl;
    for (int i = 0; i < size(); i++) {
//        cerr << "Previous: " << current->prev << endl;
//        cerr << current << endl;
//        cerr << "Next: " << current -> next << endl;
        std::cerr << current->data << " ";
        current = current->next;
    }
    std::cerr << '\n';
//    cerr << tail->data<<endl;
}

