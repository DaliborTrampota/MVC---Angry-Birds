#pragma once

#include "SDLView.h"
#include "Model.h"
#include "Math.h"

class SDLController;

class Game
{
public:
	Game();

	void Run();
	void Exit();

	Rect<int> getWindowRect() const;

private:
	Model* m_model;
	SDLView m_view;
	SDLController* m_controller;

};

