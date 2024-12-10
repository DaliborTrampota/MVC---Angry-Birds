#pragma once

#include "AbstractGameCommand.h"

class MovePlrDownCmd : public AbstractGameCommand {

	using AbstractGameCommand::AbstractGameCommand;

	void execute() override {
		m_model->moveDown();
	}

};