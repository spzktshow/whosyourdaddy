//
//  MSMvc.cpp
//  HelloCpp
//
//  Created by RockLee on 13-9-29.
//
//

#include "MSMvc.h"

USING_NS_CC;
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
	init();
}

MSModelData::~MSModelData()
{
	dispose();
}

void MSModelData::init()
{
	notificationCenter = CCNotificationCenter::sharedNotificationCenter();
}

void MSModelData::dispose()
{
	notificationCenter = NULL;
}

NS_MS_END;