#include "Game.h"

#include <chrono>

#include "GameModelProxy.h"
#include "SDLController.h"
#include "CareTaker.h"

Game::Game()
{
	m_model = new GameModelProxy(new Model(this));
	m_view = SDLView(m_model);
	m_controller = m_view.getController();

	CareTaker::get()->setModel(m_model);

	Run();
}

void Game::Run()
{
	using ms = std::chrono::duration<float, std::milli>;
	auto prevTime = std::chrono::steady_clock::now();
	float deltaTime;
	while (!m_controller->m_exit) {
		auto curTime = std::chrono::steady_clock::now();
		deltaTime = (prevTime - curTime).count();

		m_controller->pollEvents();
		m_view.render();
		m_model->update(deltaTime);

		prevTime = curTime;
	}
}

Rect<int> Game::getWindowRect() const
{
	return m_view.getWindowRect();
}

