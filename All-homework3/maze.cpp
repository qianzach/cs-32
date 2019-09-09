//
//  maze.cpp
//  hw3part3
//
//  Created by Zach Qian on 5/6/19.
//  Copyright © 2019 Zach Qian. All rights reserved.
//
//
//#include <stdio.h>
//#include <iostream>
//using namespace std;

//bool pathExists(char maze[][10], int sr, int sc, int er, int ec);
bool pathExists(char maze[][10], int sr, int sc, int er, int ec){
    maze[sr][sc] = 'X';
    if(sr == er && sc == ec){
        return true;
    }
    else{
        if(maze[sr+1][sc] != 'X' && (sr+1) < 10){
            if(pathExists(maze, sr+1, sc, er, ec))
                return true;
        }
        if(maze[sr][sc-1]!= 'X' && (sc-1) >= 0){
//            cerr << sr << " is the row and " << sc << " is the column" << endl;
             if(pathExists(maze, sr, sc-1, er, ec))
                 return true;
        }
        if(maze[sr-1][sc] != 'X' && (sr -1) >= 0){
//            cerr << sr << " is the row and " << sc << " is the column" << endl;
            if(pathExists(maze, sr-1, sc, er, ec))
                return true;
        }
        if(maze[sr][sc+1] != 'X' && (sc+1) < 10){
//            cerr << sr << " is the row and " << sc << " is the column" << endl;
            if(pathExists(maze, sr, sc+1, er, ec))
                return true;
        }
    }
    return false;
    
}
//If the start location is equal to the ending location, then we've
//solved the maze, so return true.
//Mark the start location as visted.
//For each of the four directions,
//If the location one step in that direction (from the start
//                                            location) is unvisited,
//then call pathExists starting from that location (and
//                                                  ending at the same ending location as in the
//                                                  current call).
//If that returned true,
//then return true.
//Return false.
//int main(){
//    char maze[10][10] = {
//        { 'X','X','X','X','X','X','X','X','X','X' },
//        { 'X','.','.','.','.','X','.','.','.','X' },
//        { 'X','.','X','X','.','X','X','X','.','X' },
//        { 'X','X','X','.','.','.','.','X','.','X' },
//        { 'X','.','X','X','X','.','X','X','X','X' },
//        { 'X','.','X','.','.','.','X','.','.','X' },
//        { 'X','.','.','.','X','.','X','.','.','X' },
//        { 'X','X','X','X','X','.','X','.','X','X' },
//        { 'X','.','.','.','.','.','.','.','.','X' },
//        { 'X','X','X','X','X','X','X','X','X','X' }
//    };
//    for(int i = 0; i < 10; i++){
//        for(int j = 0; j < 10; j++){
//            cout << maze[i][j] << " ";
//        }
//        cout << '\n';
//    }
//
//    if (pathExists(maze, 3,5, 8,8))
//        cout << "Solvable!" << endl;
//    else
//        cout << "Out of luck!" << endl;
//}
