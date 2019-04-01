#include "Mics/Levels/Level1.h"
#include "Game Objects/Pacman/Pacman.h"
#include "BackEnd/BackEnd.h"

cocos2d::Scene* Level1::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();
	const auto layer = Level1::create();

	scene->addChild(layer);

	return scene;
}

bool Level1::init()
{
	if (!Scene::init())
	{
		return false;
	}

	//Init map
	map = cocos2d::TMXTiledMap::create("TileMap/TileMap.tmx");
	map->setPosition(cocos2d::Vec2(500, 50));
	addChild(map,1);	

	//Init objects
	pacman = new Pacman(cocos2d::Vec2(950,405), this);

	//Init backend Tools
	collisionDetector = new CollisionDetection(this);
	keyBoardInputDetector = new KeyBoardInputManager(pacman);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyBoardInputDetector->getListener(), this);
	mapReader = new MapReader(map, this);

	//Init Walls
	wallList = mapReader->readForWalls();
	ghostWallList = mapReader->readForGhostWalls();
	spawnZoneForGhost = mapReader->readGhostSpawnZone();


	this->scheduleUpdate();
	return true;
}

void Level1::update(float delta)
{
	pacman->update(delta);
	collisionDetector->checkForCollision();
	pacman->updateSprite();
}

