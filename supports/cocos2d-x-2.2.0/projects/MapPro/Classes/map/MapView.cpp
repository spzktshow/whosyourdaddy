#include "MapView.h"
#include "MSGeometry.h"

USING_NS_CC;
USING_NS_MS;
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
	if (map)
	{
		CHECK_GL_ERROR_DEBUG();
		CCDirector* direct = CCDirector::sharedDirector();

		CCPoint a;
		a.x = 10;
		a.y = CoordinateUtils::calculateCoordinateSystem(10, direct->getWinSize());
		CCPoint b;
		b.x = 40;
		b.y = CoordinateUtils::calculateCoordinateSystem(40, direct->getWinSize());

		CCSize size;
		size.width = 50;
		size.height = 50;


		MSPoint3D topLeft(0, 0, 0);
		MSPoint3D topRight(50, 0, 0);
		MSPoint3D bottomLeft(0, 0, 50);
		MSPoint3D bottomRight(50, 0, 50);


		CCPoint tl = MapUtils::convertScreen(topLeft);
		CCPoint bl = MapUtils::convertScreen(bottomLeft);
		CCPoint tr = MapUtils::convertScreen(topRight);
		CCPoint br = MapUtils::convertScreen(bottomRight);

		tl.y = CoordinateUtils::calculateCoordinateSystem(tl.y, direct->getWinSize());
		bl.y = CoordinateUtils::calculateCoordinateSystem(bl.y, direct->getWinSize());
		tr.y = CoordinateUtils::calculateCoordinateSystem(tr.y, direct->getWinSize());
		br.y = CoordinateUtils::calculateCoordinateSystem(br.y, direct->getWinSize());

		ccDrawLine(tl, tr);	
		ccDrawLine(tr, br);	
		ccDrawLine(br, bl);	
		ccDrawLine(bl, tl);	
	}
	else
	{
		CCLayer::draw();
	}

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

/***********************MapBackGroud********************/
void MapBackGround::setMapData(Map* mapData)
{
	//2600 * 1300;
	CCSprite* background = CCSprite::create("HelloWorld.png");
	this->addChild(background);
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
