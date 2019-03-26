/**
 * @author Mike Pham - 100706123
 * @author Rebecca Buckle - 100702016
 * @author Maija Kinnunen - 100697620
 */
#pragma once

//Header Files
#include <math/CCGeometry.h>


class Hitbox
{
	//Private data members
	const cocos2d::Size size;
	cocos2d::Rect hitboxRect;
public:
	//Constructors and Destructor
	Hitbox(const cocos2d::Vec2& position, float aWidth, float aHeight);
	Hitbox(const cocos2d::Vec2& position, const cocos2d::Size& aSize);

	//Getters
	cocos2d::Rect getHitBox() const;

	//Member function
	void update(const cocos2d::Vec2 &newPosition);
};

