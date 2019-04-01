#include "BackEnd/MapReader.h"
#include <2d/CCTMXTiledMap.h>
#include <2d/CCSprite.h>
#include <2d/CCTMXLayer.h>
#include "Game Objects/Others/Walls.h"
#include "Game Objects/Others/GhostWall.h"

/**
 * @brief Initialize map reading tool
 */
MapReader::MapReader(const cocos2d::TMXTiledMap* aMapToRead, cocos2d::Scene* aScene)
	:mapToRead(aMapToRead), sceneToAddObjectTo(aScene), tileMapSize(mapToRead->getMapSize())
{
}

/**
 * @brief Finds the smallest vec2 in a vector container
 * @return Return cocos2d::Vec2
 */
cocos2d::Vec2 MapReader::getSmallestVec(const std::vector<cocos2d::Vec2>& vectorToCheck)
{
	cocos2d::Vec2 smallestVec(vectorToCheck[0]);

	for (auto i : vectorToCheck)
	{
		if (smallestVec > i)
			smallestVec = i;
	}
	return smallestVec;
}

/**
 * @brief Finds the largest vec2 in a vector container
 * @return Return cocos2d::Vec2
 */
cocos2d::Vec2 MapReader::getLargestVec(const std::vector<cocos2d::Vec2>& vectorToCheck)
{
	cocos2d::Vec2 largestVec;

	for (auto i : vectorToCheck)
	{
		if (largestVec < i)
			largestVec = i;
	}
	return largestVec;
}

/**
 * @brief Get the "Walls" layer and get all the Walls tile
 *
 * @return Return vector<Walls*>
 */
std::vector<Walls*> MapReader::readForWalls() const
{
	//Prepration
	std::vector<Walls*> tempVecForReturn;
	cocos2d::TMXLayer *wallLayer = mapToRead->getLayer("Walls");

	//Loop through every single tile and find the walls
	for (size_t x = 0; x < static_cast<size_t>(tileMapSize.width); x++)
	{
		for (size_t y = 0; y < static_cast<size_t>(tileMapSize.height); y++)
		{
			cocos2d::Sprite* currentTile = wallLayer->getTileAt(cocos2d::Vec2(x, y));
			if (currentTile != nullptr)
			{
				const cocos2d::Vec2 something(x, y);
				tempVecForReturn.push_back(new Walls(currentTile->getPosition() + mapToRead->getPosition(), sceneToAddObjectTo));
			}
		}
	}
	return tempVecForReturn;
}

/**
 * @brief Get the "Ghost Walls" layer and get all the Walls tile
 *
 * @return Return vector<GhostWalls*>
 */
std::vector<GhostWall*> MapReader::readForGhostWalls() const
{
	//Prepration
	std::vector<GhostWall*> tempVec;
	cocos2d::TMXLayer *wallLayer = mapToRead->getLayer("Ghost Walls");

	//Loop 
	for (size_t x = 0; x < static_cast<size_t>(tileMapSize.width); x++)
	{
		for (size_t y = 0; y < static_cast<size_t>(tileMapSize.height); y++)
		{
			cocos2d::Sprite* currentTile = wallLayer->getTileAt(cocos2d::Vec2(x, y));
			if (currentTile != nullptr)
			{
				const cocos2d::Vec2 something(x, y);
				tempVec.push_back(new GhostWall(currentTile->getPosition() + mapToRead->getPosition(), sceneToAddObjectTo));
			}
		}
	}
	return tempVec;
}

/**
 *@brief Reads the "Ghost Spawn Area" of the tile map to determine the
 *zone where the ghost will be spawned
 *
 *@return Return cocos2d::Rect
 */
cocos2d::Rect MapReader::readGhostSpawnZone()
{
	//Prepration
	std::vector<cocos2d::Vec2> tempVec;
	cocos2d::TMXLayer *wallLayer = mapToRead->getLayer("Ghost Spawn Area");

	//Loop
	for (size_t x = 0; x < static_cast<size_t>(tileMapSize.width); x++)
	{
		for (size_t y = 0; y < static_cast<size_t>(tileMapSize.height); y++)
		{
			cocos2d::Sprite* currentTile = wallLayer->getTileAt(cocos2d::Vec2(x, y));
			if (currentTile != nullptr)
			{
				const cocos2d::Vec2 something(x, y);
				tempVec.push_back(currentTile->getPosition() + mapToRead->getPosition());
			}
		}
	}

	//Calculate spawning rect
	const cocos2d::Vec2 smallestVec = getSmallestVec(tempVec);
	const cocos2d::Vec2 largestVec = getLargestVec(tempVec);
	const cocos2d::Size rectSize(largestVec - smallestVec);

	return cocos2d::Rect(smallestVec, rectSize);
}
