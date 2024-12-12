#pragma once

#include <vector>
#include "AbsPlayer.h"

class AbsMissile;
class GameObject;
class IGameObjectFactory;

class PlayerA : public AbsPlayer
{
public:
	PlayerA(Vec2<float> pos);
	//using AbsPlayer::AbsPlayer;
	//PlayerA(const char* name, const char* textureName) : AbsPlayer(name, textureName) {}

	void moveUp() override;
	void moveDown() override;
	void aimUp() override;
	void aimDown() override;
	void powerUp() override;
	void powerDown() override;

	void setAngle(float angle) override;
	void setPower(int power) override;

	std::vector<AbsMissile*> shoot() override;
	void primitiveShoot() override;

	void toggleShootingMode() override;

	void setFactory(IGameObjectFactory* factory);

private:
	IGameObjectFactory* m_factory;
	std::vector<AbsMissile*> m_shootingBatch;
};

