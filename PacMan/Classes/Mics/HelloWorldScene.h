#pragma once
//Header Files
#include "cocos2d.h"
#include "Game Objects/Pacman/Pacman.h"
#include "BackEnd/InputManager.h"
#include "Game Objects/Others/Walls.h"
#include "BackEnd/CollisionDetection.h"

class Level1 : public cocos2d::Scene
{
	friend class CollisionDetection;

	Pacman *character;
	KeyBoardInputManager *keyboardManager;
	cocos2d::TMXTiledMap* map;
	Walls *wall;
	CollisionDetection *collisionDetector;

	std::vector<Walls*> wallList;

public:
	//Scene creation functions
    static cocos2d::Scene* createScene();
    bool init() override;  

	//Update functions
	void update(float delta) override;

    CREATE_FUNC(Level1);
};