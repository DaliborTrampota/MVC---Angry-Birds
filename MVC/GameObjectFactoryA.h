#pragma once

#include "IGameObjectFactory.h"
#include "IMovingStrategy.h"

class AbsPlayer;
class AbsMissile;
class IModel;

class GameObjectFactoryA : public IGameObjectFactory
{
public:
	GameObjectFactoryA(IModel* model) : m_model(model) {
	
	}

	AbsPlayer* createPlayer(Vec2<int> pos) override;
	AbsMissile* createMissile(float initAngle, float initVelocity) override;

private:
	IModel* m_model;
};

