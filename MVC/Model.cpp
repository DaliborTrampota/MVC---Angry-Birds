#include "Model.h"

#include "GameObjectFactoryA.h"
#include "Game.h"
#include "GameObject.h"
#include "PlayerA.h"
#include "AbsMissile.h"

Model::Model(Game* game) : 
	m_game(game)
{
	m_objectFactory = new GameObjectFactoryA(this);
	m_player = m_objectFactory->createPlayer();
	

}

void Model::aimUp()
{
	m_player->aimUp();
}

void Model::aimDown()
{
	m_player->aimDown();
}

void Model::shoot()
{
	AbsMissile* missile = m_player->shoot();
	m_missiles.push_back(missile);
}

void Model::Update(float dt)
{

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
