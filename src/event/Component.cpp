/** @file cpp file for component class */

#include "event/Component.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "SDL.h"
#include <stdlib.h>
#include <cstring>

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

DialogueBox::~DialogueBox() {
  SDL_FreeSurface(surface);
  SDL_FreeSurface(txt_surface);
}

//#N C'est le game manager qui fixe la dimension de l'écran et tu vas avoir besoin de te la faire passer
unsigned short int DialogueBox::_init( /*unsigned short int dimX, unsigned short int dimY */) {
  // test correct initialisation
  if (!TTF_WasInit()) {
    //#N Pour appeler component GameManager doit avoir initialisé TTF, c'est ça?
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
  // assumes dimX and dimY sizes of screen
  int padding = 25; // distance between box and text

  // whole textbox
  //#N pointeur vers une struct, donc ->
  transform->w = dimX;
  transform->h = dimY/4;
  transform->x = 0;
  transform->y = dimY - transform->h;
  //#N Si y=dimY le haut de la boite sera en bas de la page car (0,0) c'est en haut à gauche


  text_transform->x = transform->x + padding;
  text_transform->y = transform->y + padding;
  text_transform->w = transform->w - padding;
  text_transform->h = transform->h - padding; // texbox - padding
  // return 0 if everything went well
  return 0;
}

unsigned short int DialogueBox::_update(SDL_Renderer * render) {
  // render textbox background
  if (SDL_RenderCopy(render, image, NULL, transform) < 0) {
    return ERRCODE_NO_RENDER;
  }
  // if there is text, render it
  if (aff != NULL) {
    txt_surface = TTF_RenderText_Solid(font, aff, color);
    //#N C'est mieux de ne pas utliser ! avec un pointeur, d'ailleurs je ne suis pas sur que ça marche
    if(txt_surface == NULL) {
      // the text did not render
      return ERRCODE_NO_AFF;
    } else {
      // here if text did render
      txt_image = SDL_CreateTextureFromSurface(txt_surface); // transform surface into texture
      //#N Pour l'instant il y a une seule ligne, c'est ça?
      if (SDL_RenderCopy(render, txt_image, NULL, text_transform)<0) {
        // if render of text surface failed
        return ERRCODE_NO_RENDER;
      }
    }
  }
  //everything went well
  return 0;
}

void DialogueBox::operator<<(const char* str) {
  //#N Je ne sais pas si strncopy est une fonction à toi mais en tout cas il y a strcpy qui fait ça dèja
  strncopy(aff, str, CHARLIM);
  if ( strlen( str ) >= CHARLIM ) {
        //#N En principe t'as pas le droit de faire ça. Ton tableau n'est pas initialisé. Il manque un new char[CHARLIM] quelquepart
        aff[ CHARLIM -1 ] = '\0';
    }
}

void DialogueBox::clean() {
  aff = NULL;
}
