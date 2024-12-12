#pragma once

#include "IMovingStrategy.h"
#include "AbsMissile.h"

class MissileA : public AbsMissile
{
public:
	MissileA(Vec2<float> pos, float angle, int velocity, IMovingStrategy* strategy);

	void move(float dt) override;

private:
	IMovingStrategy* m_movingStrategy;
};

