/**
 * @author Mike Pham - 100706123
 * @author Rebecca Buckle - 100702016
 * @author Maija Kinnunen - 100697620
 */
#include "Game Objects/Pacman/Pacman.h"


/**
 * @brief This is the constructor for Pacman
 * @param scene The scene that pacman will be on
 */
Pacman::Pacman(cocos2d::Scene *scene)
	: MovingGameObjectBase(scene,"Pacman/Pacman0002.png",cocos2d::Vec2(500,500),250)
{
	sprite->setScale(2.5);
	sprite->setRotation(90);
}

/**
 *@brief This function set the facing direction vector and the sprite rotation depends on
 *the new direction
 *@param newDirection The new direction that pacman is facing to
 */
void Pacman::setFacingDirection(const FacingDirection newDirection) const
{
	switch (newDirection)
	{
	case up:
		sprite->setRotation(0);
		physicsComponents->direction.set(0, 1);
		break;
	case down:
		sprite->setRotation(180);
		physicsComponents->direction.set(0, -1);
		break;
	case left:
		sprite->setRotation(90);
		physicsComponents->direction.set(1, 0);
		break;
	case right:
		sprite->setRotation(270);
		physicsComponents->direction.set(-1, 0);
		break;
	default:
		break;
	}
}
