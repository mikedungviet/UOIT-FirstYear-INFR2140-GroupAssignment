/*
 * 
 */
#include "HelloWorldScene.h"
#include "BackEnd/BackEnd.h"
#include "Game Objects/Ghost/Ghost.h"

USING_NS_CC;

Scene* LevelTest::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    const auto layer = LevelTest::create();

    scene->addChild(layer);

    return scene;
}

bool LevelTest::init()
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
	redGhost = new RedGhost(this, Vec2(1000, 500), 0);

	collisionDetector = new CollisionDetection(this);

	//Initiate keyboard input manager
	keyboardManager = new KeyBoardInputManager(character);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardManager->getListener(), this);

	this->scheduleUpdate();

    return true;
}

void LevelTest::update(float delta)
{
	character->update(delta);
	collisionDetector->checkForCollision();
	character->updateSprite();
}

