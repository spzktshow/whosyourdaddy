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
#include <cocos2d.h>

USING_NS_MS;
USING_NS_CC;

/*******MapNode***********/
class MapNode : public CCObject
{
public:
    MSNode* nodeData;
protected:
    /***行动权重，地图节点本质上不是地图上的物体，而是描述地图的最小单位**/
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
protected:
    
};

#endif /* defined(__HelloCpp__MapData__) */
