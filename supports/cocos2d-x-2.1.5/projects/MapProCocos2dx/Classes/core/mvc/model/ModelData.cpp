//
//  ModelData.cpp
//  MapPro
//
//  Created by RockLee on 13-9-26.
//
//

#include "ModelData.h"
USING_NS_CC;
ModelData::ModelData():GroupItem()
{
    dispatcher = new CCNotificationCenter;
}

ModelData::~ModelData()
{
    delete dispatcher;
}