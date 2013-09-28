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
#endif /* defined(__MapPro__GMatrixIndex__) */
NS_CC_BEGIN
class GMatrixIndex : public CCObject
{
public:
    GMatrixIndex(int colIndex, int rowIndex);
    ~GMatrixIndex();
    int colIndex;
    int rowIndex;
};
GMatrixIndex::GMatrixIndex(int colIndex, int rowIndex)
{
    this->colIndex = colIndex;
    this->rowIndex = rowIndex;
}
GMatrixIndex::~GMatrixIndex()
{
    
}
NS_CC_END