#pragma once

#include "GameObject.h"


class MovingGameObject : virtual public GameObject {

public:
	using GameObject::GameObject;
	MovingGameObject(Vec2<float> pos, Vec2<float> initVelocity, bool useGravity = true);

	using GameObject::move;
	void move(Vec2<float> dir, float dt);

	Vec2<float> getVelocity();
	void setVelocity(Vec2<float> vel);

	void setSpeed(float speed);
	void useGravity(bool state);
	bool affectedByGravity() const;

protected:
	Vec2<float> m_velocity;
	float m_speed = 100;
	float m_acceleration = 50;

	bool m_affectedByGravity = true;
	float m_gravity = 0.0f;
};