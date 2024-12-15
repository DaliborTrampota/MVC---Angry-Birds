#include "SDLDrawer.h"

#include "Configuration.h"

#include "GameObject.h"
#include "TextObject.h"
#include "AbsPlayer.h"

#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"


//void SDLDrawer::visitPlayer(AbsPlayer* player)
//{
//	draw(player);
//}
//
//void SDLDrawer::visitMissile(AbsMissile* missile)
//{
//	draw(missile);
//}

SDLDrawer::~SDLDrawer()
{
	//TTF_Quit();
}

void SDLDrawer::visitPlayer(AbsPlayer* player)
{
	draw(player);
	auto pos = player->getPosition();
	pos.x += 25;
	auto texData = m_resourceMgr->getResource("arrow.png");

	SDL_Rect arrow = { pos.x, pos.y, texData.dims.x, texData.dims.y };
	SDL_Point rotPoint = { 0, texData.dims.y / 2 };

	SDL_RenderCopyEx(m_renderer, texData.tex, NULL, &arrow, player->getAngle() * (180 / M_PI), &rotPoint, SDL_FLIP_NONE);
}

void SDLDrawer::visitObject(GameObject* obj)
{
	draw(obj);
}

void SDLDrawer::visitTextObject(TextObject* text)
{
	draw(text);
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
	draw(texName, new SDL_Rect{ (int)pos.x, (int)pos.y, dims.x, dims.y });
}

void SDLDrawer::draw(const char* texName, SDL_Rect* rect)
{
	SDL_Texture* tex = m_resourceMgr->getResource(texName).tex;
	int res = SDL_RenderCopy(m_renderer, tex, NULL, rect);
}

void SDLDrawer::draw(TextObject* text)
{
	TextObject::Style style = text->getStyle();
	auto pos = text->getPosition();
	TTF_Font* font = TTF_OpenFont("D:/GithubPersonal/MVC/Game/resources/fonts/arial.ttf", style.fontSize);
	if (!font)
		throw "font not loaded";

	SDL_Surface* surface = TTF_RenderText_Blended_Wrapped(
		font, 
		text->getText(), 
		{ uint8_t(style.color[0] * 255), uint8_t(style.color[1] * 255), uint8_t(style.color[2] * 255) },
		NULL
	);
	TTF_CloseFont(font);

	SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer, surface);
	SDL_Rect textRect = { pos.x, pos.y, 0, 0 };
	SDL_QueryTexture(texture, NULL, NULL, &textRect.w, &textRect.h);

	int res = SDL_RenderCopy(m_renderer, texture, NULL, &textRect);

	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}

void SDLDrawer::initSDL()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	if (TTF_Init() == -1)
		throw "hey";

	m_window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WindowWidth, WindowHeight, SDL_WINDOW_SHOWN); //SDL_WINDOW_RESIZABLE
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
