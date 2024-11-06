#pragma once

#include "AbsMissile.h"

class MissileA : public AbsMissile
{
public:
	using AbsMissile::AbsMissile;
	//MissileA(const char* name, const char* textureName) : AbsMissile(name, textureName) {}
};

