#pragma once

#include "Math.h"
#include "IObservable.h"
#include "IMovingStrategy.h"

#include <functional>
#include <vector>
#include <unordered_set>

class Game;
class GameObject;
class AbsPlayer;
class AbsMissile;
class IGameObjectFactory;

class Model : public IObservable
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

	void destroyMissiles(){};
	void toggleMovingStrategy();
	void toggleShootingMode();

	IMovingStrategy* getMovingStrategy() const;

	AbsPlayer* getPlayer() const;
	std::vector<GameObject*> getObjects() const;
	std::vector<AbsMissile*> getMissiles() const;

	void registerObserver(IObserver* observer) override;
	void unregisterObserver(IObserver* observer) override;
	void notifyObservers() override;

private:
	Game* m_game;
	IGameObjectFactory* m_objectFactory;
	std::unordered_set<IObserver*> m_observers;

	AbsPlayer* m_player;
	std::vector<AbsMissile*> m_missiles;
	int m_movingStrategyIndex = 0;

	void Update(float dt);
	void moveMissiles();

	friend class Game;
};

