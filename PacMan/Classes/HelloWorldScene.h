#pragma once

#include "Pacman.h"
#include "Ghost.h"
#include "cocos2d.h"

class HelloWorld : public cocos2d::Scene
{
protected:
	Ghost * blueghost;
	Ghost * redghost;
	Ghost * orangeghost;
	Ghost * pinkghost;
	Pacman * pacman;
public:
    static cocos2d::Scene* createScene();
    virtual bool init();  
    
    CREATE_FUNC(HelloWorld);
};

class Level1 : public HelloWorld
{
	virtual bool init() override;
	CREATE_FUNC(Level1);
};