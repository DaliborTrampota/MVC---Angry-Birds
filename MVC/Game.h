#pragma once

#include "View.h"
#include "Model.h"
#include "Controller.h"


class Game
{
public:
	Game();

	void Run();


private:
	Model m_model;
	View m_view;
	Controller* m_controller;

};

