#define VERMELHO "\033[31m"
#define VERDE "\033[32m"
#define RESET "\033[0m"

#include "TextureManager.hpp"
#include "Game.hpp"

SDL_Texture *TextureManager::load_texture(const char *file_name)
{
    std::cout << VERDE << "Textura do objeto carregada ladrao..." << RESET << std::endl;
    SDL_Surface *temp_surface = IMG_Load(file_name);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(Game::renderer, temp_surface);
    SDL_FreeSurface(temp_surface);
    
    return texture;
}

void TextureManager::draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest)
{
    SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}
