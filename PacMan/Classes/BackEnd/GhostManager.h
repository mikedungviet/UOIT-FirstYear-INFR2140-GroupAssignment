#pragma once
//Header Files
#include "Game Objects/Ghost/Ghost.h"

class GhostManager
{
public:
	GhostManager(const cocos2d::Rect &aSpawnArea, cocos2d::Scene* aScene);

private:
	//Private data members
	std::vector<GhostBase*> ghostList;
	RedGhost* redGhost;
	cocos2d::Rect spawnArea;

	//Private member functions
	cocos2d::Vec2 rollRandomSpawnVector() const;
};