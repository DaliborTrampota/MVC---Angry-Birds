#include "RealisticMovingStrategy.h"

#include "Configuration.h"
#include "AbsMissile.h"


void RealistingMovingStrategy::updatePosition(GameObject* object, float dt)
{
	AbsMissile* missile = dynamic_cast<AbsMissile*>(object);
	if (!missile->affectedByGravity())
		missile->useGravity(true);

	Vec2<float> dir = { cos(missile->getAngle()), sin(missile->getAngle()) };
	missile->move(dir * missile->getPower(), dt);
}
