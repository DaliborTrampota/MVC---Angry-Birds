#pragma once


class AbsPlayer;

class IShootingMode {
public:
	virtual const char* name() const = 0;
	virtual void shoot(AbsPlayer* plr) const = 0;
};