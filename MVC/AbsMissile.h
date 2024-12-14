#pragma once

#include "LifetimeGameObject.h"
#include "MovingGameObject.h"
#include "string"
#include "ICollidable.h"

class AbsMissile : public LifetimeGameObject, public MovingGameObject, public ICollidable
{
public:
	AbsMissile(Vec2<float> pos, float angle, int power) :
		LifetimeGameObject(pos),
		MovingGameObject(pos, { (float)cos(angle) * power, (float)sin(angle) * power }),
		m_angle(angle)
	{
		m_collisionRadius = 10.f;
		m_speed = power;
	}

	void acceptVisitor(IVisitor* visitor) override;
	float getAngle() const;
	int getPower() const;

	using MovingGameObject::move;
	virtual void move(float dt) = 0;
	virtual void onHit(ICollidable* other) override;
	bool checkCollision(ICollidable* other) override;

	static inline unsigned int s_ID = 0;
	static inline const char* s_getName(const char* name);

protected:
	float m_angle;
	bool m_active = true;
};

