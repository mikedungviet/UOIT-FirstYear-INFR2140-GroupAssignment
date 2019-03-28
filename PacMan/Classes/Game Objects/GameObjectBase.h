/**
 * @author Mike Pham - 100706123
 * @author Rebecca Buckle - 100702016
 * @author Maija Kinnunen - 100697620
 */
#pragma once

//Header Files
#include "BackEnd/HitBox.h"
#include "cocos2d.h"
#include "BackEnd/PhysicsComponents.h"

/**
 * @brief This class is the base class for all game objects
 */
class MovingGameObjectBase
{
protected:
	//Shared data members with other derived classes
	PhysicsComponents *physicsComponents;
	Hitbox *hitbox;
	cocos2d::Sprite *sprite;

	//Protected constructors
	MovingGameObjectBase(cocos2d::Scene* sceneToAddSprite, const std::string& aFileName, const cocos2d::Vec2& aStartPosition, const float& aVelocity);
public:
	virtual ~MovingGameObjectBase();

	//Getters
	cocos2d::Rect getHitbox() const;
	PhysicsComponents* getPhysicsComponent() const;
	cocos2d::Sprite* getSprite() const;

	virtual void update(const float& deltaTime);
};

