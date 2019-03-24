/*
 * 
 */
#include "HelloWorldScene.h"

USING_NS_CC;

#define KEYCODE cocos2d::EventKeyboard::KeyCode

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

	//Initiate game objects
	character = new Pacman(this);

	//Initiate keyboard manager
	keyboardManager = new KeyBoardInputManager(character);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardManager->getListener(), this);

	this->scheduleUpdate();

    return true;
}

void Level1::update(float delta)
{
	character->update(delta);
}

