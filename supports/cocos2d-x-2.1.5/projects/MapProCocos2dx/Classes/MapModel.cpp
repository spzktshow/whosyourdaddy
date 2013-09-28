#include "MapModel.h"

MapModel::MapModel()
{
	createMap();
}

MapModel::~MapModel()
{
	delete map;
}

void MapModel::createMap()
{
	CCRect* rect = new CCRect;
	GNode* gNode = new GNode(50, 50, 1, 1);
	map = new Map(rect, gNode);
}