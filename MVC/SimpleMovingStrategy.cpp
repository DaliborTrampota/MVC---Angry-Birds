#include "SimpleMovingStrategy.h"

#include "Configuration.h"
#include "AbsMissile.h"
#include <iostream>

void SimpleMovingStrategy::updatePosition(AbsMissile* missile, float dt)
{
	float time = 1.f - std::min(1.f, missile->getAge() / 500.f);
	std::cout << missile->getAge() / 2000.f << std::endl;
	missile->move({
		(float)missile->getVelocity() * time * cos(missile->getAngle()),
		(float)missile->getVelocity() * time* sin(missile->getAngle())
		});
}
