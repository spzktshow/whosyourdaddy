//
//  MapNode.cpp
//  MapPro
//
//  Created by RockLee on 13-9-27.
//
//

#include "MapNode.h"
MapNode::MapNode(CCRect* rect, GNode* node)
{
	this->rect = rect;
	this->node = node;
}

MapNode::~MapNode()
{
	delete node;
	delete rect;
}