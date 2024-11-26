#pragma once

#include "Math.h"

class AbsPlayer;
class AbsMissile;

class IGameObjectFactory {
public:
	virtual AbsPlayer* createPlayer(Vec2<int> pos) = 0;
	virtual AbsMissile* createMissile(float initAngle, float initVelocity) = 0;
};