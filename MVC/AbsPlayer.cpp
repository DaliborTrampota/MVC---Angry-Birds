#include "AbsPlayer.h"

#include "SingleShootingMode.h"
#include "DoubleShootingMode.h"

IShootingMode* AbsPlayer::SINGLE_SHOOTING_MODE = new SingleShootingMode();
IShootingMode* AbsPlayer::DOUBLE_SHOOTING_MODE = new DoubleShootingMode();

AbsPlayer::AbsPlayer(Vec2<float> pos, float initAngle, int initPower) :
	GameObject(pos),
	m_angle(initAngle),
	m_power(initPower)
{
}

void AbsPlayer::acceptVisitor(IVisitor* visitor)
{
	//visitor->visitPlayer(this);
	visitor->visitObject(this);
}

float AbsPlayer::getAngle() const
{
	return m_angle;
}

int AbsPlayer::getPower() const
{
	return m_power;
}

void AbsPlayer::takeDamage(int dmg)
{
	m_hp -= dmg;
}

int AbsPlayer::getHP() const {
	return m_hp;
}

IShootingMode* AbsPlayer::activeShootingMode() const
{
	return m_shootingMode;
}
