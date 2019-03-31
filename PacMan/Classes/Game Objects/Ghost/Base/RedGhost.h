#pragma once
#include "Game Objects/Ghost/Base/GhostBase.h"

namespace cocos2d
{
	
}


class RedGhost: public GhostBase
{
public:
	RedGhost(cocos2d::Scene* sceneToAddSprite, const cocos2d::Vec2& aStartPosition, const float& aVelocity);
};