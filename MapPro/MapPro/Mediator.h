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
#include "cocos2d.h"
#include "GroupItem.h"
#endif /* defined(__MapPro__Mediator__) */
NS_CC_BEGIN
class Mediator : public GroupItem
{
protected:
    /**监听数据变化*/
    virtual void addDataListeners();
    virtual void removeDataListeners();
};
NS_CC_END