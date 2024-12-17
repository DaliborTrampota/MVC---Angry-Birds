#pragma once

#include <string>

#include "IVisitor.h"
#include "SDLResourceManager.h"
#include "Frame.h"


struct SDL_Window;
struct SDL_Renderer;
struct SDL_Rect;

class GameObject;
class TextObject;
class AbsPlayer;


class SDLDrawer : public IVisitor
{
public:
	~SDLDrawer();

	void visitPlayer(AbsPlayer* player) override;
	void visitObject(GameObject* obj) override;
	void visitTextObject(TextObject* text) override;
	void visitUI(Frame* screen) override;

	void drawBackground();

	inline void draw(GameObject* obj);
	void draw(TextObject* text);
	void draw(GameObject* obj, const char* texName);
	void draw(const char* texName, SDL_Rect* dstRect);
	void drawFrame(Frame* frame, SDL_Rect parentBounds);

	void initSDL();
	void clear();
	void doRender();

	SDL_Rect getWindowRect() const;

private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

	SDLResourceManager* m_resourceMgr;

	Rect<float> getAbsoluteBounds(Rect<float> bounds, Units units, Rect<float> parentBounds, Units parentUnits) const;
	SDL_Rect convertToSDLRect(Rect<float> bounds, Units units, SDL_Rect parentBounds) const;
	void applyAnchor(SDL_Rect& rect, Anchor anchor);

	friend class SDLView;
};

