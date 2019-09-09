//
//  bad.cpp
//  hw4q3b
//
//  Created by Zach Qian on 5/27/19.
//  Copyright © 2019 Zach Qian. All rights reserved.
//


// Remove the movies in li with a rating below 55 and destroy them.
// It is acceptable if the order of the remaining movies is not
// the same as in the original list.
void removeBad(list<Movie*>& li)
{

    for (list<Movie*>::iterator it = li.begin(); it != li.end();it++){
        if((*it)->rating() < 55){
            delete *it;
            li.erase(it);
        }
    }
}
