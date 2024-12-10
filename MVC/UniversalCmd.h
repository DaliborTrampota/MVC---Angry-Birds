#pragma once

#include "AbstractGameCommand.h"

//template <typename Callable>
class UniversalCmd : public AbstractGameCommand {

public:
	using FuncT = std::function<void()>;//void(*)();
	UniversalCmd(IModel* model, FuncT f) 
		: AbstractGameCommand(model), m_func(f) {}

	void execute() override {
		m_func();
	}

private:
	FuncT m_func;
};