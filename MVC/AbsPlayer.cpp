#include "AbsPlayer.h"

#include "SingleShootingMode.h"
#include "DoubleShootingMode.h"

IShootingMode* AbsPlayer::SINGLE_SHOOTING_MODE = new SingleShootingMode();
IShootingMode* AbsPlayer::DOUBLE_SHOOTING_MODE = new DoubleShootingMode();

void AbsPlayer::acceptVisitor(IVisitor* visitor)
{
	//visitor->visitPlayer(this);
	visitor->visitObject(this);
}
