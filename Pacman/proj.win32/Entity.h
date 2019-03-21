#pragma once
#include "EffectSprite.h"
#include "cocos2d.h"

class Entity : public EffectSprite {
public:
protected:
	cocos2d::Vector<cocos2d::Animation *> animations;
};