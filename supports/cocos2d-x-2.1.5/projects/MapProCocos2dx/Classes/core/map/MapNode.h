//
//  MapNode.h
//  MapPro
//
//  Created by RockLee on 13-9-27.
//
//

#ifndef __MapPro__MapNode__
#define __MapPro__MapNode__

#include <iostream>
#include "cocos2d.h"
#include "GNode.h"
USING_NS_CC;
class MapNode : public CCObject
{
public:
    /**体型*/
    CCRect * rect;
    /**位置*/
    GNode* node;
    
    MapNode(CCRect* rect, GNode* node);
    
    ~MapNode();
};
#endif /* defined(__MapPro__MapNode__) */