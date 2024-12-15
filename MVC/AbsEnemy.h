#pragma once

#include "Configuration.h"
#include "MovingGameObject.h"
#include "ICollidable.h"
#include "IDamageable.h"

class AbsEnemy : public MovingGameObject, public ICollidable, public IDamageable {
public:
	AbsEnemy(Vec2<float> pos, float speed = BaseEnemySpeed) :
		MovingGameObject(pos, { -1, 0 }, false)
	{
		m_collisionRadius = 10.f;
		m_speed = speed;
		m_acceleration = EnemyAcceleration;
	}

	void acceptVisitor(IVisitor* visitor) override;

	using MovingGameObject::move;
	virtual void move(float dt) = 0;

	bool checkCollision(ICollidable* other) override;
};