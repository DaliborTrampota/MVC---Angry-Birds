#include "DoubleShootingMode.h"

#include "AbsPlayer.h"

void DoubleShootingMode::shoot(AbsPlayer* plr) const
{
	plr->aimUp();
	plr->primitiveShoot();
	plr->aimDown();
	plr->aimDown();
	plr->primitiveShoot();
	plr->aimUp();
}
