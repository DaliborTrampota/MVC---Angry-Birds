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

#include "Frame.h"
#include "Button.h"
#include "Text.h"

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
	createScreens();
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
	
	if (m_player->getHP() <= 0) {
		m_activeScreen = Screens::GameOver;
		notifyObservers();
		/*if (m_uiObjects.size() != 2) {
			Rect<int> scr = getWindowSize();
			TextObject* gameOver = new TextObject("Game over!", { scr.w / 2 - 80, scr.h / 2 }, 32);
			m_uiObjects.push_back(gameOver);
			notifyObservers();
		}*/
		return;
	}

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
	if (m_activeScreen == Screens::Play) {
		Text* infoText = dynamic_cast<Text*>(m_screens[m_activeScreen]->get(0));

		auto info = getGameInfo();
		std::stringstream text;
		text << "Shooting mode: " << m_player->activeShootingMode()->name();
		text << " | Movement: " << s_movingStrategies[m_movingStrategyIndex]->name() << std::endl;
		text << "HP: " << info.hp << "/" << PlayerHealth << " | Score: " << info.score << " | Power: " << info.power << std::endl;

		infoText->setText(text.str());
	}
}

int Model::getEnemyCount() const
{
	return 5 + EnemyCountCoef * m_score;
}

void Model::createScreens()
{
	Frame* playInterface = new Frame({ 0, 0, 1, 1 });
	playInterface->add(new Text("GameInfo", { 0, 0 }));

	Frame* welcomeScr = new Frame({ 0, 0, 1, 1 });
	welcomeScr->add(new Button({0.4, 0.46, 0.2, 0.08 }, "Play", [this]() {
		m_activeScreen = Screens::Play;
		}));

	Frame* gameOver = new Frame({ 0, 0, 1, 1 });
	gameOver->add((new Text("Game Over!", { 0.5, 0.5 }, 32))->setAlignment(Text::Middle, Text::Center));
	gameOver->add(new Button({ 0.45, 0.75, 0.1, 0.08 }, "Quit", [this]() {
		m_quit = true;
		}));

	m_screens[Screens::Menu] = welcomeScr;
	m_screens[Screens::Play] = playInterface;
	m_screens[Screens::GameOver] = gameOver;
}

float Model::getEnemySpeed() const {
	return 1.f + EnemySpeedCoef * sqrt(m_score);
}

bool Model::quit() const
{
	return m_quit;
}



// Commands ============================
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

Frame* Model::getActiveScreen()
{
	return m_screens[m_activeScreen];
}

void Model::mouseClicked(int btn, Vec2<int> pos)
{
	if (btn == 1) {
		Frame* screen = getActiveScreen();

		for (auto& clickable : screen->getAll<IClickable>(true)) {
			clickable->processClick(pos);
		}
	}
}

// Observer ============================
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
