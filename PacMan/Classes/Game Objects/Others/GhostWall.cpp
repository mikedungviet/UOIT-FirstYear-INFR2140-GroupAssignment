#include "GhostWall.h"
#include "cocos2d.h"
#include "BackEnd/HitBox.h"

GhostWall::GhostWall(const cocos2d::Vec2& aPosition, cocos2d::Scene* aSceneToAddWall)
	:hitbox(new Hitbox(aPosition + cocos2d::Vec2(16,16),32,32))
{
}

cocos2d::Rect GhostWall::getHitbox() const
{
	return hitbox->getHitBox();
}
