#include "MissileA.h"

#include "FreeFall.h"
#include "AbsEnemy.h"

MissileA::MissileA(Vec2<float> pos, float angle, int power, IMovingStrategy* strategy)
	: AbsMissile(pos, angle, power),
	GameObject(pos),
	m_movingStrategy(strategy)
{
}

void MissileA::move(float dt)
{
	m_movingStrategy->updatePosition(this, dt);
}

bool MissileA::onHit(ICollidable* other)
{
	if (!AbsMissile::onHit(other))
		return false;	

	AbsEnemy* enemy;
	if (enemy = dynamic_cast<AbsEnemy*>(other)) {
		auto myVel = getVelocity();
		setVelocity({ -400, -600 });
		enemy->setVelocity({ 50, 0 });
	}

	m_acceleration = AirDrag;
	m_movingStrategy = new FreeFall();
	return true;
}