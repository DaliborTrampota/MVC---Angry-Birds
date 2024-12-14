#pragma once

#include "IMovingStrategy.h"

class SimpleMovingStrategy : public IMovingStrategy {

public:
	SimpleMovingStrategy() = default;

	void updatePosition(GameObject* object, float dt) override;
};