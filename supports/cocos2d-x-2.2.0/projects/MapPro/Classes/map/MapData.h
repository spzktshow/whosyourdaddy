//
//  MapData.h
//  HelloCpp
//
//  Created by RockLee on 13-9-30.
//
//

#ifndef __HelloCpp__MapData__
#define __HelloCpp__MapData__

#include "MoonSugar.h"
#include "MSGeometry.h"
#include <vector>
#include <cocos2d.h>
#include <math.h>

USING_NS_MS;
USING_NS_CC;

/*******MapNode***********/
class MapNode : public CCObject
{
public:
    MSNode* nodeData;

	/**h+g**/
	int f;
	/**当前点到终点的消费**/
	int g;
	/**起点到当前点的消费**/
	int h;

	/**寻路父节点**/
	MapNode* father;

	/**是否在开放列表中**/
	bool isOpen;
	/**是否在关闭列表中**/
	bool isClose;
	/***行动权重，地图节点本质上不是地图上的物体，而是描述地图的最小单位**/
	/**暂时只有是否能行走，所以当actionWeight>=1时为不能行走<1时能行走**/
	int actionWeight;
};

/**********MapItem********/
class MapItem : public CCObject
{
public:
    MSNode* nodeData;
};

/**********Map***************/
class Map : public CCObject
{
public:
    MSNode* nodeData;

	Map(MSNode* msNode);
	~Map();

	/**检测节点是否合法**/
	bool checkNode(int rowIndex, int colIndex);
	/**创建节点序列**/
	void createNodes();
	/**根据矩阵索引获取节点**/
	MapNode* getMapNode(int rowIndex, int colIndex);

	/**销毁节点**/
	void disposeNodes();
protected:
    CCArray* nodes;
};

/***********MapUtils******/
class MapUtils : public CCObject
{
public:
	/**寻路方法**/
	static MapNode* searchPath(int startRowIndex, int startColIndex, int endRowIndex, int endColIndex, Map* map);
	/***检测是否可以通过**/
	static bool checkAllow(MapNode* mapNode);
	/****判断两个节点是否相等***/
	static bool checkNode(MapNode* a, MapNode* b);
	/*****计算当前节点到终点的h值***/
	static int calculateH(MapNode* current, MapNode* end);
	/********获取openList中最小值的f节点**********/
	static MapNode* getMinF(CCArray* openList);
	/****************清理开放列表*****************/
	static void clearOpenList(CCArray* openList);
	/***************清理关闭列表***********************/
	static void clearCloseList(CCArray* closeList);
};

/********MapFactory********/
class MapFactory
{
public:
	static MSNode* createNode(int rowIndex, int colIndex, int row, int col);

	static MapNode* createMapNode(int rowIndex, int colIndex);
};

#endif /* defined(__HelloCpp__MapData__) */
