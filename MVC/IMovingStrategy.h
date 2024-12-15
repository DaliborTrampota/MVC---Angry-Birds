#pragma once


class GameObject;

class IMovingStrategy {
public:
	virtual void updatePosition(GameObject* missile, float dt) = 0;
	virtual const char* name() = 0;
};