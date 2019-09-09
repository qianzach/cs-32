//
//  linear.cpp
//  hw3part2
//
//  Created by Zach Qian on 5/6/19.
//  Copyright © 2019 Zach Qian. All rights reserved.
//

//#include <stdio.h>
//#include <iostream>
//#include <string>
//using namespace std;

//bool somePredicate(std::string s)
//{
//    return s.empty();
//}

// Return false if the somePredicate function returns false for at
// least one of the array elements; return true otherwise.
bool allTrue(const std::string a[], int n)
{
    if(n <= 0){
        return true;
    }
    if(somePredicate(a[n-1]) == false)
        return false;

    return allTrue(a, n-1);
}

// Return the number of elements in the array for which the
// somePredicate function returns false.
int countFalse(const std::string a[], int n)
{
    if(n <= 0)
        return 0;

    return countFalse(a, n-1) + !somePredicate(a[n-1]);
    
    

}

// Return the subscript of the first element in the array for which
// the somePredicate function returns false.  If there is no such
// element, return -1.
int firstFalse(const std::string a[], int n)
{
    if(n <= 0)
        return -1;
    if(somePredicate(a[0]) == false)
        return 0;
    if(firstFalse(a+1, n-1)==-1)
        return -1;
    // do this to ensure if there is nothing that is false, you do not step out of bounds on the last recursive call
    
    return firstFalse(a+1,n-1) + 1;
    
}
// "" "" "" ""
//true, n = 4
//true n = 3  0+1
//true n = 2 0+1 +0+1
//true n = 1 0+

// Return the subscript of the least string in the array (i.e.,
// return the smallest subscript m such that a[m] <= a[k] for all
// k from 0 to n-1).  If the function is told to examine no
// elements, return -1.
int indexOfLeast(const std::string a[], int n)
{
    if(n <= 0)
        return -1;
    
//    if(n==1)
//        return 0;
    
    if (a[0] <= a[indexOfLeast(a+1, n-1)+1])
        return 0;
    else
        return (1 + indexOfLeast(a+1, n-1));

//    if(a[0] >= a[n-1] )
//        return indexOfLeast(a+1, n-1)+1;
//    else{
//
//        return indexOfLeast(a, n-1);
//    }
    
}

// If all n2 elements of a2 appear in the n1 element array a1, in
// the same order (though not necessarily consecutively), then
// return true; otherwise (i.e., if the array a1 does not include
// a2 as a not-necessarily-contiguous subsequence), return false.
// (Of course, if a2 is empty (i.e., n2 is 0), return true.)
// For example, if a1 is the 7 element array
//    "stan" "kyle" "cartman" "kenny" "kyle" "cartman" "butters"
// then the function should return true if a2 is
//    "kyle" "kenny" "butters"
// or
//    "kyle" "cartman" "cartman"
// and it should return false if a2 is
//    "kyle" "butters" "kenny"
// or
//    "stan" "kenny" "kenny"
bool includes(const std::string a1[], int n1, const std::string a2[], int n2)
{
//
    if (n1 < 0)
        n1 = 0;
    
    if (n2 < 0)
        n2 = 0;
    
    if (n2 == 0)
        return true;
    
    if (n1 == 0)
        return false;
    else{
        if(a1[0] != a2[0])
            return includes(a1+1,n1-1,a2,n2);
//        check for first instance
        else{
            return includes(a1+1,n1-1,a2+1,n2-1);
        }
    }
}


//
//int main() {
//    std::string a[10] =
//    {"1","2","3","4","5","6","0","8","9","10"};
//
//    std::string b[11] =
//    {"5","8","9","10"};
//
//    std::string c[10] =
//    {"","","","","","3","","","",""};
//
//    std::string d[10] =
//    {"","","3","","5","3","","6","d",""};
//
//    assert(allTrue(c, 10) == 0);
//    assert(allTrue(c, 5) == 1);
//    assert(allTrue(c, 0) == 1);
//    assert(allTrue(c, -1) == 1);
//
//    assert(countFalse(c , 10) == 1);
//    assert(countFalse(c, 5) == 0);
//    assert(countFalse(c, 0) == 0);
//    assert(countFalse(c, -1) == 0);
//    assert(countFalse(d, 10) == 5);
//
//    assert(firstFalse(c, 10) == 5);
//    assert(firstFalse(c, 5) == -1);
//    assert(firstFalse(c, 0) == -1);
//    assert(firstFalse(c, -1) == -1);
//    assert(firstFalse(d, 10) == 2);
//
//    assert(indexOfLeast(a, 10) == 6);
//    assert(indexOfLeast(a, 6) == 0);
//    assert(indexOfLeast(a, 0) == -1);
//    assert(indexOfLeast(a, -1) == -1);
//
//    assert(includes(a, 10, b , 4 ) == 1);
//    assert(includes(a, 5, b , 1) == 1);
//
//    assert(includes(a, 0 , b , 0) == 1);
//    assert(includes(a, 1, b ,  0  ) == 1);
//    assert(includes(a,  0, b , 1  ) == 0);
//    assert(includes(a,  1, b , 1 ) == 0);
//
//    assert(includes(a,  -10, b , 1 ) == 0);
//    assert(includes(a,  10, b , -1 ) == 1);
//    assert(includes(a,  -10, b , -1 ) == 1);
//    assert(includes(a,  10, b , 1) == 1);
//
//
//    assert(includes(a, -1, b , 1 ) == 0);
//    assert(includes(a, -1, b , 0 ) == 1);
//    assert(includes(a, 0, b , 1 ) == 0);
//    assert(includes(a, -1, b , -1 ) == 1);
//    assert(includes(a, 3, b , 5) == 0);
//
//    cout << "all test passed" << endl;
//    std::string arr[4] = {"", "f", "", "d" };
//    std::string arr1[6] = {"", "", "", "", "", ""};
//    std::string arr2[7] = {"", "", "", "urmom", "", "", ""};
//    std::string arr3[6] = {"5", "5", "3", "6", "1", "9"};
//    std::string arr4[10] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
//    std::string arr5[3] = {"2", "2", "1"};
//    assert(allTrue(arr1, 6) == true);
//    assert(allTrue(arr, 2) == false);
//    assert(allTrue(arr + 2, 2) == true);
//    assert(countFalse(arr, 4) == 2);
//    assert(firstFalse(arr, 4) == 1);
//    assert(firstFalse(arr1, 6) == -1);
//    cout << firstFalse(arr1, 6) << endl;
//    assert(firstFalse(arr2, 7) == 3);
//    assert(indexOfLeast(arr3, 6) == 4);
//    assert(indexOfLeast(arr4, 10) == 0);
//    assert(indexOfLeast(arr5, 3) == 2);

