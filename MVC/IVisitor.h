#pragma once

class AbsPlayer;
class AbsMissile;

class IVisitor {
public:
	virtual void visitPlayer(AbsPlayer* player) = 0;
	virtual void visitMissile(AbsMissile* missile) = 0;
};