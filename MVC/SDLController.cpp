#include "SDLController.h"

#include "Model.h"
#include "MyMath.h"
#include "SDL2/SDL.h"

#include "MovePlrDownCmd.h"
#include "MovePlrUpCmd.h"
#include "UniversalCmd.h"

#include "CareTaker.h"

#define CheckPress(states, keyCode) if (states[keyCode]) onKeyPress(keyCode);


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
		m_model->registerCommand(new UniversalCmd(m_model, std::bind(&IModel::shoot, m_model)));
		break;

	case SDL_SCANCODE_A:
		m_model->registerCommand(new UniversalCmd(m_model, std::bind(&IModel::aimUp, m_model)));
		break;

	case SDL_SCANCODE_Y:
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

	CheckPress(keyStates, SDL_SCANCODE_UP);
	CheckPress(keyStates, SDL_SCANCODE_DOWN);
	CheckPress(keyStates, SDL_SCANCODE_SPACE);
	CheckPress(keyStates, SDL_SCANCODE_A);
	CheckPress(keyStates, SDL_SCANCODE_Y);
	CheckPress(keyStates, SDL_SCANCODE_F);
	CheckPress(keyStates, SDL_SCANCODE_D);
	CheckPress(keyStates, SDL_SCANCODE_M);
	CheckPress(keyStates, SDL_SCANCODE_N);
	CheckPress(keyStates, SDL_SCANCODE_S);
	CheckPress(keyStates, SDL_SCANCODE_R);
	CheckPress(keyStates, SDL_SCANCODE_Z);
}
