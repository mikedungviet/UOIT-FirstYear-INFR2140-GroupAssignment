#pragma once
#include <vector>
#include <math/CCGeometry.h>

//Class Forward Declare
class Pacman;
class Walls;
class CollisionDetection;
class KeyBoardInputManager;
class MapReader;
class GhostWall;

namespace cocos2d 
{
	class TMXTiledMap;
}

class LevelBase
{
protected:
	//Protected constructor
	LevelBase() = default;

	//Friend Classes
	friend class CollisionDetection;

	//Protected Data members
	Pacman *pacman;
	
	cocos2d::TMXTiledMap *map;
	std::vector<Walls*> wallList;
	std::vector<GhostWall*> ghostWallList;
	cocos2d::Rect spawnZoneForGhost;

	//Protected Backend Tools
	CollisionDetection *collisionDetector;
	KeyBoardInputManager *keyBoardInputDetector;
	MapReader* mapReader;

};
