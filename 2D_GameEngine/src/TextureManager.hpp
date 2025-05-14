#pragma once

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <iostream>

class TextureManager
{
public:
    static SDL_Texture *load_texture(const char *file_name);
    static void draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest);
};