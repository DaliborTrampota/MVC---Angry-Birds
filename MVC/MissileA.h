#pragma once

#include "IMovingStrategy.h"
#include "AbsMissile.h"

class MissileA : public AbsMissile
{
public:
	MissileA(Vec2<int> pos, float angle, int velocity, IMovingStrategy* strategy);

	void move() override;

private:
	IMovingStrategy* m_movingStrategy;
};

