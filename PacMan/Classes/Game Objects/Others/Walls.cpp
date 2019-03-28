#include "Walls.h"
#include "BackEnd/HitBox.h"


Walls::Walls(const cocos2d::Vec2& aPosition, cocos2d::Scene *aSceneToAddWall)
	: hitbox(new Hitbox(aPosition, 32, 32)), position(aPosition),
	//Delete this after
	sprite(cocos2d::Sprite::create("TileMap/Walls.png"))
{
	sprite->setPosition(aPosition);
	aSceneToAddWall->addChild(sprite);
}


Walls::~Walls()
{
	delete hitbox;
	sprite->removeFromParentAndCleanup(true);
}

/**
 * @brief This function returns the hitbox of the wall
 *
 * @return Return the wall's hitbox as cocos2d::Rect
 */
cocos2d::Rect Walls::getHitbox() const
{
	return hitbox->getHitBox();
}

/**
 * @brief This function returns the position of the wall
 * 
 * @return Return the wall's position as cocos2d::Vec2
 */
cocos2d::Vec2 Walls::getPosition() const
{
	return position;
}
