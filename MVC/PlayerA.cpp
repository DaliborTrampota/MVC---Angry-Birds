#include "PlayerA.h"

#include "GameObjectFactoryA.h"

void PlayerA::aimUp()
{
    m_pos += { 0, -1 };
}

void PlayerA::aimDown()
{
    m_pos += { 0, 1 };
}

AbsMissile* PlayerA::shoot()
{
    return m_factory->createMissile();
}

void PlayerA::setFactory(IGameObjectFactory* factory)
{
    m_factory = factory;
}
