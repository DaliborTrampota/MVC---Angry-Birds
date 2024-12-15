#pragma once

#include "MyMath.h"
#include "IModel.h"
#include "IMovingStrategy.h"

#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>

class Game;
class GameObject;
class AbsPlayer;
class AbsMissile;
class AbsEnemy;
class IGameObjectFactory;
class AbstractGameCommand;

class Model : public IModel
{
public:
	Model();

	void moveUp() override;
	void moveDown() override;
	void aimUp() override;
	void aimDown() override;
	void powerUp() override;
	void powerDown() override;
	void shoot() override;

	void toggleMovingStrategy() override;
	void toggleShootingMode() override;


	AbsPlayer* getPlayer() const override;
	std::vector<GameObject*> getObjects() const override;
	IMovingStrategy* getMovingStrategy() const override;

	Memento* createMemento() override;
	void setMemento(Memento* memento) override;
	void registerCommand(AbstractGameCommand* cmd) override;
	void undoLastCommand() override;

	void registerObserver(IObserver* observer) override;
	void unregisterObserver(IObserver* observer) override;
	void notifyObservers() override;

	void update(float dt) override;

	void setWindowSize(Rect<int> dims) override;
	Rect<int> getWindowSize() const override;

	float getEnemySpeed() const override;

protected:
	void moveMissiles(float dt);
	void moveEnemies(float dt);
	void destroyMissiles();
	void destroyEnemies();
	void executeCommands();
	void spawnEnemies();
	void checkCollisions();
	int getEnemyCount() const;


	IGameObjectFactory* m_objectFactory;
	std::unordered_set<IObserver*> m_observers;

	AbsPlayer* m_player;
	std::vector<AbsMissile*> m_missiles;
	std::vector<AbsEnemy*> m_enemies;
	int m_movingStrategyIndex = 0;

	std::queue<AbstractGameCommand*> m_unexecutedCommands;
	std::stack<AbstractGameCommand*> m_executedCommands;

	Rect<int> m_windowSize;

	int m_score = 0;
};

