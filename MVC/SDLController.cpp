#include "SDLController.h"

#include "Model.h"
#include "MyMath.h"
#include "SDL2/SDL.h"

#include "MovePlrDownCmd.h"
#include "MovePlrUpCmd.h"
#include "UniversalCmd.h"

#include "CareTaker.h"

#define CheckPress(states, keyCode, singleShot) if (states[keyCode]) onKeyPress(keyCode, singleShot);


SDLController::SDLController(IModel* model) : m_model(model)
{
}

void SDLController::onKeyPress(SDL_Scancode key, bool singleShot)
{
	if (singleShot) {
		if (m_states[key]) return;
		m_states[key] = 1;
	}

	switch (key) {
	case SDL_SCANCODE_UP:
		m_model->registerCommand(new MovePlrUpCmd(m_model));
		break;

	case SDL_SCANCODE_DOWN:
		m_model->registerCommand(new MovePlrDownCmd(m_model));
		break;

	case SDL_SCANCODE_SPACE:
		m_model->registerCommand(new UniversalCmd(m_model, std::bind(&IModel::shoot, m_model)));
		break;

	case SDL_SCANCODE_A:
		m_model->registerCommand(new UniversalCmd(m_model, std::bind(&IModel::aimUp, m_model)));
		break;

	case SDL_SCANCODE_Z:
		m_model->registerCommand(new UniversalCmd(m_model, std::bind(&IModel::aimDown, m_model)));
		break;

	case SDL_SCANCODE_F:
		m_model->registerCommand(new UniversalCmd(m_model, std::bind(&IModel::powerUp, m_model)));
		break;

	case SDL_SCANCODE_D:
		m_model->registerCommand(new UniversalCmd(m_model, std::bind(&IModel::powerDown, m_model)));
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

	case SDL_SCANCODE_Y:
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

	case SDL_KEYUP:
		if (m_states[e.key.keysym.scancode]) {
			m_states[e.key.keysym.scancode] = 0;
		}
		break;

	case SDL_WINDOWEVENT:
		if (e.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
			m_model->setWindowSize({ 0, 0, e.window.data1, e.window.data2 });
		}
		break;
	}
	processInputs();
}


void SDLController::processInputs()
{
	const Uint8* keyStates = SDL_GetKeyboardState(NULL);

	CheckPress(keyStates, SDL_SCANCODE_UP, false)
	CheckPress(keyStates, SDL_SCANCODE_DOWN, false)
	CheckPress(keyStates, SDL_SCANCODE_SPACE, true)
	CheckPress(keyStates, SDL_SCANCODE_A, false);
	CheckPress(keyStates, SDL_SCANCODE_Z, false);
	CheckPress(keyStates, SDL_SCANCODE_F, true);
	CheckPress(keyStates, SDL_SCANCODE_D, true);
	CheckPress(keyStates, SDL_SCANCODE_M, true);
	CheckPress(keyStates, SDL_SCANCODE_N, true);
	CheckPress(keyStates, SDL_SCANCODE_S, true);
	CheckPress(keyStates, SDL_SCANCODE_R, true);
	CheckPress(keyStates, SDL_SCANCODE_Y, true);
}
