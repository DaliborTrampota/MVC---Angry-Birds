#pragma once


class GameObject;

class IMovingStrategy {
public:
	virtual void updatePosition(GameObject* missile, float dt) = 0;
};