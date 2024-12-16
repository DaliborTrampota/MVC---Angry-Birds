#include "Game.h"

#include <chrono>

#include "GameModelProxy.h"
#include "SDLController.h"
#include "CareTaker.h"

Game::Game() :
	m_model(new GameModelProxy(new Model())),
	m_view(m_model),
	m_controller(m_view.getController())
{
	CareTaker::get()->setModel(m_model);

	Run();
}

void Game::Run()
{
	using ms = std::chrono::duration<float, std::milli>;
	auto prevTime = std::chrono::steady_clock::now();
	float deltaTime;
	while (!m_controller->quit() && !m_model->quit()) {
		auto curTime = std::chrono::steady_clock::now();
		deltaTime = std::chrono::duration<float>(curTime - prevTime).count();

		m_controller->pollEvents();
		m_model->update(deltaTime);
		//printf("FPS: %i\n", (int)(1.f / deltaTime));
		prevTime = curTime;
	}
}
