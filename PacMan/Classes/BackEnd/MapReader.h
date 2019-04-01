#pragma once
#include <vector>
#include <math/CCGeometry.h>


//class forward declare
class Walls;
class GhostWall;
namespace cocos2d
{
	class TMXTiledMap;
	class Scene;
}

/**
 *@brief This class will get the read layers of a tile map and
 */
class MapReader
{
	//Private members
	const cocos2d::TMXTiledMap* mapToRead;
	cocos2d::Scene *sceneToAddObjectTo;
	const cocos2d::Size tileMapSize;

	//Private member functions
	cocos2d::Vec2 getSmallestVec(const std::vector<cocos2d::Vec2>& vectorToCheck);
	cocos2d::Vec2 getLargestVec(const std::vector<cocos2d::Vec2>& vectorToCheck);
public:
	MapReader(const cocos2d::TMXTiledMap* aMapToRead, cocos2d::Scene* aScene);

	std::vector<Walls*> readForWalls() const;
	std::vector<GhostWall*> readForGhostWalls() const;
	cocos2d::Rect readGhostSpawnZone();
};