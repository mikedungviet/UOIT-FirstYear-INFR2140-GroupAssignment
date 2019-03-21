#include "Pacman.h"

Pacman * Pacman::create(const std::string & filename)
{
	auto ret = new (std::nothrow) Pacman;

	if (ret && ret->initWithFile(filename)) {
		//cocos2d::Vector<cocos2d::SpriteFrame *> updown_frames = { cocos2d::SpriteFrame::create("", cocos2d::Rect(0,0,24,28), false, {0,0}, {24,28}) };
		cocos2d::Vector<cocos2d::SpriteFrame *> leftright_frames = { cocos2d::SpriteFrame::create("Pacman0001.png", cocos2d::Rect(0,0,16,16), false, {0,0}, {16,16}),
																cocos2d::SpriteFrame::create("Pacman0002.png", cocos2d::Rect(0,0,16,16), false, {0,0}, {16,16}),
																cocos2d::SpriteFrame::create("Pacman0003.png", cocos2d::Rect(0,0,16,16), false, {0,0}, {16,16}),
																cocos2d::SpriteFrame::create("Pacman0004.png", cocos2d::Rect(0,0,16,16), false, {0,0}, {16,16}) };

		//ret->animations.pushBack(cocos2d::Animation::createWithSpriteFrames(updown_frames, 0.3f));
		ret->animations.pushBack(cocos2d::Animation::createWithSpriteFrames(leftright_frames, 0.1f));

		ret->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(ret->animations.at(0))));
		ret->autorelease();
		return ret;
	}
	CC_SAFE_RELEASE(ret);
	return nullptr;
}
