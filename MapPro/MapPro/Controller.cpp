//
//  Controller.cpp
//  MapPro
//
//  Created by RockLee on 13-9-27.
//
//

#include "Controller.h"
#include <string>
NS_CC_BEGIN
using namespace std;
Controller::Controller()
{
    commands = new CCDictionary;
}

Controller::~Controller()
{
    delete commands;
}

void Controller::execute(const char *type, cocos2d::CCObject *data)
{
    
}

bool Controller::checkCommand(const char *type, cocos2d::Command *command)
{
    string typeStr = type;
    CCArray * typeCommandsList = getTypeCommandList(type);
    int i;
    int n = typeCommandsList->count();
    Command* compareCommand;
    for (i = 0; i < n; i ++)
    {
        compareCommand = (Command*) typeCommandsList->objectAtIndex(i);
        if (compareCommand == NULL) continue;
        if (compareCommand == command) return true;
    }
    return false;
}

void Controller::registerCommand(const char *type, cocos2d::Command *command)
{
    if (checkCommand(type, command) == false)
    {
        commands->setObject((CCObject*)command, type);
    }
}

CCArray* Controller::getTypeCommandList(const char *type)
{
    string typeStr = type;
    return (CCArray*) commands->objectForKey(typeStr);
}
NS_CC_END