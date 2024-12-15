#include "SDLResourceManager.h"

#include "string"

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"


SDLResourceManager::SDLTextureWrapper SDLResourceManager::getResource(const char* name) const
{
    return m_textures.at(name);
}

void SDLResourceManager::loadResources()
{
    loadResource("back.jpg");
    loadResource("bound.png");
    loadResource("cannon.png");
    loadResource("missile.png");
    loadResource("enemy1.png");
    loadResource("enemy2.png");
    loadResource("enemy2WithBlood.png");
    loadResource("collision.png");
    loadResource("arrow.png");
}

void SDLResourceManager::loadResource(const char* name)
{
    std::string path("resources/images/");
    path.append(name);
    SDL_Surface* surface = IMG_Load(path.c_str());
    SDLTextureWrapper texture;
    texture.tex = SDL_CreateTextureFromSurface(m_renderer, surface);
    texture.dims = { surface->w, surface->h };
    m_textures[name] = texture;
    SDL_FreeSurface(surface);
}
