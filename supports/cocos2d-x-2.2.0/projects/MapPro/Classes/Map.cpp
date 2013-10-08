//
//  Map.cpp
//  HelloCpp
//
//  Created by RockLee on 13-10-4.
//
//

#include "Map.h"

Map::Map()
{
    mapScene = CCScene::create();
    
    //
    nodesLayer = CCLayer::create();
    mapScene->addChild(nodesLayer);
}

Map::~Map()
{
    mapScene = NULL;
    nodesLayer = NULL;
}