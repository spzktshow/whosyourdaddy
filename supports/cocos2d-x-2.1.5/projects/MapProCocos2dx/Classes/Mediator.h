//
//  Mediator.h
//  MapPro
//
//  Created by RockLee on 13-9-27.
//
//

#ifndef __MapPro__Mediator__
#define __MapPro__Mediator__

#include <iostream>
#include "GroupItem.h"
#include "cocos2d.h"
USING_NS_CC;
class Mediator : public GroupItem
{
protected:
    /**监听数据变化*/
    virtual void addDataListeners();
    virtual void removeDataListeners();

	void addDataListener(const char* eventType, SEL_CallFuncO eventHandler);
	void removeDataListener(const char* eventType);

	cocos2d::CCNotificationCenter* notificationCenter;
};
#endif /* defined(__MapPro__Mediator__) */