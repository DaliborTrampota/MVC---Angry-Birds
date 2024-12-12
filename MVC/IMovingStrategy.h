#pragma once


class AbsMissile;

class IMovingStrategy {
public:
	virtual void updatePosition(AbsMissile* missile, float dt) = 0;
};