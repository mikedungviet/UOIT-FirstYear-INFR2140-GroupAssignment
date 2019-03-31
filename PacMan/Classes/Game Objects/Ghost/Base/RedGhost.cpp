#include "Game Objects/Ghost/Base/RedGhost.h"
#include "cocos2d.h"

RedGhost::RedGhost(cocos2d::Scene* sceneToAddSprite, const cocos2d::Vec2& aStartPosition, const float& aVelocity)
	: GhostBase(sceneToAddSprite, "Ghosts/RedGhost.png",aStartPosition, aVelocity)
{
	
}
