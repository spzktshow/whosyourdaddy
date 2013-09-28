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
#endif /* defined(__MapPro__GNode__) */
NS_CC_BEGIN
class GNode : public CCObject
{
public:
    GNode(int col, int row, int colIndex, int rowIndex);
    ~GNode();
    GMatrix* matrix;
    GMatrixIndex* matrixIndex;
};

GNode::GNode(int col, int row, int colIndex, int rowIndex)
{
    matrix = new GMatrix(col, row);
    matrixIndex = new GMatrixIndex(colIndex, rowIndex);
}

GNode::~GNode()
{
    delete matrixIndex;
    delete matrix;
}
NS_CC_END