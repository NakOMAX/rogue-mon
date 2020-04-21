/** @file header file for component class */

#ifndef POKE_CPN_H
#define POKE_CPN_H

//includes
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "SDL.h"
#include <stdlib.h>
#include <string>

// Error codes
#define ERRCODE_NO_COMP 1
#define ERRCODE_FONT_NOT_LOADED 2
#define ERRCODE_NO_TTF 3
#define ERRCODE_NO_AFF 4
#define ERRCODE_NO_RENDER 5

/** @class Component
    @brief container class for Components
    Components makes up a scene for events
*/
class Component {
public:
  Component();
  ~Component();
  unsigned short int _init(unsigned short int dimX, unsigned short int dimY, SDL_Renderer * render);
  unsigned short int _update(SDL_Renderer * render);
protected:
};

// Max number of characters in textbox (to adapt later)
#define CHARLIM 71
/** @class dialogueBox
    @brief Component box that gets sent text files and reads them*/
class DialogueBox : public Component {
 public:
  DialogueBox();
  /** @brief class destructor
  */
  ~DialogueBox();

  /** @brief init method
      called when launched and not when created, loads ressources
      @return ERRCODE if error happened, 0 else
  */
  unsigned short int _init(unsigned short int dimX, unsigned short int dimY, SDL_Renderer * render);

  /** @brief update method
      called by parent, ends when the event is closed or when an error happens
      @return ERRCODE if error happened, 0 else
  */
  unsigned short int _update(SDL_Renderer * render);

  /**@brief << operator for writing
    used to write a string to the box*/
  void operator << (const char* in);

  /**@brief cleans the textbox*/
  void clean();

  /** @brief changes color */
  void setColor(const SDL_Color & color);

protected :
  // for the background
  SDL_Rect * transform;
  SDL_Surface * surface;
  SDL_Texture * image;

  // for the text
  SDL_Rect * text_transform;
  SDL_Surface * txt_surface;
  SDL_Texture * txt_image;

  TTF_Font *font; // used font (Power Green ftw)
  char * aff = NULL; // current line
  //#N En principe t'as pas besoin des acolades
  SDL_Color color = {0,0,0}; //black by default, might be changed by constructor or method later
};



/**@class Button
  @brief a clickable button
  Launches the linked function*/
class Button : public Component {
public :
  /**@brief class constructor*/
  Button(SDL_Rect * pos);
  /**@brief class destructor*/
  ~Button();
  /**@brief init method, called by event*/
  unsigned short int _init(unsigned short int dimX, unsigned short int dimY, SDL_Renderer * render);
  /**@brief update method, called by event loop*/
  unsigned short int _update(SDL_Renderer * render);

protected :
  //main related
  SDL_Rect * transform;
  SDL_Surface * surface;
  SDL_Texture * image;
  SDL_Color * bg_color;

  // text related
  SDL_Rect * txt_transform;
  SDL_Surface * txt_surface;
  SDL_Texture * txt_image;

  TTF_Font * font;
  std::string * aff;
  SDL_Color textColor = {0,0,0};
};
#endif
