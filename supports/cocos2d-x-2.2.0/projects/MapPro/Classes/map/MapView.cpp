#include "MapView.h"

USING_NS_CC;
/******************MapView**********************/
void MapView::setMapData(Map* mapData)
{
	map = mapData;
}



/******************MapTileLayer************************/
MapTileLayer::MapTileLayer()
{

}

MapTileLayer::~MapTileLayer()
{

}

void MapTileLayer::draw()
{
	//CCLayer::draw();
	CHECK_GL_ERROR_DEBUG();
	CCPoint a;
	a.x = 10;
	a.y = 10;
	CCPoint b;
	b.y = 40;
	b.x = 40;
	ccDrawLine(a, b);
}

bool MapTileLayer::init()
{
	if (!CCLayer::init()) return false;
	return true;
}

MapTileLayer* MapTileLayer::create()
{
	MapTileLayer* mapTileLayer = new MapTileLayer;
	if (mapTileLayer && mapTileLayer->init())
	{
		mapTileLayer->autorelease();
		return mapTileLayer;
	}
	else
	{
		CC_SAFE_DELETE(mapTileLayer);
		return NULL;
	}
}

/***************************MapScene*********************/
MapScene::MapScene()
{

}

MapScene::~MapScene()
{

}

MapScene* MapScene::create()
{
	MapScene * mapScene = new MapScene();
	if (mapScene && mapScene->init())
	{
		mapScene->autorelease();
		return mapScene;
	}
	else
	{
		CC_SAFE_DELETE(mapScene);
		return NULL;
	}
}

bool MapScene::init()
{
	bool inited = false;
	do 
	{
		CCDirector * pDirector;
		CC_BREAK_IF(! (pDirector = CCDirector::sharedDirector()) );
		this->setContentSize(pDirector->getWinSize());

		inited = true;
	} while (0);
	return inited;
}
