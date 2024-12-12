#include "MissileA.h"

MissileA::MissileA(Vec2<float> pos, float angle, int velocity, IMovingStrategy* strategy)
	: AbsMissile(pos, angle, velocity),
	m_movingStrategy(strategy)
{
}

void MissileA::move()
{
	m_movingStrategy->updatePosition(this);
}
