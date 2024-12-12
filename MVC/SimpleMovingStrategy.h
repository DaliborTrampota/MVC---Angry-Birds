#pragma once

#include "IMovingStrategy.h"

class AbsMissile;

class SimpleMovingStrategy : public IMovingStrategy {

public:
	SimpleMovingStrategy() = default;

	void updatePosition(AbsMissile* missile, float dt) override;
};