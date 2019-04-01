#pragma once
#include "cocos2d.h"

//Class forward declared
class Hitbox;

/**
 * @brief This wall
 */
class Walls
{
	Hitbox *hitbox{ nullptr };
public:
	Walls(const cocos2d::Vec2& aPosition, cocos2d::Scene *aSceneToAddWall);
	~Walls();

	//Getter
	cocos2d::Rect getHitbox() const;
};

