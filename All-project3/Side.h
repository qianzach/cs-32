//
//  Side.h
//  project3
//
//  Created by Zach Qian on 5/12/19.
//  Copyright © 2019 Zach Qian. All rights reserved.
//

#ifndef Side_h
#define Side_h
enum Side { NORTH, SOUTH };

const int NSIDES = 2;
const int POT = 0;

inline
Side opponent(Side s)
{
    return Side(NSIDES - 1 - s);
}
#endif /* Side_h */
