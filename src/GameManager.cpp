#include "GameManager.h"
#include "sdlTools.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

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
  delete player;
  SDL_FreeSurface(surface);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  IMG_Quit();
  TTF_Quit();
  SDL_Quit();
}

short int GameManager::init(unsigned short int cheatCode, unsigned short int numberOfLayers, unsigned short int dimx, unsigned short int dimy)
{

  // SDL2 init
  if(!sdlFullInit())
  {
    printf("Failed on SDL init\n");
    return -1;
  }

  // SDL set up
  window = SDL_CreateWindow("Roguemon", SDL_WINDOWPOS_UNDEFINED,
  SDL_WINDOWPOS_UNDEFINED, dimx, dimy, SDL_WINDOW_SHOWN);
  if(window==NULL)
  {
    printf("SDL error on window creation: %s\n", SDL_GetError() );
    return -2;
  }
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
  surface = SDL_GetWindowSurface(window);

  player=new Player(/*cheatCode*/);
  map=new Map(numberOfLayers);
  nLayers = numberOfLayers;
  map->init(renderer, dimx, dimy);

  printf("Game manager successfully inited\n");
  return 0;
}

void GameManager::run()
{
  // Loop managers
  bool quit = false;
  bool selected = false;
  bool victory = false;
  //const Uint8 * keys;
  std::vector<VIterator> * options = map->getStarts();
  unsigned short int size = options->size();
  unsigned short int layersLeft = nLayers-1;
  short int selectedEvent = 0;
  map->highlight(options, selectedEvent);
  PathI pathIterator;

  printf("Game start\n");
  // Start loop
  do{
    // Event loop
    while( SDL_PollEvent( &e ) != 0 )
    {
      // User requests quit
      if( e.type == SDL_QUIT )
      {
        // Both needed to exit both loops
        quit = true;
        selected = true;
        printf("Forcing exit");

      } else if ( e.type == SDL_KEYDOWN) {
        //keys = SDL_GetKeyboardState(NULL);
        if (e.key.keysym.sym == SDLK_RIGHT)
        {
          selectedEvent = (selectedEvent + 1) % size;
          map->highlight(options, selectedEvent);
        } else if (e.key.keysym.sym == SDLK_LEFT)
        {
          if (selectedEvent - 1 < 0)
            selectedEvent = size -1;
          else
            selectedEvent = (selectedEvent - 1) % size;
          map->highlight(options, selectedEvent);
        } else if (e.key.keysym.sym == SDLK_RETURN)
        {
          map->selectPath(options->at(selectedEvent));
          selected=true;
          pathIterator = map->climbFrom(options->at(selectedEvent));
          layersLeft--;
        }
      }
    }
    // Drawing
    SDL_RenderClear(renderer);
    map->drawMap();
    SDL_RenderPresent(renderer);

    // Game loop
    while (selected && !quit && !victory){
      // Event loop
      while( SDL_PollEvent( &e ) != 0 )
      {
        //User requests quit
        if( e.type == SDL_QUIT )
        {
          printf("Forcing exit\n");
          quit = true;
        } else if ( e.type == SDL_KEYDOWN )
        {
          if (e.key.keysym.sym == SDLK_RETURN)
          {
            pathIterator = map->climbFrom(pathIterator);
            layersLeft--;
            if (layersLeft == 0)
            {
              victory = true;
              break;
            }
          }
        }
      }

      // Drawing
      SDL_RenderClear(renderer);
      map->drawMap();
      SDL_RenderPresent(renderer);
    }
  } while (!selected);
}
