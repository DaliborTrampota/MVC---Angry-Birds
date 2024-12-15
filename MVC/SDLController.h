#pragma once

#include "IController.h"

#include "SDL2/SDL.h"
#undef main



class IModel;

// SDL2 Controller
class SDLController// : public IController<SDL_Scancode>
{
public:
	SDLController() = default;
	SDLController(IModel* model);


	void onKeyPress(SDL_Scancode key, bool singleShot = false);

private:
	IModel* m_model;
	bool m_exit = false;
	Uint8* m_states = new Uint8(0);

	void pollEvents();
	void processInputs();

	friend class Game;
};

