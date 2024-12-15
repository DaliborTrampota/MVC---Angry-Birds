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


	void onKeyPress(SDL_Scancode key);

private:
	IModel* m_model;
	bool m_exit = false;


	void pollEvents();
	void processInputs();

	friend class Game;
};

