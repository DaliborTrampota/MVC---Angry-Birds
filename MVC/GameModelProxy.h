#pragma once

#include "Model.h"
#include "IMovingStrategy.h"


class GameModelProxy : public IModel
{

public:
	GameModelProxy(Model* model) : m_subject(model) {};

	void moveUp() override {
		m_subject->moveUp();
	}

	virtual void moveDown() override {
		m_subject->moveDown();
	}

	virtual void aimUp() override {
		m_subject->aimUp();
	}

	virtual void aimDown() override {
		m_subject->aimDown();
	}
	virtual void powerUp() override {
		m_subject->powerUp();
	}
	virtual void powerDown() override {
		m_subject->powerDown();
	}
	virtual void shoot() override {
		m_subject->shoot();
	}

	virtual void toggleMovingStrategy() override {
		m_subject->toggleMovingStrategy();
	}

	virtual void toggleShootingMode() override {
		m_subject->toggleShootingMode();
	}

	virtual AbsPlayer* getPlayer() const override {
		return m_subject->getPlayer();
	}

	virtual std::vector<GameObject*> getObjects() const override {
		return m_subject->getObjects();
	}

	virtual IMovingStrategy* getMovingStrategy() const override {
		return m_subject->getMovingStrategy();
	}

	virtual Memento* createMemento() override {
		return m_subject->createMemento();
	}
	virtual void setMemento(Memento* memento) override {
		m_subject->setMemento(memento);
	}
	virtual void registerCommand(AbstractGameCommand* cmd) override {
		m_subject->registerCommand(cmd);
	}
	virtual void undoLastCommand() override {
		m_subject->undoLastCommand();
	}

	void registerObserver(IObserver* observer) override {
		m_subject->registerObserver(observer);
	}

	void unregisterObserver(IObserver* observer) override {
		m_subject->unregisterObserver(observer);
	}

	void notifyObservers() override {
		m_subject->notifyObservers();
	}

protected:
	virtual void update(float dt) override {
		m_subject->update(dt);
	}

private:
	Model* m_subject;
};

