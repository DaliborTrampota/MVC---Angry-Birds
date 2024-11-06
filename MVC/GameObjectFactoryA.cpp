#include "GameObjectFactoryA.h"

#include "Model.h"
#include "PlayerA.h"
#include "MissileA.h"

AbsPlayer* GameObjectFactoryA::createPlayer()
{
    auto player = new PlayerA({ 20, 200 }, "cannon.png");
    player->setFactory(this);
    return player;
}

AbsMissile* GameObjectFactoryA::createMissile()
{
    return new MissileA(m_model->getPlayer()->getPosition(), "missile.png");
}
