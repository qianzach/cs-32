//
//  History.cpp
//  project1
//
//  Created by Zach Qian on 4/4/19.
//  Copyright © 2019 Zach Qian. All rights reserved.
//

#include "History.h"
#include "globals.h"
#include <iostream>
using namespace std;

History::History(int nRows, int nCols){
    m_rows = nRows;
    m_cols = nCols;
//    initializes the history grid to all 0
//    Assuming that when history is created, 0 zombie kills
    for(int i = 0; i < nRows; i++){
        for(int j = 0; j < nCols; j++){
            arr[i][j] = 0;
        }
    }
}

bool History::record(int r, int c){
    if (m_rows < 0  ||  m_cols < 0  ||  m_rows > MAXROWS ||  m_cols > MAXCOLS ){
        return false;
    }
//    Increases count by 1 if zombie was killed at row r, column c
    arr[r-1][c-1] +=  1;
    return true;
}

void History::display() const {
    // clears the screen and displays the history grid as the posted programs do
    char gridArr [MAXROWS][MAXCOLS];
    clearScreen();
    for(int i = 0; i < m_rows; i++){
        for(int j = 0; j < m_cols; j++){
            if(arr[i][j] == 0){
                gridArr[i][j] = '.';
                cout << gridArr[i][j];
            }
            else if(arr[i][j] >= 1 && arr[i][j] <= 27){
                gridArr[i][j] = 'A' + (arr[i][j]-1);
                cout << gridArr[i][j];
            }
            else if(arr[i][j] > 27){
                gridArr[i][j] = 'Z';
                cout << gridArr[i][j];
            }
        }
        cout << '\n';
        }
    cout << '\n';
    
    
}

