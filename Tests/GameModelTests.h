#pragma once


#include "TestClient.h"


#include "../MVC/Model.h"
#include "../MVC/AbsPlayer.h"
#include "../MVC/PlayerA.h"




class MockedModel : public Model {
public:
    AbsPlayer* getPlayer() const override {
        return new PlayerA({ 10, 50 });
    }

    void moveMissiles() {
        Model::moveMissiles(0.01);
    }
};


void undoLastCommand();
void createMissileTest();
void moveMissileTest();