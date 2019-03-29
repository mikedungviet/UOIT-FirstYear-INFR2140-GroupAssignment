/*
 * 
 */
#include "HelloWorldScene.h"
#include "BackEnd/BackEnd.h"

USING_NS_CC;

Scene* Level1::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    const auto layer = Level1::create();

    scene->addChild(layer);

    return scene;
}

bool Level1::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

	//Initiate game map
	map = TMXTiledMap::create("TileMap.tmx");
	//map->setPosition(200, 100);
	//addChild(map,0,99);

	//Initiate game objects
	character = new Pacman(this);
	for (unsigned i = 904; i <= 1128; i += 32) 
	{
		auto wall = new Walls(Vec2(i, 500), this);
		wallList.push_back(wall);
	}

	collisionDetector = new CollisionDetection(this);

	//Initiate keyboard input manager
	keyboardManager = new KeyBoardInputManager(character);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardManager->getListener(), this);

	this->scheduleUpdate();

    return true;
}

void Level1::update(float delta)
{
	character->update(delta);
	collisionDetector->checkForCollision();

	character->updateSprite();
}

