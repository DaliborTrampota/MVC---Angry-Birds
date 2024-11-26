#pragma once

#include "IController.h"

#include "SDL2/SDL.h"
#undef main


class Model;

// SDL2 Controller
class SDLController // : public IController<SDL_Scancode>
{
public:
	SDLController() = default;
	SDLController(Model* model);


	void onKeyPress(SDL_Scancode key);

private:
	Model* m_model;
	bool m_exit = false;


	void pollEvents();

	friend class Game;
};

