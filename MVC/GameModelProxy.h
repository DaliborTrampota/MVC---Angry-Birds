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

	void moveDown() override {
		m_subject->moveDown();
	}

	void aimUp() override {
		m_subject->aimUp();
	}

	void aimDown() override {
		m_subject->aimDown();
	}
	void powerUp() override {
		m_subject->powerUp();
	}
	void powerDown() override {
		m_subject->powerDown();
	}
	void shoot() override {
		m_subject->shoot();
	}

	void toggleMovingStrategy() override {
		m_subject->toggleMovingStrategy();
	}

	void toggleShootingMode() override {
		m_subject->toggleShootingMode();
	}

	AbsPlayer* getPlayer() const override {
		return m_subject->getPlayer();
	}

	std::vector<GameObject*> getObjects() const override {
		return m_subject->getObjects();
	}

	Frame* getActiveScreen() override {
		return m_subject->getActiveScreen();
	}

	void mouseClicked(int btn, Vec2<int> pos) override {
		m_subject->mouseClicked(btn, pos);
	}

	IMovingStrategy* getMovingStrategy() const override {
		return m_subject->getMovingStrategy();
	}

	Memento* createMemento() override {
		return m_subject->createMemento();
	}
	void setMemento(Memento* memento) override {
		m_subject->setMemento(memento);
	}
	void registerCommand(AbstractGameCommand* cmd) override {
		m_subject->registerCommand(cmd);
	}
	void undoLastCommand() override {
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

	void setWindowSize(Rect<int> dims) override {
		m_subject->setWindowSize(dims);
	}

	Rect<int> getWindowSize() const override {
		return m_subject->getWindowSize();
	}

	GameInfo getGameInfo() const override {
		return m_subject->getGameInfo();
	}

	float getEnemySpeed() const override {
		return m_subject->getEnemySpeed();
	}

	bool quit() const override {
		return m_subject->quit();
	}

	void update(float dt) override {
		m_subject->update(dt);
	}

private:
	Model* m_subject;
};

