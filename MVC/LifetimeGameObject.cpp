#include "LifetimeGameObject.h"

LifetimeGameObject::LifetimeGameObject(Vec2<int> pos, const char* texName) : GameObject(pos, texName)
{
}

long LifetimeGameObject::getAge() const
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(m_createdAt.time_since_epoch()).count();
}


