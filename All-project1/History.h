//
//  History.hpp
//  project1
//
//  Created by Zach Qian on 4/4/19.
//  Copyright © 2019 Zach Qian. All rights reserved.
//

#ifndef History_h
#define History_h

#include <stdio.h>
#include "globals.h"

class History
{
public:
    History(int nRows, int nCols);
    bool record(int r, int c);
    void display() const;
private:
    int m_rows;
    int m_cols;
    int arr [MAXROWS][MAXCOLS];

};
#endif /* History_hpp */
