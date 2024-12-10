#pragma once


class AbsMissile;

class IMovingStrategy {
public:
	virtual void updatePosition(AbsMissile* missile) = 0;
};