#pragma once

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <iostream>

class GameObject
{
public:
    GameObject(const char *texturesheet, int x, int y);
    ~GameObject();
    void update();
    void render();

private:
    int x_pos;
    int y_pos;
    SDL_Texture *obj_texture;
    SDL_Rect src_rect, dest_rect;
    
};