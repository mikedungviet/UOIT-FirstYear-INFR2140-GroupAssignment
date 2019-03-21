#include "Ghost.h"

Ghost * Ghost::create(const std::string & filename, static int colour)
{
	auto ret = new (std::nothrow) Ghost;

	if (ret && ret->initWithFile(filename)) {
		cocos2d::Vector<cocos2d::SpriteFrame *> leftright_frames;
		cocos2d::Vector<cocos2d::SpriteFrame *> updown_frames;
		if (colour == 1)
		{
			//updown_frames = { cocos2d::SpriteFrame::create("", cocos2d::Rect(0,0,24,28), false, {0,0}, {24,28}) };
			leftright_frames = { cocos2d::SpriteFrame::create("BlueGhost0001.png", cocos2d::Rect(0,0,16,16), false, {0,0}, {16,16}),
								 cocos2d::SpriteFrame::create("BlueGhost_Wiggle0001.png", cocos2d::Rect(0,0,16,16), false, {0,0}, {16,16}) };
		}
		else if (colour == 2)
		{
			//updown_frames = { cocos2d::SpriteFrame::create("", cocos2d::Rect(0,0,24,28), false, {0,0}, {24,28}) };
			leftright_frames = { cocos2d::SpriteFrame::create("RedGhost0000.png", cocos2d::Rect(0,0,16,16), false, {0,0}, {16,16}),
								 cocos2d::SpriteFrame::create("RedGhost_Wiggle0001.png", cocos2d::Rect(0,0,16,16), false, {0,0}, {16,16}) };
		}
		else if (colour == 3)
		{
			//updown_frames = { cocos2d::SpriteFrame::create("", cocos2d::Rect(0,0,24,28), false, {0,0}, {24,28}) };
			leftright_frames = { cocos2d::SpriteFrame::create("OrangeGhost0001.png", cocos2d::Rect(0,0,16,16), false, {0,0}, {16,16}),
								 cocos2d::SpriteFrame::create("OrangeGhost_Wiggle0001.png", cocos2d::Rect(0,0,16,16), false, {0,0}, {16,16}) };
		}
		else if (colour == 4)
		{
			//updown_frames = { cocos2d::SpriteFrame::create("", cocos2d::Rect(0,0,24,28), false, {0,0}, {24,28}) };
			leftright_frames = { cocos2d::SpriteFrame::create("PinkGhost0001.png", cocos2d::Rect(0,0,16,16), false, {0,0}, {16,16}),
								 cocos2d::SpriteFrame::create("PinkGhost_Wiggle0001.png", cocos2d::Rect(0,0,16,16), false, {0,0}, {16,16}) };
		}
		//ret->animations.pushBack(cocos2d::Animation::createWithSpriteFrames(updown_frames, 0.3f));
		ret->animations.pushBack(cocos2d::Animation::createWithSpriteFrames(leftright_frames, 0.1f));

		ret->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(ret->animations.at(0))));
		ret->autorelease();
		return ret;
	}
	CC_SAFE_RELEASE(ret);
	return nullptr;
}
