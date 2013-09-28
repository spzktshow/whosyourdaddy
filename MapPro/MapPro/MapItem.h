//
//  MapItem.h
//  MapPro
//
//  Created by RockLee on 13-9-27.
//
//

#ifndef __MapPro__MapItem__
#define __MapPro__MapItem__

#include <iostream>
#include "cocos2d.h"
#include "MapNode.h"
#endif /* defined(__MapPro__MapItem__) */
NS_CC_BEGIN
class MapItem : public MapNode
{
public:
    MapItem(CCRect* rect, GNode* node);
    ~MapItem();
};

MapItem::MapItem(CCRect* rect, GNode* node):MapNode::MapNode(rect, node)
{
    
}

MapItem::~MapItem()
{
    
}
NS_CC_END