#pragma once
#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

class Map
{
public:
    Map();
    ~Map();
    void load_map(int arr[20][25]);
    void draw_map();

private:
    SDL_Rect src, dest;
    SDL_Texture *dirt;
    SDL_Texture *grass;
    SDL_Texture *water;
    int map[20][25];
};

inline Map::~Map(){};