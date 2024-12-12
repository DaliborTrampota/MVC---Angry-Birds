#include "RealisticMovingStrategy.h"

#include "Configuration.h"
#include "AbsMissile.h"


void RealistingMovingStrategy::updatePosition(AbsMissile* missile)
{
	long time = missile->getAge() / MagicTimeConst;

	missile->move({
		(float)missile->getVelocity() * time * (float)cos(missile->getAngle()),
		(float)missile->getVelocity() * time * (float)sin(missile->getAngle()) + 0.5f * Gravity * (float)pow(time, 2.f)
		});
}
