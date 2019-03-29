/**
 * @author Mike Pham - 100706123
 * @author Rebecca Buckle - 100702016
 * @author Maija Kinnunen - 100697620
 */
#pragma once

//Header Files
#include <math/Vec2.h>

/**
 * @brief This class contains basic physics component for game objects
 * It can be used to update the new position for the object
 */
class PhysicsComponents
{
public:
	float velocity;
public:
	cocos2d::Vec2 position, direction, lastFramePosition;

	explicit PhysicsComponents(const cocos2d::Vec2 &aPosition, const float &aVelocity = 0, const cocos2d::Vec2 &aDirection = cocos2d::Vec2(1, 0));

	void update(const float& deltaT);
};

