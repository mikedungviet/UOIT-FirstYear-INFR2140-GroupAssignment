/**
 * @author Mike Pham - 100706123
 * @author Rebecca Buckle - 100702016
 * @author Maija Kinnunen - 100697620
 */
#pragma once

//Header Files
#include "cocos2d.h"
#include "Game Objects/GameObjectBase.h"


enum FacingDirection
{
	up, down, left, right,
};

/**
 *@brief This class is the main character class
 *
 *@see cocos2d::Vec2
 *@see cocos2d::Sprite
 */
class Pacman : public GameObjectBase
{
public:
	//Constructors and Destructor
	Pacman(cocos2d::Scene *scene);
	Pacman(const Pacman&) = delete;

	//Setters
	void setFacingDirection(const FacingDirection newDirection) const;

	//Member functions

	//Assignment operator
	Pacman& operator= (const Pacman&) = delete;

};

