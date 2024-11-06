#pragma once

#include "GameObject.h"
#include "string"

class AbsMissile : public GameObject
{
public:
	AbsMissile(Vec2<int> pos, const char* textureName) : GameObject(pos, textureName) {}

	void acceptVisitor(IVisitor* visitor) override;

	static inline unsigned int s_ID = 0;
	static inline const char* s_getName(const char* name);
};

