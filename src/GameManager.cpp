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
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  IMG_Quit();
  TTF_Quit();
  SDL_Quit();
}

short int GameManager::init(unsigned short int cheatCode, unsigned short int numberOfLayers, unsigned short int dimx, unsigned short int dimy)
{

  // SDL2 init
  if(sdlFullInit())
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
  renderer = SDL_CreateRenderer(window, -1, 0);
  surface = SDL_GetWindowSurface(window);

  player=new Player(/*cheatCode*/);
  map=new Map(numberOfLayers);
  map->init(renderer, dimx, dimy);

  return 0;
}

void GameManager::run()
{
  // Loop managers
  bool quit = false;
  bool selected = false;
  const Uint8 * keys;
  std::vector<VIterator> * options = map->getStarts();
  unsigned short int size = options->size();
  unsigned short int selectedEvent = 0;
  map->highlight(options, selectedEvent);
  PathI pathIterator;

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

      } else if ( e.type == SDL_KEYDOWN) {
        keys = SDL_GetKeyboardState(NULL);
        if (keys[SDLK_RIGHT] == SDL_PRESSED)
        {
          selectedEvent = (selectedEvent + 1) % size;
          map->highlight(options, selectedEvent);
        } else if (keys[SDLK_LEFT] == SDL_PRESSED)
        {
          selectedEvent = (selectedEvent - 1) % size;
          map->highlight(options, selectedEvent);
        } else if (keys[SDLK_KP_ENTER] == SDL_PRESSED)
        {
          map->selectPath(options->at(selectedEvent));
          selected=true;
          pathIterator = map->climbFrom(options->at(selectedEvent));
        }
      }
    }
    // Drawing
    map->drawMap();

    // Game loop
    while (selected && !quit){
      // Event loop
      while( SDL_PollEvent( &e ) != 0 )
      {
        //User requests quit
        if( e.type == SDL_QUIT )
        {
            quit = true;
        } else if ( e.type == SDL_KEYDOWN )
        {
          if (keys[SDLK_KP_ENTER] == SDL_PRESSED)
          {
            pathIterator = map->climbFrom(pathIterator);
          }
        }
      }

      // Drawing
      map->drawMap();
    }
  } while (!selected);
}
