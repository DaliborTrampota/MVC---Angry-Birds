#include "PushStraighStrategy.h"

#include "Configuration.h"
#include "GameObject.h"
#include "AbsEnemy.h"


void PushStraightStrategy::updatePosition(GameObject* obj, float dt)
{
	AbsEnemy* enemy = dynamic_cast<AbsEnemy*>(obj);
	enemy->move({ -1, 0 }, dt);
}
