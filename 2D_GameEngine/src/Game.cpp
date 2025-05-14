#define VERMELHO "\033[31m"
#define VERDE "\033[32m"
#define RESET "\033[0m"

#include "Game.hpp"
#include "Map.hpp"
#include "TextureManager.hpp"
#include "/home/guilherme/Documentos/Projetos-Pessoais/Pico-8/roguelike/2D_GameEngine/src/ECS/Components.hpp"
#include "Vector2D.hpp"

Map *map;
Manager manager;

SDL_Renderer *Game::renderer = nullptr;
SDL_Event Game::event;

auto& player(manager.addEntity());

void Game::init(const char *title, int x_pos, int y_pos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << VERDE << "Iniciou tudo direitinho ladrao..." << RESET << std::endl;
        window = SDL_CreateWindow(title, x_pos, y_pos, width, height, flags);
        if (window)
        {
            std::cout << VERDE << "Janela criada ladrao..." << RESET << std::endl;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 9, 20, 33, 255);
            std::cout << VERDE << "Renderer criado ladrao..." << RESET << std::endl;
        }
        is_running = true;
    }
    else
    {
        std::cout << VERMELHO << "Não iniciou ladrão, fica esperto..." << RESET << std::endl;
        is_running = false;
    }
    
    map = new Map();

    player.addComponent<TransformComponent>();
    player.addComponent<SpriteComponent>("/home/guilherme/Documentos/Projetos-Pessoais/Pico-8/roguelike/2D_GameEngine/assets/player.png");
    player.addComponent<KeyboardController>();
}

void Game::handle_events()
{
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        is_running = false;
        break;
    default:
        break;
    }
}

void Game::update()
{
    manager.refresh();
    manager.update();
}

void Game::render()
{
    SDL_RenderClear(renderer);
    map->draw_map();
    manager.draw();
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << VERDE << "Tudo limpo ladrão..." << RESET << std::endl;
}