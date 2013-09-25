//
//  Group.cpp
//  MapPro
//
//  Created by RockLee on 13-9-26.
//
//

#include "Group.h"
NS_CC_BEGIN
Group::Group()
{
    items = new CCArray();
}
Group::~Group()
{
    delete items;
}
int Group::checkItem(const char *name)
{
    int n = items->count();
    int i;
    GroupItem *item = NULL;
    for (i = 0; i < n; i++) {
        item = (GroupItem*)items->objectAtIndex(i);
        if (item && strcmp(item->name, name) == 0) {
            return i;
        }
    }
    return -1;
}
NS_CC_END