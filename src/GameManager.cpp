#include "GameManager.h"
#include "SDL.h"

GameManager::GameManager()
{
  map=NULL;
  renderer=NULL;
  surface=NULL;
  window=NULL;
}

GameManager::~GameManager()
{
  //delete player;
  delete map;
  SDL_DestroyTexture(texture);
  SDL_FreeSurface(image);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  IMG_Quit();
  SDL_Quit();
}

void GameManager::init(unsigned short int cheatCode, unsigned short int numberOfLayers) {
  //player=new Player(cheatCode);
  map=new Map(numberOfLayers);

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
  window = SDL_CreateWindow("Roguemon", SDL_WINDOWPOS_UNDEFINED,
  SDL_WINDOWPOS_UNDEFINED, dimx, dimy, SDL_WINDOW_SHOWN);
  if(window==NULL)
  {
    printf("SDL error on window creation: %s\n", SDL_GetError() );
  }
  renderer = SDL_CreateRenderer(window, -1, 0);
  surface = SDL_GetWindowSurface(window);
}

void GameManager::graph_run(unsigned short int dimx, unsigned short int dimy){

  // Loop managers
  bool quit = false;

  // Game loop
  do{
    // Event loop
    while( SDL_PollEvent( &event ) != 0 )
    {
        //User requests quit
        if( event.type == SDL_QUIT )
        {
            quit = true;
        }
    }

    // Drawing
    map->drawMap(renderer);
  } while (!quit);


}
