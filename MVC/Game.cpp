#include "Game.h"

#include "SDLController.h"
#include <chrono>

Game::Game()
{	
	m_model = new Model(this);
	m_view = SDLView(m_model);
	m_controller = m_view.getController();

	m_model->init();

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
		m_model->Update(deltaTime);

		prevTime = curTime;
	}
}

Rect<int> Game::getWindowRect() const
{
	return m_view.getWindowRect();
}

