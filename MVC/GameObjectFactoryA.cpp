#include "GameObjectFactoryA.h"

#include "IModel.h"
#include "PlayerA.h"
#include "MissileA.h"
#include "EnemyA.h"


#include "IMovingStrategy.h"
#include "PushStraighStrategy.h"

static std::vector<IMovingStrategy*> s_enemyMovingStrategies = {
    new PushStraightStrategy(),
};



AbsPlayer* GameObjectFactoryA::createPlayer(Vec2<float> pos)
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

AbsEnemy* GameObjectFactoryA::createEnemy(Vec2<int> min, Vec2<int> max)
{
    int x = rand() % (max.x - min.x) + min.x;
    int y = rand() % (max.y - min.y) + min.y;

    IMovingStrategy* randomStrategy = s_enemyMovingStrategies[rand() % s_enemyMovingStrategies.size()];

    return new EnemyA({ (float)x, (float)y }, randomStrategy);
}
