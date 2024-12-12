#include "GameModelTests.h"

#include <iostream>

#include "../MVC/Configuration.h"

#include "../MVC/Model.h"
#include "../MVC/AbsPlayer.h"
#include "../MVC/PlayerA.h"
#include "../MVC/MovePlrUpCmd.h"
#include "../MVC/IGameObjectFactory.h"
#include "../MVC/GameObjectFactoryA.h"



void undoLastCommand()
{
    IModel* model = new Model();
    auto plr = model->getPlayer();
    auto beginPos = plr->getPosition();

    model->registerCommand(new MovePlrUpCmd(model));
    model->update(0.01f);
    
    TestAssert(beginPos.y - PlayerMoveSpeed == plr->getPosition().y);
    model->undoLastCommand();
    TestAssert(beginPos.y == plr->getPosition().y);
}

void createMissileTest()
{
    IModel* model = new MockedModel();
    IGameObjectFactory* factory = new GameObjectFactoryA(model);
    AbsMissile* missile = factory->createMissile(InitAngle, InitPower);

    auto plrPos = model->getPlayer()->getPosition();

    TestAssert(plrPos.x == missile->getPosition().x);
    TestAssert(plrPos.y == missile->getPosition().y);
}

void moveMissileTest()
{
    MockedModel* model = new MockedModel();

    const int MISSILE_COUNT = 50;
    const int EXPECTED_COUNT = 0;
    const int MOVES = 100000;
    const int AIM_COUNT = 10;

    for (int i = 0; i < AIM_COUNT; ++i)
        model->aimUp();

    for (int i = 0; i < MISSILE_COUNT; ++i)
        model->shoot();

    TestAssert(model->getObjects().size() - 1 == MISSILE_COUNT);

    for (int i = 0; i < MOVES; ++i)
        model->moveMissiles();

    TestAssert(model->getObjects().size() - 1 == EXPECTED_COUNT);
}

