/**
 * @author Mike Pham - 100706123
 * @author Rebecca Buckle - 100702016
 * @author Maija Kinnunen - 100697620
 */
#include "Game Objects/GameObjectBase.h"
#include "cocos2d.h"

/**
 *@brief This is the constructor for the moving game object base class.
  * It will initialize sprite (with no texture), physics component, and
  * hitbox data members
  *
  * @param sceneToAddSprite The scene to add the sprite to
  * @param aFileName The file name for the sprite
  * @param aStartPosition The starting position of the object
  * @param aVelocity The velocity of the object
 */
MovingGameObjectBase::MovingGameObjectBase(cocos2d::Scene* sceneToAddSprite, const std::string& aFileName,
	const cocos2d::Vec2& aStartPosition, const float& aVelocity)
	:physicsComponents(new PhysicsComponents(aStartPosition, aVelocity)), sprite(cocos2d::Sprite::create(aFileName))
{
	//Set up sprite
	sprite->setScale(2.5);
	sprite->setPosition(physicsComponents->position);
	sceneToAddSprite->addChild(sprite);

	//Hit up hitbox
	hitbox = new Hitbox(aStartPosition, sprite->getBoundingBox().size);
}

/**
 * @brief This is the destructor for game object base class.
 * This will deallocate all dynamically allocated data members
 */
MovingGameObjectBase::~MovingGameObjectBase()
{
	sprite->removeFromParentAndCleanup(true);
	delete hitbox;
	delete physicsComponents;
}

/**
 * @brief This returns the hit box as a rectangle
 *
 * @return Returns cocos2d::Rect
 */
cocos2d::Rect MovingGameObjectBase::getHitbox() const
{
	return hitbox->getHitBox();
}

/**
 * @brief This function gets the physics components of the object
 *
 * @return Return PhysicsComponent pointer
 */
PhysicsComponents* MovingGameObjectBase::getPhysicsComponent() const
{
	return physicsComponents;
}

/**
 * @brief This function get the sprite of the object
 *
 * @return Return the cocos2d::Sprite pointer
 */
cocos2d::Sprite* MovingGameObjectBase::getSprite() const
{
	return sprite;
}

/**
 * @brief This function will be called when the moving object
 * collides with a wall. It will set the collisionWithWall
 * to true
 */
void MovingGameObjectBase::setCollidingWithWall()
{
	collisionWithWall = true;
}

/**
 * @brief This function updates the data members from last frame
 *
 * @param deltaTime The change of time of last frame to current frame
 */
void MovingGameObjectBase::update(const float& deltaTime)
{
	collisionWithWall = false;
	physicsComponents->update(deltaTime);
	hitbox->update(physicsComponents->position);
}

/**
 * @brief This function will update the sprite position if
 * the object is not colliding with a wall
 */
void MovingGameObjectBase::updateSprite() const
{
	if (!collisionWithWall)
		sprite->setPosition(physicsComponents->position);
	else
		physicsComponents->position = physicsComponents->lastFramePosition;
}
