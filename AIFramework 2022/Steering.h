#pragma once
#include "Vehicle.h"
#include "AIManager.h"
class Steering : public Vehicle, public AIManager
{

public:
	Vector2D Seek();
	virtual void update(const float deltaTime);
};

