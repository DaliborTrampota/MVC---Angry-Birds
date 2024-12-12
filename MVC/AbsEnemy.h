#pragma once

#include "GameObject.h"

class AbsEnemy : public GameObject {
public:
	using GameObject::GameObject;

	void acceptVisitor(IVisitor* visitor) override;

	virtual void onHit() = 0;
	virtual void damage(int amount) = 0;
};