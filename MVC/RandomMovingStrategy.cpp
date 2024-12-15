#include "RandomMovingStrategy.h"

#include <cstdlib>
#include <random>

#include "AbsMissile.h"

RandomMovingStrategy::RandomMovingStrategy(int min, int max) :
	m_distribution(min, max)
{
}

void RandomMovingStrategy::updatePosition(GameObject* object, float dt)
{
	object->move({ 1.f, (float)random() });
}

int RandomMovingStrategy::random()
{
	return m_distribution(m_generator);
}


