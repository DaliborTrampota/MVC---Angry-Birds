#pragma once

#include "IVisitor.h"
#include "SDLResourceManager.h"
#include <string>


struct SDL_Window;
struct SDL_Renderer;
struct SDL_Rect;

class GameObject;
class AbsPlayer;
class AbsMissile;


class SDLDrawer : public IVisitor
{
public:
	//void visitPlayer(AbsPlayer* player) override;
	//void visitMissile(AbsMissile* missile) override;
	void visitObject(GameObject* obj) override;

	void drawBackground();

	inline void draw(GameObject* obj);
	void draw(GameObject* obj, const char* texName);
	void draw(const char* texName, SDL_Rect* dstRect);

	void initSDL();
	void clear();
	void doRender();

	SDL_Rect getWindowRect() const;

private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

	SDLResourceManager* m_resourceMgr;

	friend class SDLView;
};

