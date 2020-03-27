#include "../Map.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

int main(int argc, char **argv)
{
  if (argc!=3)
  {
    printf("Invalid number of arguments\n");
    return -1;
  }

  // SDL2 init
  unsigned short int wdimx = atoi(argv[1]);
  unsigned short int wdimy = atoi(argv[2]);
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

  // SDL window set up
  SDL_Window * window = SDL_CreateWindow("MapTests", SDL_WINDOWPOS_UNDEFINED,
  SDL_WINDOWPOS_UNDEFINED, wdimx, wdimy, SDL_WINDOW_SHOWN);
  if(window==NULL)
  {
    printf("SDL error on window creation: %s\n", SDL_GetError() );
  }
  SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);


  // Tests
  Map pokemonMap(8);
  pokemonMap.setRenderer(renderer, wdimy);

  pokemonMap.drawMap();
  SDL_RenderPresent(renderer);
  SDL_Delay(3000);

  std::vector<VIterator> * options = pokemonMap.getStarts();
  pokemonMap.selectPath(options->at(0));

  pokemonMap.drawMap();
  SDL_RenderPresent(renderer);
  SDL_Delay(3000);

  PathI path = pokemonMap.climbFrom(options->at(0));
  pokemonMap.drawMap();
  SDL_RenderPresent(renderer);
  SDL_Delay(3000);

  for (unsigned short int i = 2; i<8; i++)
  {
    path = pokemonMap.climbFrom(path);
    pokemonMap.drawMap();
    SDL_RenderPresent(renderer);
    SDL_Delay(3000);
  }
  return 0;
}
