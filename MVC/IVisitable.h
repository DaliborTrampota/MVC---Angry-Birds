#pragma once

#include "IVisitor.h"


class IVisitable
{
public:
	virtual void acceptVisitor(IVisitor* visitor) = 0;
};

