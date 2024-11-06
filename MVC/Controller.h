#pragma once

#include "SDL2/SDL.h"
#undef main

class Model;

// SDL2 Controller
class Controller
{
public:
	Controller() = default;
	Controller(Model* model);


	void onKeyPress(SDL_Scancode key);

private:
	Model* m_model;
	bool m_exit = false;


	void pollEvents();

	friend class Game;
};

