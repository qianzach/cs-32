//
//  mazestack.cpp
//  homework2
//
//  Created by Zach Qian on 4/26/19.
//  Copyright © 2019 Zach Qian. All rights reserved.
//
#include <stdio.h>
#include <stack>
#include <string>
#include <iostream>
using namespace std;

bool pathExists(char maze[][10], int sr, int sc, int er, int ec);

class Coord
{
public:
    Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
    int r() const { return m_r; }
    int c() const { return m_c; }
private:
    int m_r;
    int m_c;
};

//assumptions:
//the maze has 10 rows;
//the maze contains only Xs and dots when passed in to the function;
//the top and bottom rows of the maze contain only Xs, as do the left and right columns;
//sr, sc, er, and ec are between 0 and 9;
//maze[sr][sc] and maze[er][ec] are '.' (i.e., not walls)
bool pathExists(char maze[][10], int sr, int sc, int er, int ec){
    // sr  =  starting row, sc=  starting column
    // er = ending row, ec = ending column
    //(Our convention is that (0,0) is the northwest (upper left) corner, with south (down) being the increasing r direction and east (right) being the increasing c direction.)
    stack<Coord> cstack; //declaring initial stack
    Coord start(sr,sc);
    cstack.push(start);
//    cerr << "start is  "  << start.r() << endl;
//    cerr << "start is  "  << start.c() << endl;

    maze[sr][sc] = 'X'; //marks starting point off after the maze has begun
    
    while(! cstack.empty()){
        Coord current = cstack.top();
//        cerr << "popped row is " << current.r() << endl;
//        cerr << "popped col is " << current.c() << endl;
        cstack.pop();
        if(current.r()==er && current.c()== ec){
            return true;
            // this indicates hat the path to the ending  coordinates has been found
        }
        else{
            if((maze[current.r()+1][current.c()] != 'X') && (current.r() + 1) < 10 ){
                Coord temp(current.r() + 1, current.c());
                cstack.push(temp);
                maze[current.r() + 1][current.c()] = 'X'; //mark  off south position as possible solution via stack push
            }
            if ((maze[current.r()][current.c() - 1] != 'X') && (current.c() - 1) >= 0){
                Coord temp(current.r() , current.c() - 1);
                cstack.push(temp);

                maze[current.r()][current.c() - 1] = 'X';
//                cerr << "here" << endl;//mark  off west position as possible solution via stack push
            }
            if((maze[current.r()-1][current.c()]!= 'X') && (current.r()-1) >= 0){
                Coord temp(current.r() - 1 ,  current.c());
                cstack.push(temp);
//                cerr << "here2" << endl;
                maze[current.r() - 1][current.c()]= 'X'; // marks off North position as possible solution via stack push
            }
            if((maze[current.r()][current.c() + 1] != 'X') && (current.c() + 1) < 10 ){
                Coord temp(current.r() , current.c() + 1);
                cstack.push(temp);
//                cerr << "here" << endl;// marks of east position as possible solution via stack push
                maze[current.r()][current.c() + 1] = 'X';
//                cerr <<'\n';
            }
        }
        
    }
    return false; //no solution
    
}
// Return true if there is a path from (sr,sc) to (er,ec)
// through the maze; return false otherwise
/*       Push the starting coordinate (sr,sc) onto the coordinate stack and
 update maze[sr][sc] to indicate that the algorithm has encountered
 it (i.e., set maze[sr][sc] to have a value other than '.').
 While the stack is not empty,
 {   Pop the top coordinate off the stack. This gives you the current
 (r,c) location that your algorithm is exploring.
 If the current (r,c) coordinate is equal to the ending coordinate,
 then we've solved the maze so return true!
 Check each place you can move from the current cell as follows:
 If you can move SOUTH and haven't encountered that cell yet,
 then push the coordinate (r+1,c) onto the stack and update
 maze[r+1][c] to indicate the algorithm has encountered it.
 
 If you can move WEST and haven't encountered that cell yet,
 then push the coordinate (r,c-1) onto the stack and update
 maze[r][c-1] to indicate the algorithm has encountered it.
 
 If you can move NORTH and haven't encountered that cell yet,
 then push the coordinate (r-1,c) onto the stack and update
 maze[r-1][c] to indicate the algorithm has encountered it.
 
 If you can move EAST and haven't encountered that cell yet,
 then push the coordinate (r,c+1) onto the stack and update
 maze[r][c+1] to indicate the algorithm has encountered it.
 }
 There was no solution, so return false */


int main()
{
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
}
