//
//  ModelData.cpp
//  MapPro
//
//  Created by RockLee on 13-9-26.
//
//

#include "ModelData.h"
NS_CC_BEGIN
ModelData::ModelData():cocos2d::GroupItem()
{
    dispatcher = new CCNotificationCenter;
}

ModelData::~ModelData()
{
    delete dispatcher;
}
NS_CC_END