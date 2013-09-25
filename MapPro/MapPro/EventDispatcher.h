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
#include "CCArray.h"

#endif /* defined(__MapPro__EventDispatcher__) */
NS_CC_BEGIN
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
NS_CC_END