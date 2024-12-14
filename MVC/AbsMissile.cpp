#include "AbsMissile.h"
#include "IDamageable.h"
#include "Configuration.h"
#include <sstream>
#include <assert.h>

void AbsMissile::acceptVisitor(IVisitor* visitor)
{
	//visitor->visitMissile(this);
	visitor->visitObject(this);
}

float AbsMissile::getAngle() const
{
	return m_angle;
}

int AbsMissile::getPower() const
{
	return m_speed;
}

void AbsMissile::onHit(ICollidable* other)
{
	if (!m_active)
		return;
	IDamageable* dmg;
	if (dmg = dynamic_cast<IDamageable*>(other)) {
		dmg->damage(PlayerDamage);
		m_active = false;
	}
}

bool AbsMissile::checkCollision(ICollidable* other)
{
	auto obj = dynamic_cast<GameObject*>(other);
	assert(obj);
	auto otherPos = obj->getPosition();
	float dist = sqrt(pow(otherPos.x - this->m_pos.x, 2) + pow(otherPos.y - this->m_pos.y, 2));
	return dist < other->getCollisionRadius() + this->m_collisionRadius;
}

inline const char* AbsMissile::s_getName(const char* name)
{
	std::stringstream newName;
	newName << name << "_" << AbsMissile::s_ID;
	return newName.str().c_str();
}
