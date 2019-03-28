/**
 * @author Mike Pham - 100706123
 * @author Rebecca Buckle - 100702016
 * @author Maija Kinnunen - 100697620
 * @author Jackson Holder - 100701005
 */
#include "CollisionDetection.h"
#include "Mics/HelloWorldScene.h"

/**
 * @brief This is the constructor for collision detection class. It needs a scene
 * with friend "power" so that it can checks for collision
 */
CollisionDetection::CollisionDetection(Level1* aRunningScene)
	: sceneToPerformDetection(aRunningScene)
{

}


/**
 * @brief This function loops through all object in the current level and do collision check
 * with each other
 */
void CollisionDetection::checkForCollision()
{
	//TODO: Check Pacman vs Fruit and other stuffs


	//TODO: Check Pacman and Ghost vs Walls
	for (auto i : sceneToPerformDetection->wallList)
	{
		const CollisionSide collisionSide = checkCollisionSide(sceneToPerformDetection->character, i);

		//TODO: Convert this switch statement as a new class
		switch (collisionSide)
		{
		case top:
			sceneToPerformDetection->character->getPhysicsComponent()->position.y += 10;
			break;
		case bot:
			sceneToPerformDetection->character->getPhysicsComponent()->position.y -= 10;
			break;
		case left:
			sceneToPerformDetection->character->getPhysicsComponent()->position.x -= 10;
			break;
		case right:
			sceneToPerformDetection->character->getPhysicsComponent()->position.x += 10;
			break;
		case noCollision:
		default:
			break;
		}
		//Collide with wall
	}
	//TODO: Check Pacman vs Ghost

}

/**
 *@brief This function gets the hit box of two objects checks if they are colliding or not.
 *If they are colliding, the side of the collision (relative to the object in the first parameter)
 *will be return. (Both objects need to have getHitBox() function)
 *
 *@param mainObject The main object to check collision with
 *@param secondaryObject The other object to see if the main object collide with
 *
 *@return Return the collision side as CollisionSide
 */
template <class T, class V>
CollisionDetection::CollisionSide CollisionDetection::checkCollisionSide(T* mainObject, V* secondaryObject)
{
	const cocos2d::Rect mainObjectHitBox = mainObject->getHitbox();
	const cocos2d::Rect secondaryObjectHitBox = secondaryObject->getHitbox();

	if (mainObjectHitBox.intersectsRect(secondaryObjectHitBox))
	{
		const cocos2d::Vec2 firstObjectTopRightCorner(mainObjectHitBox.origin + mainObjectHitBox.size);
		const cocos2d::Vec2 secondObjectTopRightCorner(secondaryObjectHitBox.origin + secondaryObjectHitBox.size);

		//Calculate the amount of overlapping with each side
		std::vector<float> tempVec;
		tempVec.push_back(secondObjectTopRightCorner.y - mainObjectHitBox.origin.y); // Top overlap
		tempVec.push_back(firstObjectTopRightCorner.y - secondaryObjectHitBox.origin.y); //Bottom overlap
		tempVec.push_back(firstObjectTopRightCorner.x - secondaryObjectHitBox.origin.x); //Left overlap
		tempVec.push_back(secondObjectTopRightCorner.x - mainObjectHitBox.origin.x); //Right overlap

		//Find the element that hold the smallest value 
		unsigned minElement{ 0 };
		for (unsigned i = 1; i < tempVec.size(); i++)
		{
			if (tempVec[i] < tempVec[i - 1])
				minElement = i;
		}

		//Return the side of the that collision happens
		switch (minElement)
		{
		case 0:
			return top;
		case 1:
			return bot;
		case 2:
			return left;
		case 3:
			return right;
		default:
			throw;
		}
	}
	return noCollision;
}
