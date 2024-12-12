#pragma once

#include "IMovingStrategy.h"

class AbsMissile;

class RealistingMovingStrategy : public IMovingStrategy {

public:
	RealistingMovingStrategy() = default;

	void updatePosition(AbsMissile* missile, float dt) override;
};