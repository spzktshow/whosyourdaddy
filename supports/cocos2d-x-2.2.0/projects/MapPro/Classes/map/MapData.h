//
//  MapData.h
//  HelloCpp
//
//  Created by RockLee on 13-9-30.
//
//

#ifndef __HelloCpp__MapData__
#define __HelloCpp__MapData__

#include "MSGeometry.h"
#include <vector>
#include <cocos2d.h>
#include "MSMvc.h"

/*******MapNode***********/
class MapNode : public cocos2d::CCObject
{
public:
    moonSugar::MSNode* nodeData;

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
class MapItem : public cocos2d::CCObject
{
public:
    moonSugar::MSNode* nodeData;
};

/**********Map***************/
class Map : public cocos2d::CCObject
{
public:
    moonSugar::MSNode* nodeData;

	Map(moonSugar::MSNode* msNode);
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
    cocos2d::CCArray* nodes;
};

/***********MapUtils******/
class MapUtils : public cocos2d::CCObject
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

	/******ISO Map*****/
	static moonSugar::MSPoint3D convertIso(cocos2d::CCPoint & point);
	static cocos2d::CCPoint convertScreen(moonSugar::MSPoint3D & point3D);
private:
	/********获取openList中最小值的f节点**********/
	static MapNode* getMinF(cocos2d::CCArray* openList);
	/****************清理开放列表*****************/
	static void clearOpenList(cocos2d::CCArray* openList);
	/***************清理关闭列表***********************/
	static void clearCloseList(cocos2d::CCArray* closeList);
};

/********MapFactory********/
class MapFactory
{
public:
	static moonSugar::MSNode* createNode(int rowIndex, int colIndex, int row, int col);

	static moonSugar::MSNode3D* createNode3D(int xIndex, int yIndex, int zIndex, int x, int y, int z);
	static moonSugar::MSNode3D* createNode3D(int rowIndex, int colIndex, int row, int col);

	static MapNode* createMapNode(int rowIndex, int colIndex);
};

/********MapModel**********/
class MapModel : public moonSugar::MSModelData
{
public:
	MapModel();
	~MapModel();

	virtual void init();
	virtual void dispose();

	Map* map;
protected:
};
#endif /* defined(__HelloCpp__MapData__) */
