#pragma once

#include "IMovingStrategy.h"
#include "AbsMissile.h"

class MissileA : public AbsMissile
{
public:
	MissileA(Vec2<float> pos, float angle, int power, IMovingStrategy* strategy);

	void move(float dt) override;
	void onHit(ICollidable* other) override;

private:
	IMovingStrategy* m_movingStrategy;
};

