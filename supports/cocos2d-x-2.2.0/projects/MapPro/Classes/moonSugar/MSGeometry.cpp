//
//  MSGeometry.cpp
//  HelloCpp
//
//  Created by RockLee on 13-9-29.
//
//

#include "MSGeometry.h"

NS_MS_BEGIN
/***Matrix**/
MSMatrix::MSMatrix(int col, int row)
{
    this->col = col;
    this->row = row;
}
/********MatrixIndex*****/
MSMatrixIndex::MSMatrixIndex(int colIndex, int rowIndex)
{
    this->colIndex = colIndex;
    this->rowIndex = rowIndex;
}
/********MSNode***********/
MSNode::MSNode(int col, int row, int colIndex, int rowIndex)
{
    matrixIndex = new MSMatrixIndex(colIndex, rowIndex);
    matrix = new MSMatrix(col, row);
}

MSNode::~MSNode()
{
    delete matrixIndex;
    delete matrix;
}
NS_MS_END;