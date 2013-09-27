//
//  ModelData.h
//  MapPro
//
//  Created by RockLee on 13-9-26.
//
//

#ifndef __MapPro__ModelData__
#define __MapPro__ModelData__

#include <iostream>
#include "cocos2d.h"
#include "GroupItem.h"
#endif /* defined(__MapPro__ModelData__) */
NS_CC_BEGIN
class ModelData : public GroupItem
{
public:
    ModelData();
    ~ModelData();
protected:
    CCNotificationCenter* dispatcher;
};
NS_CC_END