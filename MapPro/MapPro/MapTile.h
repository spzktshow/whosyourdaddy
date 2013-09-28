//
//  MapTile.h
//  MapPro
//
//  Created by RockLee on 13-9-27.
//
//

#ifndef __MapPro__MapTile__
#define __MapPro__MapTile__

#include <iostream>
#include "cocos2d.h"
#include "MapNode.h"
#endif /* defined(__MapPro__MapTile__) */
NS_CC_BEGIN
class MapTile : public MapNode
{
public:
    MapTile(CCRect* rect, GNode* node);
    
    ~MapTile();
    
    int actionWeight;
};

MapTile::MapTile(CCRect* rect, GNode* node):MapNode::MapNode(rect, node)
{
    
}

MapTile::~MapTile()
{
    
}
NS_CC_END