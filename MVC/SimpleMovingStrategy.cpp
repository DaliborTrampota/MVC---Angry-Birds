#include "SimpleMovingStrategy.h"

#include "Configuration.h"
#include "AbsMissile.h"
#include <iostream>

void SimpleMovingStrategy::updatePosition(AbsMissile* missile)
{
	float time = 1.f - std::min(1.f, missile->getAge() / 500.f);
	std::cout << missile->getAge() / 2000.f << std::endl;
	missile->move({
		(int)(missile->getVelocity() * time * cos(missile->getAngle())),
		(int)(missile->getVelocity() * time * sin(missile->getAngle()))
		});
}
