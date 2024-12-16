#pragma once

#include "MyMath.h"

class IClickable {
public:
	virtual void onClick() = 0;
	virtual void processClick(Vec2<int> clickPos) = 0;
};