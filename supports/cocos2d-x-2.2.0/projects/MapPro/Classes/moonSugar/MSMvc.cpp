//
//  MSMvc.cpp
//  HelloCpp
//
//  Created by RockLee on 13-9-29.
//
//

#include "MSMvc.h"

NS_MS_BEGIN

/*****************model****************/
MSModel* MSModel::model;

MSModel* MSModel::getInstance()
{
    if (NULL == model)
    {
        model = new MSModel;
    }
    return model;
}

void MSModel::release()
{
    delete model;
}
/***************modelData***************/

MSModelData::MSModelData()
{
    notificationCenter = CCNotificationCenter::sharedNotificationCenter();
}

MSModelData::~MSModelData()
{
    notificationCenter = NULL;
}
NS_MS_END;