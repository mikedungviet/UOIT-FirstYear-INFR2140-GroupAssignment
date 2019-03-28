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



class CollisionDetection
{
	enum CollisionSide
	{
		right,
		top,
		left,
		bot,
		noCollision
	};

	Level1 *sceneToPerformDetection;

	//Member Function
	template<class T, class V>
	static CollisionSide checkCollisionSide(T* firstObject, V* secondObject);

public:
	CollisionDetection(Level1* aRunningScene);

	void checkForCollision();

};



