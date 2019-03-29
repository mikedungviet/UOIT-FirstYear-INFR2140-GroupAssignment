#pragma once
#include <vector>

//Class Forward Declare
class Pacman;
class Walls;
class CollisionDetection;
class KeyBoardInputManager;
class MapReader;

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
	std::vector<Walls*> wallList;
	cocos2d::TMXTiledMap *map;

	//Protected Backend Tools
	CollisionDetection *collisionDetector;
	KeyBoardInputManager *keyBoardInputDetector;
	MapReader* mapReader;

};
