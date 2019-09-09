//
//  Diff.cpp
//  project4
//
//  Created by Zach Qian on 6/1/19.
//  Copyright © 2019 Zach Qian. All rights reserved.
//
#include <cassert>
#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>
#include "hash.h"
using namespace std;

//Diff File Functions and Helper Function declarations
bool applyDiff(istream& fold, istream& fdiff, ostream& fnew);
void createDiff(istream& fold, istream& fnew, ostream& fdiff);
bool getInt(istream& inf, int& n);
bool getCommand(istream& inf, char& cmd, int& length, int& offset);
void stringFromFile(istream& file, string& res);
int idealString( const string& oldFile, const string& newFile, int newOffset);

//Helper function implementations for applyDiff and createDiff
int idealString( const string& oldFile, const string& newFile, int newOffset){
    int idealOffset = -1;
    size_t oldSize = oldFile.size();
    size_t newSize = newFile.size();
    int bestChunk = CHUNK_SIZE;
    for ( int i = 0; (i+bestChunk-1)< oldSize; i++ ){
        //increment through string looking for the find string
        while(oldFile.substr(i, bestChunk) == newFile.substr(newOffset, bestChunk) && (newOffset+bestChunk-1) < newSize){
            bestChunk++;
            idealOffset = i;
        }
        
    }
    return idealOffset;
    
}
bool getInt(istream& inf, int& n)
{
    char ch;
    if (!inf.get(ch)  ||  !isascii(ch)  ||  !isdigit(ch))
        return false;
    inf.unget();
    inf >> n;
    return true;
}

bool getCommand(istream& inf, char& cmd, int& length, int& offset)
{
    if (!inf.get(cmd))
    {
        cmd = 'x';  // signals end of file
        return true;
    }
    char ch;
    switch (cmd)
    {
        case 'A':
            return getInt(inf, length) && inf.get(ch) && ch == ':';
        case 'C':
            return getInt(inf, length) && inf.get(ch) && ch == ',' && getInt(inf, offset);
        case '\r':
        case '\n':
            return true;
    }
    return false;
}
void stringFromFile(istream& file, string& res)
{
    res = "";    // wipes the string
    char c;
    // copies file data into res
    while (file.get(c))
        res += c;
}


//Diff File Implementations

bool applyDiff(istream& fold, istream& fdiff, ostream& fnew){
//    get the old string
    std::string oldFile;
    stringFromFile(fold, oldFile);
    char c;
    while (fdiff.get(c)){
        fdiff.unget();
        int length,offset;
        char command;
        if(!getCommand(fdiff, command, length, offset)){
    //        check for invalid input/command in given folder
            return false;
        }
        if(command == 'A'){
            if(length < 0)
                return false;
            for(int i = 0; i < length; i ++){
                if(!fdiff.get(c)){
                    return false;
                }
//                fdiff.get(c);
                fnew << c;
            }

        }
        else if (command == 'C'){
//            check to see if the length of the copy is greater than the sum of offset and the length of the copy
            if(offset < 0 ||  length < 0)
                return false;
            if(oldFile.size() < (offset  + length))
                return false;
            fnew << oldFile.substr(offset,length);
            }
    }
    return true;
}

void createDiff(istream& fold, istream& fnew, ostream& fdiff){
    //    process old and new files into string variables
    std::string oldFile;
    stringFromFile(fold, oldFile);
    std::string newFile;
    stringFromFile(fnew, newFile);
    if(oldFile.size() == 0 && newFile.size() == 0){
        return;
    }
    if(oldFile == newFile)
        return;
    if(oldFile.size() == 0 && newFile.size() != 0){
        fdiff << "A" << newFile.length() << ":" << newFile;
    }

    Hash hashTable;
    //    fill hash table with oldFile
    for(int i  =  0; i < oldFile.size() - CHUNK_SIZE; i++){
        hashTable.insert(oldFile.substr(i,CHUNK_SIZE), i);
    }
    //    process the fnew file
    string add = "";
    string copy = "";
    int copyOffset = 0;
    int j = 0;
    //    int nonconsOffset = 0;
    while(j <= (newFile.size() - CHUNK_SIZE)){
        string chunk = newFile.substr(j, CHUNK_SIZE);

        // for a match in the hash table
        if (hashTable.contains(chunk,copyOffset,false))
        {
            int saver = copyOffset;
            copyOffset = idealString(oldFile, newFile, j);
            if(copyOffset < 0){
                copyOffset  = saver;
            }

            if(add != ""){
                fdiff << "A" << add.length() << ":" << add;
                add = "";
            }
            int L = CHUNK_SIZE;

            while(oldFile[copyOffset + L] == newFile[j + L] && ((copyOffset + L) < oldFile.length()) && ((j + L) < newFile.length())){
                L++;
            }
            j += L;
            fdiff << "C" << L << "," << copyOffset;
//
        }
        else{
            add += chunk[0];
            j++;
        }
    }
   // write the rest of fnew to fdiff as an add command
    // write the leftover strings to fdiff
//    if (add == "")
//        fdiff << "C" << copy.length() << "," << copyOffset;
//    else if (copy == "")
//        fdiff << "A" << add.length() << ":" << add;
    // write the rest of fnew to fdiff as an add command
    fdiff << "A" << newFile.length() - j << ":" << newFile.substr(j, newFile.length() - j);
}


