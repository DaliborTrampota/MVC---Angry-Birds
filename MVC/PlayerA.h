#pragma once

#include "AbsPlayer.h"

class AbsMissile;
class GameObject;
class IGameObjectFactory;

class PlayerA : public AbsPlayer
{
public:
	PlayerA(Vec2<int> pos, const char* textureName);
	//using AbsPlayer::AbsPlayer;
	//PlayerA(const char* name, const char* textureName) : AbsPlayer(name, textureName) {}

	void moveUp() override;
	void moveDown() override;
	void aimUp() override;
	void aimDown() override;
	void powerUp() override;
	void powerDown() override;
	AbsMissile* shoot() override;

	void setFactory(IGameObjectFactory* factory);

private:
	IGameObjectFactory* m_factory;
	float m_angle;
	int m_power;
};

