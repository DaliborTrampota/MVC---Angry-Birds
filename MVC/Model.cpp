#include "Model.h"

#include "GameObjectFactoryA.h"
#include "Game.h"
#include "GameObject.h"
#include "PlayerA.h"
#include "AbsMissile.h"

#include "Configuration.h"

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
	m_missiles.push_back(m_player->shoot());
	notifyObservers();
}

void Model::Update(float dt)
{
	moveMissiles();
}

void Model::moveMissiles()
{
	for (auto& m : m_missiles) {
		m->move({ 1, 0 });
	}
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
