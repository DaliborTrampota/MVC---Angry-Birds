#include "AbsEnemy.h"

void AbsEnemy::acceptVisitor(IVisitor* visitor)
{
	visitor->visitObject(this);
}
