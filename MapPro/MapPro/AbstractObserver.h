//
//  AbstractObserver.h
//  MapPro
//
//  Created by RockLee on 13-9-27.
//
//

#ifndef __MapPro__AbstractObserver__
#define __MapPro__AbstractObserver__

#include <iostream>
#include "cocos2d.h"
#include "GroupItem.h"
#include <map.h>
#include <string>
#endif /* defined(__MapPro__AbstractObserver__) */
using namespace std;
NS_CC_BEGIN
class AbstractObserver : public GroupItem
{
public:
    /**纯虚函数，子类派生相应的逻辑，type为消息类型，data为数据*/
    virtual void handler(const char* type, CCObject* data);
    protected:
};
NS_CC_END