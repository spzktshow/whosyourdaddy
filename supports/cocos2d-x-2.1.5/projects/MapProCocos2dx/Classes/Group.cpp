//
//  Group.cpp
//  MapPro
//
//  Created by RockLee on 13-9-26.
//
//

#include "Group.h"

using namespace cocos2d;
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

GroupItem* Group::getItem(const char *name)
{
    int i = checkItem(name);
    if (i != -1)
    {
        return (GroupItem*)items->objectAtIndex(i);
    }
    return NULL;
}


GroupItem* Group::getItemIndex(unsigned int index)
{
    if (index < items->count())
    {
        return (GroupItem*)items->objectAtIndex(index);
    }
    return NULL;
}

int Group::addItem(GroupItem *groupItem)
{
    return addItemIndex(groupItem, items->count());
}

int Group::addItemIndex(GroupItem *groupItem, unsigned int index)
{
    int i = checkItem(groupItem->name);
    if (i == -1)
    {
        items->insertObject((CCObject*)groupItem, index);
        return index;
    }
    return i;
}

GroupItem* Group::removeItemIndex(unsigned int index)
{
    GroupItem* groupItem = getItemIndex(index);
    if (groupItem)
    {
        items->removeObjectAtIndex(index);
    }
    return groupItem;
}

GroupItem* Group::removeItem(const char *name)
{
    int index = checkItem(name);
    if (index != -1)
    {
        return removeItemIndex(index);
    }
    return NULL;
}

void Group::removeAll()
{
    items->removeAllObjects();
}