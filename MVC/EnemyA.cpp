#include "EnemyA.h"

#include "Configuration.h"

EnemyA::EnemyA(Vec2<float> pos) :
	AbsEnemy(pos),
	m_hp(DefaultEnemyHP)
{
}

void EnemyA::onHit()
{

}

void EnemyA::damage(int amount)
{
	m_hp -= amount;
}

const char* EnemyA::getTextureName() const
{
	if (m_hp > 66) return "enemy1.png";
	if (m_hp > 33) return "enemy2.png";
	return "enemy2WithBlood.png";
}
