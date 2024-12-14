#pragma once

#include "IMovingStrategy.h"

class GameObject;

class RealistingMovingStrategy : public IMovingStrategy {

public:
	RealistingMovingStrategy() = default;

	void updatePosition(GameObject* object, float dt) override;
};