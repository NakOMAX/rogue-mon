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

// unsigned short int Component::_init( unsigned short int dimX, unsigned short int dimY, SDL_Renderer * render) {
//   return ERRCODE_NO_COMP;
// }
//
// unsigned short int Component::_update(SDL_Renderer * render) {
//   return ERRCODE_NO_COMP;
// }

/// -------------------------------------------------------------- DIALOGUE BOX

DialogueBox::DialogueBox() {

}

DialogueBox::~DialogueBox() {
  SDL_FreeSurface(surface);
  surface = NULL;
  SDL_FreeSurface(txt_surface);
  txt_surface = NULL;
  TTF_CloseFont(font);
  font = NULL;
  SDL_DestroyTexture(image);
  SDL_DestroyTexture(txt_image);
  delete aff;
  delete af2;
  delete af3;
  delete transform;
  delete text_transform;
  delete l2_transform;
  delete l3_transform;
}

//#N C'est le game manager qui fixe la dimension de l'écran et tu vas avoir besoin de te la faire passer
unsigned short int DialogueBox::_init( unsigned short int dimX, unsigned short int dimY, SDL_Renderer * render ) {

  // test correct initialisation
  if (!TTF_WasInit()) {
    //#N Pour appeler component GameManager doit avoir initialisé TTF, c'est ça?
    std::cout<<"TTF not init"<<std::endl;
    return ERRCODE_NO_TTF;
  }

  font = loadFont("data/Font/pkmnem.ttf", 40);

  surface = loadImage("data/Components/dialogueBox.png");

  image = SDL_CreateTextureFromSurface(render,surface);

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

  l2_transform = new SDL_Rect;
  l2_transform->x = text_transform->x;
  l2_transform->y = text_transform->y + 40;
  //RectCopy(l2_transform, text_transform);

  l3_transform = new SDL_Rect;
  l3_transform->x = text_transform->x;
  l3_transform->y = l2_transform->y + 40;
  // RectCopy(l3_transform, l2_transform);



  // init char *
  aff = new char [CHARLIM];
  af2 = new char [CHARLIM];
  af3 = new char [CHARLIM];
  clean();

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
  // line 1
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
  // line 2
  if (af2 != NULL && af2[0]!='\0') {
    txt_surface = TTF_RenderText_Solid(font, af2, color);

    if(txt_surface == NULL) {
      // the text did not render
      printf("Box: Can't render. Error. Forcing exit...\n" );
      return ERRCODE_NO_AFF;
    } else {
      // here if text did render
      txt_image = SDL_CreateTextureFromSurface(render, txt_surface); // transform surface into texture
      SDL_QueryTexture(txt_image, NULL, NULL, &l2_transform->w, &l2_transform->h);
      //#N Pour l'instant il y a une seule ligne, c'est ça?
      if (SDL_RenderCopy(render, txt_image, NULL, l2_transform)<0) {
        // if render of text surface failed
        printf("Box: Can't present rendering. Forcing exit\n" );
        return ERRCODE_NO_RENDER;
      }
    }
  }
  // line 3
  if (af3 != NULL && af3[0]!='\0') {
    txt_surface = TTF_RenderText_Solid(font, af3, color);

    if(txt_surface == NULL) {
      // the text did not render
      printf("Box: Can't render. Error. Forcing exit...\n" );
      return ERRCODE_NO_AFF;
    } else {
      // here if text did render
      txt_image = SDL_CreateTextureFromSurface(render, txt_surface); // transform surface into texture
      SDL_QueryTexture(txt_image, NULL, NULL, &l3_transform->w, &l3_transform->h);
      //#N Pour l'instant il y a une seule ligne, c'est ça?
      if (SDL_RenderCopy(render, txt_image, NULL, l3_transform)<0) {
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
  std:: cout << str;
  clean();
  std::string buf (str);

  std::string buf2 = buf.substr(0, CHARLIM-1);
  strncpy(aff, buf2.c_str(), CHARLIM);
  if ( strlen( str ) >= CHARLIM ) {
    aff[ CHARLIM -1 ] = '\0';
    buf2 = buf.substr(CHARLIM, CHARLIM-1);
    strncpy(af2, buf2.c_str(), CHARLIM);
    if ((strlen(str) >= 2*CHARLIM)) {
      af2[CHARLIM-1] = '\0';
      buf2 = buf.substr(CHARLIM*2, CHARLIM-1);
      strncpy(af3, buf2.c_str(), CHARLIM);
      if ((strlen(str) >= 3*CHARLIM)) {
        af3[CHARLIM-1] = '\0';
      }
    }
  }
}

void DialogueBox::clean() {
  aff[0] = '\0';
  af2[0] = '\0';
  af3[0] = '\0';
}

bool DialogueBox::isEmpty() {
  return (((aff[0] == '\0' || aff == NULL) && (af2[0] == '\0' || af2 == NULL))
          && ((af3[0] == '\0' || af3 == NULL))
        );
}

void DialogueBox::setColor(const SDL_Color & c) {
  color = c;
}

/// ----------------------------------------------------------- Drawable Sprite
//code

Sprite::Sprite(const std::string adress,const SDL_Rect pos, bool oversize, unsigned short int multiplier) {
  transform = new SDL_Rect;
  transform->x = pos.x;
  transform->y = pos.y;
  if (oversize) {
    transform->h = pos.h;
    transform->w = pos.w;
  }
  filename = adress;
  ovsize = oversize;
  multi = multiplier;
}

Sprite::~Sprite() {
  SDL_FreeSurface(surface);
  SDL_DestroyTexture(texture);
  delete transform;
  surface = NULL;
  texture = NULL;
  transform = NULL;
}

unsigned short int Sprite::_init(unsigned short int dimX, unsigned short int dimY, SDL_Renderer * render) {
  surface = loadImage(filename.c_str());
  texture = SDL_CreateTextureFromSurface(render,surface);
  if(!ovsize) SDL_QueryTexture(texture, NULL, NULL, &transform->w, &transform->h);
  transform->w *= multi;
  transform->h *= multi;
  return 0;
}

unsigned short int Sprite::_update(SDL_Renderer * render) {
  if (SDL_RenderCopy(render, texture, NULL, transform)<0) {
    printf("sprite does not render, exiting... \n");
    return ERRCODE_NO_RENDER;
  }
  return 0;
}
