#include "Game Objects/Ghost/Base/GhostBase.h"

GhostBase::GhostBase(cocos2d::Scene* sceneToAddSprite, const std::string& fileName,
	const cocos2d::Vec2& aStartPosition, const float& aVelocity)
	:MovingGameObjectBase(sceneToAddSprite, fileName, aStartPosition, aVelocity)
{
}
