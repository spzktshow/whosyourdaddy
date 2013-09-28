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
#endif /* defined(__MapPro__MapNode__) */
NS_CC_BEGIN
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

MapNode::MapNode(CCRect* rect, GNode* node)
{
    this->rect = rect;
    this->node = node;
}

MapNode::~MapNode()
{
    delete node;
    delete rect;
}
NS_CC_END