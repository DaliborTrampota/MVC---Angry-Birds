#include "MovingGameObject.h"

#include "Configuration.h"

MovingGameObject::MovingGameObject(Vec2<float> pos, Vec2<float> initVelocity, bool useGravity) :
	GameObject(pos),
	m_velocity(initVelocity),
	m_affectedByGravity(useGravity)
{
}

void MovingGameObject::move(Vec2<float> dir, float dt)
{
	dir.setLength(m_speed);
	m_velocity = Vec2<float>::moveTowards(m_velocity, dir, dt * m_acceleration);
	if (m_affectedByGravity)
		m_gravity += 0.5f * Gravity * dt; // pow(dt, 2.f);

	move(m_velocity * dt + Vec2<float>{ 0.f, m_gravity });
}

Vec2<float> MovingGameObject::getVelocity()
{
	return m_velocity;
}

void MovingGameObject::setVelocity(Vec2<float> vel)
{
	m_velocity = vel;
}

void MovingGameObject::setSpeed(float speed)
{
	m_speed = speed;
}

void MovingGameObject::useGravity(bool state)
{
	m_affectedByGravity = state;
	m_gravity = 0.f;
}

bool MovingGameObject::affectedByGravity() const
{
	return m_affectedByGravity;
}
