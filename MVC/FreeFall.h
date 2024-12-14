#pragma once

#include "IMovingStrategy.h"


class FreeFall : public IMovingStrategy {
public:
	FreeFall() = default;

	void updatePosition(GameObject* obj, float dt) override;
};