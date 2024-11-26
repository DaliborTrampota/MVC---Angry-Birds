#include "GameObjectFactoryA.h"

#include "Model.h"
#include "PlayerA.h"
#include "MissileA.h"

AbsPlayer* GameObjectFactoryA::createPlayer(Vec2<int> pos)
{
    auto player = new PlayerA(pos, "cannon.png");
    player->setFactory(this);
    return player;
}

AbsMissile* GameObjectFactoryA::createMissile(float initAngle, float initVelocity)
{
    return new MissileA(m_model->getPlayer()->getPosition(), "missile.png", initAngle, initVelocity);
}
