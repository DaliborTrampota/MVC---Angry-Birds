#include "SDLView.h"

#include "IModel.h"
#include "GameObject.h"
#include "Frame.h"

#include "SDL2/SDL.h"


SDLView::SDLView(IModel* model) : 
	m_model(model),
	m_cont(model)
{
	m_gameDrawer.initSDL();
	model->registerObserver(this);
}

void SDLView::render()
{
	m_gameDrawer.clear();
	m_gameDrawer.drawBackground();
	for (auto& obj : m_model->getObjects()) {
		obj->acceptVisitor(&m_gameDrawer);
	}
	m_model->getActiveScreen()->acceptVisitor(&m_gameDrawer);
	m_gameDrawer.doRender();
}

void SDLView::update()
{
	render();
}

Rect<int> SDLView::getWindowRect() const
{
	SDL_Rect rect = m_gameDrawer.getWindowRect();
	return { rect.x, rect.y, rect.w, rect.h };
}

SDLController* SDLView::getController()
{
	return &m_cont;
}
