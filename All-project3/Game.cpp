//
//  Game.cpp
//  project3
//
//  Created by Zach Qian on 5/12/19.
//  Copyright © 2019 Zach Qian. All rights reserved.
//

#include "Game.h"

Game::Game(const Board& b, Player* south, Player* north): m_Board(b), m_PlayerSouth(south),m_PlayerNorth(north),m_currentSide(SOUTH){}

void Game::display() const{
    //    Display the game's board in a manner of your choosing, provided you show the names of the players and a reasonable representation of the state of the board.
    //    to make the UI not disgusting, I created a TabCounter that is based off the size of the # of holes
    int tab = 0;
    if(m_Board.holes() % 2 == 0)
        tab =( m_Board.holes()/2);
    else
        tab = (m_Board.holes()/2) + 1;
//    integer accounting for the number of holes
    int multDigitHoles = 0;
//    in case of having holes() more than 10
    int fullPotNorth = 0;
//    if the north pot has more than one digit, then we have to add a space to make it look better
    if (m_Board.beans(NORTH, 0) > 9)
        fullPotNorth++;
    
    for (int i = 0; i < tab; i++){
//        add tabs to find the approximate middle of the board
        cout << "   ";
    }
    for (int i = 0; i < fullPotNorth; i++){
        //        add tabs up to the point where the last digit for the # of beans in N pot is going to be
        cout << "   ";
    }
//    print out the northern player's name in the middle location from tab
    cout << m_PlayerNorth->name() << endl;
    for (int i = 1; i < m_Board.holes() + 1; i++){
//        print out value of beans with spaces
        cout << "   " << m_Board.beans(NORTH, i);
    }
//    spaces in case north pot > 9
    for (int i = 0; i < fullPotNorth; i++){
        cout << "   ";
    }
    cout << '\n';
//    print out the number of beans in the north pot
    cout << " " << m_Board.beans(NORTH, 0);
    
    for (int i = 0; i < m_Board.holes(); i++){
//        account for necessary extra spaces
        cout << "    ";
    }
    for (int i = 1; i < m_Board.holes() + 1; i++){
//        print out bean count in the north holes
        if (m_Board.beans(NORTH, i) >= 10)
            multDigitHoles++;
    }
    for (int i = 1; i < m_Board.holes() + 1; i++){
        //        print out bean count in the south holes
        if (m_Board.beans(SOUTH, i) > 9)
            multDigitHoles++;
    }
    for (int i = 0; i < multDigitHoles; i++){
//        account for holes with beans > 9
        cout << " ";
    }
//    print out the number of beans in south pot
    cout << m_Board.beans(SOUTH, 0) << '\n';
//    print out new line after the pot size for south
//    cout << '\n';
    for (int i = 1; i < m_Board.holes() + 1; i++){
        cout << "   " << m_Board.beans(SOUTH, i);
    }
    for (int i = 0; i < fullPotNorth; i++){
        cout << "   ";
    }
    cout << '\n';
    for (int i = 0; i < tab; i++){
        cout << "   ";
    }
    for (int i = 0; i < fullPotNorth; i++){
        cout << "   ";
    }
//    finally  print out the south players' name in the middle
    cout << m_PlayerSouth->name() << endl;
    
}


