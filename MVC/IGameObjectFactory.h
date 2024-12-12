#pragma once

#include "MyMath.h"

class AbsPlayer;
class AbsMissile;

class IGameObjectFactory {
public:
	virtual AbsPlayer* createPlayer(Vec2<float> pos) = 0;
	virtual AbsMissile* createMissile(float initAngle, float initVelocity) = 0;
};