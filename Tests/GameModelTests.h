#pragma once


#include "TestClient.h"


#include "../MVC/Model.h"
#include "../MVC/AbsPlayer.h"
#include "../MVC/PlayerA.h"
#include "../MVC/GameObjectFactoryA.h"




class MockedModel : public Model {
public:
    MockedModel() {
        m_activeScreen = Screens::Play;
        m_player = new PlayerA({ 10, 50 });
        static_cast<PlayerA*>(m_player)->setFactory(new GameObjectFactoryA(this));
    }

    AbsPlayer* getPlayer() const override {
        return m_player;
    }

    void moveMissiles() {
        Model::moveMissiles(0.01);
    }
};


void undoLastCommand();
void createMissileTest();
void moveMissileTest();