#include "RealisticMovingStrategy.h"

#include "Configuration.h"
#include "AbsMissile.h"


void RealistingMovingStrategy::updatePosition(AbsMissile* missile)
{
	long time = missile->getAge() / MagicTimeConst;

	missile->move({
		(int)(missile->getVelocity() * time * cos(missile->getAngle())),
		(int)(missile->getVelocity() * time * sin(missile->getAngle()) + 0.5 * Gravity * pow(time, 2))
		});
}
