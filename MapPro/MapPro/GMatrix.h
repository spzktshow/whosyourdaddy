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
#endif /* defined(__MapPro__GMatrix__) */
NS_CC_BEGIN
class GMatrix : public CCObject
{
public:
    GMatrix(int col, int row);
    ~GMatrix();
    int col;
    int row;
};
GMatrix::GMatrix(int col, int row)
{
    this->col = col;
    this->row = row;
}
GMatrix::~GMatrix()
{
    
}
NS_CC_END