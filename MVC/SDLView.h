#pragma once

#include "SDLController.h"
#include "SDLDrawer.h"
#include "IView.h"

#include <unordered_map>
#include <string>

class Model;
class GameObject;
struct SDL_Rect;


// SDL2 View
class SDLView // : public IView
{
public:
	SDLView() = default;
	SDLView(Model* model);

	void render();
	Rect<int> getWindowRect() const;

	SDLController* getController() {
		return &m_cont;
	}

private:
	Model* m_model;
	SDLController m_cont;
	SDLDrawer m_gameDrawer;
};

