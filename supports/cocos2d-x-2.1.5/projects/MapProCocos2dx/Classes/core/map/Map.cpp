//
//  Map.cpp
//  MapPro
//
//  Created by RockLee on 13-9-27.
//
//

#include "Map.h"
Map::Map(CCRect* rect, GNode* node):MapNode(rect, node)
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

void Map::create()
{
	int i, j;
	for (i = 0; i < Map::node->matrix->col; i++) {
		CCArray* rowList = new CCArray;
		for (j = 0; j < Map::node->matrix->row; j++)
		{
			MapNode* rowNode = MapFactory::createMapNode(i, j);
			rowList->addObject(rowNode);
		}
		nodes->addObject(rowList);
	}
}

MapNode* Map::getMapNode(int colIndex, int rowIndex)
{
	if (checkMapNode(colIndex, rowIndex) == false) return NULL;
	CCArray* rowList = (CCArray*) nodes->objectAtIndex(rowIndex);
	return (MapNode*) rowList->objectAtIndex(colIndex);
}

bool Map::checkMapNode(int colIndex, int rowIndex)
{
	if (colIndex < Map::node->matrix->col && rowIndex < Map::node->matrix->row) return true;
	return false;
}

MapNode* MapFactory::createMapNode(int colIndex, int rowIndex)
{
    GNode* createMapNodeGNode = new GNode(1, 1, colIndex, rowIndex);
    CCRect* rect = new CCRect();
	MapNode* returnMapNode = new MapNode(rect, createMapNodeGNode);
    return returnMapNode;
}