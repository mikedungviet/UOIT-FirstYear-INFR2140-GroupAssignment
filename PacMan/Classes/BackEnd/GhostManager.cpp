#include "BackEnd/GhostManager.h"

GhostManager::GhostManager(const cocos2d::Rect& aSpawnArea, cocos2d::Scene* aScene)
	:spawnArea(aSpawnArea)
{
	redGhost = new RedGhost(aScene, rollRandomSpawnVector(), 0);
	ghostList.push_back(redGhost);
}


cocos2d::Vec2 GhostManager::rollRandomSpawnVector() const
{
	cocos2d::Vec2 spawningVec;
	//Get random number of each side
	spawningVec.x = cocos2d::RandomHelper::random_real(spawnArea.getMinX(), spawnArea.getMaxX());
	spawningVec.y = cocos2d::RandomHelper::random_real(spawnArea.getMinY(), spawnArea.getMaxY());

	//Return
	return spawningVec;
}
