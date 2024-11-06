#pragma once

#include "IGameObjectFactory.h"

class AbsPlayer;
class AbsMissile;
class Model;

class GameObjectFactoryA : public IGameObjectFactory
{
public:
	GameObjectFactoryA(Model* model) : m_model(model) {}

	AbsPlayer* createPlayer() override;
	AbsMissile* createMissile() override;

private:
	Model* m_model;
};

