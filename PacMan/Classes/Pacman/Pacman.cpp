#include "Pacman.h"


/**
 * @brief This is the constructor for Pacman
 * @param scene The scene that pacman will be on
 */
Pacman::Pacman(cocos2d::Scene *scene)
	: sprite(cocos2d::Sprite::create("Pacman/Pacman0002.png")), position(500, 500), facingDirection(0, 1),
	scenePacmanOn(scene)
{
	sprite->setPosition(position);
	sprite->setScale(2);
	scenePacmanOn->addChild(sprite);
}

/**
 * @brief This is the destructor for Pacman. This will deletes any dynamically allocated variables
 */
Pacman::~Pacman()
{
	scenePacmanOn->removeChild(sprite);
}


/**
 * @brief This function returns the sprite pointer for pacman
 * @return Returns a cocos2d Sprite pointer
 */
cocos2d::Sprite* Pacman::getSprite() const
{
	return sprite;
}

/**
 *@brief This function set the facing direction vector and the sprite rotation depends on
 *the new direction
 *@param newDirection The new direction that pacman is facing to
 */
void Pacman::setFacingDirection(const FacingDirection newDirection)
{
	switch (newDirection)
	{
	case up:
		sprite->setRotation(0);
		facingDirection.set(0, 1);
		break;
	case down:
		sprite->setRotation(180);
		facingDirection.set(0, -1);
		break;
	case left:
		sprite->setRotation(90);
		facingDirection.set(1, 0);
		break;
	case right:
		sprite->setRotation(270);
		facingDirection.set(-1, 0);
		break;
	default:
		break;
	}
}

/**
 * @brief This function updates the new position for Pacman using physics
 * @param deltaT The change of time from last frame to current frame
 */
void Pacman::update(const float& deltaT)
{
	position += facingDirection * velocity * deltaT;
	sprite->setPosition(position);
}
