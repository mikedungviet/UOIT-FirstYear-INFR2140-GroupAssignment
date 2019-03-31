/**
 * @author Mike Pham - 100706123
 * @author Rebecca Buckle - 100702016
 * @author Maija Kinnunen - 100697620
 */
#include "BackEnd/HitBox.h"


/**
 *@brief Constructor for hit box class
 *@param position The position of the hit box (bottom left corner)
 *@param aWidth The width of the hit box
 *@param aHeight The height of the hit box
 */
Hitbox::Hitbox(const cocos2d::Vec2 &position, float aWidth, float aHeight)
	:size(cocos2d::Size(aWidth,aHeight)), hitboxRect(cocos2d::Rect(position,size))
{
}

/**
 *@brief Constructor for hit box class
 *@param position The position of the hit box (bottom left corner)
 *@param aSize The size of the hit box as cocos2d::Size
 */
Hitbox::Hitbox(const cocos2d::Vec2& position, const cocos2d::Size& aSize)
	:size(aSize), hitboxRect(cocos2d::Rect(position, size))
{
}

/**
 * @brief This function returns the hit box data member
 * @return Return cocos2d::Rect
 */
cocos2d::Rect Hitbox::getHitBox() const
{
	return hitboxRect;
}

/**
 * @brief This function set the new size of the hitbox
 * @param newSize The new size for the hitbox
 */
void Hitbox::setNewSize(const cocos2d::Size& newSize)
{
	size = newSize;
}

/**
 * @brief This function updates the hit box position
 * @param newPosition The new position of the object
 */
void Hitbox::update(const cocos2d::Vec2& newPosition)
{
	hitboxRect.setRect(newPosition.x, newPosition.y, size.width, size.height);
}



