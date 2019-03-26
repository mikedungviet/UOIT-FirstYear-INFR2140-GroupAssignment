#pragma once

#include "cocos2d.h"
#include "Game Objects/Pacman/Pacman.h"
#include "BackEnd/InputManager.h"

class Level1 : public cocos2d::Scene
{
	Pacman *character;
	KeyBoardInputManager *keyboardManager;

public:
	//Scene creation functions
    static cocos2d::Scene* createScene();
    bool init() override;  

	//Update functions
	void update(float delta) override;

    CREATE_FUNC(Level1);
};