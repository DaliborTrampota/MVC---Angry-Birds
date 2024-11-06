#pragma once

#include "Controller.h"
#include "SDLDrawer.h"

#include <unordered_map>
#include <string>


class Model;
class GameObject;
struct SDL_Rect;


// SDL2 View
class View
{
public:
	View() = default;
	View(Model* model);

	void render();
	SDL_Rect getWindowRect() const;

	Controller* getController() {
		return &m_cont;
	}

private:
	Model* m_model;
	Controller m_cont;
	SDLDrawer m_gameDrawer;
};

