//
//  Command.cpp
//  MapPro
//
//  Created by RockLee on 13-9-27.
//
//

#include "Command.h"
Command::Command()
{
	
}

Command::~Command()
{
	
}

void Command::execute(const char *type, CCObject *data)
{
    
}

ModelData* Command::getModelData(const char *type)
{
    Model* model = Model::getInstance();
    ModelData* modelData = (ModelData*) model->getItem(type);
    return modelData;
}