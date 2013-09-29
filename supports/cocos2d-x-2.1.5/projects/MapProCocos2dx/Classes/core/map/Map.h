//
//  Map.h
//  MapPro
//
//  Created by RockLee on 13-9-27.
//
//

#ifndef __MapPro__Map__
#define __MapPro__Map__

#include <iostream>
#include "MapNode.h"
class Map : public MapNode
{
public:
    /**2维数组，保存所有的node*/
    CCArray* nodes;
    
    /**mapItem列表*/
    CCArray* items;
    
    Map(CCRect* rect, GNode* node);
    ~Map();

	/**根据colIndex, rowIndex获取mapMapNode*/
	MapNode* getMapNode(int colIndex, int rowIndex);
protected:
    /**创建*/
    void create();
	/**检测是否有colIndex, rowIndex下的MapNode*/
	bool checkMapNode(int colIndex, int rowIndex);
};

class MapFactory
{
public:
    /**静态函数创建MapNode*/
    static MapNode* createMapNode(int colIndex, int rowIndex);
};

#endif /* defined(__MapPro__Map__) */