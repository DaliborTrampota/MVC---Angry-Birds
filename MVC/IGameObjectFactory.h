#pragma once

#include "MyMath.h"

class AbsPlayer;
class AbsMissile;
class AbsEnemy;

class IGameObjectFactory {
public:
	virtual AbsPlayer* createPlayer(Vec2<float> pos) = 0;
	virtual AbsMissile* createMissile(float initAngle, float initVelocity) = 0;
	virtual AbsEnemy* createEnemy(Vec2<int> min, Vec2<int> max) = 0; // bounding box where the enemy can spawn
};