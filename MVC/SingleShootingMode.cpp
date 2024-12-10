#include "SingleShootingMode.h"

#include "AbsPlayer.h"

void SingleShootingMode::shoot(AbsPlayer* plr) const
{
	plr->primitiveShoot();
}
