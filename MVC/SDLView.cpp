#include "SDLView.h"

#include "Model.h"
#include "GameObject.h"

#include "SDL2/SDL.h"

SDLView::SDLView(Model* model) : m_model(model)
{
	m_gameDrawer.initSDL();
	m_cont = SDLController(m_model);
}

void SDLView::render()
{
	m_gameDrawer.clear();
	m_gameDrawer.drawBackground();
	for (auto& obj : m_model->getObjects()) {
		obj->acceptVisitor(&m_gameDrawer);
	}
	m_gameDrawer.doRender();
}

Rect<int> SDLView::getWindowRect() const
{
	SDL_Rect rect = m_gameDrawer.getWindowRect();
	return { rect.x, rect.y, rect.w, rect.h };
}
