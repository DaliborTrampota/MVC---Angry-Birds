#pragma once

#include "GameObject.h"
#include <chrono>

class LifetimeGameObject : public GameObject
{
	using Clock = std::chrono::steady_clock;

public:
	LifetimeGameObject(Vec2<float> pos);

	/* Returns time of the object in milliseconds */
	long getAge() const;

private:
	Clock::time_point m_createdAt;
};

