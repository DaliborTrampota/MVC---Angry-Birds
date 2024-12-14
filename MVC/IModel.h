#pragma once

#include "MyMath.h"
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
class AbstractGameCommand;

class IModel : public IObservable
{

public:
	virtual void moveUp() = 0;
	virtual void moveDown() = 0;
	virtual void aimUp() = 0;
	virtual void aimDown() = 0;
	virtual void powerUp() = 0;
	virtual void powerDown() = 0;
	virtual void shoot() = 0;

	virtual void toggleMovingStrategy() = 0;
	virtual void toggleShootingMode() = 0;

	virtual AbsPlayer* getPlayer() const = 0;
	virtual std::vector<GameObject*> getObjects() const = 0;
	virtual IMovingStrategy* getMovingStrategy() const = 0;


	struct Memento {
		Vec2<float> position;
		float angle;
		int velocity;
	};

	virtual Memento* createMemento() = 0;
	virtual void setMemento(Memento* memento) = 0;
	virtual void registerCommand(AbstractGameCommand* cmd) = 0;
	virtual void undoLastCommand() = 0;

	virtual void update(float dt) = 0;

	virtual void setWindowSize(Rect<int> dims) = 0;
};

