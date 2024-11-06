#include "View.h"

#include "Model.h"
#include "GameObject.h"

#include "SDL2/SDL.h"

View::View(Model* model) : m_model(model)
{
	m_gameDrawer.initSDL();
	m_cont = Controller(m_model);
}

void View::render()
{
	m_gameDrawer.clear();
	m_gameDrawer.drawBackground();
	for (auto& obj : m_model->getObjects()) {
		obj->acceptVisitor(&m_gameDrawer);
	}
	m_gameDrawer.doRender();
}

SDL_Rect View::getWindowRect() const
{
	return m_gameDrawer.getWindowRect();
}
