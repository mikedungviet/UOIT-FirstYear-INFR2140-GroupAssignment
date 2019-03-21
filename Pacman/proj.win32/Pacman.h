#pragma once
#include "Entity.h"

class Pacman : public Entity {
public:
	static Pacman * create(const std::string& filename);
private:
	bool leftright;
};