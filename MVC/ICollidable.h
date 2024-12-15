#pragma once

class ICollidable {
public:
	virtual bool onHit(ICollidable* other) = 0;
	virtual bool checkCollision(ICollidable* other) = 0;

	float getCollisionRadius() const {
		return m_collisionRadius;
	}

protected:
	float m_collisionRadius;
};