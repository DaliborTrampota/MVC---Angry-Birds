#pragma once

#include "AbsEnemy.h"
#include "IMovingStrategy.h"

class EnemyA : public AbsEnemy {

public:
	EnemyA(Vec2<float> pos, float speed, IMovingStrategy* strategy);

	void move(float dt) override;
	const char* getTextureName() const override;

	bool onHit(ICollidable* other) override { return true; };
	void onKill() override;

private:
	IMovingStrategy* m_movingStrategy;
};