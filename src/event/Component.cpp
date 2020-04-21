/** @file cpp file for component class */

#include "Component.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "SDL.h"
#include "sdlTools.h"
#include <stdlib.h>
#include <cstring>
#include <iostream> //debug
#include <string>

Component::Component() {
}

Component::~Component() {
}

unsigned short int Component::_init( unsigned short int dimX, unsigned short int dimY, SDL_Renderer * render) {
  return ERRCODE_NO_COMP;
}

unsigned short int Component::_update(SDL_Renderer * render) {
  return ERRCODE_NO_COMP;
}

/// -------------------------------------------------------------- DIALOGUE BOX

DialogueBox::DialogueBox() {

}

DialogueBox::~DialogueBox() {
  SDL_FreeSurface(surface);
  SDL_FreeSurface(txt_surface);
  delete aff;
  delete transform;
  delete text_transform;
}

//#N C'est le game manager qui fixe la dimension de l'écran et tu vas avoir besoin de te la faire passer
unsigned short int DialogueBox::_init( unsigned short int dimX, unsigned short int dimY, SDL_Renderer * render ) {
  std::cout<<"Initiated dialogue box"<<std::endl; //debug
  // test correct initialisation
  if (!TTF_WasInit()) {
    //#N Pour appeler component GameManager doit avoir initialisé TTF, c'est ça?
    std::cout<<"TTF not init"<<std::endl;
    return ERRCODE_NO_TTF;
  }

  font = loadFont("data/Font/pkmnem.ttf", 40);
  std::cout<<"surface and image start"<<std::endl; //debug
  surface = loadImage("data/Components/dialogueBox.png");
  std::cout<<"surface done"<<std::endl; //debug
  image = SDL_CreateTextureFromSurface(render,surface);
  std::cout<<"surface and image worked"<<std::endl; //debug
  // generate SDL_Rect : position
  // assumes dimX and dimY sizes of screen
  int padding = 50; // distance between box and text

  transform = new SDL_Rect;
  // whole textbox
  //#N pointeur vers une struct, donc ->
  transform->w = dimX;
  transform->h = dimY/4;
  transform->x = 0;
  transform->y = dimY - transform->h;
  //#N Si y=dimY le haut de la boite sera en bas de la page car (0,0) c'est en haut à gauche

  text_transform = new SDL_Rect;
  text_transform->x = transform->x + padding;
  text_transform->y = transform->y + padding/2;

  // init char *
  aff = new char [CHARLIM];
  // return 0 if everything went well
  return 0;
}

unsigned short int DialogueBox::_update(SDL_Renderer * render) {
  // render textbox background
  if (SDL_RenderCopy(render, image, NULL, transform) < 0) {
    printf("Box: No renderer error. Forcing exit...\n" );
    return ERRCODE_NO_RENDER;
  }

  // if there is text, render it
  if (aff != NULL && aff[0]!='\0') {
    txt_surface = TTF_RenderText_Solid(font, aff, color);

    if(txt_surface == NULL) {
      // the text did not render
      printf("Box: Can't render. Error. Forcing exit...\n" );
      return ERRCODE_NO_AFF;
    } else {
      // here if text did render
      txt_image = SDL_CreateTextureFromSurface(render, txt_surface); // transform surface into texture
      SDL_QueryTexture(txt_image, NULL, NULL, &text_transform->w, &text_transform->h);
      //#N Pour l'instant il y a une seule ligne, c'est ça?
      if (SDL_RenderCopy(render, txt_image, NULL, text_transform)<0) {
        // if render of text surface failed
        printf("Box: Can't present rendering. Forcing exit\n" );
        return ERRCODE_NO_RENDER;
      }
    }
  }
  //everything went well
  return 0;
}

void DialogueBox::operator<<(const char* str) {
  //#N Je ne sais pas si strncopy est une fonction à toi mais en tout cas il y a strcpy qui fait ça dèja
  strncpy(aff, str, CHARLIM);
  if ( strlen( str ) >= CHARLIM ) {
        aff[ CHARLIM -1 ] = '\0';
    }
}

void DialogueBox::clean() {
  aff[0] = '\0';
}

void DialogueBox::setColor(const SDL_Color & c) {
  color = c;
}

/// ----------------------------------------------------------- CLICKABLE BUTTON

Button::Button(SDL_Rect * pos /*, function pointer*/){
  transform = pos;
}

Button::~Button(){
  SDL_FreeSurface(surface);
  SDL_FreeSurface(txt_surface);
  delete aff;
  delete transform;
  delete txt_transform;
}

unsigned short int Button::_init(unsigned short int dimX, unsigned short int dimY, SDL_Renderer * render) {
  return ERRCODE_NO_COMP;
}

unsigned short int Button::_update(SDL_Renderer * render) {
  return ERRCODE_NO_COMP;
}
