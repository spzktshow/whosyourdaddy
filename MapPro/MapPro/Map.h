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
#include "cocos2d.h"
#include "MapNode.h"
#endif /* defined(__MapPro__Map__) */
NS_CC_BEGIN
class Map : public MapNode
{
public:
    /**2维数组，保存所有的node*/
    CCArray* nodes;
    
    /**mapItem列表*/
    CCArray* items;
    
    Map(CCRect* rect, GNode* node);
    ~Map();
    
protected:
    /**创建*/
    void create();
};

Map::Map(CCRect* rect, GNode* node):MapNode::MapNode(rect, node)
{
    nodes = new CCArray;
    create();
}

Map::~Map()
{
    int n = nodes->count();
    CCArray* childList;
    for (int i = 0; i < n; i ++)
    {
        childList = (CCArray*)&nodes[i];
        delete childList;
    }
    delete nodes;
    delete items;
}

class MapFactory
{
public:
    /**静态函数创建MapNode*/
    static MapNode* createMapNode(int col, int row);
};
NS_CC_END