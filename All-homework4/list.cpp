//
//  list.cpp
//  hw4q4a
//
//  Created by Zach Qian on 5/27/19.
//  Copyright © 2019 Zach Qian. All rights reserved.
//

void listAll(const Domain* d, string path) // two-parameter overload
{
    if(d == nullptr)
        return;
    if(d->subdomains().size()== 0){
        std::cout  << path << endl;
        return;
    }
    for(int i = 0; i < d->subdomains().size(); i++){
        if(path == ""){
            listAll(d->subdomains()[i], d->subdomains()[i]->label());
        }
        else{
            listAll(d->subdomains()[i], d->subdomains()[i]->label() + "." + path);
        }
    }
}
