#include "Walls.h"
#include "BackEnd/HitBox.h"


Walls::Walls(const cocos2d::Vec2& aPosition, cocos2d::Scene *aSceneToAddWall)
	: hitbox(new Hitbox(aPosition + cocos2d::Vec2(16,16),32,32))
{/*Empty*/}

/**
 * @brief Delete any dynamically allocated data members
 */
Walls::~Walls()
{
	delete hitbox;
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
