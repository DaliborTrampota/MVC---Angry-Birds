#pragma once

#include "Configuration.h"
#include "MovingGameObject.h"
#include "ICollidable.h"
#include "IDamageable.h"

class AbsEnemy : public MovingGameObject, public ICollidable, public IDamageable {
public:
	AbsEnemy(Vec2<float> pos) :
		MovingGameObject(pos, { -1, 0 }, false)
	{
		m_collisionRadius = 10.f;
		m_speed = BaseEnemySpeed;
		m_acceleration = EnemyAcceleration;
	}

	void acceptVisitor(IVisitor* visitor) override;

	using MovingGameObject::move;
	virtual void move(float dt) = 0;

	virtual void onHit(ICollidable* other) override {};
	//virtual void onKill() override;
	bool checkCollision(ICollidable* other) override;
	//virtual const char* getTextureName() const = 0;
};