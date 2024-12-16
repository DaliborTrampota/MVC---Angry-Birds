#pragma once

#include "SDLController.h"
#include "SDLDrawer.h"
#include "IView.h"
#include "IObserver.h"

#include <unordered_map>
#include <string>

class IModel;

// SDL2 View
class SDLView : public IObserver // : public IView
{
public:
	SDLView(IModel* model);

	void render();
	void update() override;

	Rect<int> getWindowRect() const;
	SDLController* getController();

private:
	IModel* m_model;
	SDLController m_cont;
	SDLDrawer m_gameDrawer;
};

