#include "EnemyA.h"

#include "Configuration.h"
#include "FreeFall.h"

EnemyA::EnemyA(Vec2<float> pos, float speed, IMovingStrategy* strategy) :
	AbsEnemy(pos, speed),
	GameObject(pos),
	m_movingStrategy(strategy)
{
	m_affectedByGravity = false;
	m_hp = EnemyHP;
}

void EnemyA::move(float dt)
{
	m_movingStrategy->updatePosition(this, dt);
}

const char* EnemyA::getTextureName() const
{
	if (m_hp > 66) return "enemy1.png";
	if (m_hp > 33) return "enemy2.png";
	return "enemy2WithBlood.png";
}

void EnemyA::onKill()
{
	setVelocity({ 400, 600 });
	m_acceleration = AirDrag;
	m_movingStrategy = new FreeFall();
}
