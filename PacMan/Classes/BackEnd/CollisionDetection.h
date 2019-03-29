/**
 * @author Mike Pham - 100706123
 * @author Rebecca Buckle - 100702016
 * @author Maija Kinnunen - 100697620
 * @author Jackson Holder - 100701005
 */
#pragma once
//Header Files

//Foward declare classes
class Level1;
class LevelBase;

/**
 * This class goes through all Game Objects for a scene class and check for any collision
 * using AABB collision detection
 * 
 */
class CollisionDetection
{
	LevelBase *sceneToPerformDetection;

	//Member Function
	template<class T, class V>
	static bool checkCollisionSide(T* mainObject, V* secondaryObject);

public:
	CollisionDetection(LevelBase* aRunningScene);
	void checkForCollision() const;
};



