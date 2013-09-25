//
//  EventDispatcher.cpp
//  MapPro
//
//  Created by RockLee on 13-9-26.
//
//

#include "EventDispatcher.h"
NS_CC_BEGIN
EventDispatcher::EventDispatcher()
{
    EventDispatcher::observers = new CCArray();
}

EventDispatcher::~EventDispatcher()
{
    delete EventDispatcher::observers;
}

void EventDispatcher::dispatchEvent(const char* eventType, CCObject* data)
{
    int index = checkObserver(eventType);
    if (index != -1)
    {
        CCNotificationObserver* observer = (CCNotificationObserver*)observers->objectAtIndex(index);
        if (NULL == observer) return;
        observer->performSelector(data);

    }
}

void EventDispatcher::addEventListener(const char *eventType, SEL_CallFuncO eventHandler)
{
    if (checkObserver(eventType) != -1) {
        return;
    }
    CCNotificationObserver * observer = new CCNotificationObserver(this, eventHandler, eventType, NULL);//new
    observers->addObject(observer);
}

void EventDispatcher::removeEventListener(const char* eventType, SEL_CallFuncO eventHandler)
{
    int index = checkObserver(eventType);
    if (index != -1)
    {
        observers->removeObjectAtIndex(index, true);//delete
    }
}

int EventDispatcher::checkObserver(const char *eventType)
{
    CCObject* obj = NULL;
    int index = 0;
    CCARRAY_FOREACH(EventDispatcher::observers, obj)
    {
        CCNotificationObserver* observer = (CCNotificationObserver*) obj;
        if (NULL == observer)
            continue;
        if (0 == strcmp(observer->getName(), eventType))
        {
            return index;
        }
        index ++;
    }
    return -1;
}
NS_CC_END