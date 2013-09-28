//
//  ModelData.h
//  MapPro
//
//  Created by RockLee on 13-9-26.
//
//

#ifndef __MapPro__ModelData__
#define __MapPro__ModelData__

#include "cocos2d.h"
#include "GroupItem.h"
USING_NS_CC;
class ModelData : public GroupItem
{
public:
    ModelData();
    ~ModelData();
protected:
    CCNotificationCenter* dispatcher;
};
#endif /* defined(__MapPro__ModelData__) */