//
//  Group.h
//  MapPro
//
//  Created by RockLee on 13-9-26.
//
//

#ifndef __MapPro__Group__
#define __MapPro__Group__

#include <iostream>
#include "cocos2d.h"
#include "GroupItem.h"
#endif /* defined(__MapPro__Group__) */
NS_CC_BEGIN
class Group
{
public:
    Group();
    ~Group();
    int checkItem(const char *name);
int addItem(GroupItem *groupItem);
GroupItem* removeItem(const char *name);
protected:
    CCArray* items;
};
NS_CC_END