#include "CareTaker.h"

CareTaker* CareTaker::get()
{
	static CareTaker* s_instance = new CareTaker();
	return s_instance;
}

void CareTaker::setModel(IModel* model)
{
	m_model = model;
}

void CareTaker::createMemento()
{
	assert(m_model);
	m_mementos.push(m_model->createMemento());
}

void CareTaker::restoreMemento()
{
	assert(m_model);
	if (!m_mementos.empty()) {
		m_model->setMemento(m_mementos.top());
		m_mementos.pop();
	}
}
