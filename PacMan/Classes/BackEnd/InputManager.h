#pragma once

//Header files
#include "cocos2d.h"

//Forward Declared Classes
class Pacman;

/**
 * @brief This class detects and process key events pressed by the player
 */
class KeyBoardInputManager
{
	cocos2d::EventListenerKeyboard *listener;
	Pacman *pacManInstance;
public:
	//Constructors and Destructor
	KeyBoardInputManager(Pacman *aPacmanPtr);
	KeyBoardInputManager(KeyBoardInputManager const&) = delete;
	~KeyBoardInputManager();

	//Getters
	cocos2d::EventListenerKeyboard* getListener() const;

	//Keyboard functions
	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

	//Assignment operator
	KeyBoardInputManager& operator= (KeyBoardInputManager const&) = delete;
};

