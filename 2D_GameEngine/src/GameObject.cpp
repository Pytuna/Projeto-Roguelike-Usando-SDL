#define VERMELHO "\033[31m"
#define VERDE "\033[32m"
#define RESET "\033[0m"

#include "GameObject.hpp"
#include "Game.hpp"
#include "TextureManager.hpp"

GameObject::GameObject(const char *texturesheet, int x, int y)
{
    obj_texture = TextureManager::load_texture(texturesheet);
    std::cout << VERDE << "Objeto renderizado ladrao..." << RESET << std::endl;
    x_pos = x;
    y_pos = y;
}

void GameObject::update()
{
    x_pos++;
    y_pos++;
    src_rect.h = 32;
    src_rect.w = 32;
    src_rect.x = 0;
    src_rect.y = 0;

    dest_rect.x = x_pos;
    dest_rect.y = y_pos;
    dest_rect.h = src_rect.h * 2;
    dest_rect.w = src_rect.w * 2;
}

void GameObject::render()
{
    SDL_RenderCopy(Game::renderer, obj_texture, &src_rect, &dest_rect);
}