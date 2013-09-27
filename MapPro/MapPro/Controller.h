//
//  Controller.h
//  MapPro
//
//  Created by RockLee on 13-9-27.
//
//

#ifndef __MapPro__Controller__
#define __MapPro__Controller__

#include <iostream>
#include "cocos2d.h"
#include <string>
#include "Command.h"
#endif /* defined(__MapPro__Controller__) */
NS_CC_BEGIN
class Controller
{
public:
    Controller();
    ~Controller();
    void execute(const char* type, CCObject* data);
    void registerCommand(const char* type, Command* command);
    void unRegisterCommand(const char* type, Command* command);
    void unRegisterAll();
    bool checkCommand(const char* type, Command* command);
protected:
    /**向controller中注册的命令的hash列表
     */
    CCDictionary* commands;
    CCArray* getTypeCommandList(const char* type);
};
NS_CC_END