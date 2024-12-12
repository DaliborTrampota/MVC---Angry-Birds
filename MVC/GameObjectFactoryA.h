#pragma once

#include "IGameObjectFactory.h"
#include "IMovingStrategy.h"

class IModel;

class GameObjectFactoryA : public IGameObjectFactory
{
public:
	GameObjectFactoryA(IModel* model) : m_model(model) {
	
	}

	AbsPlayer* createPlayer(Vec2<float> pos) override;
	AbsMissile* createMissile(float initAngle, float initVelocity) override;
	AbsEnemy* createEnemy(Vec2<int> min, Vec2<int> max) override;

private:
	IModel* m_model;
};

