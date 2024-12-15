#pragma once

#include <vector>

#include "Configuration.h"
#include "GameObject.h"
#include "AbsMissile.h"
#include "IShootingMode.h"

class AbsPlayer : public GameObject
{
public:
	static IShootingMode* SINGLE_SHOOTING_MODE;
	static IShootingMode* DOUBLE_SHOOTING_MODE;

	AbsPlayer(Vec2<float> pos, float initAngle, int initPower);
	//AbsPlayer(const char* name, const char* textureName) : GameObject(name, textureName) {}

	void acceptVisitor(IVisitor* visitor) override;

	virtual void moveUp() = 0;
	virtual void moveDown() = 0;
	virtual void aimUp() = 0;
	virtual void aimDown() = 0;
	virtual void powerUp() = 0;
	virtual void powerDown() = 0;

	virtual std::vector<AbsMissile*> shoot() = 0;
	virtual void primitiveShoot() = 0;

	virtual void toggleShootingMode() = 0;

	float getAngle() const;
	int getPower() const;

	virtual void setAngle(float angle) = 0;
	virtual void setPower(int power) = 0;

	void takeDamage(int dmg);
	int getHP() const;
	IShootingMode* activeShootingMode() const;

protected:
	IShootingMode* m_shootingMode = nullptr;
	float m_angle;
	int m_power;

	int m_hp = PlayerHealth;
};

