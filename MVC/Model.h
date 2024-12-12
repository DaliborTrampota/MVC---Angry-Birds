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

	void destroyMissiles(){};
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

	void update(float dt);

	void setWindowSize(Rect<int> dims);

protected:
	Game* m_game;
	IGameObjectFactory* m_objectFactory;
	std::unordered_set<IObserver*> m_observers;

	AbsPlayer* m_player;
	std::vector<AbsMissile*> m_missiles;
	int m_movingStrategyIndex = 0;

	void moveMissiles();
	void executeCommands();

	std::queue<AbstractGameCommand*> m_unexecutedCommands;
	std::stack<AbstractGameCommand*> m_executedCommands;

	Rect<int> m_windowSize;
};

