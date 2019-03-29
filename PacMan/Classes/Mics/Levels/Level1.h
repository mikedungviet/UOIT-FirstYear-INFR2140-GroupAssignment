#pragma once
#include <2d/CCScene.h>
#include "Mics/Levels/LevelBase.h"

class Level1 : public cocos2d::Scene, public LevelBase
{
public:
	//Scene creation functions
	static cocos2d::Scene* createScene();
	bool init() override;

	//Update functions
	void update(float delta) override;

	CREATE_FUNC(Level1);
};
