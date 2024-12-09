#include "SDLDrawer.h"

#include "GameObject.h"
#include "AbsPlayer.h"

#include "SDL2/SDL.h"


//void SDLDrawer::visitPlayer(AbsPlayer* player)
//{
//	draw(player);
//}
//
//void SDLDrawer::visitMissile(AbsMissile* missile)
//{
//	draw(missile);
//}

void SDLDrawer::visitObject(GameObject* obj)
{
	draw(obj);
}

void SDLDrawer::drawBackground()
{
	draw("back.jpg", NULL);
}

inline void SDLDrawer::draw(GameObject* obj)
{
	draw(obj, obj->getTextureName());
}

void SDLDrawer::draw(GameObject* obj, const char* texName)
{
	auto pos = obj->getPosition();
	auto dims = m_resourceMgr->getResource(texName).dims;//obj->getDimensions();
	draw(texName, new SDL_Rect{ pos.x, pos.y, dims.x, dims.y });
}

void SDLDrawer::draw(const char* texName, SDL_Rect* rect)
{
	SDL_Texture* tex = m_resourceMgr->getResource(texName).tex;
	int res = SDL_RenderCopy(m_renderer, tex, NULL, rect);
}

void SDLDrawer::initSDL()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	m_window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
	m_renderer = SDL_CreateRenderer(m_window, -1, 0);

	m_resourceMgr = new SDLResourceManager(m_renderer);
	m_resourceMgr->loadResources();

	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
	SDL_RenderClear(m_renderer);
	SDL_RenderPresent(m_renderer);
}

void SDLDrawer::clear()
{
	SDL_RenderClear(m_renderer);
}

void SDLDrawer::doRender()
{
	SDL_RenderPresent(m_renderer);
}

SDL_Rect SDLDrawer::getWindowRect() const
{
	SDL_assert(m_renderer);
	int w, h;
	SDL_GetRendererOutputSize(m_renderer, &w, &h);
	return SDL_Rect{ 0, 0, w, h };
}
