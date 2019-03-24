#pragma once
#include "cocos2d.h"

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
class Pacman
{
	//Private data member
	cocos2d::Sprite *sprite;
	cocos2d::Scene* scenePacmanOn;
	cocos2d::Vec2 facingDirection, position;
	float velocity{250};
public:
	//Constructors and Destructor
	Pacman(cocos2d::Scene *scene);
	Pacman(const Pacman&) = delete;
	~Pacman();

	//Getters
	cocos2d::Sprite* getSprite() const;

	//Setters
	void setFacingDirection(const FacingDirection newDirection);

	//Member function
	void update(const float& deltaT);

	//Assignment operator
	Pacman& operator= (const Pacman&) = delete;

};