void Game::status(bool& over, bool& hasWinner, Side& winner) const{
    if(m_Board.beansInPlay(NORTH) == 0 || m_Board.beansInPlay(SOUTH) == 0){
        over = true;
        if((m_Board.beans(NORTH, 0) + m_Board.beansInPlay(NORTH)  )  == (m_Board.beans(SOUTH, 0) + m_Board.beansInPlay(SOUTH))){
            //            if north and south have the same bean count in their pots
            hasWinner = false;
        }
        else{
            hasWinner = true;
            winner = (m_Board.beans(NORTH, 0) + m_Board.beansInPlay(NORTH)  ) >  (m_Board.beans(SOUTH, 0) + m_Board.beansInPlay(SOUTH)) ? NORTH : SOUTH;
            // Using ternary expression to compare the pot sizes; it  will return NORTH if expr is true and false otherwise
            }
        }
    else{
        over = false;
    }
}
////If the game isn't over (i.e., more moves are possible), set over to false and do not change anything else. Otherwise, set over to true and hasWinner to true if the game has a winner, or false if it resulted in a tie. If hasWinner is set to false, leave winner unchanged; otherwise, set it to the winning side.
//
bool Game::move(){
    Side endSide;
    Side winner;
    int endHole;
    int currHole;
    bool over;
    bool hasWinner;
    //    here i created two generic players to simplify this code
    Player* genPlayer1;
    Player* genPlayer2;
    
//    this way we don't have to have so many cases
    if (m_currentSide == SOUTH){
        genPlayer1 = m_PlayerSouth;
        genPlayer2 = m_PlayerNorth;
    }
    else{
        genPlayer1 = m_PlayerNorth;
        genPlayer2 = m_PlayerSouth;
    }
//choose first move for the first player
    currHole = genPlayer1 -> chooseMove(m_Board, m_currentSide);
    m_Board.sow(m_currentSide, currHole, endSide, endHole);
//    display();
    //check status of game
    this->status(over, hasWinner, winner);
    if(over == true){
        display();
        cout << "Regular gameplay now terminating because one side has no more beans." << endl;
        for (int i = 0; i < m_Board.holes() + 1; i++){
            m_Board.moveToPot(opponent(m_currentSide), i , opponent(m_currentSide));
            m_Board.moveToPot(m_currentSide, i , m_currentSide);
        }
        cout << "Placing the remaining beans into each players' pots." << endl;
        display();
        return false;
    }
    

    //    Case 2:  Game not over but the sow leads to bean landing in pot for final step
    while (endHole == 0 && endSide == m_currentSide){
        display();
        cout << genPlayer1->name() << " has landed in their own pot. Please pick another hole:" << endl;
        currHole = genPlayer1 -> chooseMove(m_Board, m_currentSide);
        m_Board.sow(m_currentSide, currHole, endSide, endHole);
//        check status of winner EVERY time
        this->status(over, hasWinner, winner);
//        supplementary check to see if the n+1th move resulted in end game
        if(over == true){
            display();
            cout << "Regular gameplay now terminating because one side has no more beans." << endl;
            for (int i = 0; i < m_Board.holes() + 1; i++){
                m_Board.moveToPot(opponent(m_currentSide), i , opponent(m_currentSide));
                m_Board.moveToPot(m_currentSide, i , m_currentSide);
            }
            cout << "Placing the remaining beans into each players' pots." << endl;
            return false;
        }
    }
    //  Case 3: Capture
    if (endSide == m_currentSide && endHole != 0 && m_Board.beans(m_currentSide, endHole) == 1 && m_Board.beans(opponent(m_currentSide), endHole) != 0){
        cout << genPlayer1->name() << " has gotten a capture. Retrieving beans and opponent's beans... " << endl;
        m_Board.moveToPot(m_currentSide, endHole, m_currentSide);
        m_Board.moveToPot(opponent(m_currentSide), endHole, m_currentSide);
        m_Board.setBeans(m_currentSide, endHole, 0);
        m_Board.setBeans(opponent(m_currentSide), endHole, 0);
    }
//    check status
    this->status(over, hasWinner, winner);
    //if game is over, move all of the beans on the remaining side into the remaining side's pot and return false
    if(over == true){
        display();
        cout << "Regular gameplay now terminating because one side has no more beans." << endl;
        for (int i = 0; i < m_Board.holes() + 1; i++){
            m_Board.moveToPot(opponent(m_currentSide), i , opponent(m_currentSide));
            m_Board.moveToPot(m_currentSide, i , m_currentSide);
        }
        cout << "Placing the remaining beans into each players' pots." << endl;
        display();
        return false;
    }
//    switch sides
//    display();
    m_currentSide = opponent(m_currentSide);
    return true;
}
//If the game is over, return false. Otherwise, make a complete move for the player whose turn it is (so that it becomes the other player's turn) and return true. "Complete" means that the player sows the seeds from a hole and takes any additional turns required or completes a capture. If the player gets an additional turn, you should display the board so someone looking at the screen can follow what's happening.




void  Game::play(){
    cout << "On the north side we have: " << m_PlayerNorth->name() << endl;
    cout << "On the south side we have: " << m_PlayerSouth->name() << endl;
    cout << "Here's the map set up:" << endl;
    display();
    while(move() == true){
        if (!m_PlayerNorth -> isInteractive() && !m_PlayerSouth ->isInteractive())
        {
            display();
            cout << "Press ENTER to continue on with the game: ";
            cin.ignore(10000, '\n');
        }
        
        else
            display();

    }
//    check to see if  game is over
    bool over;
    bool hasWinner;
    Side winner;
    this->status(over, hasWinner, winner);
    if(hasWinner == false)
//        check if there is a tie
        cout << "There is a tie!" << endl;
    else{
//        display();
        if(winner == NORTH){
            display();
            cout << m_PlayerNorth->name() << " wins!" << endl;
        }
        else if(winner == SOUTH){
            display();
            cout << m_PlayerSouth->name() << " wins!" << endl;
        }
    }
}



int Game::beans(Side s, int hole)const{
//    Return the number of beans in the indicated hole or pot of the game's board, or −1 if the hole number is invalid. This function exists so that we and you can more easily test your program.
    if(this->m_Board.beans(s, hole) == -1){
        return -1;
    }
    else{
        return this->m_Board.beans(s, hole);
    }
}

