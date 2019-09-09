//
//  tree.cpp
//  hw3part4
//
//  Created by Zach Qian on 5/7/19.
//  Copyright © 2019 Zach Qian. All rights reserved.
//
//
//#include <stdio.h>
//#include <iostream>
//#include <cassert>
//using namespace std;

//int countIncludes(const string a1[], int n1, const string a2[], int n2);
//void separate(string a[], int n, string separator,
//              int& firstNotLess, int& firstGreater);
//void order(string a[], int n);



// Return the number of ways that all n2 elements of a2 appear
// in the n1 element array a1 in the same order (though not
// necessarily consecutively).  The empty sequence appears in a
// sequence of length n1 in 1 way, even if n1 is 0.
// For example, if a1 is the 7 element array
//    "stan" "kyle" "cartman" "kenny" "kyle" "cartman" "butters"
// then for this value of a2            the function must return
//    "stan" "kenny" "cartman"                      1
//    "stan" "cartman" "butters"                    2
//    "kenny" "stan" "cartman"                      0
//    "kyle" "cartman" "butters"                    3
int countIncludes(const std::string a1[], int n1, const std::string a2[], int n2)
{
    if(n2 < 0)
        n2 = 0;
    if(n2 == 0)
        return 1;
    if(n1 <= 1){
        if(n2 == 1 && a1[0] == a2[0])
            return 1;
        return 0;
    }

        if(a1[0] != a2[0]){
            return countIncludes(a1+1, n1-1, a2, n2);
        }
        else{
            return countIncludes(a1+1, n1-1, a2+1, n2-1) + countIncludes(a1+1, n1-1, a2, n2);
        }

}

// Exchange two strings
void exchange(std::string& x, std::string& y)
{
    std::string t = x;
    x = y;
    y = t;
}

// Rearrange the elements of the array so that all the elements
// whose value is < separator come before all the other elements,
// and all the elements whose value is > separator come after all
// the other elements.  Upon return, firstNotLess is set to the
// index of the first element in the rearranged array that is
// >= separator, or n if there is no such element, and firstGreater is
// set to the index of the first element that is > separator, or n
// if there is no such element.
// In other words, upon return from the function, the array is a
// permutation of its original value such that
//   * for 0 <= i < firstNotLess, a[i] < separator
//   * for firstNotLess <= i < firstGreater, a[i] == separator
//   * for firstGreater <= i < n, a[i] > separator
// All the elements < separator end up in no particular order.
// All the elements > separator end up in no particular order.
void separate(std::string a[], int n, std::string separator,
              int& firstNotLess, int& firstGreater)
{
    if (n < 0)
        n = 0;
    
    // It will always be the case that just before evaluating the loop
    // condition:
    //  firstNotLess <= firstUnknown and firstUnknown <= firstGreater
    //  Every element earlier than position firstNotLess is < separator
    //  Every element from position firstNotLess to firstUnknown-1 is
    //    == separator
    //  Every element from firstUnknown to firstGreater-1 is not known yet
    //  Every element at position firstGreater or later is > separator
    
    firstNotLess = 0;
    firstGreater = n;
    int firstUnknown = 0;
    while (firstUnknown < firstGreater)
    {
        if (a[firstUnknown] > separator)
        {
            firstGreater--;
            exchange(a[firstUnknown], a[firstGreater]);
        }
        else
        {
            if (a[firstUnknown] < separator)
            {
                exchange(a[firstNotLess], a[firstUnknown]);
                firstNotLess++;
            }
            firstUnknown++;
        }
    }
}
// Rearrange the elements of the array so that
// a[0] <= a[1] <= a[2] <= ... <= a[n-2] <= a[n-1]
// If n <= 1, do nothing.
void order(std::string a[], int n)
{
    if(n <= 1)
        return;
    int firstNotLess;
    int firstGreater;
    separate(a, n, a[0], firstNotLess,firstGreater);
    order(a, firstNotLess);
    order(a+firstGreater, n-firstGreater);
}
//
////
//int main() {
//    string incl1[7] = { "stan", "kyle" ,"cartman", "kenny", "kyle", "cartman" ,"butters" };
//    string incl2[3] = { "stan", "kenny" ,"cartman" };
//    string incl3[3] = {"stan", "cartman", "butters"};
//    string incl4[3] = {"kenny", "stan", "cartman"};
//    string incl5[3] = {"kyle", "cartman", "butters"};
//    assert(countIncludes(incl1, 7, incl2, 3) == 1);
//    assert(countIncludes(incl1, 7, incl3, 3) == 2);
//    assert(countIncludes(incl1, 7, incl4, 3) == 0);
//    assert(countIncludes(incl1, 7, incl5, 3) == 3);
//    string ib[4] = {"a", "a", "a", "b"};
//    string ii[2] = {"a", "b"};
//    assert(countIncludes(ib, 4, ii, 2) == 3);
//    string rb[4] = {"b", "a", "a", "a"};
//    string ri[2] = {"a", "b"};
//    assert(countIncludes(rb, 4, ri, 2) == 0);
//    string pb[9] = {"1", "2", "3", "3", "1", "2", "3", "3", "1"}; //12345678
//    string pi[3] = {"2", "3", "1"};
//    assert(countIncludes(pb, 9, pi, 3) == 8);
//    string sepb[5] = {"aaa", "ddd", "ccc", "bbb", "eee"};
//    string sepex[8] = { "h", "g", "f", "e", "d", "c", "b", "a"};
//    order(sepex, 8);
//    for (int i = 0; i < 8; i++){
//        cout << sepex[i] << endl;
//    }
//    order(sepb, 5);
//    for (int k = 0; k < 5; k++){
//        cout << sepb[k] << endl;
//    }
////
////
//    // insert code here...
//    string arr4[] = {"7","8","2","4","3","5","5","5","5"};
//
////    order(arr4, 9);
////    for(int i = 0; i < 9; i++)
////        cout << arr4[i];
////    cout << '\n';
//    string arr[] = {"1","1","2","3","1","2","3"};
//    string arr2[] = {"1","1","2","3"};
//    string arr1[] = {"1","2","3"};
//    string arr3[] = {"1","2","3","1","2","3"};
////    cout << countIncludes(arr, 7, arr1, 3) << endl;
//
//    return 0;
//}
