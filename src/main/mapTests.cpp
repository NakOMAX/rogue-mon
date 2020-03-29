#include "../Map.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "SDL.h"

#ifdef __WIN32__
#include <windows.h>

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow) {
  int w_argc = 0;
  LPWSTR* w_argv = CommandLineToArgvW(GetCommandLineW(), &w_argc);
  if (w_argv) {
    char** my_argv = new char*[w_argc];
    int my_argc = 0;

    for (int i = 0; i < w_argc; ++i) {
      int w_len = lstrlenW(w_argv[i]);
      int len = WideCharToMultiByte(CP_ACP, 0, w_argv[i], w_len, NULL, 0, NULL, NULL);
      my_argv[my_argc] = new char[len+1];
      WideCharToMultiByte(CP_ACP, 0, w_argv[i], w_len, my_argv[my_argc], len+1, NULL, NULL);
      ++my_argc;
    }

    main(my_argc, my_argv);

    for (int i = 0; i < my_argc; ++i) {
      delete[] my_argv[i];
    }
    delete[] my_argv;

    LocalFree(w_argv);
  }
}
#endif

int main(int argc, char *argv[])
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
  pokemonMap.init(renderer, wdimy);

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
