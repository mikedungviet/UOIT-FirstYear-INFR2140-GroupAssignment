/**
 * @author Mike Pham - 100706123
 * @author Rebecca Buckle - 100702016
 * @author Maija Kinnunen - 100697620
 */
#pragma once

//Header Files
#include "BackEnd/HitBox.h"
#include "BackEnd/PhysicsComponents.h"

//Class forward Declared
namespace cocos2d
{
	class Sprite;
	class Scene;
}

/**
 * @brief This class is the base class for all moving
 * game objects
 */
class MovingGameObjectBase
{
protected:
	//Shared data members with other derived classes
	PhysicsComponents *physicsComponents;
	Hitbox *hitbox;
	cocos2d::Sprite *sprite;
	bool collisionWithWall{false};

	//Protected constructors
	MovingGameObjectBase(cocos2d::Scene* sceneToAddSprite, const std::string& aFileName, const cocos2d::Vec2& aStartPosition, const float& aVelocity);

	//Protected member functions
	
public:
	virtual ~MovingGameObjectBase();

	//Getters
	cocos2d::Rect getHitbox() const;
	PhysicsComponents* getPhysicsComponent() const;
	cocos2d::Sprite* getSprite() const;

	//Setter
	void setCollidingWithWall();

	//Member function
	virtual void update(const float& deltaTime);
	void updateSprite() const;
};

