#pragma once

#include "IModel.h"

class AbstractGameCommand {
public:
	AbstractGameCommand(IModel* model) : m_model(model), m_memento(nullptr) {};

	AbstractGameCommand* doExecute() {
		m_memento = m_model->createMemento();
		execute();
		return this;
	}

	void undoExecute() {
		m_model->setMemento(m_memento);
	}

protected:
	virtual void execute() = 0;
	IModel* m_model;
	IModel::Memento* m_memento;

};