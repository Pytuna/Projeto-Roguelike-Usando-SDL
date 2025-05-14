#pragma once

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_events.h"
#include <iostream>

class Game
{
public:
    Game();
    ~Game();
    void init(const char *title, int x_pos, int y_pos, int width, int height, bool fullscreen);
    void handle_events();
    void update();
    void render();
    void clean();
    bool running() { return is_running; };
    static SDL_Renderer *renderer;
    static SDL_Event event;

private:
    int count = 0;
    bool is_running;
    SDL_Window *window;
};

inline Game::Game() {}
inline Game::~Game() {}