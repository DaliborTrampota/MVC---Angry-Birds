#include "PlayerA.h"

#include <algorithm>
#define _USE_MATH_DEFINES
#include <math.h>

#include "GameObjectFactoryA.h"
#include "SingleShootingMode.h"

#include "Configuration.h"

PlayerA::PlayerA(Vec2<float> pos) :
    AbsPlayer(pos, InitAngle, InitPower),
    m_factory(nullptr)
{
    m_shootingMode = SINGLE_SHOOTING_MODE;
}

void PlayerA::moveUp()
{
    m_pos += { 0, -1 * PlayerMoveSpeed };
}

void PlayerA::moveDown()
{
    m_pos += { 0, 1 * PlayerMoveSpeed };
    //m_pos.y = std::clamp(m_pos.y, 0, );
}

void PlayerA::aimUp()
{
    m_angle = std::clamp(m_angle - AngleStep, -(float)M_PI_2, (float)M_PI_2);
}

void PlayerA::aimDown()
{
    m_angle = std::clamp(m_angle + AngleStep, -(float)M_PI_2, (float)M_PI_2);
}

void PlayerA::powerUp()
{
    m_power = std::min(m_power + PowerStep, MaxPower);
}

void PlayerA::powerDown()
{
    m_power = std::max(m_power - PowerStep, MinPower);
}

void PlayerA::setAngle(float angle)
{
    m_angle = angle;
}

void PlayerA::setPower(int power)
{
    m_power = power;
}

std::vector<AbsMissile*> PlayerA::shoot()
{
    m_shootingBatch.clear();
    m_shootingMode->shoot(this);
    return m_shootingBatch;
}

void PlayerA::primitiveShoot()
{
    m_shootingBatch.push_back(m_factory->createMissile(m_angle, m_power));
}

void PlayerA::toggleShootingMode()
{
    if (strcmp("SingleShootingMode", m_shootingMode->name()) != 0) {
        m_shootingMode = SINGLE_SHOOTING_MODE;
    }
    else if (dynamic_cast<SingleShootingMode*>(m_shootingMode)) {
        m_shootingMode = DOUBLE_SHOOTING_MODE;
    }

}

void PlayerA::setFactory(IGameObjectFactory* factory)
{
    m_factory = factory;
}
