//
//  GMatrixIndex.h
//  MapPro
//
//  Created by RockLee on 13-9-27.
//
//

#ifndef __MapPro__GMatrixIndex__
#define __MapPro__GMatrixIndex__

#include <iostream>
#include "cocos2d.h"
class GMatrixIndex : public cocos2d::CCObject
{
public:
    GMatrixIndex(int colIndex, int rowIndex);
    ~GMatrixIndex();
    int colIndex;
    int rowIndex;
};
#endif /* defined(__MapPro__GMatrixIndex__) */