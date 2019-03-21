#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    const auto layer = HelloWorld::create();

    scene->addChild(layer);

    return scene;
}

bool HelloWorld::init()
{
	Texture2D::TexParams tp = { GL_NEAREST, GL_NEAREST, GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE };
    if ( !Scene::init() )
    {
        return false;
    }
   
    auto label = Label::createWithSystemFont("Pac-Man", "Arial", 96);
    label->setAnchorPoint(cocos2d::Vec2(0.0, 0.0));
    this->addChild(label, 1);

	// Player
	pacman = Pacman::create("Pacman0001.png");
	pacman->getTexture()->setTexParameters(tp);
	pacman = Pacman::create("Pacman0002.png");
	pacman->getTexture()->setTexParameters(tp);
	pacman = Pacman::create("Pacman0003.png");
	pacman->getTexture()->setTexParameters(tp);
	pacman = Pacman::create("Pacman0004.png");
	pacman->getTexture()->setTexParameters(tp);
	pacman->setScale(4);
	pacman->setPosition(cocos2d::Vec2(200.0f, 200.0f));

	// Blue Ghost
	blueghost = Ghost::create("BlueGhost0001.png", 1);
	blueghost->getTexture()->setTexParameters(tp);
	blueghost = Ghost::create("BlueGhost_Wiggle0001.png", 1);
	blueghost->getTexture()->setTexParameters(tp);
	blueghost->setScale(4);
	blueghost->setPosition(cocos2d::Vec2(200.0f, 300.0f));

	// Red Ghost
	redghost = Ghost::create("RedGhost0000.png", 2);
	redghost->getTexture()->setTexParameters(tp);
	redghost = Ghost::create("RedGhost_Wiggle0001.png", 2);
	redghost->getTexture()->setTexParameters(tp);
	redghost->setScale(4);
	redghost->setPosition(cocos2d::Vec2(250.0f, 300.0f));

	// Orange Ghost
	orangeghost = Ghost::create("OrangeGhost0001.png", 3);
	orangeghost->getTexture()->setTexParameters(tp);
	orangeghost = Ghost::create("OrangeGhost_Wiggle0001.png", 3);
	orangeghost->getTexture()->setTexParameters(tp);
	orangeghost->setScale(4);
	orangeghost->setPosition(cocos2d::Vec2(300.0f, 300.0f));

	// Pink Ghost
	pinkghost = Ghost::create("PinkGhost0001.png", 4);
	pinkghost->getTexture()->setTexParameters(tp);
	pinkghost = Ghost::create("PinkGhost_Wiggle0001.png", 4);
	pinkghost->getTexture()->setTexParameters(tp);
	pinkghost->setScale(4);
	pinkghost->setPosition(cocos2d::Vec2(350.0f, 300.0f));

	this->addChild(pacman, 3);
	this->addChild(blueghost, 3);
	this->addChild(redghost, 3);
	this->addChild(orangeghost, 3);
	this->addChild(pinkghost, 3);

    return true;
}