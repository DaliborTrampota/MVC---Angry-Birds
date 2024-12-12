#pragma once

#include <unordered_map>
#include "MyMath.h"

struct SDL_Texture;
struct SDL_Renderer;

class SDLResourceManager
{
public:
	SDLResourceManager(SDL_Renderer* renderer) : m_renderer(renderer) {};

	struct SDLTextureWrapper {
		SDL_Texture* tex;
		Vec2<int> dims;
	};


	SDLTextureWrapper getResource(const char* name) const;
	void loadResources();

private:
	SDL_Renderer* m_renderer;
	std::unordered_map<const char*, SDLTextureWrapper> m_textures;

	void loadResource(const char* name);
};

