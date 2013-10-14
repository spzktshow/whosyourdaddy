//
//  MapData.cpp
//  HelloCpp
//
//  Created by RockLee on 13-9-30.
//
//

#include "MapData.h"

/*******Map*******/
Map::Map(MSNode* msNode)
{
	nodeData = msNode;

	createNodes();
}

Map::~Map()
{
	disposeNodes();
}

bool Map::checkNode(int rowIndex, int colIndex)
{
	if (rowIndex >= 0 && rowIndex < nodeData->matrix->row && colIndex >= 0 && colIndex < nodeData->matrix->col) return true;
	return false;
}

void Map::createNodes()
{
	nodes = new CCArray;
	for (int i = 0; i < nodeData->matrix->row; i ++)
	{
		CCArray* colList = 	new CCArray;
		for (int j = 0; j < nodeData->matrix->col; j ++)
		{
			MapNode* mapNode = MapFactory::createMapNode(i, j);
			colList->addObject(mapNode);
		}
		nodes->addObject(colList);
	}
}

void Map::disposeNodes()
{
	int n = nodes->count();
	int m;
	for (int i = 0; i < n; i ++)
	{
		CCArray* colList = (CCArray*) nodes->objectAtIndex(i);
		m = colList->count();
		for (int j = 0; j < n; j++)
		{
			delete colList->objectAtIndex(j);
		}
		delete colList;
	}
	delete nodes;
}

MapNode* Map::getMapNode(int rowIndex, int colIndex)
{
	if (checkNode(rowIndex, colIndex) == false) return NULL;
	CCArray* colList =  (CCArray*) nodes->objectAtIndex(rowIndex);
	return (MapNode*) colList->objectAtIndex(colIndex);
}

/*******MapFactory******/
MapNode* MapFactory::createMapNode(int rowIndex, int colIndex)
{
	MapNode* mapNode = new MapNode();
	MSNode* msNode = createNode(rowIndex, colIndex, 1, 1);
	mapNode->nodeData = msNode;
	mapNode->isClose = false;
	mapNode->isOpen = false;
	mapNode->f = 0;
	mapNode->g = 0;
	mapNode->h = 0;
	mapNode->actionWeight = 0;
	return mapNode;
}

MSNode* MapFactory::createNode(int rowIndex, int colIndex, int row, int col)
{
	MSNode* msNode = new MSNode(col, row, colIndex, rowIndex);
	return msNode;
}

/****************MapUtils******************/
bool MapUtils::checkAllow(MapNode* mapNode)
{
	if (mapNode->actionWeight >= 1) return false;
	return true;
}

bool MapUtils::checkNode(MapNode* a, MapNode* b)
{
	if (a->nodeData->matrixIndex->rowIndex == b->nodeData->matrixIndex->colIndex
		&& a->nodeData->matrixIndex->colIndex == b->nodeData->matrixIndex->colIndex)
	{
		return true;
	}
	return false;
}

int MapUtils::calculateH(MapNode* current, MapNode* end)
{
	return (abs(end->nodeData->matrixIndex->colIndex - current->nodeData->matrixIndex->colIndex) 
		+ abs(end->nodeData->matrixIndex->rowIndex - current->nodeData->matrixIndex->rowIndex)) * 10;
}

MapNode* MapUtils::getMinF(CCArray* openList)
{
	MapNode* mapNode = NULL;
	int n = openList->count();
	int index;
	for (int i = 0; i < n; i ++)
	{
		MapNode* checkNode = (MapNode*)openList->objectAtIndex(i);
		if (mapNode == NULL || checkNode->f < mapNode->f)
		{
			mapNode = checkNode;
			index = i;
		}
	}
	openList->removeObjectAtIndex(index);
	return mapNode;
}

void MapUtils::clearCloseList(CCArray* closeList)
{
	int n = closeList->count();
	for (int i = 0; i < n; i ++)
	{
		MapNode* mapNode = (MapNode*)closeList->objectAtIndex(i);
		mapNode->isClose = false;
	}
}

