//
//  Map.h
//  HelloCpp
//
//  Created by RockLee on 13-10-4.
//
//

#ifndef __HelloCpp__Map__
#define __HelloCpp__Map__

#include <cocos2d.h>
#include "MoonSugar.h"
USING_NS_CC;
USING_NS_MS;

class MapNodeLayer : public CCLayer
{
public:
    virtual void draw();
};

class Map
{
public:
    Map();
    ~Map();
protected:
    // 场景
    CCScene* mapScene;
    //地图节点层
    MapNodeLayer* nodesLayer;
};
#endif /* defined(__HelloCpp__Map__) */
