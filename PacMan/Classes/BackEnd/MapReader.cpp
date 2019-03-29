#include "BackEnd/MapReader.h"
#include <2d/CCTMXTiledMap.h>
#include <2d/CCSprite.h>
#include <2d/CCTMXLayer.h>
#include "Game Objects/Others/Walls.h"

MapReader::MapReader(const cocos2d::TMXTiledMap* aMapToRead, cocos2d::Scene* aScene)
	:mapToRead(aMapToRead), sceneToAddObjectTo(aScene)
{
}

std::vector<Walls*> MapReader::readForWalls() const
{
	//Prep
	std::vector<Walls*> tempVecForReturn;
	cocos2d::TMXLayer *wallLayer = mapToRead->getLayer("Walls");
	const cocos2d::Size tileMapSize = mapToRead->getMapSize();
	cocos2d::Vec2 wallPosition(mapToRead->getPosition().x + 32, mapToRead->getPosition().y + 32 * tileMapSize.height);

	//Loop through every single tile
	for (size_t x = 0; x < static_cast<size_t>(tileMapSize.width); x++)
	{
		for (size_t y = 0; y < static_cast<size_t>(tileMapSize.height); y++)
		{
			if (wallLayer->getTileAt(cocos2d::Vec2(x, y)) != nullptr)
			{
				const cocos2d::Vec2 something(x, y);
				tempVecForReturn.push_back(new Walls(wallPosition, sceneToAddObjectTo));
			}
			wallPosition.y -= 32;
		}
		wallPosition.x += 32;
		wallPosition.y = mapToRead->getPosition().y + 32 * tileMapSize.height;

	}
	return tempVecForReturn;
}
