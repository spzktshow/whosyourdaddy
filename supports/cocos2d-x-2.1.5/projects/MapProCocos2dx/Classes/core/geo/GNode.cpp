//
//  GNode.cpp
//  MapPro
//
//  Created by RockLee on 13-9-27.
//
//

#include "GNode.h"
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