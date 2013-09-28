//
//  EventDispatcher.h
//  MapPro
//
//  Created by RockLee on 13-9-26.
//
//

#ifndef __MapPro__EventDispatcher__
#define __MapPro__EventDispatcher__

#include <iostream>
#include "cocos2d.h"
USING_NS_CC;
class EventDispatcher : public CCObject
{
public:
    EventDispatcher();
    ~EventDispatcher();
    void dispatchEvent(const char* eventType, CCObject* data);
    
    void addEventListener(const char* eventType, SEL_CallFuncO eventHandler);
    void removeEventListener(const char* eventType, SEL_CallFuncO eventHandler);
protected:
    CCArray* observers;
    //===func
    int checkObserver(const char* eventType);
};

#endif /* defined(__MapPro__EventDispatcher__) */