//
//  MSGeometry.h
//  HelloCpp
//
//  Created by RockLee on 13-9-29.
//
//

#ifndef __HelloCpp__MSGeometry__
#define __HelloCpp__MSGeometry__
#include <cocos2d.h>
#include "MoonSugar.h"

NS_MS_BEGIN
/********Matrix****/
class MSMatrix
{
public:
    MSMatrix(int col, int row);
    int col;
    int row;
};

/********MatrixIndex*******/
class MSMatrixIndex
{
public:
    MSMatrixIndex(int colIndex, int rowIndex);
    int colIndex;
    int rowIndex;
};

/*********Node***********/
class MSNode
{
public:
    MSMatrixIndex* matrixIndex;
    MSMatrix* matrix;
    
    MSNode(int col, int row, int colIndex, int rowIndex);
    virtual ~MSNode();
};

NS_MS_END;

#endif /* defined(__HelloCpp__MSGeometry__) */
