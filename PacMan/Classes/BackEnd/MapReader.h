#pragma once
#include <vector>


//class forward declare
class Walls;
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
	const cocos2d::TMXTiledMap* mapToRead;
	cocos2d::Scene *sceneToAddObjectTo;
public:
	MapReader(const cocos2d::TMXTiledMap* aMapToRead, cocos2d::Scene* aScene);

	std::vector<Walls*> readForWalls() const;
};