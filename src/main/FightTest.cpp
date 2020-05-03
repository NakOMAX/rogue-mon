#include "../event/Fight.h"

#include "SDL.h"

int main (void)
{
    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    SDL_RenderClear(renderer);
    SDL_Event evt;
    Fight firstFight;
    firstFight.init(renderer, 120,150);
    firstFight.run(renderer,evt);


}