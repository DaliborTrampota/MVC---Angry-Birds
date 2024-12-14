#include "SimpleMovingStrategy.h"

#include "Configuration.h"
#include "GameObject.h"
#include "AbsMissile.h"
#include <iostream>

void SimpleMovingStrategy::updatePosition(GameObject* object, float dt)
{
	AbsMissile* missile = dynamic_cast<AbsMissile*>(object);
	if (missile->affectedByGravity())
		missile->useGravity(false);

	Vec2<float> dir = { cos(missile->getAngle()), sin(missile->getAngle()) };
	missile->move(dir, dt);
}
