#include "GameObjectFactoryA.h"

#include "IModel.h"
#include "PlayerA.h"
#include "MissileA.h"

AbsPlayer* GameObjectFactoryA::createPlayer(Vec2<int> pos)
{
    auto player = new PlayerA(pos);
    player->setTexture("cannon.png");
    player->setFactory(this);
    return player;
}

AbsMissile* GameObjectFactoryA::createMissile(float initAngle, float initVelocity)
{
    auto missile = new MissileA(m_model->getPlayer()->getPosition(), initAngle, initVelocity, m_model->getMovingStrategy());
    missile->setTexture("missile.png");
    return missile;
}
