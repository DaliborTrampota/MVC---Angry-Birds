#pragma once

#include "IGameObjectFactory.h"
#include "IMovingStrategy.h"

class AbsPlayer;
class AbsMissile;
class Model;

class GameObjectFactoryA : public IGameObjectFactory
{
public:
	GameObjectFactoryA(Model* model) : m_model(model) {
	
	}

	AbsPlayer* createPlayer(Vec2<int> pos) override;
	AbsMissile* createMissile(float initAngle, float initVelocity) override;

private:
	Model* m_model;
};

