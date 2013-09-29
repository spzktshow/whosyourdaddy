//
//  Mediator.cpp
//  MapPro
//
//  Created by RockLee on 13-9-27.
//
//

#include "Mediator.h"

void Mediator::addDataListener(const char* eventType, SEL_CallFuncO eventHandler)
{
	notificationCenter->addObserver(this, eventHandler, eventType, NULL);
}

void Mediator::removeDataListener(const char* eventType)
{
	notificationCenter->removeObserver(this, eventType);
}