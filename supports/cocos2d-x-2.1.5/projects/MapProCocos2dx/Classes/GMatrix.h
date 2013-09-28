//
//  GMatrix.h
//  MapPro
//
//  Created by RockLee on 13-9-27.
//
//

#ifndef __MapPro__GMatrix__
#define __MapPro__GMatrix__

#include <iostream>
#include "cocos2d.h"
class GMatrix : public cocos2d::CCObject
{
public:
    GMatrix(int col, int row);
    ~GMatrix();
    int col;
    int row;
};
#endif /* defined(__MapPro__GMatrix__) */