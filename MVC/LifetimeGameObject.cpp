#include "LifetimeGameObject.h"

LifetimeGameObject::LifetimeGameObject(Vec2<int> pos) : GameObject(pos)
{
	m_createdAt = Clock::now();
}

long LifetimeGameObject::getAge() const
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(Clock::now() - m_createdAt).count();
}


