/**
 * @author Mike Pham - 100706123
 * @author Rebecca Buckle - 100702016
 * @author Maija Kinnunen - 100697620
 */
#include "BackEnd/InputManager.h"
#include "Game Objects/Pacman/Pacman.h"

//Typedef
#define KEYCODE cocos2d::EventKeyboard::KeyCode

/**
 *Constructor for the keyboard manager
 *@param aPacmanPtr A pointer for class Pacman that can be used to control
 */
KeyBoardInputManager::KeyBoardInputManager(Pacman *aPacmanPtr)
	:pacManInstance(aPacmanPtr)
{
	listener = cocos2d::EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(KeyBoardInputManager::onKeyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(KeyBoardInputManager::onKeyReleased, this);
}

/**
 *Destructor for the keyboard manager. This will delete any dynamically allocated variables
 */
KeyBoardInputManager::~KeyBoardInputManager()
{
	delete listener;
}

/**
 *This function returns the keyboard event listener pointer
 *@return Return cocos2d::EventListenerKeyboard pointer
 */
cocos2d::EventListenerKeyboard* KeyBoardInputManager::getListener() const
{
	return listener;
}

/**
 *This function processes when a key is pressed down
 *@param keyCode The key being pressed
 *@param event Cocos2d event dispatcher to set the key pressed to true for processing
 */
void KeyBoardInputManager::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
	switch (keyCode)
	{
	case KEYCODE::KEY_W:
		pacManInstance->setFacingDirection(up);
		break;
	case KEYCODE::KEY_S:
		pacManInstance->setFacingDirection(down);
		break;
	case KEYCODE::KEY_D:
		pacManInstance->setFacingDirection(left);
		break;
	case KEYCODE::KEY_A:
		pacManInstance->setFacingDirection(right);
		break;
	default:
		break;
	}
}

/**
 *This function processes when a pressed key is released
 *@param keyCode The key being released
 *@param event Cocos2d event dispatcher to set the key pressed to true for processing
 */
void KeyBoardInputManager::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
	switch (keyCode)
	{
	case KEYCODE::KEY_W:
	case KEYCODE::KEY_S:
	case KEYCODE::KEY_D:
	case KEYCODE::KEY_A:
	default:
		break;
	}
}
