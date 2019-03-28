#pragma once
#include "cocos2d.h"

//Class forward declared
class Hitbox;

class Walls
{
	Hitbox *hitbox{ nullptr };
	cocos2d::Vec2 position;

	/*
	 * TODO: Delete these data members when finish implementing collision system and tile map
	 */
	cocos2d::Sprite *sprite;
public:
	Walls(const cocos2d::Vec2& aPosition, cocos2d::Scene *aSceneToAddWall);
	~Walls();

	//Getter
	cocos2d::Rect  getHitbox() const;
	cocos2d::Vec2 getPosition() const;
};

