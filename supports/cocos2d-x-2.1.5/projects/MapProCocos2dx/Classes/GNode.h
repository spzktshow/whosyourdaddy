//
//  GNode.h
//  MapPro
//
//  Created by RockLee on 13-9-27.
//
//

#ifndef __MapPro__GNode__
#define __MapPro__GNode__

#include <iostream>
#include "cocos2d.h"
#include "GMatrix.h"
#include "GMatrixIndex.h"
class GNode : public cocos2d::CCObject
{
public:
    GNode(int col, int row, int colIndex, int rowIndex);
    ~GNode();
    GMatrix* matrix;
    GMatrixIndex* matrixIndex;
};
#endif /* defined(__MapPro__GNode__) */