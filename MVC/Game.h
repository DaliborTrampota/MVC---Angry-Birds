#pragma once

#include "SDLView.h"
#include "IModel.h"
#include "MyMath.h"

class SDLController;

class Game
{
public:
	Game();

	void Run();

private:
	IModel* m_model;
	SDLView m_view;
	SDLController* m_controller;

};

