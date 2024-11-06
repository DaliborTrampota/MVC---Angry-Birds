#pragma once

#include "AbsPlayer.h"

class AbsMissile;
class GameObject;
class IGameObjectFactory;

class PlayerA : public AbsPlayer
{
public:
	using AbsPlayer::AbsPlayer;
	//PlayerA(const char* name, const char* textureName) : AbsPlayer(name, textureName) {}

	void aimUp() override;
	void aimDown() override;
	AbsMissile* shoot() override;

	void setFactory(IGameObjectFactory* factory);

private:
	IGameObjectFactory* m_factory;
};

