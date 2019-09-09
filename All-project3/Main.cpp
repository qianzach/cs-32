//
//  main.cpp
//  project3
//
//  Created by Zach Qian on 5/11/19.
//  Copyright © 2019 Zach Qian. All rights reserved.
//

#include <iostream>
#include "Board.h"
#include "Game.h"
#include "Player.h"
#include "Side.h"
#include <iostream>
using namespace std;

int main() {
//    Board b(3, 2);
//    cout << b.holes() << endl;
//    cout << b.totalBeans() << endl;
//    cout << b.beans(NORTH, POT) << endl;
//    assert(b.holes() == 3  &&  b.totalBeans() == 12  &&
//           b.beans(SOUTH, POT) == 0  &&  b.beansInPlay(SOUTH) == 6);
//
//    b.setBeans(SOUTH, 1, 1);
//    cout << b.totalBeans() << endl;
//
//    b.moveToPot(SOUTH, 2, SOUTH);
//    cout << b.totalBeans() << endl;
//    cout << b.beans(SOUTH, 2) << endl;
//    cout << b.beans(SOUTH, POT) << endl;
//    cout << b.beansInPlay(SOUTH) << endl;
//    assert(b.totalBeans() == 11  &&  b.beans(SOUTH, 1) == 1  &&
//           b.beans(SOUTH, 2) == 0  &&  b.beans(SOUTH, POT) == 2  &&
//           b.beansInPlay(SOUTH) == 3);
//    cout << b.beans(NORTH, 0) << " IS THW NORTH 0 POT" << endl;
//    Side es;
//    int eh;
//    cout << b.beans(SOUTH,3) << " beans" << endl;
//    b.sow(SOUTH, 3, es, eh);
////    assert(es == NORTH);
//    cout << es << endl;
//    assert(es == NORTH  &&  eh == 3  &&  b.beans(SOUTH, 3) == 0  &&
//           b.beans(NORTH, 3) == 3  &&  b.beans(SOUTH, POT) == 3  &&
//           b.beansInPlay(SOUTH) == 1  &&  b.beansInPlay(NORTH) == 7);
//    b.setBeans(NORTH, 1, 4);
//    cout << b.beans(NORTH, 2) << endl;
//    b.sow(NORTH, 1, es, eh);
//    assert(es == SOUTH && eh == 3 && b.beans(NORTH, 0) == 1);
//    assert(b.beansInPlay(SOUTH) == 6);
//
//    b.setBeans(NORTH, 2, 6);
//    b.sow(NORTH,2,es,eh);
//    assert(es == SOUTH && eh == 0 && b.beans(SOUTH,0)  == 3);
//    cout << b.beans(NORTH, 2) << endl;
//    cout << b.beans(NORTH, 1) << endl;
//    cout << b.beans(NORTH,0) << " POTS " << endl;
//    cout << b.beans(SOUTH, 1) << endl;
//    cout << b.beans(SOUTH, 0) << endl;
//    cout << eh << endl;
//    assert(b.sow(NORTH, 0, es, eh) == false);
//    assert(b.sow(SOUTH, 0, es, eh) == false);
//    assert(b.sow(NORTH, 4, es, eh) == false);
//    assert(b.sow(SOUTH, 4, es, eh) == false);
//    b.setBeans(NORTH, 3, 3);
//    b.sow(NORTH, 3, es, eh);
//    assert(b.beans(NORTH, 0) == 1 && eh == 0 && es == NORTH);
    
//    cout << b.beans(NORTH, 3);
//    b.sow(NORTH, 3, es, eh);
//    assert(es == NORTH && eh == 1 && b.beans(NORTH, 1) == 3);
    
//    assert(b.sow(SOUTH, 2, es, eh) == false); // check for empty hole
    
//    b.setBeans(SOUTH, 2, 2);
//    b.sow(SOUTH, 2, es, eh);
//    assert(b.beans(SOUTH, 0) == 3 && eh == 0 && es == SOUTH);
    //    cout << "all tests passed"  << endl;
//
//    b.setBeans(SOUTH, 1, 10);
//    b.sow(SOUTH, 1, es, eh);
//    assert(b.beans(SOUTH, 0) == 4 && es == SOUTH && eh == 0 &&  (b.beansInPlay(SOUTH) + b.beansInPlay(NORTH)) == 16 && b.beans(NORTH, 0) == 0);
    
//    HumanPlayer hp("Marge");
//    BadPlayer bp("Homer");
//    Board a(3,6);
//    Game g(b, &hp, &bp);
//    g.display();
//    cout << "game created " << endl;
//    BadPlayer bp1("Bart");
//    BadPlayer bp2("Homer");
//    Board b(3, 0);
//    b.setBeans(SOUTH, 1, 2);
//    b.setBeans(NORTH, 2, 1);
//    b.setBeans(NORTH, 3, 2);
//    Game g(b, &bp1, &bp2);
//    bool over;
//    bool hasWinner;
//    Side winner;
//    //    Homer
//    //   0  1  2
//    // 0         0
//    //   2  0  0
//    //    Bart
//    g.status(over, hasWinner, winner);
//    assert(!over && g.beans(NORTH, POT) == 0 && g.beans(SOUTH, POT) == 0 &&
//           g.beans(NORTH, 1) == 0 && g.beans(NORTH, 2) == 1 && g.beans(NORTH, 3) == 2 &&
//           g.beans(SOUTH, 1) == 2 && g.beans(SOUTH, 2) == 0 && g.beans(SOUTH, 3) == 0);
//    g.move();
//    //   0  1  0
//    // 0         3
//    //   0  1  0
//    g.status(over, hasWinner, winner);
//    assert(!over && g.beans(NORTH, POT) == 0 && g.beans(SOUTH, POT) == 3 &&
//           g.beans(NORTH, 1) == 0 && g.beans(NORTH, 2) == 1 && g.beans(NORTH, 3) == 0 &&
//           g.beans(SOUTH, 1) == 0 && g.beans(SOUTH, 2) == 1 && g.beans(SOUTH, 3) == 0);
    
//    BadPlayer bp1("Bart");
//    BadPlayer bp2("Homer");
//    Board b(3, 0);
//    b.setBeans(SOUTH, 1, 2);
//    b.setBeans(NORTH, 2, 1);
//    b.setBeans(NORTH, 3, 2);
//    Game g(b, &bp1, &bp2);
//    bool over;
//    bool hasWinner;
//    Side winner;
//    //    Homer
//    //   0  1  2
//    // 0         0
//    //   2  0  0
//    //    Bart
//    g.display();
//    g.status(over, hasWinner, winner);
//    assert(!over && g.beans(NORTH, POT) == 0 && g.beans(SOUTH, POT) == 0 &&
//           g.beans(NORTH, 1) == 0 && g.beans(NORTH, 2) == 1 && g.beans(NORTH, 3) == 2 &&
//           g.beans(SOUTH, 1) == 2 && g.beans(SOUTH, 2) == 0 && g.beans(SOUTH, 3) == 0);
//    g.move();
//    g.display();
//    //   0  1  0
//    // 0         3
//    //   0  1  0
//    g.status(over, hasWinner, winner);
//    assert(!over && g.beans(NORTH, POT) == 0 && g.beans(SOUTH, POT) == 3 &&
//           g.beans(NORTH, 1) == 0 && g.beans(NORTH, 2) == 1 && g.beans(NORTH, 3) == 0 &&
//           g.beans(SOUTH, 1) == 0 && g.beans(SOUTH, 2) == 1 && g.beans(SOUTH, 3) == 0);
//    g.move();
//    g.display();
////    //   1  0  0
////    // 0         3
////    //   0  1  0
//    g.status(over, hasWinner, winner);
//    assert(!over && g.beans(NORTH, POT) == 0 && g.beans(SOUTH, POT) == 3 &&
//           g.beans(NORTH, 1) == 1 && g.beans(NORTH, 2) == 0 && g.beans(NORTH, 3) == 0 &&
//           g.beans(SOUTH, 1) == 0 && g.beans(SOUTH, 2) == 1 && g.beans(SOUTH, 3) == 0);
//    g.move();
//    g.display();
////    //   1  0  0
////    // 0         3
////    //   0  0  1
//    g.status(over, hasWinner, winner);
//    cout << g.beans(NORTH, POT) << " NORTH POT"<<endl;
//    cout <<  g.beans(SOUTH, POT) << " SOUT  POT" << endl;
//    cout << g.beans(NORTH, 1) << " NORTH  1" << endl;
//    cout << g.beans(NORTH, 2) << " NORTH  2" << endl;
//    cout  << g.beans(NORTH, 3) << " NORTH 3" << endl;
//    cout << g.beans(SOUTH, 1) << " SOUTH 1" << endl;
//    cout <<  g.beans(SOUTH, 2) << " SOUTH 2" << endl;
//    cout << g.beans(SOUTH, 3) << " SOUTH 3" << endl;
//    assert(!over && g.beans(NORTH, POT) == 0 && g.beans(SOUTH, POT) == 3 &&
//           g.beans(NORTH, 1) == 1 && g.beans(NORTH, 2) == 0 && g.beans(NORTH, 3) == 0 &&
//           g.beans(SOUTH, 1) == 0 && g.beans(SOUTH, 2) == 0 && g.beans(SOUTH, 3) == 1);
////
//    g.move();
//    //   0  0  0
//    // 1         4
//    //   0  0  0
//    g.status(over, hasWinner, winner);
//    assert(over && g.beans(NORTH, POT) == 1 && g.beans(SOUTH, POT) == 4 &&
//           g.beans(NORTH, 1) == 0 && g.beans(NORTH, 2) == 0 && g.beans(NORTH, 3) == 0 &&
//           g.beans(SOUTH, 1) == 0 && g.beans(SOUTH, 2) == 0 && g.beans(SOUTH, 3) == 0);
//    assert(hasWinner && winner == SOUTH && over == true);
//    cout << g.beans(SOUTH, 3) << " South 3 has this" << endl;
//    cout << g.beans(SOUTH, 1) << " South 1 has this" << endl;
//
//    cout << g.beans(SOUTH, 3)<< endl;
//    g.display();
//
//    cout << "good" << endl;

    
    
    
    
    //    Play Tests:
//    SmartPlayer sp("AI lookin Ass");
//    BadPlayer hp("ZACH");
//    Board b(3,2);
    
    
//    HumanPlayer sp("not AI");
//    SmartPlayer hp("AI");
 
//          AVOIDS OPPONENT CAPTURE
//        Board b(4, 0);
//
//
//        b.setBeans(NORTH, 2, 1);
//        b.setBeans(SOUTH, 1, 2);
//        b.setBeans(SOUTH, 3, 1);
    
    
//         Picks 1st
//    Board b(4, 0);
//
//
//    b.setBeans(NORTH, 2, 1);
//    b.setBeans(SOUTH, 1, 1);
//    b.setBeans(SOUTH, 3, 1);
    
//      TIE CASE
//    Board b(4, 0);
//
//
//    b.setBeans(NORTH, 3, 1);
//    b.setBeans(SOUTH, 1, 1);
//    b.setBeans(SOUTH, 3, 2);

//
//
//    Board b(5, 0);
//    b.setBeans(NORTH, 3, 1);
//    b.setBeans(SOUTH, 1, 1);
//    b.setBeans(SOUTH, 4, 1);
    
//    b.setBeans(NORTH, 1, 0);
//    b.setBeans(NORTH, 2, 0);
//    b.setBeans(NORTH, 3, 3);
//    b.sow(SOUTH, 2, es, eh);
//    b.sow(SOUTH,1,es,eh);
//    cout << eh << endl;
//    cout << b.beans(SOUTH, 1);
//    assert(b.beansInPlay(SOUTH) == 5);
//    assert(b.beans(SOUTH, 0) == 1);
//    Game g(b, &sp, &hp);
//    Side es;
//    int eh;
//    g.display();
//    b.sow(SOUTH,4,es,eh);
//    cout << b.beans(SOUTH, 5) << endl;
    //    cout << b.holes();
//    g.play();
    
    
//    // board test
//
//    int nHoles = 6;
//
//    int nInitialBeansPerHole = 4;
//
//    Board a(nHoles, nInitialBeansPerHole);
//
//
//
//    assert(a.beansInPlay(NORTH) == 4*6);
//
//    assert(a.beansInPlay(SOUTH) == 4*6);
//
//    assert(a.totalBeans() == 4*6*2);
//
//    assert(a.setBeans(NORTH, 3, 0) == 1);
//
//    assert(a.setBeans(NORTH, -1, 0) == 0);
//
//    assert(a.setBeans(NORTH, 7, 0) == 0);
//
//    assert(a.totalBeans() == 4*6*2-4);
//
//    assert(a.beansInPlay(NORTH) == 4*5);
//
//    assert(a.beansInPlay(SOUTH) == 4*6);
//
//    assert(a.setBeans(NORTH, 3, 4) == 1);
//
//    Side endSide = SOUTH;
//
//    int endHole = 999;
//
//    assert(a.sow(NORTH, 3, endSide, endHole) == 1
//
//           && endSide == SOUTH
//
//           && endHole == 1);
//    assert(a.totalBeans() == 4*6*2);
//
//    assert(a.beansInPlay(NORTH) == 4*6-2);
//
//    assert(a.beansInPlay(SOUTH) == 4*6+1);
//
//    assert(a.holes() == 6);
//
//    assert(a.totalBeans() == 4*6*2);
//
//    Board board(6, 3);
//
//    //test beans
//
//    assert(board.beans(NORTH, 0) == 0);
//
//    assert(board.beans(NORTH, 1) == 3);
//
//    assert(board.beans(NORTH, 2) == 3);
//
//    assert(board.beans(NORTH, 3) == 3);
//
//    assert(board.beans(NORTH, 4) == 3);
//
//    assert(board.beans(NORTH, 5) == 3);
//
//    assert(board.beans(NORTH, 6) == 3);
//
//    assert(board.beans(NORTH, 7) == -1);
//
//    assert(board.beans(NORTH, -1) == -1);
//
//    assert(board.beans(SOUTH, 0) == 0);
//
//    assert(board.beans(SOUTH, 1) == 3);
//
//    assert(board.beans(SOUTH, 2) == 3);
//
//    assert(board.beans(SOUTH, 3) == 3);
//
//    assert(board.beans(SOUTH, 4) == 3);
//
//    assert(board.beans(SOUTH, 5) == 3);
//
//    assert(board.beans(SOUTH, 6) == 3);
//
//    assert(board.beans(SOUTH, 7) == -1);
//
//    assert(board.beans(SOUTH, 8) == -1);
//
//    assert(board.beans(SOUTH, 8) == -1);
//
////    test totalbeans
//
//    assert(board.beansInPlay(NORTH)     == 18);
//
//    assert(board.beansInPlay(SOUTH)         == 18);
//
//    assert(board.totalBeans()               == 2*18);
//
//    assert(board.setBeans(NORTH, 1, 20));
//
//    assert(board.beansInPlay(NORTH)         == 18 - 3 + 20);
//
//    assert(board.beansInPlay(SOUTH)         == 18);
//
//    assert(!board.setBeans(NORTH, -1, 20));
//
//    assert(!board.setBeans(NORTH, 9, 20));
//
//    assert(board.beans(NORTH, 1)            == 20);
//
//    assert(board.totalBeans()               == 18 * 2 - 3 + 20);
//
//    assert(board.setBeans(NORTH, 0, 20));
//
//    assert(board.totalBeans()               == 18*2 - 3 + 20 * 2);
//
//
//
//    //test movetopot
//
//    assert(board.moveToPot(NORTH, 2, NORTH));
//
//    assert(board.beans(NORTH, 0) == 23);
//
//    assert(board.moveToPot(NORTH, 1, NORTH));
//
//    assert(!board.moveToPot(NORTH, 0, NORTH));
//
//    assert(board.moveToPot(NORTH, 2, SOUTH));
//
//    assert(board.moveToPot(SOUTH, 2, SOUTH));
//
//    assert(!board.moveToPot(SOUTH, 0, SOUTH));
//
//
//    cout << "asdfsa" << endl;
//
//    //test sow
//
//    Board c(6, 4);
//
//    //    Side endSide;
//
//    int endhole;
//
//    //Test the Sow Function
//
//    assert(c.sow(NORTH, 3, endSide, endhole));
//
//    assert(endhole == 1);
//
//    assert(endSide == SOUTH);
//
//
//
//    assert(c.sow(NORTH, 1, endSide, endhole));
//
//    assert(endhole == 4);
//
//    assert(endSide == SOUTH);
//
//
//
//    assert(!c.sow(NORTH, 0, endSide, endhole));
//
//    assert(c.setBeans(SOUTH, 1, 20));
//
//    assert(c.sow(SOUTH, 1, endSide, endhole));
//
//    assert(endhole == 6);
//
//    assert(endSide == NORTH);
//
//    assert(c.sow(SOUTH, 1, endSide, endhole));
//
//    assert(endhole == 2);
//
//    assert(endSide == SOUTH);
//
//
//
//    cout << "board -- all passed\n";
//
//    //bad player
//
//    Board d(6, 4);
//
//    assert(d.setBeans(SOUTH, 1, 0));
//
//    assert(d.setBeans(SOUTH, 2, 0));
//
//    assert(d.setBeans(SOUTH, 3, 0));
//
//    assert(d.setBeans(SOUTH, 4, 0));
//
//    assert(d.setBeans(SOUTH, 5, 0));
//
//    assert(d.setBeans(SOUTH, 6, 0));
//
//    BadPlayer bad("BadComputer");
//
//    assert(!bad.isInteractive());
//
//    assert(bad.name() == "BadComputer");
//
//    //The bad player should choose the the lowest possible hole that is availiable
//
//    assert(bad.chooseMove(d, SOUTH) == -1);
//
//    assert(bad.chooseMove(d, NORTH) == 1);
//
//    d.sow(NORTH, 1, endSide, endhole);
//
//    assert(bad.chooseMove(d, NORTH) == 2);
//
//    d.sow(NORTH, 2, endSide, endhole);
//
//    assert(bad.chooseMove(d, NORTH) == 1);
//
//    cout << "player -- all passed\n";
//
//    //test game class
//
//
//
//    BadPlayer bp1("Bart");
//
//    BadPlayer bp2("Homer");
//
//    Board f(3, 0);
//
//    f.setBeans(SOUTH, 1, 2);
//
//    f.setBeans(NORTH, 2, 1);
//
//    f.setBeans(NORTH, 3, 2);
//
//    Game g(f, &bp1, &bp2);
//
//    bool over;
//
//    bool hasWinner;
//
//    Side winner;
//
//    g.status(over, hasWinner, winner);
//
//    assert(!over && g.beans(NORTH, POT) == 0 && g.beans(SOUTH, POT) == 0 &&
//
//           g.beans(NORTH, 1) == 0 && g.beans(NORTH, 2) == 1 && g.beans(NORTH, 3) == 2 &&
//
//           g.beans(SOUTH, 1) == 2 && g.beans(SOUTH, 2) == 0 && g.beans(SOUTH, 3) == 0);
//
//
//
//    g.move();
//
//    g.status(over, hasWinner, winner);
//
//    assert(!over && g.beans(NORTH, POT) == 0 && g.beans(SOUTH, POT) == 3 &&
//
//           g.beans(NORTH, 1) == 0 && g.beans(NORTH, 2) == 1 && g.beans(NORTH, 3) == 0 &&
//
//           g.beans(SOUTH, 1) == 0 && g.beans(SOUTH, 2) == 1 && g.beans(SOUTH, 3) == 0);
//
//    g.move();
//
//    g.status(over, hasWinner, winner);
//
//    assert(!over && g.beans(NORTH, POT) == 0 && g.beans(SOUTH, POT) == 3 &&
//
//           g.beans(NORTH, 1) == 1 && g.beans(NORTH, 2) == 0 && g.beans(NORTH, 3) == 0 &&
//
//           g.beans(SOUTH, 1) == 0 && g.beans(SOUTH, 2) == 1 && g.beans(SOUTH, 3) == 0);
//
//    g.move();
//
//    g.status(over, hasWinner, winner);
//
//    assert(!over && g.beans(NORTH, POT) == 0 && g.beans(SOUTH, POT) == 3 &&
//
//           g.beans(NORTH, 1) == 1 && g.beans(NORTH, 2) == 0 && g.beans(NORTH, 3) == 0 &&
//
//           g.beans(SOUTH, 1) == 0 && g.beans(SOUTH, 2) == 0 && g.beans(SOUTH, 3) == 1);
//
//    g.move();
//
//    g.status(over, hasWinner, winner);
//
//    assert(over && g.beans(NORTH, POT) == 1 && g.beans(SOUTH, POT) == 4 &&
//
//           g.beans(NORTH, 1) == 0 && g.beans(NORTH, 2) == 0 && g.beans(NORTH, 3) == 0 &&
//
//           g.beans(SOUTH, 1) == 0 && g.beans(SOUTH, 2) == 0 && g.beans(SOUTH, 3) == 0);
//
//    assert(hasWinner && winner == SOUTH);
//
//
//    Board alpha(1, 1);
//
//    alpha.setBeans(NORTH, 0, 9);
//
//    alpha.setBeans(NORTH, 1, 2);
//
//    alpha.setBeans(SOUTH, 1, 0);
//
//    alpha.setBeans(SOUTH, 0, 10);
//
//
//
//    BadPlayer cert("billy");
//
//    BadPlayer dad("jef");
//
//    Game beta(alpha, &cert, &dad);
//
//
//
//    bool ov = false;
//
//    bool haW = false;
//
//    Side wen = SOUTH;
////
//    beta.status(ov, haW, wen);
//
//    assert(ov && haW && wen == NORTH);
//
//    alpha.setBeans(NORTH, 1, 1);
//
//    Game gamma(alpha, &cert, &dad);
//
//    gamma.status(ov, haW, wen);
//
//    assert(ov && !haW);
//
//
//
//    cout << "game -- all passed\n";
//
//    SmartPlayer smartP("check1");
//    HumanPlayer humanP("check");
//    Board board1(4, 0);
//    board1.setBeans(NORTH, 2, 1);
//    board1.setBeans(SOUTH, 2, 1);
//    board1.setBeans(SOUTH, 1, 1);
//    board1.setBeans(SOUTH, 3, 1);
//    Game game(board1,&smartP,&humanP);
//    game.play();
    
    return 0;
    
}
