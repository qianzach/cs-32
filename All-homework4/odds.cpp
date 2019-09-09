//
//  odds.cpp
//  hw4q3a
//
//  Created by Zach Qian on 5/27/19.
//  Copyright © 2019 Zach Qian. All rights reserved.
//

// Remove the odd integers from v.
// It is acceptable if the order of the remaining even integers is not
// the same as in the original vector.
void removeOdds(vector<int>& v)
{
    if(v.size() == 0)
        return;
    vector <int> ::iterator it;
    it = v.begin();
    while(it != v.end()){
        if(*it % 2 != 0){
            it = v.erase(it);
        }
        else{
            it++;
        }
    }
}
