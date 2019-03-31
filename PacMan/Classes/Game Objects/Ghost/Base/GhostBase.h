#pragma once
#include "Game Objects/GameObjectBase.h"

//Class Forward Declare
namespace cocos2d
{
	class Sprite;
}
class Hitbox;

class GhostBase : public MovingGameObjectBase
{
protected:
	GhostBase(cocos2d::Scene* sceneToAddSprite, const std::string& fileName, const cocos2d::Vec2& aStartPosition, const float& aVelocity);
	
};
