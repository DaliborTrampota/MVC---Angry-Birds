#pragma once

class AbsPlayer;
class AbsMissile;

class IGameObjectFactory {
public:
	virtual AbsPlayer* createPlayer() = 0;
	virtual AbsMissile* createMissile() = 0;
};