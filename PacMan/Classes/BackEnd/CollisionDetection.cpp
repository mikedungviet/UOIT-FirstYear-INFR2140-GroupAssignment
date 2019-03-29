/**
 * @author Mike Pham - 100706123
 * @author Rebecca Buckle - 100702016
 * @author Maija Kinnunen - 100697620
 * @author Jackson Holder - 100701005
 */
#include "CollisionDetection.h"
#include "Mics/HelloWorldScene.h"
#include "Mics/Levels/LevelBase.h"

 /**
  * @brief This is the constructor for collision detection class. It needs a scene
  * with friend "power" so that it can checks for collision
  */
CollisionDetection::CollisionDetection(LevelBase* aRunningScene)
	: sceneToPerformDetection(aRunningScene)
{

}


/**
 * @brief This function loops through all object in the current level and do collision check
 * with each other
 */
void CollisionDetection::checkForCollision() const
{
	//TODO: Check Pacman vs Fruit and other stuffs


	//TODO: Check Pacman and Ghost vs Walls
	for (auto i : sceneToPerformDetection->wallList)
	{
		if (checkCollisionSide(sceneToPerformDetection->pacman, i))
			sceneToPerformDetection->pacman->isCollidingWithWall();
	}
	//TODO: Check Pacman vs Ghost

}

/**
 *@brief This function gets the hit box of two objects checks if they are colliding or not.
 *
 *@param mainObject The main object to check collision with
 *@param secondaryObject The other object to see if the main object collide with
 *
 *@return True if the objects are colliding.\n
 *		  False if the objects are not colliding
 *
 */
template <class T, class V>
bool CollisionDetection::checkCollisionSide(T* mainObject, V* secondaryObject)
{
	const cocos2d::Rect mainObjectHitBox = mainObject->getHitbox();
	const cocos2d::Rect secondaryObjectHitBox = secondaryObject->getHitbox();

	return mainObjectHitBox.intersectsRect(secondaryObjectHitBox);
}
