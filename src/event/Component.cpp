/** @file cpp file for component class */

#include "event/Component.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "SDL.h"
#include <stdlib.h>
#include <string.h>

// BLOC POUR TEST, INCLU AVEC MAP.cpp
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
        printf("Error: %s\n", SDL_GetError());
      }
    }
  }
  return surface;
}
// FIN BLOC TEST

unsigned short int Component::_init() {
  return ERRCODE_NO_COMP;
}

unsigned short int Component::_update() {
  return ERRCODE_NO_COMP;
}

unsigned short int DialogueBox::_init() {
  // test correct initialisation
  if (!TTF_WasInit()) {
    return ERRCODE_NO_TTF;
  }
  // load font
  font = TTF_OpenFont("../../data/Font/Pkmnem.ttf", 16);
  if (!font) {
    return ERRCODE_FONT_NOT_LOADED;
  }
  // load textbox texture
  surface = loadImage("../data.Components/dialogueBox.png");
  image = SDL_CreateTextureFromSurface(surface);
  // return 0 if everything went well
  return 0;
}

unsigned short int DialogueBox::_update() {
  // if there is text, render it
  if (aff != NULL) {
    if(!(txtSurface = TTF_RenderText_Solid(font, aff, color))) {
      // the text did not render
      return ERRCODE_NO_AFF;
    } else {
      //everything worked, take care of the rest
    }
  }

  return 0;
}

void DialogueBox::operator<<(const char* str) {
  aff = str;
}

void DialogueBox::clean() {
  //
}
