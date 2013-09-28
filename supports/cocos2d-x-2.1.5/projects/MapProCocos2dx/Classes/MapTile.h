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
USING_NS_CC;
class MapTile : public MapNode
{
public:
    MapTile(CCRect* rect, GNode* node);
    
    ~MapTile();
    
    int actionWeight;
};
#endif /* defined(__MapPro__MapTile__) */