#include "RandomMovingStrategy.h"

#include <cstdlib>
#include <random>

#include "AbsMissile.h"

RandomMovingStrategy::RandomMovingStrategy()
	: m_distribution(-2, 2)
{
}

void RandomMovingStrategy::updatePosition(AbsMissile* missile, float dt)
{
	missile->move({ 1.f, (float)getDir() });
}

int RandomMovingStrategy::getDir()
{
	return m_distribution(m_generator);
}


