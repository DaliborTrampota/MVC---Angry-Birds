#pragma once

#include "MyMath.h"

class IController;

class IView {
public:
	virtual void render() = 0;
	virtual Rect<int> getWindowRect() const = 0;
	virtual IController* getController() const = 0;
};