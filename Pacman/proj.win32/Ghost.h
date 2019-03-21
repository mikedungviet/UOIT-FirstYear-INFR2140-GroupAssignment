#pragma once
#include "Entity.h"

class Ghost : public Entity {
public:
	static Ghost * create(const std::string& filename, static int colour);
private:
	bool leftright;
};