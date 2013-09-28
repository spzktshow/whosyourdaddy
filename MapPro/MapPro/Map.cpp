//
//  Map.cpp
//  MapPro
//
//  Created by RockLee on 13-9-27.
//
//

#include "Map.h"
NS_CC_BEGIN
void Map::create()
{
    int i, j;
    for (i = 0; i < Map::node->matrix->col; i++) {
        CCArray* rowList = new CCArray;
        for (j = 0; j < Map::node->matrix->row; j++)
        {
//            //MapNode* rowNode = MapFactory::createMapNode();
//            rowList->addObject(rowNode);
        }
        nodes->addObject(rowList);
    }
}

MapNode* MapFactory::createMapNode(int col, int row)
{
//    GNode* createMapNodeGNode = new GNode(
//    CCRect* rect = new CCRect();
    return NULL;
}
NS_CC_END