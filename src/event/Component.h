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
  virtual unsigned short int _init(unsigned short int dimX, unsigned short int dimY, SDL_Renderer * render) = 0;
  virtual unsigned short int _update(SDL_Renderer * render) = 0;
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
  virtual unsigned short int _init(unsigned short int dimX, unsigned short int dimY, SDL_Renderer * render);

  /** @brief update method
      called by parent, ends when the event is closed or when an error happens
      @return ERRCODE if error happened, 0 else
  */
  virtual unsigned short int _update(SDL_Renderer * render);

  /**@brief << operator for writing
    used to write a string to the box*/
  void operator << (const char* in);

  /**@brief cleans the textbox*/
  void clean();

  /**@brief returns true if aff is empty or NULL*/
  bool isEmpty();

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
  // text line 2
  SDL_Rect * l2_transform;
  // text line 3
  SDL_Rect * l3_transform;
  // retrospect : should've done a struct + array

  TTF_Font *font; // used font (Power Green ftw)
  char * aff = NULL; // current line
  char * af2 = NULL;
  char * af3 = NULL;
  //#N En principe t'as pas besoin des acolades
  SDL_Color color = {0,0,0}; //black by default, might be changed by constructor or method later
};



/**@class Sprite
  create an image (might animate later)*/
class Sprite : public Component {
public :
  /** @brief class constructor
      @param adress link to the used image file
      @param pos position and size of the img file*/
  Sprite(const std::string adress, const SDL_Rect pos, bool overwrite_size = false, unsigned short int multiplier = 1);
  /** @brief class destructor*/
  ~Sprite();
  /** @brief see component base init*/
  unsigned short int _init(unsigned short int dimX, unsigned short int dimY, SDL_Renderer * render);
  /** @brief see component base update*/
  unsigned short int _update(SDL_Renderer * render);
private :
  // image data
  SDL_Rect * transform;
  SDL_Surface * surface;
  SDL_Texture * texture;
  // private data
  std::string filename;
  bool ovsize;
  unsigned short int multi;
};
#endif
