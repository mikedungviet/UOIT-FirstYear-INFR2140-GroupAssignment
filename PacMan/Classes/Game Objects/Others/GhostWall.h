#pragma once
//Header Files
#include <math/Vec2.h>

//Class forward declare
class Hitbox;
namespace cocos2d 
{
	class Scene;
	class Rect;
}

class GhostWall
{
public:
	//Constructors and Destructor
	GhostWall(const cocos2d::Vec2& aPosition, cocos2d::Scene *aSceneToAddWall);

	//Getters
	cocos2d::Rect getHitbox() const;
private:
	Hitbox* hitbox{ nullptr };
};
