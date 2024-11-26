#pragma once

#include "Math.h"

#include <functional>
#include <vector>

class Game;
class GameObject;
class AbsPlayer;
class AbsMissile;
class IGameObjectFactory;

class Model
{

public:
	Model() = delete;
	Model(Game* game);

	void init();

	void moveUp();
	void moveDown();
	void aimUp();
	void aimDown();
	void powerUp();
	void powerDown();
	void shoot();

	AbsPlayer* getPlayer() const;
	std::vector<GameObject*> getObjects() const;

private:
	Game* m_game;
	IGameObjectFactory* m_objectFactory;

	AbsPlayer* m_player;
	std::vector<AbsMissile*> m_missiles;

	void Update(float dt);

	friend class Game;
};

