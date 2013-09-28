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
	model = Model::getInstance();
}

Command::~Command()
{
	model = NULL;
}