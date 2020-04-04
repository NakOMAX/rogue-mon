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
  // generate SDL_Rect : position
  // assumes WIN_X and WIN_Y sizes of screen
  int padding = 25; // distance between box and text
  transform.x = 0; transform.y = WIN_Y; transform.w = WIN_X; transform.h = WIN_Y/4; // whole textbox
  text_transform.x = transform.x+padding; text_transform.y = transform.y-padding;
  text_transform.w = transform.w - padding; text_transform.h = transform.h-padding; // texbox - padding
  // return 0 if everything went well
  return 0;
}

unsigned short int DialogueBox::_update(SDL_Renderer render) {
  // render textbox background
  if (SDL_RenderCopy(render, image, NULL, transform) < 0) {
    return ERRCODE_NO_RENDER;
  }
  // if there is text, render it
  if (aff != NULL) {
    if(!(txtSurface = TTF_RenderText_Solid(font, aff, color))) {
      // the text did not render
      return ERRCODE_NO_AFF;
    } else {
      // here if text did render
      txt_image = SDL_CreateTextureFromSurface(txtSurface); // transform surface into texture
      if (SDL_RenderCopy(render, txt_image, NULL, text_transform)) {
        // if render of text surface failed
        return ERRCODE_NO_RENDER;
      }
    }
  }
  //everything went well
  return 0;
}

void DialogueBox::operator<<(const char* str) {
  aff = str;
}

void DialogueBox::clean() {
  //
}
