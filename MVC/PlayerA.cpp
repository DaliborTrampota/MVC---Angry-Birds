#include "PlayerA.h"

#include "GameObjectFactoryA.h"

#include "Configuration.h"

PlayerA::PlayerA(Vec2<int> pos) :
    AbsPlayer(pos),
    m_angle(InitAngle),
    m_power(InitPower)
{
}

void PlayerA::moveUp()
{
    m_pos += { 0, -1 * PlayerMoveSpeed };
}

void PlayerA::moveDown()
{
    m_pos += { 0, 1 * PlayerMoveSpeed };
}

void PlayerA::aimUp()
{
    m_angle += AngleStep;
}

void PlayerA::aimDown()
{
    m_angle += AngleStep;
}

void PlayerA::powerUp()
{
    m_power += PowerStep;
}

void PlayerA::powerDown()
{
    m_power -= PowerStep;
}

AbsMissile* PlayerA::shoot()
{
    return m_factory->createMissile(m_angle, m_power);
}

void PlayerA::setFactory(IGameObjectFactory* factory)
{
    m_factory = factory;
}
