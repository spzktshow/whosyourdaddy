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

/******************Matrix3d**********/
class MSMatrix3D : MSMatrix
{
public:
	MSMatrix3D(int x, int y, int z);
	MSMatrix3D(int col, int row);//y = 0;
	int x;//col
	int y;//
	int z;//row
};

/*******************MatrixIndex3d*************/
class MSMatrixIndex3D : MSMatrixIndex
{
public:
	MSMatrixIndex3D(int xIndex, int yIndex, int zIndex);
	MSMatrixIndex3D(int colIndex, int rowIndex);//y = 0;
	int xIndex;//colIndex
	int yIndex;//
	int zIndex;//rowIndex
};

/*******************Point3D*************/
class MSPoint3D
{
public:
	int x;
	int y;
	int z;
};

NS_MS_END;

#endif /* defined(__HelloCpp__MSGeometry__) */
