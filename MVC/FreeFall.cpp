#include "FreeFall.h"

#include "MovingGameObject.h"

void FreeFall::updatePosition(GameObject* obj, float dt)
{
	auto mobj = dynamic_cast<MovingGameObject*>(obj);

	if (!mobj->affectedByGravity())
		mobj->useGravity(true);

	mobj->move({ 0, 0 }, dt);
}
