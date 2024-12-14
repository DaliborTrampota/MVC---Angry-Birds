#include "AbsEnemy.h"
#include <assert.h>

void AbsEnemy::acceptVisitor(IVisitor* visitor)
{
	visitor->visitObject(this);
}

bool AbsEnemy::checkCollision(ICollidable* other)
{
	auto obj = dynamic_cast<GameObject*>(other);
	assert(obj);
	auto otherPos = obj->getPosition();
	float dist = sqrt(pow(otherPos.x - this->m_pos.x, 2) + pow(otherPos.y - this->m_pos.y, 2));
	return dist < other->getCollisionRadius() + this->m_collisionRadius;
}
