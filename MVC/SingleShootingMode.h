#pragma once

#include "IShootingMode.h"

class SingleShootingMode : public IShootingMode {
public:
	const char* name() const override {
		return "SingleShootingMode";
	}

	void shoot(AbsPlayer* plr) const override;
};