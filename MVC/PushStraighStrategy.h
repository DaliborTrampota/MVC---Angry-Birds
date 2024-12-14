#pragma once

#include "IMovingStrategy.h"

class GameObject;

class PushStraightStrategy : public IMovingStrategy {

public:
	PushStraightStrategy() = default;

	void updatePosition(GameObject* obj, float dt) override;


};