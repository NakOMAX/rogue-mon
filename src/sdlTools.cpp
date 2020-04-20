#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <string>

bool sdlFullInit()
{
  // SDL2 init
  if( SDL_Init( SDL_INIT_VIDEO ) < 0)
  {
    printf("SDL error on init: %s\n", SDL_GetError() );
    return false;
  }
  // SDL Image init
  int flags = IMG_INIT_PNG|IMG_INIT_JPG;
  int initted = IMG_Init(flags);
  if((initted&flags) != flags) {
    printf("IMG_Init: Failed to init required jpg and png support!\n");
    printf("IMG_Init: %s\n", IMG_GetError());
    return false;
  }
  // SDL TTF init
  if( TTF_Init() == -1) {
    printf("TTF Init: Failed to initialise TTF\n");
    printf("TTF Init: %s\n", TTF_GetError());
    return false;
  }

  return true;
}

SDL_Surface * loadImage(const std::string & filename)
{
  SDL_Surface * surface;
  surface = IMG_Load(filename.c_str());
  if (surface==NULL)
  {
    std::string modFilename;
    modFilename = "../" + filename;
    surface = IMG_Load(modFilename.c_str());
    if (surface==NULL)
    {
      modFilename = "../" + modFilename;
      surface = IMG_Load(modFilename.c_str());
      if (surface==NULL)
      {
        printf("Image not found. Error: %s\n", SDL_GetError());
      }
    }
  }
  return surface;
}

TTF_Font * loadFont(const std::string & filename, int size)
{
  TTF_Font * font;
  font = TTF_OpenFont(filename.c_str(), size);
  if (font==NULL)
  {
    std::string modFilename;
    modFilename = "../" + filename;
    font = TTF_OpenFont(modFilename.c_str(), size);
    if (font==NULL)
    {
      modFilename = "../" + modFilename;
      font = TTF_OpenFont(modFilename.c_str(), size);
      if (font==NULL)
      {
        printf("Font not found. Error: %s\n", SDL_GetError());
      }
    }
  }
  return font;
}
