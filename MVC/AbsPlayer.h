#pragma once

#include "GameObject.h"
#include "AbsMissile.h"

class AbsPlayer : public GameObject
{
public:
	using GameObject::GameObject;
	//AbsPlayer(const char* name, const char* textureName) : GameObject(name, textureName) {}

	void acceptVisitor(IVisitor* visitor) override;

	virtual void moveUp() = 0;
	virtual void moveDown() = 0;
	virtual void aimUp() = 0;
	virtual void aimDown() = 0;
	virtual void powerUp() = 0;
	virtual void powerDown() = 0;
	virtual AbsMissile* shoot() = 0;
};

