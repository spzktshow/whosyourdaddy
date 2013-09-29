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
#include "MapNode.h"
class MapItem : public MapNode
{
public:
    MapItem(CCRect* rect, GNode* node);
    ~MapItem();
};
#endif /* defined(__MapPro__MapItem__) */