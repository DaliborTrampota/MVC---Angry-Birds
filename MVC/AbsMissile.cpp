#include "AbsMissile.h"
#include "sstream"

void AbsMissile::acceptVisitor(IVisitor* visitor)
{
	visitor->visitMissile(this);
}

inline const char* AbsMissile::s_getName(const char* name)
{
	std::stringstream newName;
	newName << name << "_" << AbsMissile::s_ID;
	return newName.str().c_str();
}
