/** @file header file for component class */

#ifndef POKE_CPN_H
#define POKE_CPN_H

#include "SDL_ttf.h"
#include "SDL_image.h"
#include "SDL.h"
#include <stdlib.h>
#include <string.h>

#define ERRCODE_NO_COMP 1
#define ERRCODE_FONT_NOT_LOADED 2
#define ERRCODE_NO_TTF 3
#define ERRCODE_NO_AFF 4

/** @class Component
    @brief container class for Components
    Components makes up a scene for events
*/
class Component {
public:
  unsigned short int _init();
  unsigned short int _update();
protected:
};


/** @class dialogueBox
    @brief Component box that gets sent text files and reads them*/
class DialogueBox : public Component {

  /** @brief init method
      called when launched and not when created, loads ressources
      @return ERRCODE if error happened, 0 else
  */
  unsigned short int _init();

  /** @brief update method
      called by parent, ends when the event is closed or when an error happens
      @return ERRCODE if error happened, 0 else
  */
  unsigned short int _update();

  /**@brief << operator for writing
    used to write a string to the box*/
  void operator << (const char* str);

  /**@brief cleans the textbox*/
  void clean();

protected :
  SDL_Texture * image;
  SDL_Surface * surface;
  SDL_Surface * txtSurface;
  //int x, y;
  //SDL_RWops *textio;
  TTF_Font *font;
  char * aff = NULL;
  SDL_Color color = {0,0,0}; //black by default, might be changed by constructor or method later
};

#endif
