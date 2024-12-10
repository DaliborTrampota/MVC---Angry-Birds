#pragma once

#include "SDLView.h"
#include "IModel.h"
#include "Math.h"

class SDLController;

class Game
{
public:
	Game();

	void Run();

	Rect<int> getWindowRect() const;

private:
	IModel* m_model;
	SDLView m_view;
	SDLController* m_controller;

};

