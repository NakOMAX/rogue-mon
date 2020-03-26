#include "../Map.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

int main(void)
{
  // SDL2 init
  if( SDL_Init( SDL_INIT_VIDEO ) < 0)
  {
    printf("SDL error on init: %s\n", SDL_GetError() );
  }
  // SDL Image init
  int flags = IMG_INIT_PNG|IMG_INIT_JPG;
  int initted = IMG_Init(flags);
  if((initted&flags) != flags) {
    printf("IMG_Init: Failed to init required jpg and png support!\n");
    printf("IMG_Init: %s\n", IMG_GetError());
  }

  // SDL set up
  SDL_Window * window = SDL_CreateWindow("MapTests", SDL_WINDOWPOS_UNDEFINED,
  SDL_WINDOWPOS_UNDEFINED, 800, 800, SDL_WINDOW_SHOWN);
  if(window==NULL)
  {
    printf("SDL error on window creation: %s\n", SDL_GetError() );
  }
  SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);

  Map pokemonMap(4);
  pokemonMap.setRenderer(renderer);
  pokemonMap.drawMap(renderer);
  SDL_RenderPresent(renderer);

  SDL_Delay(2000);

  return 0;
}
