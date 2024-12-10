#pragma once

#include "AbstractGameCommand.h"

class MovePlrUpCmd : public AbstractGameCommand {

	using AbstractGameCommand::AbstractGameCommand;

	void execute() override {
		m_model->moveUp();
	}

};