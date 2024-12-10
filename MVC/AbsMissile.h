#pragma once

#include "LifetimeGameObject.h"
#include "string"

class AbsMissile : public LifetimeGameObject
{
public:
	AbsMissile(Vec2<int> pos, float angle, int velocity) :
		LifetimeGameObject(pos),
		m_angle(angle),
		m_velocity(velocity)
	{
	}

	void acceptVisitor(IVisitor* visitor) override;
	float getAngle() const;
	int getVelocity() const;

	using GameObject::move;
	virtual void move() = 0;

	static inline unsigned int s_ID = 0;
	static inline const char* s_getName(const char* name);

private:
	float m_angle;
	int m_velocity;
};

