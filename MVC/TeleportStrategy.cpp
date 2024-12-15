#include "TeleportStrategy.h"
#include "GameObject.h"
#include <cstdlib>

void TeleportStrategy::updatePosition(GameObject* obj, float dt)
{
	if (random() == 0) {
		auto curPos = obj->getPosition();
		auto dims = m_model->getWindowSize();
		Vec2<float> newPos = { curPos.x - (random() % 40 + 5), random() % (dims.h - 60) + 10 };
		obj->setPos(newPos);
	}
}
