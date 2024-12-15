#pragma once

#include "IMovingStrategy.h"

#include <random>

class GameObject;


class RandomMovingStrategy : public IMovingStrategy {

public:
	RandomMovingStrategy(int min = -2, int max = 2);

	void updatePosition(GameObject* object, float dt) override;

	const char* name() override {
		return "Random";
	}

protected:
	std::mt19937 m_generator;
	std::uniform_int_distribution<int> m_distribution;

	int random();
};