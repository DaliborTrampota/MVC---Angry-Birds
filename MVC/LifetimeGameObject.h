#pragma once

#include "GameObject.h"
#include <chrono>

class LifetimeGameObject : public GameObject
{
public:
	LifetimeGameObject(Vec2<int> pos, const char* texName);

	/* Returns time of the object in milliseconds */
	long getAge() const;

private:
	std::chrono::time_point<std::chrono::system_clock> m_createdAt;
};

