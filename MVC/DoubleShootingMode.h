#pragma once

#include "IShootingMode.h"

class DoubleShootingMode : public IShootingMode {
public:
	const char* name() const override {
		return "DoubleShootingMode";
	}

	void shoot(AbsPlayer* plr) const override;
};