//TEST

//void greet(ostream& outf)    // outf is a name of our choosing
//{
//    outf << "Hello" << endl;
//}
//
//int main() {
//    //    ofstream outfile("/Users/qianzach/Desktop/UCLA CS 32/project4/greeting.txt");
//    //    if ( ! outfile )
//    //    {
//    //        cerr << "Error: Cannot create greeting.txt!" << endl;
//    //        return 1;
//    //    }
//    //    greet(outfile); // writes Hello to the file greetings.txt
//    //    greet(cout);    // writes Hello to the screen
//    //    char temp;
//    //    ifstream infile("/Users/qianzach/Desktop/UCLA CS 32/project4/greeting.txt");
//    //    while(infile.get(temp)){
//    //        cout << temp;
//    //    }
//    //    string temp1 = "ABCDEFGHIJBLAHPQRSTUVPQRSTUV";
//    //    string temp2 = "XYABCDEFGHIJBLETCHPQRSTUVPQRSTQQELF";
////    XYABCDEFGHIJBLETCHPQRSTUVPQRSTQQELF
////    string diffFile = "XYC12,0A3:ETCC13,13A5:QQELF";
////    ifstream temp1("/Users/qianzach/Desktop/UCLA CS 32/project4/test.txt");
////    ifstream temp2("/Users/qianzach/Desktop/UCLA CS 32/project4/applyTest.txt");
////    ofstream finalTest("/Users/qianzach/Desktop/UCLA CS 32/project4/results.txt");
////    applyDiff(temp1, temp2, finalTest);
////    cout << "Good" << endl;
//    Hash h;
//    cout << "yes" << endl;
//    ifstream oldFile("/Users/qianzach/Desktop/UCLA_CS_32/p4test/old.txt");
//    ifstream newFile("/Users/qianzach/Desktop/UCLA_CS_32/p4test/new.txt");
//    ofstream diff("/Users/qianzach/Desktop/UCLA_CS_32/p4test/diff.txt");
//    createDiff(oldFile, newFile, diff);
////    ifstream jeff("/Users/qianzach/Desktop/UCLA_CS_32/p4test/diff.txt");
////    ofstream newF("/Users/qianzach/Desktop/UCLA_CS_32/p4test/new.txt");
////
////    applyDiff(oldFile, jeff, newF);
//    cout << "Done "  << endl;
////    string sa[] = { "abc", "def", "ghi", "jkl", "mno", "pqr", "stu", "vwx",
////        "xyz", "123", "456", "789", "000" };
////    int i = 0;
////    // test inserting into the hash table
////    for (; i < 8; i++)
////        h.insert(sa[i], 0);
////    // h should be rehashed here
////    for (; i < 13; i++)
////        h.insert(sa[i], 0);
////    h.print();
////    // tests searching the hash table
////    cout.setf(ios::boolalpha);
////    for (i = 0; i < 13; i++)
////        assert(h.contains(sa[i]));
////    // tests the offset accessor
////    for (i = 0; i < 13; i++){
////        assert(h.getOffset(sa[i]) == 0);
////        cout << "good" << endl;
////    }
////    assert(h.getOffset("not in table") == -1);
////    cout << "Hash tests passed.\n\n";
//}


