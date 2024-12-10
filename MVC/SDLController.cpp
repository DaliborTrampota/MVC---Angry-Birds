#include "SDLController.h"

#include "Model.h"
#include "Math.h"
#include "SDL2/SDL.h"

#include "MovePlrDownCmd.h"
#include "MovePlrUpCmd.h"

#include "CareTaker.h"

SDLController::SDLController(IModel* model) : m_model(model)
{
}

void SDLController::onKeyPress(SDL_Scancode key)
{
	switch (key) {
	case SDL_SCANCODE_UP:
		m_model->registerCommand(new MovePlrUpCmd(m_model));
		break;

	case SDL_SCANCODE_DOWN:
		m_model->registerCommand(new MovePlrDownCmd(m_model));
		break;

	case SDL_SCANCODE_SPACE:
		m_model->shoot();
		break;

	case SDL_SCANCODE_A:
		m_model->aimUp();
		break;

	case SDL_SCANCODE_Y:
		m_model->aimDown();
		break;

	case SDL_SCANCODE_F:
		m_model->powerUp();
		break;

	case SDL_SCANCODE_D:
		m_model->powerDown();
		break;

	case SDL_SCANCODE_M:
		m_model->toggleMovingStrategy();
		break;

	case SDL_SCANCODE_N:
		m_model->toggleShootingMode();
		break;

	case SDL_SCANCODE_S:
		CareTaker::get()->createMemento();
		break;

	case SDL_SCANCODE_R:
		CareTaker::get()->restoreMemento();
		break;

	case SDL_SCANCODE_Z:
		m_model->undoLastCommand();
		break;


	case SDL_SCANCODE_ESCAPE:
		m_exit = true;
	}
}



void SDLController::pollEvents()
{
	SDL_Event e;
	SDL_PollEvent(&e);
	switch (e.type) {
	case SDL_QUIT:
		m_exit = true;
		break;

	case SDL_KEYDOWN:
		onKeyPress(e.key.keysym.scancode);
		break;
	}
}
