//
//  Command.h
//  MapPro
//
//  Created by RockLee on 13-9-27.
//
//

#ifndef __MapPro__Command__
#define __MapPro__Command__

#include <iostream>
#include "cocos2d.h"
#include "Model.h"
#include "ModelData.h"
/**
 业务逻辑命令Command，可以直接持有model层的引用，改变model数据
 */
using namespace cocos2d;
class Command
{
public:
	Command();
	~Command();
    /**业务逻辑执行函数，data可以为Null*/
    virtual void execute(const char* type, CCObject* data);
protected:
    /**持有model层的引用，可以从model获取相应的data进行改变*/
    ModelData* getModelData(const char* type);
};
#endif /* defined(__MapPro__Command__) */