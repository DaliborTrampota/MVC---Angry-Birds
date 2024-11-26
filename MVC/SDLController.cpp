#include "SDLController.h"

#include "Model.h"
#include "Math.h"


#include "SDL2/SDL.h"

SDLController::SDLController(Model* model) : m_model(model)
{
}

void SDLController::onKeyPress(SDL_Scancode key)
{
	switch (key) {
	case SDL_SCANCODE_W:
		m_model->moveUp();
		break;

	case SDL_SCANCODE_S:
		m_model->moveDown();
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