void MapUtils::clearOpenList(CCArray* openList)
{
	int n = openList->count();
	for (int i = 0; i < n; i ++)
	{
		MapNode* mapNode = (MapNode*)openList->objectAtIndex(i);
		mapNode->isOpen = false;
	}
}

MapNode* MapUtils::searchPath(int startRowIndex, int startColIndex, int endRowIndex, int endColIndex, Map* map)
{
	CCArray* openList = new CCArray;
	CCArray* closeList = new CCArray;
	MapNode* endNode = map->getMapNode(endRowIndex, endColIndex);
	MapNode* searchNode = map->getMapNode(startRowIndex, startColIndex);
	searchNode->g = 0;
	searchNode->h = MapUtils::calculateH(searchNode, endNode);
	searchNode->f = searchNode->g + searchNode->h;
	int g, f, h;
	const int NORMAL = 10;
	const int ANGLE = 14;
	while (searchNode->nodeData->matrixIndex->rowIndex != endRowIndex || searchNode->nodeData->matrixIndex->colIndex != endColIndex)
	{
		/***遍历点的四周****/
		int colIndex, rowIndex, col, row, i, j;
		row = min(searchNode->nodeData->matrixIndex->rowIndex + 2, map->nodeData->matrix->row);
		col = min(searchNode->nodeData->matrixIndex->colIndex + 2, map->nodeData->matrix->col);
		rowIndex = max(searchNode->nodeData->matrixIndex->rowIndex - 1, 0);
		colIndex = max(searchNode->nodeData->matrixIndex->colIndex - 1, 0);
		for (i = rowIndex; i < row; i ++)
		{

			for (j = colIndex; j < col; j ++)
			{
				MapNode* checkNode = map->getMapNode(i, j);
				/**是否和检测的节点相等**/
				bool b1 = MapUtils::checkNode(searchNode, checkNode);
				/**是否容许通过**/
				bool b2 = MapUtils::checkAllow(checkNode);
				/**斜角是否容许通过**/
				bool b3 = MapUtils::checkAllow(map->getMapNode(searchNode->nodeData->matrixIndex->rowIndex, checkNode->nodeData->matrixIndex->colIndex));
				/**斜角是否容许通过**/
				bool b4 = MapUtils::checkAllow(map->getMapNode(searchNode->nodeData->matrixIndex->colIndex, checkNode->nodeData->matrixIndex->rowIndex));
				if (b1 == true || b2 == false || b3 == false || b4 == false)
				{
					continue;
				}
				if (searchNode->nodeData->matrixIndex->rowIndex != checkNode->nodeData->matrixIndex->rowIndex
					&& searchNode->nodeData->matrixIndex->colIndex != checkNode->nodeData->matrixIndex->colIndex)
				{
					g = searchNode->g + ANGLE;
				}
				else
				{
					g = searchNode->g + NORMAL;
				}
				h = MapUtils::calculateH(checkNode, endNode);
				f = g + h;
				if (checkNode->isOpen == true || checkNode->isClose == true)
				{
					if (checkNode->f > f)
					{
						checkNode->f = f;
						checkNode->h = h;
						checkNode->g = g;
						checkNode->father = searchNode;
					}
				}
				else
				{
					checkNode->f = f;
					checkNode->h = h;
					checkNode->g = g;
					checkNode->father = searchNode;

					checkNode->isOpen = true;
					openList->addObject(checkNode);
				}
			}
		}
		searchNode->isClose = true;
		closeList->addObject(searchNode);
		if (openList->count() <= 0)
		{
			return NULL;
		}
		searchNode = MapUtils::getMinF(openList);/**获取f值最小的节点，并且从openList中删除**/
		searchNode->isOpen = false;
	}
	clearCloseList(closeList);
	clearOpenList(openList);
	delete openList;
	delete closeList;
	return searchNode;
}