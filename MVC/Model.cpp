#include "Model.h"

#include <algorithm>
#include <sstream>

#include "GameObjectFactoryA.h"
#include "Game.h"
#include "GameObject.h"
#include "PlayerA.h"
#include "AbsMissile.h"
#include "AbsEnemy.h"

#include "SimpleMovingStrategy.h"
#include "RealisticMovingStrategy.h"
#include "RandomMovingStrategy.h"

#include "AbstractGameCommand.h"

#include "Configuration.h"


static std::vector<IMovingStrategy*> s_movingStrategies = {
	new SimpleMovingStrategy(),
	new RealistingMovingStrategy(),
	new RandomMovingStrategy(),
};


Model::Model() :
	m_player(nullptr),
	m_windowSize({ 0, 0, WindowWidth, WindowHeight })
{
	m_objectFactory = new GameObjectFactoryA(this);
	m_player = m_objectFactory->createPlayer({ PlayerX, WindowHeight / 2 });
}

void Model::moveUp()
{
	m_player->moveUp();
	notifyObservers();
}

void Model::moveDown()
{
	m_player->moveDown();
	notifyObservers();
}

void Model::aimUp()
{
	m_player->aimUp();
	notifyObservers();
}

void Model::aimDown()
{
	m_player->aimDown();
	notifyObservers();
}

void Model::powerUp()
{
	m_player->powerUp();
	notifyObservers();
}

void Model::powerDown()
{
	m_player->powerDown();
	notifyObservers();
}

void Model::shoot()
{
	auto shotMissiles = m_player->shoot();
	m_missiles.insert(m_missiles.end(), shotMissiles.begin(), shotMissiles.end());
	notifyObservers();
}

void Model::destroyMissiles()
{
	auto newEnd = std::remove_if(m_missiles.begin(), m_missiles.end(), [&](AbsMissile* missile) {
		auto pos = missile->getPosition();
		if (pos.x > m_windowSize.w || pos.x < 0 || pos.y > m_windowSize.h || pos.y < 0) {
			delete missile;
			return true;
		}
		return false;
		});
	m_missiles.erase(newEnd, m_missiles.end());
}

void Model::destroyEnemies()
{
	auto newEnd = std::remove_if(m_enemies.begin(), m_enemies.end(), [&](AbsEnemy* enemy) {
		auto pos = enemy->getPosition();
		if (enemy->dead() && pos.x > m_windowSize.w || pos.x < 0 || pos.y > m_windowSize.h || pos.y < 0) {
			delete enemy;
			return true;
		}
		else if (pos.x <= PlayerX) {
			delete enemy;
			m_player->takeDamage(EnemyDamage);
			return true;
		}
		return false;
		});
	m_enemies.erase(newEnd, m_enemies.end());
}

void Model::toggleMovingStrategy()
{
	m_movingStrategyIndex = (m_movingStrategyIndex + 1) % s_movingStrategies.size();
}

void Model::toggleShootingMode()
{
	m_player->toggleShootingMode();
}

void Model::update(float dt)
{
	updateUI();

	moveMissiles(dt);
	moveEnemies(dt);
	checkCollisions();
	spawnEnemies();
	executeCommands();	
}

void Model::setWindowSize(Rect<int> dims)
{
	m_windowSize = dims;
}

Rect<int> Model::getWindowSize() const
{
	return m_windowSize;
}

Model::GameInfo Model::getGameInfo() const
{
	return {
		m_score,
		m_enemies.size(),
		m_player->getPower(),
		m_player->getAngle(),
		m_player->getHP(),
	};
}

void Model::moveMissiles(float dt)
{
	for (auto& m : m_missiles) {
		m->move(dt);
	}
	destroyMissiles();
	notifyObservers();
}

void Model::moveEnemies(float dt)
{
	for (auto& e : m_enemies) {
		e->move(dt);
	}
	destroyEnemies();
	notifyObservers();
}

void Model::executeCommands()
{
	while (!m_unexecutedCommands.empty()) {
		auto cmd = m_unexecutedCommands.front();
		m_unexecutedCommands.pop();
		cmd->doExecute();
		m_executedCommands.push(cmd);
	}
}

void Model::spawnEnemies()
{
	Vec2<int> min, max;

	//min = { m_windowSize.w - 150, 25 };
	//max = { m_windowSize.w - 25, m_windowSize.h - 75 };

	min = { m_windowSize.w, 25 };
	max = { m_windowSize.w + 10, m_windowSize.h - 75 };

	if (m_enemies.size() < getEnemyCount() && rand() % 100 == 0) {
		m_enemies.push_back(m_objectFactory->createEnemy(min, max));
	}
}

void Model::checkCollisions()
{
	for (auto& m : m_missiles) {
		for (auto& e : m_enemies) {
			if (m->checkCollision(e)) {
				if(m->onHit(e) && e->dead()) {
					m_score += EnemyKillScore;
				}
			}
		}
	}
}

void Model::updateUI()
{
	auto info = getGameInfo();
	std::stringstream text;
	text << "Shooting mode: " << m_player->activeShootingMode()->name();
	text << " | Movement: " << s_movingStrategies[m_movingStrategyIndex]->name() << std::endl;
	text << "HP: " << info.hp << "/" << PlayerHealth << " | Score: " << info.score << " | Power: " << info.power << std::endl;

	m_gameInfo.setText(text.str());
}

int Model::getEnemyCount() const
{
	return 5 + EnemyCountCoef * m_score;
}

float Model::getEnemySpeed() const {
	return 1.f + EnemySpeedCoef * sqrt(m_score);
}

IModel::Memento* Model::createMemento()
{
	auto plr = getPlayer();
	return new Memento{ 
		plr->getPosition(),
		plr->getAngle(),
		plr->getPower()
	};
}

void Model::setMemento(Memento* memento)
{
	auto plr = getPlayer();
	plr->setPos(memento->position);
	plr->setAngle(memento->angle);
	plr->setPower(memento->velocity);
}

void Model::registerCommand(AbstractGameCommand* cmd)
{
	m_unexecutedCommands.push(cmd);
}

void Model::undoLastCommand()
{
	if (!m_executedCommands.empty()) {
		m_executedCommands.top()->undoExecute();
		m_executedCommands.pop();
		notifyObservers();
	}
}


IMovingStrategy* Model::getMovingStrategy() const
{
	return s_movingStrategies[m_movingStrategyIndex];
}

AbsPlayer* Model::getPlayer() const
{
	return m_player;
}

std::vector<GameObject*> Model::getObjects() const
{
	auto objects = std::vector<GameObject*>{ m_player };
	objects.insert(objects.end(), m_missiles.begin(), m_missiles.end());
	objects.insert(objects.end(), m_enemies.begin(), m_enemies.end());
	return objects;
}

std::vector<GameObject*> Model::getUIObjects() const
{
	return m_uiObjects;
}

void Model::registerObserver(IObserver* observer)
{
	m_observers.insert(observer);
}

void Model::unregisterObserver(IObserver* observer)
{
	m_observers.erase(observer);
}

void Model::notifyObservers()
{
	for (auto o : m_observers) {
		o->update();
	}
}
