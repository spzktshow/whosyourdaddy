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

using namespace cocos2d;
class Group
{
public:
    Group();
    ~Group();
    
    int checkItem(const char *name);
    GroupItem* getItem(const char *name);
    GroupItem* getItemIndex(unsigned int index);
    
    int addItem(GroupItem *groupItem);
    int addItemIndex(GroupItem *groupItem, unsigned int index);
    
    GroupItem* removeItem(const char *name);
    GroupItem* removeItemIndex(unsigned int index);
    void removeAll();
protected:
    CCArray* items;
};
#endif /* defined(__MapPro__Group__) */