#include "RandomMovingStrategy.h"

#include <cstdlib>
#include <random>

#include "AbsMissile.h"

RandomMovingStrategy::RandomMovingStrategy()
	: m_distribution(-2, 2)
{
}

void RandomMovingStrategy::updatePosition(AbsMissile* missile)
{
	missile->move({ 1, getDir() });
}

int RandomMovingStrategy::getDir()
{
	return m_distribution(m_generator);
}


