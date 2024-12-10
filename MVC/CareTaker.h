#pragma once

#include <stack>
#include <assert.h>
#include "IModel.h"

class CareTaker {
public:
	static CareTaker* get();

	void setModel(IModel* model);

	void createMemento();

	void restoreMemento();

private:
	CareTaker() = default;

	IModel* m_model = nullptr;
	std::stack<IModel::Memento*> m_mementos;


};