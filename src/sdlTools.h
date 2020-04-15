#ifndef _SDL_TOOLS
#define _SDL_TOOLS

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <string>

bool sdlFullInit();
SDL_Surface * loadImage(const std::string & filename);
TTF_Font * loadFont(const std::string & filename, int size);

#endif
