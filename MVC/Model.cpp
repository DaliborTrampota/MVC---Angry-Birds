#include "Model.h"

#include "GameObjectFactoryA.h"
#include "Game.h"
#include "GameObject.h"
#include "PlayerA.h"
#include "AbsMissile.h"

#include "SimpleMovingStrategy.h"
#include "RealisticMovingStrategy.h"
#include "RandomMovingStrategy.h"

#include "Configuration.h"


static std::vector<IMovingStrategy*> s_movingStrategies = {
	new SimpleMovingStrategy(),
	new RealistingMovingStrategy(),
	new RandomMovingStrategy(),
};


Model::Model(Game* game) :
	m_game(game),
	m_player(nullptr)
{
	m_objectFactory = new GameObjectFactoryA(this);
}

void Model::init() 
{
	m_player = m_objectFactory->createPlayer({ PlayerX, m_game->getWindowRect().h / 2 }); // m_renderer null if in ctor, fix
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

void Model::toggleMovingStrategy()
{
	m_movingStrategyIndex = (m_movingStrategyIndex + 1) % s_movingStrategies.size();

}

void Model::toggleShootingMode()
{
	m_player->toggleShootingMode();
}

void Model::Update(float dt)
{
	moveMissiles();
}

void Model::moveMissiles()
{
	for (auto& m : m_missiles) {
		m->move();
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
	return objects;
}

std::vector<AbsMissile*> Model::getMissiles() const
{
	return m_missiles;
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
