#include "../event/Fight.h"
#include "Player.h"
#include "WildPok.h"
#include <iostream>

#include "SDL.h"

#ifdef __WIN32__
#include <windows.h>

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow) {
  printf("OS: Windows\n");
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
  return 0;
}
#endif

int main(int argc, char *argv[])
{
    unsigned short int wdimx, wdimy;
  if (argc!=3)
  {
    printf("Resolution set to default\n");
    //return -1;
    wdimx = 1200;
    wdimy = 750;
  } else {
    wdimx = atoi(argv[1]);
    wdimy = atoi(argv[2]);
  }

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
  // SDL TTF init
  if( TTF_Init() == -1) 
  {
    printf("TTF Init: Failed to initialise TTF\n");
    printf("TTF Init: %s\n", TTF_GetError());
  }
    // SDL window set up
  SDL_Window * window = SDL_CreateWindow("MapTests", SDL_WINDOWPOS_UNDEFINED,
  SDL_WINDOWPOS_UNDEFINED, wdimx, wdimy, SDL_WINDOW_SHOWN);
  if(window==NULL)
  {
    printf("SDL error on window creation: %s\n", SDL_GetError() );
  }
  //auto sdlFlags = ;
  SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
  SDL_RenderClear(renderer);


    Player player;
    WildPok opposant;
    Fight firstFight(player,opposant);
    std :: cout << launch(renderer, wdimx, wdimy);


}