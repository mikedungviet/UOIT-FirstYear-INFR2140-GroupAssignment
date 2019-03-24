#include "BackEnd/InputManager.h"
#include "Pacman/Pacman.h"

//Typedef
#define KEYCODE cocos2d::EventKeyboard::KeyCode

///<summary>Constructor for the keyboard manager </summary>
/// <param name="aPacmanPtr">A pointer for class Pacman that can be used to control </param>
KeyBoardInputManager::KeyBoardInputManager(Pacman *aPacmanPtr)
	:pacManInstance(aPacmanPtr)
{
	listener = cocos2d::EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(KeyBoardInputManager::onKeyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(KeyBoardInputManager::onKeyReleased, this);
}

///<summary>Destructor for the keyboard manager. This will delete any dynamically allocated variables
/// </summary>
KeyBoardInputManager::~KeyBoardInputManager()
{
	delete listener;
}

///<summary>This function returns the keyboard event listener pointer </summary>
cocos2d::EventListenerKeyboard* KeyBoardInputManager::getListener() const
{
	return listener;
}
///<summary>This function processes when a key is pressed down
/// </summary>
/// <param name="keyCode">What key is being pressed</param>
/// <param name="event">cocos2d event dispatcher to set the key pressed to true for processing </param>
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

///<summary>This function processes when a pressed key is released
/// </summary>
/// <param name="keyCode">What key is being pressed</param>
/// <param name="event">cocos2d event dispatcher to set the key pressed to true for processing </param>
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
