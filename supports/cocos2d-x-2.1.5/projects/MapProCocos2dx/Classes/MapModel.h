#pragma once

#include "ModelData.h"
#include "Map.h"
class MapModel : public ModelData
{
public:
	MapModel();
	~MapModel();

	void createMap();
protected:
	/**µØÍ¼Êý¾Ý*/
	Map* map;

};