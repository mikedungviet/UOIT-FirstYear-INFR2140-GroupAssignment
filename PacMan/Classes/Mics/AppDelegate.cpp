#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "Mics/Levels/Level1.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
		glview = GLViewImpl::createWithRect("PacMan", cocos2d::Rect(0, 0, 1920, 1080));
        director->setOpenGLView(glview);
    }

    director->runWithScene(Level1::createScene());

    return true;
}

void AppDelegate::applicationDidEnterBackground() {
}

void AppDelegate::applicationWillEnterForeground() {
}