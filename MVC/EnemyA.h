#pragma once

#include "AbsEnemy.h"

class EnemyA : public AbsEnemy {

public:
	EnemyA(Vec2<float> pos);

	void onHit() override;
	void damage(int amount) override;

	const char* getTextureName() const;

private:
	int m_hp;

};