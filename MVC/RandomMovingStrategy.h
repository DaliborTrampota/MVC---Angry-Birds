#pragma once

#include "IMovingStrategy.h"

#include <random>

class GameObject;


class RandomMovingStrategy : public IMovingStrategy {

public:
	RandomMovingStrategy();

	void updatePosition(GameObject* object, float dt) override;


private:
	std::mt19937 m_generator;
	std::uniform_int_distribution<int> m_distribution;

	int getDir();
};