//    string arr[6] = {"", "a", "", "b", "c", "d"};
//    string temp[1] = {"1"};
//    cerr << indexOfLeast(arr, 6) << endl;
//    cerr << indexOfLeast(temp, 1);
//    assert(indexOfLeast(arr, 6) == 0);
//    string arr1[4] = {"D", "A", "we", ""};
//    string arr2[4] = {"WED", "!", "b", "qs"};
//    string arr3[5] = { "Ad", "sd", "ah", "SA", "3234"};
//    string arr4[6] = { "a", "b", "a", "b", "a", "b"};
//    string arr5[4] = {"", "", "", ""};
//    string arr6[4] = {"0", "0", "0", "&"};
//    string arr7[1] = {""};
//    string arr8[1] = {"dferewsedr"};
//    string arr9[0];
//    string arr10[2] = { "", ""};
//    string arr11[2] = {"a", "7654"};
//    string arr12[10] = {"", "", "", "", "", "", "", "", "234", ""};
//    assert(!allTrue(arr1, 4));
//    assert(!allTrue(arr2, 4));
//    assert(!allTrue(arr3, 5));
//    assert(!allTrue(arr4, 6));
//    assert(allTrue(arr5, 4));
//    assert(!allTrue(arr6, 4));
//    assert(allTrue(arr7, 1));
//    assert(!allTrue(arr8, 1));
//    assert(allTrue(arr9, 0));
//    assert(countFalse(arr, 6) == 4);
//    assert(countFalse(arr1, 4) == 3);
//    assert(countFalse(arr2, 4) == 4);
//    assert(countFalse(arr3, 5) == 5);
//    assert(countFalse(arr4, 6) == 6);
//    assert(countFalse(arr5, 4) == 0);
//    assert(countFalse(arr6, 4) == 4);
//    assert(countFalse(arr7, 1) == 0);
//    assert(countFalse(arr8, 1) == 1);
//    assert(countFalse(arr9, -32) == 0);
//    assert(countFalse(arr10, 2) == 0);
//    assert(countFalse(arr11, 2) == 2);
//    assert(countFalse(arr12, 10) == 1);
//    assert(firstFalse(arr, 6) == 1);
//    assert(firstFalse(arr1, 4) == 0);
//    assert(firstFalse(arr3, 5) == 0);
//    assert(firstFalse(arr5, 4) == -1);
//    assert(firstFalse(arr7, 1) == -1);
//    assert(firstFalse(arr9, 0) == -1);
//    assert(firstFalse(arr10, 1) == -1);
//    assert(firstFalse(arr12, 10) == 8);
//    assert(indexOfLeast(arr1, 4) == 3);
//    assert(indexOfLeast(arr2, 4) == 1);
//    assert(indexOfLeast(arr3, 5) == 4);
//    assert(indexOfLeast(arr4, 6) == 0);
//    assert(indexOfLeast(arr5, 4) == 0);
//        assert(indexOfLeast(arr6, 4) == 3);
//    string incl1[7] = { "stan", "kyle" ,"cartman", "kenny", "kyle", "cartman" ,"butters" };
//    string incl2[3] = { "kyle" ,"kenny" ,"butters"};
//    string incl3[3] = {"kyle", "cartman", "cartman"};
//    string incl4[3] = {"kyle", "butters", "kenny"};
//    string incl5[3] = {"stan","kenny" , "kenny"};
//    assert(includes(incl1, 7, incl2, 3));
//    assert(includes(incl1, 7, incl3, 3));
//    assert(!includes(incl1, 7, incl4, 3));
//    assert(!includes(incl1, 7, incl5, 3));
//    cout << "passed all tests! (LINEAR)";
//    cerr << "all good" << endl;
//    return 0;
//}
