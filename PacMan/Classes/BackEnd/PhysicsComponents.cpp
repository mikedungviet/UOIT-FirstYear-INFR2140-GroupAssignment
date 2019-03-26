/**
 * @author Mike Pham - 100706123
 * @author Rebecca Buckle - 100702016
 * @author Maija Kinnunen - 100697620
 */
#include "PhysicsComponents.h"

/**
 *
 * @param aPosition The beginning position of the object
 * @param aVelocity The velocity of the object
 * @param aDirection The direction that the object is facing or going
 * to move
 */
PhysicsComponents::PhysicsComponents(const cocos2d::Vec2 &aPosition, const float &aVelocity, const cocos2d::Vec2 &aDirection)
	: velocity(aVelocity), position(aPosition), direction(aDirection)
{
}

/**
 * @brief This function updates the physics part
 */
void PhysicsComponents::update(const float& deltaT)
{
	position += velocity * direction * deltaT;
}
